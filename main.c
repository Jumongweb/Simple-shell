#include "main.h"

int main(int c, char **env)
{
        (void)c;
        char *prompt = "#cisfun$ ";
        char *buffer = NULL;
        char *arg[10], *delim = " \n";
        size_t buff_size = 0;
        ssize_t n_chars;
        pid_t child_ID;
        int status, i, j;

        while (1)
        {
        if (isatty(0))
                print_string(prompt);

        n_chars = getline(&buffer, &buff_size, stdin);

        if (n_chars == -1)
        {
                free(buffer);
                exit(0);
        }

        i = 0;
        while (buffer[i])
        {
                if (buffer[i] == '\n')
                        buffer[i] = 0;
                        i++;
        }

        j = 0;
        arg[j] = strtok(buffer, delim);

        while (arg[j])
        {
                arg[++j] = strtok(NULL, delim);
        }

        child_ID = fork();
        if (child_ID < 0)
        {
                print_string("Forking failed");
                free(buffer);
                exit(0);
        }
        else if (child_ID == 0)
        {
                if (execve(arg[0], arg, env) == -1)
                print_string("Command does not exit\n");
        }
        else
                wait(&status);
        }

        free(buffer);
        return (0);

}
