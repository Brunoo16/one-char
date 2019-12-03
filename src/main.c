#include "main.h"

int main(void)
{
    char file_name[60];
    printf("Enter the script file name below:\n");
    scanf("%59[^\n]", file_name);
    if(ReadFile(file_name))
    {
        Interpret();
        FlushStdin();
        getchar(); // Just to keep the console open. This works for now.
    }
    else
    {
        exit(1);
    }
    return 0;
}
