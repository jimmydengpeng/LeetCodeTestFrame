
#include "util.h"

/******基础设施函数******/
void traverse_arr(int arr[], int max_len)
{
    printf("[ ");
    for (int i = 0; i < max_len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void traverse_linked_list(struct ListNode *ll)
{
    while (ll != NULL)
    {
        printf("%d", ll->val);
        if (ll->next != NULL)
            printf(" -> ");
        else
            printf("\n");
        ll = ll->next;
    }
}

struct ListNode *init_linked_list_by_str(char *str)
{
    printf("now is in init_ll\n");
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    printf("1\n");
    head->val = 123;
    printf("%d\n", head->val);
    head->next = NULL;
    struct ListNode *tail;
    tail = head;
    int i = 0;
    while (str[i] != '\0')
    {
        printf("2:%d\n", i);
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        printf("now is converting char %c into integer %d.\n", str[i], str[i] - '0');
        p->val = (int)(str[i] - '0');
        p->next = NULL;
        printf("i=%d : p->val=%d\n", i, p->val);
        tail->next = p;
        tail = p;
        i++;
    }
    return head->next;
}

int inputInteger()
{
    printf("输入一个整数，按enter结束：\n");
    int a;
    scanf("%d", &a);
    return a;
}
void inputString(char *dest)
{
    printf("输入字符串，按enter结束：\n");
    char str[MAX_INPUT_STR_LEN];
    int i = 0;
    fgets(str, MAX_INPUT_STR_LEN, stdin);

    strcpy(dest, str);
}

bool is_atoiable(char *atoi_str)
{
    bool flag = true;
    int i = 0;
    while (atoi_str[i] != '\0')
    {

        if (atoi_str[i] > '9' || atoi_str[i] < '0')
        {
            flag = false;
            break;
        }
        atoi_str++;
    }
    return flag;
}

void strtolowercase(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        if (src[i] == 32)
        {
            dest[i] = src[i];
        }
        else if (src[i] < 91)
        {
            dest[i] = src[i] + 32;
        }
        else
        {
            dest[i] = src[i];
        }
        i++;
    }
    dest[i] = '\0';
}