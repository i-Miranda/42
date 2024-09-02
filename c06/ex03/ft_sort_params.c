#include <unistd.h>

void    ft_sort_params(int argc, char **argv)
{
    int     i;
    int     j;
    char    *temp;

    while (argc > 1)
    {
        i = 1;
        while (i < argc && argv[i + 1] != NULL)
        {
            j = 0;
            while (argv[i][j] != '\0')
            {
                if (argv[i][j] > argv[i + 1][j])
                {
                    temp = argv[i];
                    argv[i] = argv[i + 1];
                    argv[i + 1] = temp;
                    break;
                }
                else if (argv[i][j] < argv[i + 1][j])
                    break;
                else
                    j++;
            }
            i++;
        }
        argc--;
    }
}

int main(int argc, char *argv[])
{
    int     i;
    int     j;
    
    ft_sort_params(argc, argv);
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
