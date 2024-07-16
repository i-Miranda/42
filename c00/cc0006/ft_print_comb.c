#include <unistd.h>

void	ft_print_comb2(void)
{
	int counter;

	char first_left;
	char second_left;
	char first_right;
	char second_right;
	char space;
	char comma;

	first_left = '0';
	second_left = '0';
	first_right = '0';
	second_right = '0';
	space = ' ';
	comma = ',';
	counter = 0;
	while(counter <= 9999)
	{
		write(1,&first_left,1);
		write(1,&first_right,1);
		write(1,&space,1);
		write(1,&second_left,1);
		write(1,&second_right,1);
		if(counter != 9999)
		{
			write(1,&comma,1);
			write(1,&space,1);
		}
		if(second_right == '9')
		{
			second_right = '0';
			if(second_left == '9')
			{
				second_left = '0';
				if(first_right == '9')
				{
					first_right = '0';
					if(first_left == '9')
						first_left = '0';
					else
						first_left++;
				}
				else
					first_right++;
			}
			else
				second_left++;
		}
		else
			second_right++;
		counter++;
	}
}
int main(void)
{
	ft_print_comb2();
	return (0);
}
