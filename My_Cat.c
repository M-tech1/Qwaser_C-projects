#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **acv)
{
    char chr;
    int x = 1;

    while (x < ac)
    {
        FILE *fp = fopen(acv[x], "r"); // this will open the file in read mode
        if (fp < 0)
        {
            perror(acv[x]);

            return -1;
        }

        while ((chr = getc(fp)) != EOF) // readubg char by char till it equals EOF

        {
            write(1, &chr, 1);
        }

        fclose(fp);
        x++;
    }
}