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
    store_history();
    exit(EXIT_SUCCESS);
}

void run_command(char* cur_command){
    char* argument_list[max_arg_length];
    char* old_argument = strdup(cur_command);
    int num_arguments;
    my_strtok(argument_list, &num_arguments, " \n\t", cur_command);
    
    if (num_arguments == 0) return;
    char* main_command = strdup(argument_list[0]);

    add_to_history(parse_to_string(argument_list, num_arguments), default_history_storage_size);

    if (strcmp(main_command, "echo") == 0){
        echo(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "cd") == 0){
        cd(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "pwd") == 0){
        pwd(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "quit") == 0 || strcmp(main_command, "exit") == 0){
        my_quit();
    } else if (strcmp(main_command, "ls") == 0){
        ls(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "pinfo") == 0){
        pinfo(&argument_list[1], num_arguments - 1);
    } else if (strcmp(main_command, "history") == 0){
        history(default_history_display_num);
    } 

    else {
        run_in_foreground(argument_list);
    }
}

void my_cwd(){
    getcwd(cur_dir, max_str_len);
}

char* get_month(int m_num){
    if (m_num == 1) return "Jan";
    if (m_num == 2) return "Feb";
    if (m_num == 3) return "Mar";
    if (m_num == 4) return "Apr";
    if (m_num == 5) return "May";
    if (m_num == 6) return "Jun";
    if (m_num == 7) return "Jul";
    if (m_num == 8) return "Aug";
    if (m_num == 9) return "Sep";
    if (m_num == 10) return "Oct";
    if (m_num == 11) return "Nov";
    if (m_num == 11) return "Dec";
}

char* parse_to_string(char** args_list, int arg_num){
    char* ret_string = (char*) malloc(sizeof(char) * max_str_len);

    strcpy(ret_string, args_list[0]);

    for (int i = 1; i<arg_num; i++){
        strcat(ret_string, " ");
        strcat(ret_string, args_list[i]);
    }

    return ret_string;
}