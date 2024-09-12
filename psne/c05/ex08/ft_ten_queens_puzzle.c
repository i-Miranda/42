#include <unistd.h>

void ft_print_solved(char *solution)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while (solution[i] != '\0')
    {
        sum += solution[i];
        i++;
    }
    if (sum == 525)
    {
        write(1, solution, 10);
        write(1, "\n", 1);
    }
}

int ft_single_solution(char *solution)
{
    int solved;
    int i;
    int j;

    solved = 0;
    i = 0;
    while (i < 10)
    {
        j = i;
        while (j <= 0)
        {
            solution[i] = '0';
            if (i != 0)
            {
                if ((solution[i] == solution[i - j])
                || (solution[i] == solution[i - j] - j)
                || (solution[i] == solution[i - j] + j))
                    solution[i]++;
            }
            j--;
        }
        i++;
    }
    return (solved);
}

int ft_ten_queens_puzzle(void)
{
    int total_solutions;
    char    solution[10];

    total_solutions = 0;
    while (total_solutions < 724)
    {
        if (ft_single_solution(solution) == 1)
        {
            total_solutions ++;
            ft_print_solved(solution);
        }
    }
    return (total_solutions);
}

int main(void)
{
    ft_ten_queens_puzzle();
    return (0);
}
