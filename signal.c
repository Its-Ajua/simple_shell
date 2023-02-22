#include "shell.h"

/**
 * sign_handler - Handles the signals
 * @signal_id: The identifier of the signal to handle
 *
 * Return: Nothing
 */
void sign_handler(int signal_id)
{
	if (signal_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
