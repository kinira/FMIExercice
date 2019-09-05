#include <unistd.h>
#include <string.h>
int main(void)
{
char* buff = "Hello, world!\n";
int p;
if (fork() == 0) write(1, buff, strlen(buff));
p = fork();
write(1, buff, strlen(buff));
}