#include "src/problems.h"

bool is_double_roman_number(char c1, char c2, int *ret_num)
{
    bool flag = false;
    if (c1 == 'I' && (c2 == 'V' || c2 == 'X'))
    {
        flag = true;
        if (c2 == 'V')
            *ret_num = 4;
        else
            *ret_num = 9;
    }
    else if (c1 == 'X' && (c2 == 'L' || c2 == 'C'))
    {
        flag = true;
        if (c2 == 'L')
            *ret_num = 40;
        else
            *ret_num = 90;
    }
    else if (c1 == 'C' && (c2 == 'D' || c2 == 'M'))
    {
        flag = true;
        if (c2 == 'D')
            *ret_num = 400;
        else
            *ret_num = 900;
    }
    return flag;
}

int romanToInt(char *s)
{
    printf("passed to: %s\n", s);
    int res = 0;
    int i = 0;
    int ret_num;
    while (s[i] != '\0')
    {
        ret_num = 0;
        if (
            (s[i + 1] != '\0') &&
            (is_double_roman_number(s[i], s[i + 1], &ret_num)))
        {
            printf("ret_num: %d [i = %d]\n", ret_num, i);
            res += ret_num;
            i += 2;
        }
        else
        {
            switch (s[i])
            {
            case 'I':
                res += 1;
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                res += 10;
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                res += 100;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            default:
                break;
            }
            i++;
        }
    }

    return res;
}