#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "header_files.h"

int main(int argc, char** argv)
{
    int def_attempt = 10;
    char* secret_coded = secret_code(argc, argv);

    if (secret_coded == NULL)
    {
        secret_coded = gen_random();
    }

    if (attempt_limit(argc, argv) > 0)
    {
        def_attempt = attempt_limit(argc, argv);
    }

    printf("sec code %s\n", secret_coded);
    start_game(def_attempt, secret_coded);
}

