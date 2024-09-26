#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

int lenstr(char *str);
void	teststr(char *func);
void catfunc(char *name);
void	funcresult(char *result, char *expected);
char *buildstr(int start, int end);
char charplusint(unsigned int index, char c);
void	strplusint(unsigned int index, char *str);

//!---TESTS---!//

void	test_ft_issomething(int(*ft)(int), int(*f)(int), char *func);
void	test_ft_strlen(size_t expected);
void	test_ft_memset(void *testptr, int c, size_t len);
void	test_ft_bzero(void *testptr, size_t len);
void	test_ft_memcpymove(void *(*mem)(void *, const void *, size_t), char * func, void *dst, const void *src, size_t n, char *expected);
void	test_ft_strlsomething(size_t (*f)(char *, const char *, size_t), char *func, char *str, const char *cstr, size_t sizetest, size_t expected);
void	test_ft_tosomething(int (*to)(int), char *func, char *test, char *expected);
void	test_ft_strchr(char *(*f)(const char *, int), char *func, char *str, int chr, char *position);
void	test_ft_strncmp(const char *s1, const char *s2, size_t n, int expected);
void	test_ft_memchr(const char *str, int c, size_t n, char *expected);
void	test_ft_memcmp(const void *s1, const void *s2, size_t n);
void	test_ft_strnstr(const char *haystack, const char *needle, size_t len, char *expected);
void	test_ft_atoi(char *ascii, int expected);
void	test_ft_calloc(size_t count, size_t size, char *expected);
void	test_ft_strdup(const char *str, char *expected);
void	test_ft_substr(char	const *s, unsigned int start, size_t len, char	*expected);
void	test_ft_strsomething(char *(*f)(char const *, char const *), char *func, char const *s1, char const *s2, char *expected);
void	test_ft_split(char const *s, char c, char **expected);
void	test_ft_itoa(int n, char *expected);
void	test_ft_strmapi(char const *s, char (*f)(unsigned int, char), char *expected);
void	test_ft_striteri(char *s, void (*f)(unsigned int, char *), char *expected);
void	test_ft_putchrptr_fd(void (*put)(char *, int), char *func, char *chrptr, int fd);
void	test_ft_putchar_fd(char c, int fd);
void	test_ft_putnbr_fd(int nbr, int fd);

//------TEST COMPILATION--------//

void	test_part_one(void);
void	test_part_two(void);
void	test_bonus(void);
