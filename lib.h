#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//========= function prototype =========// 

int str_to_int(char *s);
void _str(char *str1, char *str2);
bool str_check(char *str1, char *str2);
bool str_check1(char *str1);
bool str_check2(char *str1);

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
bool str_check(char *str1, char *str2)
{
    for (int i = 0; i <= strlen(str2); i++)
        if (*(str1+i) != *(str2+i)) return 0;
    return 1;
}
bool str_check1(char *str1)
{
    if (strlen(str1) == 0) return 0;
    return 1;
}
bool str_check2(char *str1)
{
    if (strlen(str1) == 0) return 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        int val = (int)(*(str1+i));
        if (val < 48 || val >57) return 0;
    }
    return 1;
}

#endif
