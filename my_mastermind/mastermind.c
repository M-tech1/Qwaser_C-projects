#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include "header_files.h"
#include "string.h"



// ***************  Defining all my Unit functions  *******************

int my_strlen(char* str)
{
    int lent = 0;
    for (int x = 0; str[x] !='\0'; x++)    
        lent = lent + 1;
    return lent;
}

int my_isAlpha(char chr)
{
    if ((chr >= 'A' && chr <= 'Z' ) || (chr >= 'a' && chr <= 'z'))
        return 1;

    return 0;
}


int my_strcmp(char *a, char *b) {
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return 1;
        }
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0') ? 0 : 1;
}

int is_Number(char* sn)
{
    for (int x = 0; sn[x] !='\0'; x++)
        if (my_isAlpha(sn[x]) > 0)
            return true;     
    return false; 
}



char* secret_code(int argc, char* string[]) {
    char* code = NULL;
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(string[i], "-c") == 0 && i+1 < argc) {
            code = string[i+1];
            break;
        }
    }
    if (code == NULL) {
        code = gen_random();
    }
    return code;
}



int attempt_limit(int argc, char* argv[]) {
    int limit = 0;

    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-t") == 0) {
            limit = atoi(argv[i+1]);
            break;
        }
    }
    return limit;
}



int start_game(int attempt_limit, char* secret_code) {
  char guess_string[5];  // Declare an array to store the user's guess
  int correct_value = 0;
  int users_attempts = 0;
  int missed_value = 0;

  printf("Will you find the secret code?\nPlease enter a valid guess\n");
  while (users_attempts < attempt_limit) {
    printf("---\nRound %d\n", users_attempts);

    
    if (read(0, guess_string, 5) == -1) {
     return EXIT_SUCCESS;
    }

    // Check if the input contains only digits
    if (is_Number(guess_string)) {
      printf("Wrong input!\n");
      continue;
    }

// The secret code is guaranteed to be 4 characters long
    for (int j = 0; j < 4; j++) {  
      if (secret_code[j] == guess_string[j]) {
        correct_value++;
      }

        // The guess is guaranteed to be 4 characters long
      for (int k = 0; k < 4; k++) {  
        if (secret_code[j] == guess_string[k] && j != k) {
          missed_value++;
        }
      }
    }


    if (missed_value == 0 && correct_value == 4) {
      printf("Congratz! You did it!\n");
      return 0;
    } else {
      printf("Well placed pieces: %d\n", correct_value);
      printf("Misplaced pieces: %d\n", missed_value);
      correct_value = 0;
      missed_value = 0;
    }
    users_attempts++;

    if (users_attempts == attempt_limit) {
      printf("\nOoops! GAME OVER \n");
    }
  }

  return 0;
}
