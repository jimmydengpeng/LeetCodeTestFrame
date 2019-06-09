#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#ifndef _UTIL_H
#define _UTIL_H

#define MAX_TITLE_LEN 20
#define MAX_INPUT_STR_LEN 100

/******Definition for singly-linked list*******/
/******链表定义*******/
struct ListNode
{
    int val;
    struct ListNode *next;
};

// typedef char ElementType;

// typedef struct Stack
// {
//     char str[10];
//     int top;
// } Stack;

// Stack stk;

// char pop()
// {
//     char empty_c = '\0';
//     if (stk.top == 0)
//         return empty_c;
//     else
//     {
//         stk.top--;
//         return stk.str[stk.top];
//     }
// }

// void push(char c)
// {
//     if (stk.top <= 10)
//     {
//         stk.str[stk.top] = c;
//         stk.top += 1;
//     }
// }

/******基础设施函数******/
void traverse_arr(int arr[], int max_len);
void traverse_linked_list(struct ListNode *ll);
struct ListNode *init_linked_list_by_str(char *str);
int inputInteger();
void inputString(char *dest);
bool is_atoiable(char *atoi_str);
void strtolowercase(char *dest, const char *src);

#endif