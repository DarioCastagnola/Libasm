#include <unistd.h>
#include <stdio.h>
#include <string.h>
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);

int main ()
{
    //testing write
    printf("Testing Real write:\n");
    write(1, "Suca\n", 5);
    printf("Testing LIBASM write:\n");
    ft_write(1, "Suca\n", 5);
    //testing Strlen
    printf("Testing Real strlen:\n");
    printf("strlen = %ld\n", strlen("Suca"));
    printf("Testing LIBASM strlen:\n");
    printf("strlen = %ld\n", ft_strlen("Suca"));
    //testing strcpy
    char buffer[10];
    printf("Testing real strcpy:\n");
    printf("%s\n", strcpy(buffer, "Cane"));
    printf("Testing LIBASM strcpy:\n");
    printf("%s\n", ft_strcpy(buffer,"Cane"));
}