#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


/*An array of strings representing the environment variables.*/
extern char **environ;

void free_memory(char **argv);
void print_shell_prompt(void);
void print_shell_error(char *shell_name, int cmd_idx, char **cmd,
	char *err_msg);

char *read_command(void);
char **tokenize_command(char *cmd, char *delim);
size_t tokens_count(char *cmd_line, char *delim);
char **tokens_array(size_t count, char *cmd_line, char *delim, char *token);
int exec_command(char **cmd, char **argv, int cmd_idx, int *exit_status);
void process_command(char **cmd, char **argv, int cmd_idx, int *exit_status);
char *get_cmd_path(char **cmd, char **argv, int cmd_idx);
void child_process_exec(char *cmd_path, char **cmd);
void parent_process_exec(pid_t pid, char **cmd, char *cmd_path, int *status);
void handle_operators(char **cmd, char **argv, char *cmd_line, char *operator,
	int *exit_status, int cmd_idx);

char *_getenv(char *name);
char *_getpath(char *cmd);
char *check_command(char *cmd, struct stat st);

/***********************************/
void rev_string(char *str, int strlen);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int num);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

char *_itoa(int num);
int _atoi(char *s);

int check_if_builtin_cmd(char *cmd);
int handle_builtin_cmd(char **cmd, char **argv, int *exit_status,
	int cmd_idx);
int exit_shell(char **cmd, char **argv, int *exit_status, int cmd_idx);


int print_env(char **cmd);

int is_positive_num(char *str);

int _setenv(char *envname, char *envval, int overwrite);
int set_new_env(char *envname, char *envval);
int modify_env(char *envname, char *envval, int overwrite);
char *construct_env_str(char *envname, char *envval);
void print_env_error(char **cmd, int *exit_status, char *shell_name,
	int cmd_idx);

int _unsetenv(char *envname);

int change_dir(char **cmd);
char *cd_home(char *curr_dir, char *home_val);
char *cd_prev(char *curr_dir, char *old_pwd_val);
char *cd_to(char *path, char *curr_dir);
void free_cd_memory(char *curr_dir, char *old_pwd, char *home_env);

char *check_for_operator(char *cmd_line);

#endif
