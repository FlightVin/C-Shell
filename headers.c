#include "headers.h"

size_t max_str_len = 1e3;
size_t command_len = 1e3;
size_t max_arg_length = 1e3;
int pwd_flag = 0;
int shell_pid = 0;

char root_dir_path[1000] = "\0";
char* user_name = NULL;
char old_pwd[1000] = "\0";
char cur_dir[1000] = "\0";
char input_message[1000] = "\0";

long process_exec_time = 0;
int is_foreground_running = 0;
int cur_foreground_process_pid = 0;
char cur_foreground_process_name[1000];

int default_history_storage_size = 20;
int default_history_display_num = 10;
char history_storage_file_name[1000] = ".history_storage_file";
char history_storage_file[2000];