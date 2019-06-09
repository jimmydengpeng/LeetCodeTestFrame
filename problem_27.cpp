
// int removeElement(int *nums, int numsSize, int val)
// {
//     int max_len = numsSize;
//     for (int i = 0; i < max_len; i++)
//     {
//         traverse_arr(nums, numsSize);
//         if (nums[i] == val)
//         {
//             for (int k = max_len; k > i; k--)
//             {
//                 if (nums[k] == val)
//                 {
//                     max_len--;
//                 }
//                 else
//                 {
//                     nums[i] = nums[max_len];
//                     max_len--;
//                 }
//             }
//         }
//     }
//     return max_len;
// }

int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    while (nums[i] != NULL)
    {
        std::cout << nums[i] << ",";
        i++;
    }
}
