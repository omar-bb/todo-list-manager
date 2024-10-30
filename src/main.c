#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        print_info();
    } 
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-h") || strcmp(argv[1], "--help"))
        {
            print_help();
        }
    }

    return 0;
}

