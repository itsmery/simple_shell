#include "main.h"

/**
 * main - our main shell function
 * Return: 0 on success
 */
int main(void)
{
	char *userInput, **args = NULL;
	size_t buf_size = 0, i;
	int exit_num = -1;

	while (666)
	{
		userInput = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (read_user_input(&userInput, &buf_size) == -1)
		{
			free(userInput);
			break;
		}
		if (userInput[0] == '\0')
		{
			free(userInput);
			continue;
		}
		if (check_spaces_tabs(userInput))
		{
			free(userInput);
			continue;
		}
		args = tokenize_input(userInput);
		if (!validate_command(args, userInput, exit_num))
		{
			free(userInput);
			continue;
		}
		exit_num = execute_forked_command(args, userInput);
		if (args != NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		free(userInput);
	}
	return (0);
}
