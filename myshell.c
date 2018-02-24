#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#define BUFFSIZE 1024
extern char **getline();
int get_size(char **in)
{
    int i = 0;
    while (in[i] != NULL)
        ++i;
    return i;
}
int main()
{
    char *home = "/usr/home";
    int i;
    char buffer[BUFFSIZE];
    char **input;
    char pwd[BUFFSIZE];
    while (1)
    {
        if (getcwd(pwd, sizeof(pwd)) != NULL)
            printf("myshell@freebsd:%s # ", pwd);
        else
            printf("error with getcwd()");

        input = getline();
        rl_bind_key('\t', rl_complete);
        printf("\n%s\n", input[1]);
        if (*input[0] == *("cd"))
        {
            int ret;
            char *dirr;
            if (input[1] != NULL)
            {
                if (input[1][0] != '/')
                {
                    dirr = strcat(strcat(pwd, "/"), input[1]);
                    ret = chdir(dirr);
                }
                else
                    ret = chdir(input[1]);
            }
            else
            {
                ret = chdir(home);
            }

            if (ret == -1)
            {
                perror("cd");
            }
        }
        for (int i = 0; input[i] != NULL; ++i)
        {
        }
    }
    return 0;
}
