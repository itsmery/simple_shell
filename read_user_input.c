#include "main.h"
/**
 * read_user_input - Reads user input
 * @userInput: buffer to hold user input
 * @buf_size: size of the buffer
 *
 * Return: number of characters read on success, -1 on failure
 */
ssize_t read_user_input(char **userInput, size_t *buf_size)
{
	ssize_t readNO;

	readNO = getline(userInput, buf_size, stdin);
	if (readNO == -1)
	{
		if (!isatty(STDIN_FILENO))
			return (-1);
		free(userInput);
		perror("getline()");
		exit(EXIT_FAILURE);
	}
	if ((*userInput)[readNO - 1] == '\n')
		(*userInput)[readNO - 1] = '\0';

	return (readNO);
}
