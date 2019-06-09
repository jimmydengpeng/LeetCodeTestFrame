#include "src/problems.h"

bool isPalindrome(int x)
{
    int y = reverse(x);
    return y == x ? true : false;
}
