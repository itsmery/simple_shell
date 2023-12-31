#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/* MAIN FUNCTIONS*/
int command_exists(char **args);
int execute_command(char **args, char *userInput);
int handle_builtins(char **args, char *userInput, int exit_num);
char **tokenize_input(char *userInput);
int check_spaces_tabs(char *str);
ssize_t read_user_input(char **userInput, size_t *buf_size);
int execute_forked_command(char **args, char *userInput);
int validate_command(char **args, char *userInput, int exit_num);
void free_args(char **args);
void handle_sig(int sig);

/* STR HANDLERS */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_sprintf(char *str, char *delim, char *src);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif /* MAIN_H */
