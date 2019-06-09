
#include <unistd.h>
#include <getopt.h>

#include "util.h"
// #include "problems.h"

#ifndef _FRAME_H
#define _FRAME_H

static const char CMDNAME[10] = {};
static int verbose_flag;

struct problem_id
{
    int pid_indicator;           //
    int p_number;                //0
    char p_title[MAX_TITLE_LEN]; //1
};

void print_usage();
void print_help();

void run_problem(struct problem_id pid);
void describe_problem(struct problem_id pid);
void parse_opt(int argc, char *const *argv);

#endif