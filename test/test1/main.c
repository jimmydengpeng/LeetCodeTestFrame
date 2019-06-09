#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    fin = fopen("./in.txt", "r");
    fout = fopen("out.txt", "a");

    char str[100];
    fgets(str, 100, fin);

    fprintf(fout, "%s", str);

    return 0;
}
