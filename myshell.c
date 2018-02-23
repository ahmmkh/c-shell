#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#define BUFFSIZE 1024
extern char **getline();

int main()
{
    int i;
    char buffer[BUFFSIZE];
    char **input;
    char pwd[BUFFSIZE];
    while (1)
    {
        if (getcwd(pwd, sizeof(pwd)) != NULL)
        {
            printf("myshell@freebsd:%s", pwd);
        }
        else
        {
            printf("error with getcwd");
        }
        input = getline();
        for (int i = 0; input[i] != NULL; ++i)
        {
            if (*input[0] == *("cd"))
            {
                printf("done");
            }
        }
    }
    return 0;
}
