#include <unistd.h>

int ft_single_solution()
{
    int solved;
    int i;
    char    j;
    char    solution[10];

    solved = 0;
    while (i < 10)
    {
        j = '0';
        if (solution[i] == solution[i - 1])
        {
            j++:
            solution[i] = j;
        }
        i++;
    }
    if (solution == 525) //the sum of '0' thru '9'
    {
        write(1, solution, 10);
        write(1, "\n", 1);
        solved = 1;
    }
    return (solved);
}

int ft_ten_queens_puzzle(void)
{
    int total_solutions;

    total_solutions = 0;
    while (total_solutions < 724)
    {
        total_solutions += ft_single_solution();
    }
    return (total_solutions);
}

int main(void)
{
    ft_ten_queens_puzzle();
    return (0);
}
