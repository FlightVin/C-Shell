#include "headers.h"
#include "echo.h"

void echo(char** arg_list, size_t num_eles){ // print after getting tokenized input
    for (int i = 0; i<num_eles; i++){
        printf("%s ", arg_list[i]);
    }
    printf("\n");
} 