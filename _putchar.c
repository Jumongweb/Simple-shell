#include "main.h"

int _putchar(char c)
{
        return (write(1, &c, 1));
}

int print_string(char *str)
{
        int i = 0, count = 0;
        while (str[i])
        {
                count += _putchar(str[i++]);
        }
        return (count);
}
