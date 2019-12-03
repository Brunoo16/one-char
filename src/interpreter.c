#include "interpreter.h"

#define MAX_STACK_SIZE 40000

struct Script
{
    unsigned long file_size;
    char* buffer;
} script_file;

bool ReadFile(const char* file_name)
{
    FILE* file_pointer = fopen(file_name, "r");

    if(file_pointer != NULL)
    {
        fseek(file_pointer, 0, SEEK_END);
        script_file.file_size = ftell(file_pointer);
        fseek(file_pointer, 0, SEEK_SET);

        script_file.buffer = (char*)malloc(script_file.file_size + 1);
        memset(script_file.buffer, 0, script_file.file_size + 1);

        fread(script_file.buffer, 1, script_file.file_size, file_pointer);

        fclose(file_pointer);
        return true;
    }
    else
    {
        return false;
    }
}


void Interpret(void)
{
    static char stack[MAX_STACK_SIZE] = {0};
    const char* stack_end_addr = &stack[MAX_STACK_SIZE - 1];
    char* instruction_pointer = stack;
    int times_to_repeat = 0;
    unsigned long loop_start = 0;
    unsigned long loop_end = 0;

    for(unsigned long i = 0; i < script_file.file_size; ++i)
    {
        switch(script_file.buffer[i])
        {
            case 'a':
            {
                if((instruction_pointer + 1) <= stack_end_addr)
                {
                    instruction_pointer++;
                }
                break;
            }
            case 'b':
            {
                if((instruction_pointer - 1) >= stack)
                {
                    instruction_pointer--;
                }
                break;
            }
            case 'c':
            {
                (*instruction_pointer)++;
                break;
            }
            case 'd':
            {
                (*instruction_pointer)--;
                break;
            }
            case 'e':
            {
                putchar(*instruction_pointer);
                break;
            }
            case 'f':
            {
                FlushStdin();
                char input[60];
                scanf("%59[^\n]", input);
                const int length = strlen(input);

                for(int i = 0; i < length; ++i)
                {
                    if(((instruction_pointer + i + 1) <= stack_end_addr))
                    {
                        *(instruction_pointer + i) = input[i];
                    }
                }
                break;
            }
            case 'g':
            {
                char* end = strchr(script_file.buffer + i, 'h');

                if(end != NULL)
                {
                    times_to_repeat = *instruction_pointer;
                    loop_start = i;
                    loop_end = (end - script_file.buffer);
                }
                break;
            }
            case 'h':
            {
                if(i == loop_end)
                {
                    if((times_to_repeat - 1) > 0)
                    {
                        i = loop_start;
                        times_to_repeat--;
                    }
                }
                break;
            }
            case 'i':
            {
                if((instruction_pointer - 1) >= stack)
                {
                    *instruction_pointer += *(instruction_pointer - 1);
                }
                else
                {
                    *instruction_pointer += *instruction_pointer;
                }
                break;
            }
            case 'j':
            {
                if((instruction_pointer - 1) >= stack)
                {
                    *instruction_pointer -= *(instruction_pointer - 1);
                }
                else
                {
                    *instruction_pointer -= *instruction_pointer;
                }
                break;
            }
            case 'k':
            {
                if((instruction_pointer - 1) >= stack)
                {
                    *instruction_pointer *= *(instruction_pointer - 1);
                }
                else
                {
                    *instruction_pointer *= *instruction_pointer;
                }
                break;
            }
            case 'l':
            {
                printf("%i\n", *instruction_pointer);
                break;
            }
            case 'm':
            {
                if((instruction_pointer - 1) >= stack)
                {
                    const char previous_value = *instruction_pointer;

                    *instruction_pointer = *(instruction_pointer - 1);
                    *(instruction_pointer - 1) = previous_value;
                }
                break;
            }
            case 'n':
            {
                if((instruction_pointer + 1) <= stack_end_addr)
                {
                    const char previous_value = *instruction_pointer;

                    *instruction_pointer = *(instruction_pointer + 1);
                    *(instruction_pointer + 1) = previous_value;
                }
                break;
            }
            case 'o':
            {
                FlushStdin();
                char input[60];
                scanf("%59[^\n]", input);
                const int length = strlen(input);

                for(int i = 0; i < length; ++i)
                {
                    if(((instruction_pointer + i + 1) <= stack_end_addr))
                    {
                        *(instruction_pointer++) = input[i];
                        instruction_pointer--;
                    }
                }
                break;
            }
            case 'p':
            {
                FlushStdin();
                *instruction_pointer = getchar();
            }
        }
    }
}
