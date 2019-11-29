// Tatami.c

#include <math.h>
#include <stdio.h>

#define nMax 100000000

unsigned char v[nMax];

int Tatami(int s)
{
    const int nMaxSqrt = sqrt(nMax);

    for (int i = 0; i < nMaxSqrt; i++)
    {
        int k2, k3;
        for (int k = 1;
            (k2 = ((k * i) + k + 2)) <= (k3 = (((k + 1) * i) - k - 3));
            ++k)
        {
            if ((i * k2) >= nMax)
                break;
            for (int j = k2; j <= k3; ++j)
            {
                if ((i & j & 1) || (i * j >= nMax))
                    continue;
                ++v[i * j];
            }
        }
    }

    for (int i = 0; i < nMax; ++i)
        if (v[i] == s)
            return i;
}

int main()
{
    printf("The smallest room size s for which T(s) = 200 is %d\n", Tatami(200));
}
