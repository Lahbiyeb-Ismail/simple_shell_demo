#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_command(void);
char **tokenize_command(char *cmd, size_t *argc);
void free_memory(char *cmd, char **argv);

#endif
