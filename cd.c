#include "headers.h"
#include "path.h"

void cd(char** path, int num){
    if (num > 1){
        printf("Wrong format! Enter only one argument.\n");
        return;
    }
    getcwd(cur_dir, max_str_len);

    if (num == 0){ // change to root directory
        int chdir_ret = chdir(root_dir_path);

        if (chdir_ret < 0){
            printf("No such path exists!\n");
            return;
        }
    } else if (*path[0] == '-'){ // change to previous directory
        if (!pwd_flag){
            printf("old_pwd doesn't exist!\n");
            return;
        }
        printf("%s\n", old_pwd);
        chdir(old_pwd);
    } else { // change to path
        char new_path[1000];
        absolute_path(*path, new_path);
        int chdir_ret = chdir(new_path);
        if (chdir_ret < 0){
            printf("No such path exists!\n");
            return;
        }
    }

    // set pwd_flag for executing cd -
    strcpy(old_pwd, cur_dir);
    pwd_flag = 1;
}