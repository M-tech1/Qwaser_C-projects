# Welcome to My Printf
***

## Task
To re-implement the Printf built in function

## Description
This project is about recreating the functioning logic of `printf` in C. The function created `my_printf` should be able to process the `format` given and accept a variable number of parameters.
Hence, the project is about creating a `variadic` function. The function implements `%[doux]` (for different number formats), `%c` (for character), `%s` (for string) and `%p` (for pointers).
The general steps taken were... find a way of processing the `format` and replacing placeholders with their appropriate values, 
printing it out to the stdout, and return the length of string output. I had many repeating blocks of code, so I opted to refactor the entire codebase. It is now modular,
 
## Installation
No Installation

## Usage
To use the function `my_printf`, call into where you want to use it, in this format:
```
my_printf(char* restrict format, ...)

#e.g.
my_printf("Hello, %s.", "Samuel");
my_printf("His name is %s, he is %u years old. He score %d in the past test", "Umeh", 12, -5);
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
