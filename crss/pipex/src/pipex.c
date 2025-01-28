#include "pipex.h"

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	int fd_infile;
	int	fd_outfile;

	fd_infile = open((const char *)infile, O_RDONLY | O_CREAT);
	fd_outfile = open((const char *)outfile, O_RDWR | O_CREAT);
}
