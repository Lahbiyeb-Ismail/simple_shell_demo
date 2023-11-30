#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_command(void);
char **tokenize_command(char *cmd, size_t *argc);
void free_memory(char *cmd, char **argv);
int exec_command(char **argv);
void print_shell_prompt(void);

#endif
