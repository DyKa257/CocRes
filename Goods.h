#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct Goods Goods;
struct Goods 
{
    char date[100];
    char name[100];
    int num;
    char unit[100];
};
void import_goods();
int check_goods();
void export_goods();
void report2();

void import_goods(char name[20], int num, char unit[20])
{
    Goods obj;

    strcpy(obj.name, name);
    obj.num = num;
    strcpy(obj.unit, unit);

    g_print("%s,%d,%s\n", obj.name, obj.num, obj.unit);
	time_t t;
	time(&t);
    g_print("%s,%d,%s\n", obj.name, obj.num, obj.unit);
	strcpy(obj.date, ctime(&t));

    g_print("%s,%d,%s\n", obj.name, obj.num, obj.unit);
	FILE *goodsf;
	goodsf = fopen("dat/Goods.dat", "ab");
	fwrite(&obj, sizeof(Goods), 1, goodsf);
	fclose(goodsf);
	FILE *importf;
	importf = fopen("dat/Import.dat", "ab");
	fwrite(&obj, sizeof(Goods), 1, importf);
	fclose(importf);
} 
int check_goods(char name[20], int num, char unit[20])
{
    Goods obj;

    FILE *goodsf = fopen("dat/Goods.dat", "rb");
	while(fread(&obj, sizeof(Goods), 1, goodsf))
    {
        g_print("%s,%d,%s\n", obj.name, obj.num, name);
        if (!strcmp(name, obj.name)) num -= obj.num;
    }
    if (num <= 0) return 1; else return 0;
    fclose(goodsf);
}
void export_goods(char name[20], int num, char unit[20])
{
    Goods obj;

    if (num == 0) return;

    FILE *goodsf = fopen("dat/Goods.dat", "rb");
	while(fread(&obj, sizeof(Goods), 1, goodsf))
    {
		if(!strcmp(obj.name, name))
        {
            if (obj.num > num)
            {
                obj.num -= num;
                g_print("%s, %d, %d\n", name, num, obj.num);
                FILE *copyGoods = fopen("dat/copyGoods.dat", "ab");
                fwrite(&obj, sizeof(Goods), 1, copyGoods);
                fclose(copyGoods);
                Goods tmp = obj;
                tmp.num = num;
                FILE *export = fopen("dat/Export.dat", "ab");
                fwrite(&tmp, sizeof(Goods), 1, export);
                fclose(export);
                break;
            } else
            {
                FILE *export = fopen("dat/Export.dat", "ab");
                fwrite(&obj, sizeof(Goods), 1, export);
                fclose(export);
            }
		} else
        {
            FILE *copyGoods = fopen("dat/copyGoods.dat", "ab");
            fwrite(&obj, sizeof(Goods), 1, copyGoods);
            fclose(copyGoods);
        }
    }
	fclose(goodsf);
	FILE *fileDel = fopen("dat/Goods.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, fileDel);
	fclose(fileDel);
	// copy file
	FILE *readCopy = fopen("dat/copyGoods.dat", "rb");
	while(fread(&obj, sizeof(Goods), 1, readCopy)){
		FILE *copyGoods = fopen("dat/Goods.dat", "ab");
		fwrite(&obj, sizeof(Goods), 1, copyGoods);
		fclose(copyGoods);
	}
	fclose(readCopy);
	FILE *fileDel1 = fopen("dat/copyGoods.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, fileDel1);
	fclose(fileDel1);
}
void report2(char startDay[25], char endDay[25], char startMonth[25], char endMonth[25])
{
    Goods obj;

    FILE *findmana = fopen("dat/Import.dat", "rb");
	FILE *findmanacsv = fopen("Manage.csv", "w");
	fprintf(findmanacsv,"Import:\n");
    fprintf(findmanacsv,"Time, Name, Number, Unit\n");
    while(fread(&obj, sizeof(Goods), 1, findmana))
    {
		char cusTime[50];
    	char *month, *day;

		strcpy(cusTime, obj.date);
    	month = strtok(cusTime, " ");
    	month = strtok( NULL, " ");    	
        day = strtok( NULL, " ");

        g_print(",%s,%d,%s\n", obj.name, obj.num, obj.unit);
		if(check_day(day, month) >= check_day(startDay, startMonth) &&
			check_day(day, month) <= check_day(endDay, endMonth))
		{
			fprintf(findmanacsv,"%s", obj.date);
			fprintf(findmanacsv,",%s,%d,%s\n", obj.name, obj.num, obj.unit);
		}
	}
	fclose(findmana);
	fclose(findmanacsv);
    
    findmana = fopen("dat/Export.dat", "rb");
	findmanacsv = fopen("Manage.csv", "a");
	fprintf(findmanacsv,"Export:\n");
    fprintf(findmanacsv,"Time, Name, Number, Unit\n");
    while(fread(&obj, sizeof(Goods), 1, findmana))
    {
		char cusTime[50];
    	char *month, *day;

		strcpy(cusTime, obj.date);
    	month = strtok(cusTime, " ");
    	month = strtok( NULL, " ");    	
        day = strtok( NULL, " ");

        g_print(",%s,%d,%s\n", obj.name, obj.num, obj.unit);
		if(check_day(day, month) >= check_day(startDay, startMonth) &&
			check_day(day, month) <= check_day(endDay, endMonth))
		{
			fprintf(findmanacsv,"%s", obj.date);
			fprintf(findmanacsv,",%s,%d,%s\n", obj.name, obj.num, obj.unit);
		}
	}
	fclose(findmana);
	fclose(findmanacsv);
}