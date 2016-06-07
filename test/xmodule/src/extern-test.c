#include <stdio.h>

extern int foo_func() ;

int main()
{
    printf(" Foo-func: %d\n ", foo_func() );
    return 0;
}
