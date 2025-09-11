#include <unistd.h>
#include <stdio.h>
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern size_t ft_strlen(const char *s);
extern char *strcpy(char *dest, const char *src);

int main ()
{
    ft_write(1, "Suca\n", 5);
    printf("strlen = %ld\n", ft_strlen("Suca"));
}