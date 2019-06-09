#include "src/frame.h"

int main(int argc, char *const *argv)
{
    CMDNAME = argv[0];
    parse_opt(argc, argv);
    return 0;
}
