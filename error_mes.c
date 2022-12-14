#include "headers.h"
#include "error_mes.h"

void throw_error(char* error_message){
    // exits shell only
    char* error_code_string = " Error code: %d\n";
    char* error_string = (char*) malloc(sizeof(char) * (strlen(error_message) + strlen(error_code_string) + 1));
    strcpy(error_string, error_message);
    strcat(error_string, error_code_string);

    printf(error_string, error_string, errno);
    
    add_to_history("exit with faliure", default_history_storage_size);

    perror("Program Status/Error");
    exit(EXIT_FAILURE);
}