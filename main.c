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

int main ()
{
    //testing read
    // int fd = 0;
    // char bufferforread[1024];
    // ssize_t n;
    // fd = open("example.txt", O_RDONLY);
    // if (fd < 0) {
    //     perror("open failed");
    //     return 1;
    // }
    // n = ft_read(fd, bufferforread, sizeof(bufferforread)-1);
    // if (n < 0) {
    //     perror("ft_read failed");
    //     close(fd);
    //     return 1;
    // }
    // bufferforread[n] = '\0';  // null-terminate the string
    // printf("File content:\n%s\n", bufferforread);
    // close(fd);
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
    // testing strdup
    char *buffer1;
    char *buffer2;
    printf("Testing REAL strdup:\n");
    buffer1 = strdup("Cane");
    printf("%s\n", buffer1);
    free(buffer1);
    buffer2 = ft_strdup("Cane");
    printf("Testing LIBASM strdup:\n");
    printf("%s\n", buffer2);
    free(buffer2);
    
}