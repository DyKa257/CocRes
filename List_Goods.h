#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define fin_1 "list_goods.txt"

//========= class List_Goods =========//

typedef struct List_Goods List_Goods;
struct List_Goods
{
    char *name;
    int num;
    char *unit;
    List_Goods *next;
    void (*add)(List_Goods *obj, char *name, int num, char *unit);
    void (*delete)(List_Goods *father, List_Goods *obj);
    void (*addalr)(List_Goods *obj, char *name, int num);
    void (*inp)(List_Goods *obj);
    void (*out)(List_Goods *obj);
    void (*destroy)(List_Goods *obj);
};
List_Goods *List_Goods_Init();
List_Goods *Goods_Init(char *name, int num, char *unit);
void Add_Goods(List_Goods *obj, char *name, int num, char *unit);
void Delete_Goods(List_Goods *father, List_Goods *obj);
void Addalr_Goods(List_Goods *obj, char *name, int num);
void Inp_Goods(List_Goods *obj);
void Out_Goods(List_Goods *obj);
void Destroy_Goods(List_Goods *obj);

//========= function definition =========//

List_Goods *List_Goods_Init()
{
    List_Goods* obj = (List_Goods*) malloc(sizeof(List_Goods));
    obj->next = NULL;
    obj->name = (char*)malloc(sizeof(char));
    obj->unit = (char*)malloc(sizeof(char));
    obj->name = "";
    obj->num = 0;
    obj->unit = "";
    obj->add = &Add_Goods;
    obj->delete = &Delete_Goods;
    obj->addalr = &Addalr_Goods;
    obj->inp = &Inp_Goods;
    obj->out = &Out_Goods;
    obj->destroy = &Destroy_Goods;
    return (List_Goods*) obj;
}
List_Goods *Goods_Init(char *name, int num, char *unit)
{
    List_Goods* obj = (List_Goods*) malloc(sizeof(List_Goods));
    obj->next = NULL;
    obj->name = malloc(strlen(name) * sizeof(char));
    obj->unit = malloc(strlen(unit) * sizeof(char));
    _str(obj->name, name);
    obj->num = num;
    _str(obj->unit, unit);
    obj->add = &Add_Goods;
    obj->delete = &Delete_Goods;
    obj->addalr = &Addalr_Goods;
    obj->inp = &Inp_Goods;
    obj->out = &Out_Goods;
    obj->destroy = &Destroy_Goods;
    return (List_Goods*) obj;
}
void Add_Goods(List_Goods *obj, char *name, int num, char *unit)
{
    List_Goods *list_goods = Goods_Init(name, num, unit);
    List_Goods *tmp = obj;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = list_goods;
}
void Delete_Goods(List_Goods *father, List_Goods *obj)
{
    father->next = obj->next;
    free(obj);
}
void Addalr_Goods(List_Goods *obj, char *name, int num)
{
    List_Goods *list_goods = obj;
    for(; list_goods != NULL; list_goods = list_goods->next)
    {
        if (list_goods->name == name) list_goods->num += num;
        return;
    }
}
void Inp_Goods(List_Goods *obj)
{
    FILE *inp = fopen(fin_1, "r");
    char tmp[50];
    char tmp1[50];
    while (!feof(inp))
    {
        fscanf(inp, "%s", &tmp);
        for (int i = 0; i < strlen(tmp); i++)
            tmp1[i] = tmp[i];
        char *name = malloc(sizeof(char));
        name = strtok(tmp1, ",");
        char *num_char = malloc(sizeof(char));
        num_char = strtok(NULL, ",");
        int num = str_to_int(num_char);
        char *unit = malloc(sizeof(char));
        unit = strtok(NULL, ",");
        obj->add(obj, name, num, unit);
    }
    fclose(inp);
}
void Out_Goods(List_Goods *obj)
{
    FILE *out = fopen(fin_1, "w");
    List_Goods *list_goods = obj->next;
    for(; list_goods->next != NULL; list_goods = list_goods->next)
    {
        fprintf(out, "%s,", list_goods->name);
        fprintf(out, "%d,", list_goods->num);
        fprintf(out, "%s,\n", list_goods->unit);
    }
    fprintf(out, "%s,", list_goods->name);
    fprintf(out, "%d,", list_goods->num);
    fprintf(out, "%s,", list_goods->unit);
    fclose(out);
}
void Destroy_Goods(List_Goods *obj)
{    
    List_Goods *tmp = obj->next;
    while(1)
    {        
        free(obj->name);
        free(obj->unit);
        free(obj);
        obj = tmp;
        if (tmp == NULL) return;
        tmp = obj->next;
    }
}
