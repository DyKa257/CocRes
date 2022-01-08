#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//========= function prototype =========// 

int str_to_int(char *s);
void _str(char *str1, char *str2);

//========= function definition =========//

int str_to_int(char *s)
{
    int tmp = 0;
    for (int i; *s != '\0'; s++)
    {
        tmp *= 10;
        tmp += (*s - '0');
    }
    return tmp;
}
void _str(char *str1, char *str2)
{
    for (int i = 0; i <= strlen(str2); i++)
        *(str1+i) = *(str2+i);
}

#endif
