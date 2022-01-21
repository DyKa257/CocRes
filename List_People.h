#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"
#define fin_3 "list_people.txt"

//========= class List_People =========// 

typedef struct List_People List_People;
struct List_People
{
    char *ID;
    char *user;
    char *pass;
    List_People *next;
    void (*add)(List_People *obj, char *ID, char *user, char *pass);
    void (*delete)(List_People *father, List_People *obj);
    int (*check)(List_People *obj, char *user, char *pass);
    void (*inp)(List_People *obj);
    void (*out)(List_People *obj);
    void (*destroy)(List_People *obj);
};
List_People *List_People_Init();
List_People *People_Init(char *ID, char *user, char *pass);
void Add_People(List_People *obj, char *ID, char *user, char *pass);
void Delete_People(List_People *father, List_People *obj);
int Check_People(List_People *obj, char *user, char *pass);
void Inp_People(List_People *obj);
void Out_People(List_People *obj);
void Destroy_People(List_People *obj);

//========= function prototype =========// 

int str_to_int(char *s);
void _str(char *str1, char *str2);

//========= function definition =========//

List_People *List_People_Init()
{
    List_People* obj = (List_People*) malloc(sizeof(List_People));
    obj->next = NULL;
    obj->ID = malloc(sizeof(char));
    obj->user = malloc(sizeof(char));
    obj->pass = malloc(sizeof(char));
    obj->ID = "";
    obj->user = "";
    obj->pass = "";
    obj->add = &Add_People;
    obj->delete = &Delete_People;
    obj->check = &Check_People;
    obj->inp = &Inp_People;
    obj->out = &Out_People;
    obj->destroy = &Destroy_People;
    return (List_People*) obj;
}
List_People *People_Init(char *ID, char *user, char *pass)
{
    List_People* obj = (List_People*) malloc(sizeof(List_People));
    obj->next = NULL;
    obj->ID = malloc(strlen(ID) * sizeof(char));
    obj->user = malloc(strlen(user) * sizeof(char));
    obj->pass = malloc(strlen(pass) * sizeof(char));
    _str(obj->ID, ID);
    _str(obj->user, user);
    _str(obj->pass, pass);
    obj->add = &Add_People;
    obj->delete = &Delete_People;
    obj->check = &Check_People;
    obj->inp = &Inp_People;
    obj->out = &Out_People;
    obj->destroy = &Destroy_People;
    return (List_People*) obj;
}
void Add_People(List_People *obj, char *ID, char *user, char *pass)
{
    List_People *list_people = People_Init(ID, user, pass);
    List_People *tmp = obj;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = list_people;
}
void Delete_People(List_People *father, List_People *obj)
{
    father->next = obj->next;
    free(obj);
}
int Check_People(List_People *obj, char *user, char *pass)
{
    List_People *list_people = obj->next;
    for(; list_people->next != NULL; list_people = list_people->next)
    {
        if (str_check(list_people->user, user) && str_check(list_people->pass, pass)) \
            return (list_people->ID[0] - '0');
    }
    return 0;
}
void Inp_People(List_People *obj)
{
    FILE *inp = fopen(fin_3, "r");
    char tmp[500];
    char tmp1[500];
    while (!feof(inp))
    {
        fscanf(inp, "%s", &tmp);
        for (int i = 0; i <= strlen(tmp); i++)
            tmp1[i] = tmp[i];
        char *ID = strtok(tmp1, ",");
        char *user = strtok(NULL, ",");
        char *pass = strtok(NULL, ",");
        obj->add(obj, ID, user, pass);
    }
    fclose(inp);
}
void Out_People(List_People *obj)
{
    FILE *out = fopen(fin_3, "w");
    List_People *list_people = obj->next;
    for(; list_people->next != NULL; list_people = list_people->next)
    {
        fprintf(out, "%s,", list_people->ID);
        fprintf(out, "%d,", list_people->user);
        fprintf(out, "%s,\n", list_people->pass);
    }
    fprintf(out, "%s,", list_people->ID);
    fprintf(out, "%d,", list_people->user);
    fprintf(out, "%s,", list_people->pass);
    fclose(out);
}
void Destroy_People(List_People *obj)
{    
    List_People *tmp = obj->next;
    while(1)
    {        
        free(obj->ID);
        free(obj->pass);
        free(obj);
        obj = tmp;
        if (tmp == NULL) return;
        tmp = obj->next;
    }
}