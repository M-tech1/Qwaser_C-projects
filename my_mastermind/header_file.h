#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


char* gen_random();
int my_strlen(char* string);
int is_Number(char* s);
int my_strcmp(char *a,char *b);
int my_isAlpha(char ch);
char* secret_code(int argc, char* string[]);
int attempt_limit(int argc, char* string[]);
int start_game(int attempt_limit, char* secret_code);
 