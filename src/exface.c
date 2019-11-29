/* Tatami Array Get / Set / Add
UXLIBS: -lm
*/
/*  EJO This is the C BASIC extension library for use with extami.sb. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../basext.h"
#include "cbasic.h"

DIM AS unsigned char v[100000000];

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

besFUNCTION(get_v)
  DIM AS long idx;
  DIM AS long value;
  besARGUMENTS("i")
    AT idx
  besARGEND
  value = v[idx];
  besRETURN_LONG(value);
besEND

besFUNCTION(set_v)
  DIM AS long idx;
  DIM AS long value;
  besARGUMENTS("ii")
    AT idx, AT value
  besARGEND
  v[idx] = value;
  besRETURNVALUE = NULL;
besEND

besFUNCTION(add_v)
  DIM AS long idx;
  DIM AS long value;
  besARGUMENTS("ii")
    AT idx, AT value
  besARGEND
  v[idx] += value;
  besRETURNVALUE = NULL;
besEND
