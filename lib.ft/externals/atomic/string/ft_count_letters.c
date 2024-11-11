#include <ctype.h>
#include <stdio.h>
unsigned int ft_count_letters(char*s)
{
    int i = 0;
    while(*s != '\0')
            (isalpha(*s++))?i++:0;
    return i;
}
int main(void)
{
    printf("\n%d\n",ft_count_letters("hello, wodjf_.ño<u!"));
    return (0);
}