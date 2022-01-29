#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct items items;
struct items {
	char item[20];
	float price;
	int qty;
};
typedef struct orders orders;
struct orders {
	char table[100];
	char date[100];
	int numOfItems;
	items itm[100];
};
void order();
void reset_bill();
void report();
int	check_day();

void order(char table[20], int numOfItems, items itm[500])
{
	orders obj;

	time_t t;
	time(&t);
	strcpy(obj.date, ctime(&t));
    strcpy(obj.table, table);
    obj.numOfItems = 0;
    for (int i = 0; i < numOfItems; i++)
        if (itm[i].qty > 0)
        {
            strcpy(obj.itm[obj.numOfItems].item, itm[i].item);    
            obj.itm[obj.numOfItems].price = itm[i].price;
            obj.itm[obj.numOfItems].qty = itm[i].qty;            
			obj.numOfItems++;
        }
	FILE *printBill;
	printBill = fopen("dat/printBill.dat", "ab");
	fwrite(&obj, sizeof(orders), 1, printBill);
	fclose(printBill);
	FILE *saveBill;
	saveBill = fopen("dat/RestaurantBill.dat", "ab");
	fwrite(&obj, sizeof(orders), 1, saveBill);
	fclose(saveBill);
	g_print("%s\n", obj.date);
}
void reset_bill()
{
	FILE *del;
	del = fopen("dat/printBill.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, del);
	fclose(del);
}
void report(char startDay[25], char endDay[25], char startMonth[25], char endMonth[25]) 
{
	int invoiceFound = 0, numCus = 0;
	float grandTotal = 0;
	float income = 0;
	orders order;
	FILE *findBill = fopen("dat/RestaurantBill.dat", "rb");
	FILE *findBillCsv = fopen("RestaurantBill.csv", "w");
	fprintf(findBillCsv,"Time, Number, Name, Price\n");
	while(fread(&order, sizeof(orders), 1, findBill)){
		char cusTime[50];
    	char *month, *day;
		float total = 0;

		strcpy(cusTime, order.date);
    	month = strtok(cusTime, " ");
    	month = strtok( NULL, " ");
    	day = strtok( NULL, " ");
		g_print("%s,%s\n", month, day);
		g_print("%d,%d\n", check_day(day, month), check_day(startDay, startMonth));
		g_print("%d,%d\n", check_day(day, month), check_day(endDay, endMonth));
		if(check_day(day, month) >= check_day(startDay, startMonth) &&
			check_day(day, month) <= check_day(endDay, endMonth))
		{
			fprintf(findBillCsv,"%s", order.date);
			for(int i=0; i<order.numOfItems; i++){
				fprintf(findBillCsv,",%d,%s",order.itm[i].qty,order.itm[i].item);
				total += order.itm[i].qty * order.itm[i].price;
				fprintf(findBillCsv,",%.2f$\n", order.itm[i].qty * order.itm[i].price);
			}
			fprintf(findBillCsv,"Tax(4%),,,%.2f$\n", total * 0.04);
			fprintf(findBillCsv,"Total,,,%.2f$\n", total + total * 0.04);
           	numCus++;
			grandTotal += total;

		}
	}
    income += grandTotal + grandTotal * 0.04;
	fprintf(findBillCsv,"\nNumber of Customer : %d\n", numCus);
 	fprintf(findBillCsv,"\nTotal Income : %.2f$\n", income);
	if(!invoiceFound){
		printf("Sorry the invoice doesnot exists");
	} else {
		printf("\nNum of cus: %d\ngrand total: %.2f$", numCus, grandTotal + grandTotal / 25);
	}
	fclose(findBill);
	fclose(findBillCsv);
}
