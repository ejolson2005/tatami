PROGRAM TatamiProgram;
USES crt;

VAR nMax : LONGWORD = 100000000;
VAR nMaxSqrt : LONGWORD;
VAR v : ARRAY OF WORD;
VAR t : LONGWORD;

FUNCTION tatami(t : LONGWORD) : LONGWORD;
VAR ix, i, j, k2, k3, k4 : LONGWORD;
BEGIN
   tatami := 0;
   nMaxSqrt := Trunc(Sqrt(Double(nMax)));
   SetLength(v, nMax);
   FOR i := 0 TO nMax - 1 DO
      v[i] := 0;

   i := 7;
   WHILE i < nMaxSqrt DO
   BEGIN
      k2 := i + 3;
      k3 := i + i - 4;
      WHILE (k2 <= k3) AND ((i * k2) < nMax) DO
      BEGIN
         k4 := (nMax - 1) DIV i;
         IF k3 < k4 THEN
            k4 := k3;
         j := k2;
         WHILE j <= k4 DO
         BEGIN
            ix := (i * j) DIV 2;
            v[ix] := v[ix] + 1;
            j := j + 2;
         END;
         k2 := k2 + i + 1;
         k3 := k3 + i - 1;
      END;
      i := i + 2;
   END;
   i := 8;
   WHILE i < nMaxSqrt DO
   BEGIN
      k2 := i + 3;
      k3 := i + i - 4;
      WHILE (k2 <= k3) AND ((i * k2) < nMax) DO
      BEGIN
         k4 := (nMax - 1) DIV i;
         IF k3 < k4 THEN
            k4 := k3;
         FOR j := k2 TO K4 DO
         BEGIN
            ix := (i * j) DIV 2;
            v[ix] := v[ix] + 1;
         END;
         k2 := k2 + i + 1;
         k3 := k3 + i - 1;
      END;
      i := i + 2;
   END;
   FOR i := 0 TO nMax DIV 2 DO
      IF v[i] = t THEN
      BEGIN
         tatami := i + i;
         EXIT;
      END;
END;

BEGIN
   t := 200;
   WriteLn('T(', tatami(t), ') = ', t);
END.
