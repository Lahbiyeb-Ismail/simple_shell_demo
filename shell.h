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
char **tokenize_command(char *cmd);
size_t tokens_count(char *cmd_line, char *delim);
char **tokens_array(size_t count, char *cmd_line, char *delim, char *token);
int exec_command(char **cmd, char **argv, int cmd_idx);

char *_getenv(char *name);
char *_getpath(char *cmd);
char *check_command(char *cmd, struct stat st);

/***********************************/
void rev_string(char *str, int strlen);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

char *_itoa(int num);
int _atoi(char *s);

int check_if_builtin_cmd(char *cmd);
void handle_builtin_cmd(char **cmd, char **argv, int *exit_status, int cm_idx);
void exit_shell(char **cmd, char **argv, int *exit_status, int cmd_idx);


void print_env(char **cmd, int *exit_status);

int is_positive_num(char *str);

#endif
