head -n 1 *.c | awk '!(NR%3==0)' | awk 'NR%2==0' | sed 's/$/;/' |
sed '1s/^/#include <unistd.h>\n\n/' > libft.a
