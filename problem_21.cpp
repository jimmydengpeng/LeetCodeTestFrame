#include "src/problems.h"

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tail;
    tail = head;
    head->next = NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            // printf("%d < %d\n", l1->val, l2->val);
            struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = l1->val;
            tail->next = p;
            tail = p;
            l1 = l1->next;
        }
        else
        {
            // printf("%d < %d\n", l2->val, l1->val);
            struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->val = l2->val;
            tail->next = p;
            tail = p;
            l2 = l2->next;
        }
    }
    if (l1 == NULL)
    {
        // while (l2 != NULL)
        // {
        //     struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        //     p->val = l2->val;
        //     tail->next = p;
        //     tail = p;
        //     l2 = l2->next;
        // }
        tail->next = l2;
    }
    else
    {
        // while (l1 != NULL)
        // {
        //     struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        //     p->val = l1->val;
        //     tail->next = p;
        //     tail = p;
        //     l1 = l1->next;
        // }
        tail->next = l1;
    }
    return head->next;
}