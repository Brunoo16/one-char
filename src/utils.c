#include "utils.h"

void FlushStdin(void)
{
    int ch;
    while(((ch = getchar()) !='\n') && (ch != EOF));
}
