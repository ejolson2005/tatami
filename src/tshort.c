// tatami-with-shift-shorts.c

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nMax 100000000
#define nMaxSqrt sqrt(nMax)

unsigned short v[nMax / 2];

int Tatami(int s)
{
    for (int i = 7; i < nMaxSqrt; i += 2)
    {
        int k2 = i + 3;
        int k3 = i + i - 4;
        while ((k2 <= k3) && ((i * k2) < nMax))
        {
            int k4 = (nMax - 1) / i;
            if (k3 < k4)
                k4 = k3;
            for (int j = k2; j <= k4; j += 2)
                ++v[(i * j) / 2];
            k2 += i + 1;
            k3 += i - 1;
        }
    }
    for (int i = 8; i < nMaxSqrt; i += 2)
    {
        int k2 = i + 3;
        int k3 = i + i - 4;
        while ((k2 <= k3) && ((i * k2) < nMax))
        {
            int k4 = (nMax - 1) / i;
            if (k3 < k4)
                k4 = k3;
            for (int j = k2; j <= k4; ++j)
                ++v[(i * j) / 2];
            k2 += i + 1;
            k3 += i - 1;
        }
    }

    for (int i = 0; i < nMax / 2; ++i)
        if (v[i] == s)
            return i + i;
}

int main(int ac, char* av[])
{
    int s = atoi(av[1]);
    printf("T(%d) = %d\n", Tatami(s), s);
}
