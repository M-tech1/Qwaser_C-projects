#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// write a method to sort the string
char *sort_str(char *str)
{
    char *nstr;
    nstr = (char *)malloc(strlen(str) - 1);
    nstr = strdup(str);
    int strln = strlen(str);
    char temp;

    int i, j;

    for (i = 0; i < strln; i++)
    {
        for (j = 0; j < strln; j++)
        {
            if (nstr[i] < nstr[j])
            {
                temp = nstr[i];
                nstr[i] = nstr[j];
                nstr[j] = temp;
            }
        }
    }

    return nstr;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
    }
    int i = 1;
    int j = 1;
    int totallen = 0;

    while (1)
    {
        if (argv[i] == NULL) break;
        totallen = totallen + strlen(argv[i]);
        i++;
    }

    char *word = malloc(totallen);
    while (1)
    {
        if (argv[j] == NULL) break;
        strcat(word, argv[j]);
        j++;
    }

    char *new_str = sort_str(word);

    int count = 0;
    char *checked;
    checked = (char *)malloc(strlen(new_str));
    int strln = strlen(new_str);
    for (int i = 0; i < strln; i++)
    {
        for (int j = 0; j < strln; j++)
        {
            if ((!strchr(checked, new_str[i])) && (new_str[i] == new_str[j]))
                count++;
        }

        if (!(strchr(checked, new_str[i])))
        {
            printf("%c:%d\n", new_str[i], count);

            count = 0;
        }
        checked[i] = new_str[i];
    }

    return 0;
}

