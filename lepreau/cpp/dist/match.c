/*
 * match.c - based on Steve Johnson's pdp11 version
 *
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	Noveber 80
 * Copyright (c) 1980 Jay Lepreau for Dec-20 version
 */

/* Dec-20 version: slightly modified pdp-11 one.	J.Lepreau 11/80  */

# include "mfile2"

/*
 * Make sure that when longs are used as
 *	return(<long exp>)
 * they return an integer
 */
#if bigshapes
# define logical(e)	((e) != 0)
#else
# define logical(e)	(e)
#endif

struct optab *rwtable;

struct optab *opptr[DSIZE];

int fldsz, fldshf;

static int mamask[] = { /* masks for matching dope with shapes */
	SIMPFLG,	/* OPSIMP */
	SIMPFLG|ASGFLG,	/* ASG OPSIMP */
	COMMFLG,	/* OPCOMM */
	COMMFLG|ASGFLG,	/* ASG OPCOMM */
	MULFLG,		/* OPMUL */
	MULFLG|ASGFLG,	/* ASG OPMUL */
	DIVFLG,		/* OPDIV */
	DIVFLG|ASGFLG,	/* ASG OPDIV */
	UTYPE,		/* OPUNARY */
	TYFLG,		/* ASG OPUNARY is senseless */
	LTYPE,		/* OPLEAF */
	TYFLG,		/* ASG OPLEAF is senseless */
	0,		/* OPANY */
	ASGOPFLG|ASGFLG,	/* ASG OPANY */
	LOGFLG,		/* OPLOG */
	TYFLG,		/* ASG OPLOG is senseless */
	FLOFLG,		/* OPFLOAT */
	FLOFLG|ASGFLG,	/* ASG OPFLOAT */
	SHFFLG,		/* OPSHFT */
	SHFFLG|ASGFLG,	/* ASG OPSHIFT */
	SPFLG,		/* OPLTYPE */
	TYFLG,		/* ASG OPLTYPE is senseless */
	};

int sdebug = 0;

tshape( p, shape ) NODE *p; SHAPESZ shape; {
	/* return true if shape is appropriate for the node p
	   side effect for SFLD is to set up fldsz,etc */
	register o, mask;

	o = p->op;

	if( sdebug ){
		printf( "tshape( %o, %o), op = %d\n", p, shape, o );
		}

	if( shape & SPECIAL ){

		switch( shape ){

		case SZERO:
		case SONE:
		case SMONE:
			if( o != ICON || p->name[0] ) return(0);
			if( p->lval == 0 && shape == SZERO ) return(1);
			else if( p->lval == 1 && shape == SONE ) return(1);
			else if( p->lval == -1 && shape == SMONE ) return(1);
			else return(0);

		default:
			return( special( p, shape ) );
			}
		}

	if( shape & SANY ) return(1);

	if( (shape&INTEMP) && shtemp(p) ) return(1);

	if( (shape&SWADD) && (o==NAME||o==OREG) ){
		if( BYTEOFF(p->lval) ) return(0);
		}

	switch( o ){

	case NAME:
		return( logical(shape & SNAME));    
	case ICON:
		mask = SCON;
		return( logical(shape & mask));

	case FLD:
		if( shape & SFLD ){
			if( !flshape( p->left ) ) return(0);
			/* it is a FIELD shape; make side-effects */
			o = p->rval;
			fldsz = UPKFSZ(o);
# ifdef RTOLBYTES
			fldshf = UPKFOFF(o);
# else
			fldshf = SZINT - fldsz - UPKFOFF(o);
# endif
			return(1);
			}
		return(0);

	case CCODES:
		return( logical(shape&SCC));

	case REG:
		/* distinctions:
		SAREG	any scalar register
		STAREG	any temporary scalar register
		SBREG	any lvalue (index) register
		STBREG	any temporary lvalue register
		*/
		mask = isbreg( p->rval ) ? SBREG : SAREG;
		if( istreg( p->rval ) && busy[p->rval]<=1 ) mask |= mask==SAREG ? STAREG : STBREG;
		return( logical(shape & mask));

	case OREG:
		return( logical(shape & SOREG));

	case UNARY MUL:
		/* return STARNM or STARREG or 0 */
		return( logical(shumul(p->left) & shape));

		}

	return(0);
	}

