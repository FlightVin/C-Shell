#include "headers.h"

void my_strtok(char** list, int* num, char* args, char* in_data){
    list[0] = strtok(in_data, args);
    *num = 0;

    while(list[*num]){
        list[++(*num)] = strtok(NULL, args);
    }
}

int detect_amp(char* str){
    for (int i = 0; i<strlen(str); i++){
        if (str[i] == '&') return 1;
    }
    return 0;
}

void my_quit(){
    exit(EXIT_SUCCESS);
}

void run_command(char* cur_command){
    const int max_arg_length = 1000;

    char* argument_list[max_arg_length];


    char* old_argument = strdup(cur_command);
    int num_arguments;
    my_strtok(argument_list, &num_arguments, " \n\t", cur_command);
    if (num_arguments == 0) return;
    char* main_command = strdup(argument_list[0]);

    if (strcmp(main_command, "echo") == 0){
        echo(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "cd") == 0){
        cd(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "pwd") == 0){
        pwd(&argument_list[1], num_arguments - 1); //NOTE - HOME is pseudo home, home is actual home
    } else if (strcmp(main_command, "quit") == 0 || strcmp(main_command, "exit") == 0){
        my_quit();
    } else if (strcmp(main_command, "ls") == 0){
        ls(&argument_list[1], num_arguments - 1);
    }
    
    else {
        printf("Invalid command: %s\n", main_command);
    }
}

void my_cwd(){
    getcwd(cur_dir, max_str_len);
}