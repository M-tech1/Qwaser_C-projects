#include "header_files.h"
#include <stdlib.h>
#include <time.h>

#define MAX 7

int distn_colors[5];
int colr[MAX];
char res[5];

char* gen_random() {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        colr[i] = i;
    }

    for (int i = 0; i < MAX - 1; i++) {
        int c = rand() % (MAX - i);
        int t = colr[i];
        colr[i] = colr[i + c];
        colr[i + c] = t;
    }

    for (int i = 0; i < 4; i++) {
        distn_colors[i] = colr[i] + 1;
    }

    for (int i = 0; i < 4; i++) {
        res[i] = '0' + distn_colors[i];
    }

    return res;
}

