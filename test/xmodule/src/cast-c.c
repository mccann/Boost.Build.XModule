#include "stdio.h"

extern char* message() ;

int main()
{
    printf("%s\n",message());
    return 0;
}
