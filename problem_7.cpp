#include "src/problems.h"

int reverse(int x)
{
    int isNeg = 0;
    if (x < 0)
        isNeg = 1;
    if (x == -pow(2, 31))
        return 0;
    long long y = isNeg ? -x : x;
    int max_digit = 1;
    int flag = 1;
    while (flag)
    {
        flag = y / 10;
        if (flag)
        {
            y = flag;
            max_digit += 1;
        }
    }
    // printf("%d 有%d位数。\n", x, max_digit);

    flag = 1;
    y = isNeg ? -x : x;

    long long n = 0;
    long long res = 0;
    for (int i = 1; i <= max_digit; i++)
    {
        n = y / (int)(pow(10, max_digit - i));
        y = y % (int)(pow(10, max_digit - i));
        res += n * (int)pow(10, i - 1);
    }

    if (isNeg)
    {
        if (res > pow(2, 31))
        {
            return 0;
        }
        else
        {
            return -res;
        }
    }
    else
    {
        if (res > pow(2, 31) - 1)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }

    // return isNeg ? -res : res;
}
