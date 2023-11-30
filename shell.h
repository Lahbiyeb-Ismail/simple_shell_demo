#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_command(void);
char **tokenize_command(char *cmd);
void free_memory(char **argv);
int exec_command(char **cmd, char **argv, char **env);
void print_shell_prompt(void);

int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

#endif
