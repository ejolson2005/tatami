/* Tatami Array Get / Set / Add
UXLIBS: -lm
*/
/*  EJO This is the C BASIC extension library for use with mixtami.sb. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../basext.h"
#include "cbasic.h"

DIM AS unsigned char v[50000000];

/****************************
 Extension Module Functions
****************************/

besVERSION_NEGOTIATE
  RETURN_FUNCTION((int)INTERFACE_VERSION);
besEND

besSUB_START
  DIM AS long PTR p;
  besMODULEPOINTER = besALLOC(sizeof(long));
  IF (besMODULEPOINTER EQ NULL) THEN_DO RETURN_FUNCTION(0);
  p = (long PTR)besMODULEPOINTER;
  RETURN_FUNCTION(0);
besEND

besSUB_FINISH
  DIM AS long PTR p;
  p = (long PTR)besMODULEPOINTER;
  IF (p EQ NULL) THEN_DO RETURN_FUNCTION(0);
  RETURN_FUNCTION(0);
besEND


/************************
 Tatami array functions
************************/

besFUNCTION(do_v)
  DIM AS long start;
  DIM AS long end;
  DIM AS long value;
  DIM AS long idx;
  besARGUMENTS("iii")
    AT start, AT end, AT value
  besARGEND
  DEF_FOR (idx = start TO idx <= end STEP INCR idx + 2)
  BEGIN_FOR
    v[(value * idx) / 2] += 1;
  NEXT
  besRETURNVALUE = NULL;
besEND 

besFUNCTION(find_s)
  DIM AS long s;
  DIM AS long idx;
  besARGUMENTS("i")
    AT s
  besARGEND
  DEF_FOR (idx = 0 TO idx <= 49999999 STEP INCR idx)
  BEGIN_FOR
    IF (v[idx] == s) THEN
      besRETURN_LONG(idx + idx);
         EXIT_FOR
    END_IF
  NEXT
besEND  