int tdebug = 0;

ttype( t, tword ) TWORD t; {
	/* does the type t match tword */

	if( tword & TANY ) return(1);

	if( tdebug ){
		printf( "ttype( %o, %o )\n", t, tword );
		}
	if( ISPTR(t) && (tword&TPTRTO) ) {
		do {
			t = DECREF(t);
		} while ( ISARY(t) );
			/* arrays that are left are usually only
			   in structure references... */
		return( ttype( t, tword&(~TPTRTO) ) );
		}
	if( t != BTYPE(t) ) return( tword & TPOINT ); /* TPOINT means not simple! */
	if( tword & TPTRTO ) return(0);

	switch( t ){

	case CHAR:
		return( tword & TCHAR );
	case SHORT:
		return( tword & TSHORT );
	case STRTY:
	case UNIONTY:
		return( tword & TSTRUCT );
	case INT:
		return( tword & TINT );
	case UNSIGNED:
		return( tword & TUNSIGNED );
	case USHORT:
		return( tword & TUSHORT );
	case UCHAR:
		return( tword & TUCHAR );
	case ULONG:
		return( tword & TULONG );
	case LONG:
		return( tword & TLONG );
	case FLOAT:
		return( tword & TFLOAT );
	case DOUBLE:
		return( tword & TDOUBLE );
		}

	return(0);
	}

setrew(){
	/* set rwtable to first value which allows rewrite */
	register struct optab *q;
	register int i;

	for( q = table; q->op != FREE; ++q ){
		if( q->needs == REWRITE ){
			rwtable = q;
			goto more;
			}
		}
	cerror( "bad setrew" );


	more:
	for( i=0; i<DSIZE; ++i ){
		if( dope[i] ){ /* there is an op... */
			for( q=table; q->op != FREE; ++q ){
				/*  beware; things like LTYPE that match
				    multiple things in the tree must
				    not try to look at the NIL at this
				    stage of things!  Put something else
				    first in table.c  */
				/* at one point, the operator matching was 15% of the
				    total comile time; thus, the function
				    call that was here was removed...
				*/

				if( q->op < OPSIMP ){
					if( q->op==i ) break;
					}
				else {
					register opmtemp;
					if((opmtemp=mamask[q->op - OPSIMP])&SPFLG){
						if( i==NAME || i==ICON || i==OREG ) break;
						else if( shltype( i, NIL ) ) break;
						}
					else if( (dope[i]&(opmtemp|ASGFLG)) == opmtemp ) break;
					}
				}
			opptr[i] = q;
			}
		}
	if (odebug > 3) {
		printf("setrew:\n");
		for (i = 0; i < DSIZE; i++) {
		    printf("opptr[%d] = %o, table[%d]", i, opptr[i],
			opptr[i]-table ); 	/* C divides last for you!! */
			printf("	opst[%d] = %s\n", i, opst[i]);
			}
		}

	}

match( p, cookie ) NODE *p; {
	/* called by: order, gencall
	   look for match in table and generate code if found unless
	   entry specified REWRITE.
	   returns MDONE, MNOPE, or rewrite specification from table */

	register struct optab *q;
	register NODE *r;

	rcount();
	if (odebug > 2) {		/* maybe should be above rcount? */
		printf("match start(%o, ", p);
		prcook(cookie);
		printf(")\n");
		}

	if( cookie == FORREW ) q = rwtable;
	else q = opptr[p->op];

	for( ; q->op != FREE; ++q ){

		/* at one point the call that was here was over 15% of the total time;
		    thus the function call was expanded inline */
		if( q->op < OPSIMP ){		/* single operator */
			if( q->op!=p->op ) continue;
			}
		else {				/* operator class */
			register opmtemp;
			if((opmtemp=mamask[q->op - OPSIMP])&SPFLG){
				if( p->op!=NAME && p->op!=ICON && p->op!= OREG &&
					! shltype( p->op, p ) ) continue;
				}
			else if( (dope[p->op]&(opmtemp|ASGFLG)) != opmtemp ) continue;
			}
	
		if (odebug > 2) {
			printf("op match: template# %d, ", q-table);
			prcook(q->visit);
			printf("(%o); cookie: ", q->visit);
			prcook(cookie);
			putchar('\n');
			}

		if( !(q->visit & cookie ) ) continue;
		r = getlr( p, 'L' );			/* see if left child matches */
		if( !tshape( r, q->lshape ) ) continue;
		if( !ttype( r->type, q->ltype ) ) continue;
		r = getlr( p, 'R' );			/* see if right child matches */
		if( !tshape( r, q->rshape ) ) continue;
		if( !ttype( r->type, q->rtype ) ) continue;

			/* REWRITE means no code from this match but go ahead
			   and rewrite node to help future match */
		if( q->needs & REWRITE ) return( q->rewrite );
		if( !allo( p, q ) ) continue;		/* if can't generate code, skip entry */

		/* resources are available */

		if (odebug > 1) printf("MATCHED template# %d\n", q - table);


#ifdef FIELDOPS				/* kludge -fjl */
		if (p->op == FLD) {
		    fldsz = UPKFSZ(p->rval);
		    fldshf = szty(p->type)*SZINT - fldsz - UPKFOFF(p->rval);
		}
#endif
		expand( p, cookie, q->cstring, q );	/* generate code */
		reclaim( p, q->rewrite, cookie );

		return(MDONE);

		}

	return(MNOPE);
	}

