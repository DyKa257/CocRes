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
	char table[20];
	char date[25];
	int numOfItems;
	items itm[500];
};
void order();
void printBill();
void billHistory();
void cusBill();

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
	printBill = fopen("printBill.dat", "ab");
	fwrite(&obj, sizeof(orders), 1, printBill);
	fclose(printBill);
	FILE *saveBill;
	saveBill = fopen("RestaurantBill.dat", "ab");
	fwrite(&obj, sizeof(orders), 1, saveBill);
	fclose(saveBill);
}
void reset_bill()
{
	FILE *del;
	del = fopen("printBill.dat", "wb");
	fwrite(NULL, sizeof(NULL), 1, del);
	fclose(del);
}
void printBill(char tbl[20])
{
	
}/*
void billHistory() {
	int i, numCus = 0;
	float grandTotal = 0;
	struct orders order;
	system("cls");
	FILE *billHis = fopen("RestaurantBill.dat", "rb");
	while(fread(&order, sizeof(struct orders), 1, billHis)){
		float total = 0;
		for(i=0; i<order.numOfItems; i++){
			total += order.itm[i].qty * order.itm[i].price;
		}
		generateBillFooter(total);
		numCus++;
		grandTotal += total;
	}
	fclose(billHis);
	printf("\nnum of cus: %d\ngrand total: %f", numCus, grandTotal + grandTotal / 25);
	getch();
	menu();
}
void cusBill() {
	int i, invoiceFound = 0, numCus;
	float grandTotal = 0;
	char month[20];
	struct orders order;
	printf("Enter the month (Jan): ");
	//get month
	fflush(stdin);
	gets(month);
	system("cls");
	FILE *findBill = fopen("RestaurantBill.dat", "rb");
	while(fread(&order, sizeof(struct orders), 1, findBill)){
		char mth[50];
    	char sep[] = " ,\t\n";
    	char *token;
		float total = 0;
		
		strcpy(mth, order.date);
    	token = strtok(mth, sep);
    	while( token != NULL )
    	{
        	// Get next token: 
        	token = strtok( NULL, sep);
        	// While there are tokens in "string"
        	break;
    	}
		if(!strcmp(token, month)){
			generateBillHeader(order.customer, order.date);
			for(i=0; i<order.numOfItems; i++){
				generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
				total += order.itm[i].qty * order.itm[i].price;
			}
			generateBillFooter(total);
			invoiceFound = 1;
			numCus++;
			grandTotal += total;
		}		
	}
	if(!invoiceFound){
		printf("Sorry the invoice doesnot exists");
	} else {
		printf("\nnum of cus: %d\ngrand total: %f", numCus, grandTotal + grandTotal / 25);
	}
	fclose(findBill);
	getch();
	menu();
}*/