#include "main.h"
/**
 * validate_command - Checks if the command is a builtin or exists
 * @args: array of command arguments
 * @userInput: user input buffer
 * @exit_num: exit number
 *
 * Return: 1 if the command is valid, 0 otherwise
 */
int validate_command(char **args, char *userInput, int exit_num)
{
	if (handle_builtins(args, userInput, exit_num))
	{
		return (0);
	}
	if (!command_exists(args))
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free_args(args);
		return (0);
	}

	return (1);
}
