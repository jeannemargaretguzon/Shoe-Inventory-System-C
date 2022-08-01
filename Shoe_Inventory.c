/* CASE STUDY_1 
The inventory of a shoe store lists shoes by stock number. 
With each stock number, there is associated a style number in the range of 0 to 50, 
	the number of pairs in each size (sizes range from 3 to 14) and a price. 
A program is to be written to keep track of the inventory. 
The user is given the following choices: enter a new record, display a record, 
	change the price of the stock item, or change the number on hand. 
When specifying a record the user may give either the stock number, or the style number. 
The array index can be used as a stock number. 
If the user decides to change the stock on hand, the program should ask which sizes will have their stock on hand changed. 
The program should be designed to run indefinitely, keeping track of changed in stock.

			MASAYA SHOE INVENTORY TR.ACKING
			Maligaya St., FarView Quezon City

- New Record
- Display Record
- Edit / Update
- Price
- Number on Hand (Stock Level / available qty)
	WHAT IS YOUR CHOICE?  ___________
	WANT TO TRY AGAIN? */

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

int NewRecord(int stockNo);
void DisplayRec();
int EditPrice();
int EditStock();
int stockNo = 1;

struct ShoeInv{
	int stock;
	float price;
	int style;
		struct ShoeStock	{
			int size; 
			int stockH;
		}SHOESTOCK[12];
}Records[50];

main(){
	char answer, Y, y, N, n;
	int a,i;
	
	do	{
		printf("\t\t\tMASAYA SHOE INVENTORY TRACKING\n\t\t\tMaligaya St., FarView Quezon City");

		printf("\n1. New Record\n2. Display Record\n3. Edit/Update\n\tPrice\n\tNumber on Hand (Stock Level / Available qty)");
		printf("\n\n\tWHAT IS YOUR CHOICE?\t");
		scanf("%d", &a);	
		switch(a)	{
			case 1:
				system("cls");
				stockNo = NewRecord(stockNo);
				break;
			case 2:
				system("cls");
				DisplayRec();
				break;
			case 3:
				system("cls");
				printf("Enter 1 for Price. Enter 2 for Number on Hand.\t");
				scanf("%d", &i);
				switch(i){
					case 1:
						EditPrice();
						break;
					case 2:
						EditStock();
				}
		}
			
		printf("\t\t\nWANT TO TRY AGAIN? Y/N\t");
		scanf("%s%*c", &answer);
		system("cls");
	}while((answer == 'y') || (answer == 'Y'));
}

int NewRecord(int stockNo){
	int x,y,z,a; 
	
	printf("Stock No. %d", stockNo);
	Records[stockNo].stock = stockNo;
	
	printf("\nStyle Number. (0-50) :  ");
	scanf("%d", &y);
	while(y > 51)	{	
		if (y == Records[stockNo].style){
		printf("Please try again.");
	}
		printf("\nStyle Number: (1-50) ");
		scanf("%d", &y);;
	}
	
	Records[stockNo].style = y;
	
	printf("Price:\t");
	scanf("%f", &Records[stockNo].price);
	printf("\n Size \t  Stock On Hand\n");
	        
	for (x = 3; x < 15; x++){
	    Records[stockNo].SHOESTOCK[x].size= x;
	    printf("   %d\t\t", Records[stockNo].SHOESTOCK[x].size);
	    scanf("%d", &Records[stockNo].SHOESTOCK[x].stockH); }
	    
	++stockNo;
	return stockNo;
}

void DisplayRec(){
	int x, y,z, a; 
	int stockNo = 0;

	system("cls");
	printf("Enter the stock number:\t");	
	scanf("%d", &stockNo);
 
	printf("Enter the style number:\t");	
	scanf("%d", &Records[stockNo].style);

	system("cls");
	printf("\nStock Number: %d", Records[stockNo].stock);
	printf("\nStyle Number: %d", Records[stockNo].style);
	printf("\nPrice: %f\n", Records[stockNo].price);
	printf("\n Size \t  Stock On Hand\n");
	for (x = 3; x < 15; x++){
		printf("\n   %d\t\t%d" ,Records[stockNo].SHOESTOCK[x].size ,Records[stockNo].SHOESTOCK[x].stockH);
	}			
}

EditPrice(){
	system("cls");
	
	int x, y,z; 
	float change;
	int stockNo = 0;
	
	printf("Enter the stock number:\t");	
	scanf("%d", &stockNo);
 
	printf("Enter the style number:\t");	
	scanf("%d", &Records[stockNo].style);

	system("cls");
	printf("\nStock Number: %d", Records[stockNo].stock);
	printf("\nStyle Number: %d", Records[stockNo].style);
	printf("\nPrice: %f\n", Records[stockNo].price);
	printf("\n Size \t  Stock On Hand\n");
	for (x = 3; x < 15; x++){
		printf("\n   %d\t\t%d" ,Records[stockNo].SHOESTOCK[x].size ,Records[stockNo].SHOESTOCK[x].stockH);
	}			
	
	printf("\nEnter the new price:\t");
	scanf("%f", &Records[stockNo].price);
}

EditStock(){
	system("cls");
	
	int x, y, z, a;
	int stockNo;
	
	printf("Enter the stock number:\t");	
	scanf("%d", &stockNo);
 
	printf("Enter the style number:\t");	
	scanf("%d", &Records[stockNo].style);

	system("cls");
	printf("\nStock Number: %d", Records[stockNo].stock);
	printf("\nStyle Number: %d", Records[stockNo].style);
	printf("\nPrice: %f\n", Records[stockNo].price);
	printf("\n Size \t  Stock On Hand\n");
	for (x = 3; x < 15; x++){
		printf("\n   %d\t\t%d" ,Records[stockNo].SHOESTOCK[x].size ,Records[stockNo].SHOESTOCK[x].stockH);
	}			
	
	printf("\nEnter the size of the product you want to edit:\t");
	scanf("%d", &x);
	
	printf("\nEnter the new stock:\t");
	scanf("%d", &Records[stockNo].SHOESTOCK[x].stockH);
}

