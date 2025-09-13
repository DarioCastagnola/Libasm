#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>


extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern char *ft_strdup(const char *s);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);

int main ()
{
    //testing Strlen
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
    int fd_write = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_write < 0) {
        perror("open");
        return 1;
    }
    printf("Testing valid file descriptor\n");
    errno = 0;
    ssize_t ret2 = ft_write(fd_write, "Hello file\n", 11);
    printf("ft_write returned: %zd (errno: %d - %s)\n", ret2, errno, strerror(errno));
    close(fd_write);
    printf("Testing invalid fd\n");
    errno = 0;
    ssize_t ret3 = ft_write(-1, "Hello invalid\n", 14);
    printf("ft_write returned: %zd (errno: %d - %s)\n", ret3, errno, strerror(errno));
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
    bufferforread[n] = '\0';
    printf("File content:\n%s\n", bufferforread);
    close(fd);
    errno = 0;
    printf("Testing ft_read with invalid fd");
    ssize_t ret4 = ft_read(-1, bufferforread, sizeof(bufferforread) -1);
    printf("ft_read returned: %zd (errno: %d - %s)\n", ret4, errno, strerror(errno));
    printf("Testing ft_read from stdin\n");
    printf("Type something and press Enter:\n> ");
    errno = 0;
    n = ft_read(0, bufferforread, sizeof(bufferforread)-1); // fd=0 is stdin
    if (n < 0) {
        perror("ft_read failed");
        return 1;
    }
    bufferforread[n] = '\0';
    printf("You typed (%zd bytes): %s", n, bufferforread);
    printf("errno: %d - %s\n", errno, strerror(errno));
    // // testing strdup
    char *buffer1 = 0;
    char *buffer2 = 0;
    char *buffer3 = 0;
    char *buffer4 = 0;
    printf("Testing empty strdup:\n");
    buffer1 = strdup("");
    printf("%s\n", buffer1);
    buffer2 = ft_strdup("");
    printf("Testing empty ft_strdup:\n");
    printf("%s\n", buffer2);
    printf("Testing verylong strdup:\n");
    buffer3 = strdup("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm");
    printf("%s\n", buffer3);
    buffer4 = ft_strdup("qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm");
    printf("Testing verylong ft_strdup:\n");
    printf("%s\n", buffer4);
    free(buffer1);
    free(buffer2);
    free(buffer3);
    free(buffer4);
}