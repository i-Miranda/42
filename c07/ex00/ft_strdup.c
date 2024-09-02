#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    char    *str;
    int i;

    str = malloc(ft_strlen(src) * sizeof(char));
    i = 0;
    while (src[i] != '\0')
    {
        str[i] = src[i];
        i++;
    }
    return (str);
}

int main(int argc, char *argv[])
{
    char    *str;
    int i;

    i = 0;
    while (argv[1][i] != '\0')
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    str = ft_strdup(argv[1]);
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
