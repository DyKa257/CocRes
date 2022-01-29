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
int check_day(char day[25], char month[25])
{
	int tmp = atoi(day);
	if (!strcmp(month, "Jan"))
	{
		tmp += 40*1;
	}
	if (!strcmp(month, "Feb"))
	{
		tmp += 40*2;
	}
	if (!strcmp(month, "Mar"))
	{
		tmp += 40*3;
	}
	if (!strcmp(month, "Apr"))
	{
		tmp += 40*4;
	}
	if (!strcmp(month, "May"))
	{
		tmp += 40*5;
	}
	if (!strcmp(month, "Jun"))
	{
		tmp += 40*6;
	}
	if (!strcmp(month, "Jul"))
	{
		tmp += 40*7;
	}
	if (!strcmp(month, "Aug"))
	{
		tmp += 40*8;
	}
	if (!strcmp(month, "Sep"))
	{
		tmp += 40*9;
	}
	if (!strcmp(month, "Oct"))
	{
		tmp += 40*10;
	}
	if (!strcmp(month, "Nov"))
	{
		tmp += 40*11;
	}
	if (!strcmp(month, "Dec"))
	{
		tmp += 40*12;
	}
	return tmp;
}

#endif
