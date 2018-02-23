#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#define BUFFSIZE 512
extern char **getline();

int main()
{
    int i;
    char buffer[BUFFSIZE];
    char **input;
    while (1)
    {
        input = getline();
        for (int i = 0; input[i] != NULL; ++i)
        {
            if (*input[0] == *"cd" )
            {
                printf("done");
            }
        }
    }
    return 0;
}
