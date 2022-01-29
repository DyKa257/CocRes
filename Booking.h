#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct Book Book;
struct Book 
{
	char name[100];
	char phone[11];
	char table[20];
}List_Table[20];

void booking(char name[100], char phone[11], char table[20])
{
	Book obj;
	strcpy(obj.name, name);
	strcpy(obj.phone, phone);
	strcpy(obj.table, table);
	
	FILE *booking;
	booking = fopen("dat/BookingTable.dat", "ab");
	fwrite(&obj, sizeof(Book), 1, booking);
	fclose(booking);
}

bool check_table(char phone[100], char table[20])
{
	Book obj;
	FILE *check = fopen("dat/BookingTable.dat", "rb");
	while(fread(&obj, sizeof(Book), 1, check)){
		g_print("%s, %s, %s, %s\n", obj.phone, phone, obj.table, table);
		if (!strcmp(obj.phone, phone) && !strcmp(obj.table, table))
			return 1;
	}
	return 0;
}

char *get_name(char table[20])
{
	char *tmp = malloc(100*sizeof(char));
	Book obj;
	FILE *check = fopen("dat/BookingTable.dat", "rb");
	while(fread(&obj, sizeof(Book), 1, check)){
		if (!strcmp(obj.table, table))
			_str(tmp, obj.name);
	}
	return tmp;
}

void reset_table()
{
	FILE *del;
	del = fopen("dat/BookingTable.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, del);
	fclose(del);
}