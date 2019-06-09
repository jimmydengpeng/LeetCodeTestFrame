#include "src/problems.h"

#define max_stack_len 10000

typedef struct Stack
{
    char str[max_stack_len];
    int top;
} Stack;

Stack stk;

char pop()
{
    char empty_c = '\0';
    if (stk.top == 0)
        return empty_c;
    else
    {
        stk.top--;
        return stk.str[stk.top];
    }
}

void push(char c)
{
    if (stk.top <= max_stack_len)
    {
        stk.str[stk.top] = c;
        stk.top += 1;
    }
}

bool is_Pair(char c1, char c2)
{
    char b[] = "([{)]}";

    for (int i = 0; i < 6; i++)
    {
        if (c1 == b[i])
        {
            if (i < 3)
            {
                if (c2 == b[i + 3])
                    return true;
                else
                    return false;
            }
            else if (c2 == b[i - 3])
                return true;
            else
                return false;
        }
    }
    return false;
}

bool is_end_bracket(char c)
{
    if (
        (c == ')') ||
        (c == ']') ||
        (c == '}'))
    {
        // printf("%c is end bracket\n", c);
        return true;
    }
    else
    {
        // printf("%c is not end bracket\n", c);
        return false;
    }
}

bool isValid(char *s)
{
    stk.top = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        // printf("now is running at: %c:%d\n", s[i], i);
        if (s[i] == ' ')
            i++;
        else if ((stk.top == 0) && is_end_bracket(s[i]))
        {
            // printf("1\n");
            return false;
        }
        else if ((stk.top != 0) && is_end_bracket(s[i]))
        {
            if (is_Pair(pop(), s[i]))
                i++;
            else
            {
                // printf("2\n");
                return false;
            }
        }
        else if (!is_end_bracket(s[i]))
        {
            // printf("now is pushing: %c:%d\n", s[i], i);
            push(s[i]);
            // if (stk.str[i] == s[i])
            //     printf("DONE pushing at: %c:%d\n", stk.str[i], i);
            // else
            // {
            //     printf("ERROR pushing at: %c:%d\n", stk.str[i], i);
            //     printf("4\n");
            //     return false;
            // }
            i++;
        }
        else
        {
            i++;
        }
    }
    if (stk.top == 0)
    {
        return true;
    }
    else
    {
        // printf("3\n");
        return false;
    }
}
