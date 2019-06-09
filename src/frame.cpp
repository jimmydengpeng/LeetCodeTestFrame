
#include "frame.h"
#include <vector>

void print_usage()
{
    printf("USAGE: %s [-opt] [arg]\n", CMDNAME);
}

void print_help()
{
    printf("HELP:\n");
    print_usage();
}

/******测试、处理、加载问题的函数******/
void problem_7()
{
    printf("《整数反转 Reverse Integer》\n");
    printf("%d\n", reverse(inputInteger()));
}

void problem_9()
{
    printf("《判断是否回文数 Palindrome Number》\n");
    if (isPalindrome(inputInteger()))
        printf("Yes!\n");
    else
        printf("No!\n");
}

void problem_13()
{
    printf("《罗马数转整数》\n");
    char roman_number[MAX_INPUT_STR_LEN];
    inputString(roman_number);
    printf("input: %s\n", roman_number);
    int roman_number_integer = romanToInt(roman_number);
    printf("%d\n", roman_number_integer);
}

void problem_14()
{
    char *strs[] =
        {};
    // {"flower", "flowq", "fwlowaada", "flowag"};
    char *common_prefix = longestCommonPrefix(strs, 0);
    puts(common_prefix);
}

void problem_20()
{
    char b_str[] = "()[]{}";
    if (isValid(b_str))
        printf("Valid!\n");
    else
        printf("Invalid!\n");
}
void problem_21()
{
    char str[] = "1246";
    struct ListNode *l1 = init_linked_list_by_str(str);
    printf("l1: ");
    traverse_linked_list(l1);
    char str2[] = "2378";
    struct ListNode *l2 = init_linked_list_by_str(str2);
    printf("l2: ");
    traverse_linked_list(l2);

    struct ListNode *l3 = mergeTwoLists(l1, l2);
    traverse_linked_list(l3);
}
void problem_26()
{
    int nums[] = {1, 1};
    int lens = removeDuplicates(nums, 2);
    printf("%d\n", lens);
    for (int i = 0; i < lens; i++)
    {
        printf("%d ", nums[i]);
    }
}

void problem_27()
{
    vector();
    std::vector nums = {0, 1, 2, 2, 3, 0, 4, 2};
    // traverse_arr(nums, 8);
    int val = 3;
    removeElement(nums, val);
    // printf("%d\n", len);
}

/*********运行加载问题函数********/
void run_problem(struct problem_id pid)
{
    //如果用户输入的是英文Title
    if (pid.pid_indicator)
    {
        char lwc_p_title[MAX_TITLE_LEN];
        strtolowercase(lwc_p_title, pid.p_title);

        if (!strcmp("reverseinteger", lwc_p_title))
            problem_7();
        else if (!strcmp("palindromenumber", lwc_p_title))
            problem_9();
        else
        {
            printf("该问题问题没有解答！请重新输入！\n");
        }
    }
    //用户输入的是数字
    else
    {
        switch (pid.p_number)
        {
        case 7:
            problem_7();
            break;
        case 9:
            problem_9();
            break;
        case 13:
            problem_13();
            break;
        case 14:
            problem_14();
            break;
        case 20:
            problem_20();
            break;
        case 21:
            problem_21();
            break;
        case 26:
        {
            problem_26();
            break;
        }
        case 27:
        {
            problem_27();
            break;
        }
        default:
            printf("该问题问题没有解答！请重新输入！\n");
            break;
        }
    }
}

void describe_problem(struct problem_id pid)
{
    // print_problem(pid.p_number);
}

/***分析命令行选项参数的函数***/
void parse_opt(int argc, char *const *argv)
{
    static struct option long_options[] =
        {
            /* These options set a flag. */
            {"verbose", no_argument, &verbose_flag, 1},
            {"brief", no_argument, &verbose_flag, 0},
            /* These options don’t set a flag.
             We distinguish them by their indices. */
            {"run", required_argument, 0, 'r'},
            {"describe", required_argument, 0, 'd'},
            {"help", no_argument, 0, 'h'},
            {0, 0, 0}};

    int option_index = 0;

    int c = getopt_long(argc, argv, "r:d:h", long_options, &option_index);
    if (c == -1)
    {
        printf("WRONG OPTION: %s -%s!\n", argv[0], argv[1]);
        print_usage();

        exit(0);
    }

    if (optind < argc)
    {
        printf("ERROR: 参数过多！\n");
        print_usage();
        exit(0);
    }

    else
    {
        struct problem_id pid;
        if (is_atoiable(optarg))
        {
            pid.pid_indicator = 0;
            pid.p_number = atoi(optarg);
        }
        else
        {
            pid.pid_indicator = 1;
            strcpy(pid.p_title, optarg);
        }

        switch (c)
        {
        case 'h':
            print_help();
            break;
        case 'r':
            run_problem(pid);
            break;
        case 'd':
            describe_problem(pid);
            break;
        default:
            break;
        }
    }
}