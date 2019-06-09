#include "src/problems.h"

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }
    else if (
        numsSize == 0)
    {
        return 0;
    }

    int max_len = numsSize;
    for (int i = 0; i < max_len; i++)
    {
        // traverse_arr(nums, max_len);
        int curr = nums[i];
        // printf("now is running at: nus[%d] = %d\n", i, curr);
        int j = i + 1;
        while ((j < max_len) && (nums[j] == curr))
        {
            j++;
        }
        // printf("j = %d\n", j);
        if (j > (i + 1))
        {
            int k = i + 1;
            while (j < max_len)
            {
                // printf("%d<-%d\n", nums[k], nums[j]);
                nums[k++] = nums[j++];
            }
            max_len -= (j - k);
            // printf("max_len = %d\n", max_len);
        }
    }
    return max_len;
}
