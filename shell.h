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

void print_shell_prompt(void);
void print_shell_error(char *shell_name, char *cmd, int cmd_idx);
void free_memory(char **argv);

char *read_command(void);
char **tokenize_command(char *cmd);
int exec_command(char **cmd, char **argv, int cmd_idx);

char *_getenv(char *name);
char *_getpath(char *cmd);

/***********************************/
void rev_string(char *str, int strlen);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

char *_itoa(int num);

int check_if_builtin_cmd(char *cmd);
void handle_builtin_cmd(char **cmd, int exit_status);
void exit_shell(char **cmd, int exit_status);


#endif