int rtyflg = 0;
extern int tnumflag;		/* template # flag - in reader.c */

expand( p, cookie, cp, q ) NODE *p;  register char *cp; struct optab *q; {
	/* generate code by interpreting table entry */

	CONSZ val;
	int numflg = 0;

	rtyflg = 0;

	for( ; *cp; ++cp ){		/* order these switches by frequncy */
		switch( *cp ){

		case '\n':		/* put out template # */
			if (tnumflag && !numflg) {  /* only once per template*/
				numflg++;
				printf("\t\t;%d", q - table);
			}	/* fall thru */
		default:
			PUTCHAR( *cp );
			continue;  /* this is the usual case... */

		case 'A': /* address of */
			adrput( getlr( p, *++cp ) );
			continue;

		case 'C': /* for constant value only */
			conput( getlr( p, *++cp ) );
			continue;

		case 'I': /* in instruction -- works with 'V' for dec-20 */
			insput( p, getlr(p, *++cp) );  /* added 1st parm -fjl*/
			continue;

		case 'O':  /* opcode string */
			hopcode( *++cp, p->op );
			continue;

		case 'V': /* variable format address depending on type of op */
			  /* (either conput or adrput depending if SACON) fjl*/
			vadrput( getlr( p, *++cp ) );
			continue;

		case 'Z':  /* special machine dependent operations */
			zzzcode( p, *++cp );
			continue;

		case 'T':
			/* rewrite register type is suppressed */
			rtyflg = 1;
			continue;

		case 'F':  /* this line deleted if FOREFF is active */
			if( cookie & FOREFF ) while( *++cp != '\n' ) ; /* VOID */
			continue;

		case 'S':  /* field size */
			printf( "%d", fldsz );
			continue;

		case 'H':  /* field shift */
			printf( "%d", (SZINT-1) - fldshf ); /* 20 hack -fjl */
			continue;

		case 'M':  /* field mask */
		case 'N':  /* complement of field mask */
			val = 1;
			val <<= fldsz;
			--val;
			val <<= fldshf;
			adrcon( *cp=='M' ? val : ~val );
			continue;

		case 'L':  /* output special label field */
			printf( "%d", p->label );
			continue;

		case 'B':  /* byte offset in word */
			val = getlr(p,*++cp)->lval;
			val = BYTEOFF(val);
			printf( CONFMT, val );
			continue;

		case 'U': /* for upper half of address, only */
			upput( getlr( p, *++cp ) );
			continue;

			}

		}

	}

NODE *
getlr( p, c ) NODE *p; {

	/* return the pointer to the left or right side of p, or p itself,
	   depending on the optype of p */

	switch( c ) {

	case '1':
	case '2':
	case '3':
		return( &resc[c-'1'] );

	case 'L':
		return( optype( p->op ) == LTYPE ? p : p->left );

	case 'R':
		return( optype( p->op ) != BITYPE ? p : p->right );

		}
	cerror( "bad getlr: %c", c );
	/* NOTREACHED */
	}
