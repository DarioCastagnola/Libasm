#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern char *ft_strdup(const char *s);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);

int main ()
{
    // testing Strlen
    printf("Testing Real strlen empty:\n");
    printf("strlen = %ld\n", strlen(""));
    printf("Testing LIBASM strlen empty:\n");
    printf("strlen = %ld\n", ft_strlen(""));
    printf("Testing Real strlen verylong:\n");
    printf("strlen = %ld\n", strlen("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm"));
    printf("Testing LIBASM strlen verylong:\n");
    printf("strlen = %ld\n", ft_strlen("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm"));
    //testing strcpy
    char buffer[1024];
    printf("Testing real strcpy empty:\n");
    printf("%s\n", strcpy(buffer, ""));
    printf("Testing LIBASM strcpy empty:\n");
    printf("%s\n", ft_strcpy(buffer,""));
    printf("Testing real strcpy very long:\n");
    printf("%s\n", strcpy(buffer, "qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm"));
    printf("Testing LIBASM strcpy very long:\n");
    printf("%s\n", ft_strcpy(buffer,"qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm"));
    // testing strcmp
    printf("ft_strcmp equal= %d\n", ft_strcmp("Ciao", "Ciao"));
    printf("strcmp equal= %d\n", strcmp("Ciao", "Ciao"));
    printf("ft_strcmp both empty= %d\n", ft_strcmp("", ""));
    printf("strcmp both empty= %d\n", strcmp("", ""));
    printf("ft_strcmp first empty= %d\n", ft_strcmp("", "Ciao"));
    printf("strcmp first empty= %d\n", strcmp("", "Ciao"));
    printf("ft_strcmp second empty= %d\n", ft_strcmp("Ciao", ""));
    printf("strcmp second empty= %d\n", strcmp("Ciao", ""));
    //testing write
    // int fd_write = 0;
    // fd_write = open("example.txt", o);
    printf("Testing stdout write:\n");
    write(1, "Suca\n", 5);
    printf("Testing stdout ft_write:\n");
    ft_write(1, "Suca\n", 5);
    //testing read
    int fd = 0;
    char bufferforread[1024];
    ssize_t n;
    fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }
    n = ft_read(fd, bufferforread, sizeof(bufferforread)-1);
    if (n < 0) {
        perror("ft_read failed");
        close(fd);
        return 1;
    }
    bufferforread[n] = '\0';  // null-terminate the string
    printf("File content:\n%s\n", bufferforread);
    close(fd);
    // testing strdup
    char *buffer1 = 0;
    char *buffer2 = 0;
    printf("Testing REAL strdup:\n");
    buffer1 = strdup("Cane");
    printf("%s\n", buffer1);
    buffer2 = ft_strdup("suca");
    printf("Testing LIBASM strdup:\n");
    printf("%s\n", buffer2);
    printf("Ciao\n");
    free(buffer1);
    free(buffer2);
    
}