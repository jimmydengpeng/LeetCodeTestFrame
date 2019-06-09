#include "src/problems.h"

void str_cat_c(char *dest, char c)
{
    int i = 0;
    int dest_len = strlen(dest);
    dest[dest_len + 1] = '\0';
    dest[dest_len] = c;
    // puts(dest);
}

bool is_common_c(char **strs, int strsSize, int index)
{
    bool flag = true;
    for (int i = 0; i < strsSize - 1; i++)
    {
        for (int j = i + 1; j < strsSize; j++)
        {
            if (strs[i][index] != strs[j][index])
                flag = false;
        }
    }

    return flag;
}

char *longestCommonPrefix(char *strs[], int strsSize)
{

    if (
        (strlen(*strs) == 0) ||
        (strsSize == 0))
    {
        printf("empty strs, now return.\n");
        return NULL;
    }
    int min_str_len = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++)
    {
        if (strlen(strs[i]) < min_str_len)
            min_str_len = strlen(strs[i]);
    }
    // printf("%d\n", min_str_len);
    char *common_prefix = (char *)malloc((min_str_len + 1) * sizeof(char));
    common_prefix[0] = '\0';

    for (int i = 0; i < min_str_len; i++)
    {
        if (is_common_c(strs, strsSize, i) && (i == 0))
        {
            str_cat_c(common_prefix, strs[i][i]);
        }
        else if (!is_common_c(strs, strsSize, i) && (i == 0))
            return NULL;
        else if (is_common_c(strs, strsSize, i))
            str_cat_c(common_prefix, strs[0][i]);
        else
            return common_prefix;
    }

    return common_prefix;
}