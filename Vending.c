#include <stdio.h>
#include <stdlib.h> // Include the stdlib library for the rand() function.

#define min 3
#define passcode 2048

void entrymenu();
void Items();
void Item_purchase();
void admin();

float total_amount;

// Initialize item prices and quantities
float AP, BP, CP; //cost of each item
int AQ, BQ, CQ; //quantity of each item

int main() {
    int b = -1; // Initialize b to an invalid value to enter the loop.
    total_amount = 0.0; // Initialize total_amount.
    AP = 2.75;
    BP = 3.0;
    CP = 4.5;
    AQ = 6;
    BQ = 4;
    CQ = 11;

    while (b != 0) {
        entrymenu();
        scanf("%d", &b); 
        switch (b) {
            case 1:
                Item_purchase();
                break;
            case 2:
                admin();
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Please enter a valid input.\n");
        }
    }
    return 0;
}

void entrymenu () {
    printf("Please enter your choice \n");
    printf("1. Purchase Item\n");
    printf("2. Enter Admin mode\n");
    printf("3. Exit\n");
}

void Items(){
    printf("1. Snickers | %.2f aed | %d items available \n" , AP , AQ );
    printf("2. water | %.2f aed | %d items available \n" , BP, BQ );
    printf("3. Gatorade | %.2f aed | %d items available \n" , CP , CQ);
    printf("0. Cancel purchase \n");
}


void Item_purchase (){
int x; //item choice
int y; //confirmation choice 
float IP; //item price
float CPay = 0.0; //customer payment
float coins; //coins inputed by user
float change;// amount user is due
int quantity; //number of items in stock

printf("Please choose an item of your liking\n");
Items ();
scanf("%d", &x);

  switch (x){
    case 0:
     return;
     break;

    case 1:
    printf("You have selected a snickers bar. Quantity: %d Price: %.2f \n", AQ , AP );
    printf("Please confirm your purchase (0/1)");
    scanf("%d", &y);
    IP = AP;
    quantity= AQ;
    if (y==0){
        return;
    }
    break;

    case 2:
    printf("You have selected a Water bottle. Quantity: %d Price: %.2f \n", BQ , BP );
    printf("Please confirm your purchase (0/1)");
    scanf("%d", &y);
    IP = BP;
    quantity= BQ;
    if (y==0){
        return;
    }
    break;
    
    case 3:
    printf("You have selected a gatorade bottle. Quantity: %d Price: %.2f \n", CQ , CP );
    printf("Please confirm your purchase (0/1)");
    scanf("%d", &y);
    IP = CP;
    quantity= CQ;
    if (y==0){
        return;
    }
    break;

    default:
        printf("Invalid input, try again. \n");
        return;
        break;
    }
        if (y==1){
          while(CPay< IP)
          {
            printf("Please insert a coin. (1.0, 0.5, 0.25) \n");
            scanf("%f", &coins);
            if(coins!= 0.25 && coins!= 0.5 && coins != 1.0){
                printf("Purchase has been cancelled due to invalid coin input. \n ");
                return;
            }
            else{
            CPay += coins; 
            }
          }
          change = CPay - IP;
          printf("You have purchased item number %d, you have paid a total of %.2f, your due change is %.2f. \n", x ,CPay, change );
          total_amount += IP;
          quantity -= 1;

              switch (x){
                case 1:
                AQ=quantity;
                break;
                case 2:
                BQ=quantity;
                break;
                case 3:
                CQ=quantity;
                break;
             }

          if (quantity == min){
            printf("The item's stock is equal to, or is less than the minimum stock, please refill this item. \n");
          }
        }


  }

 void admin(){
   int admincode;
   int z; //admin menu choice
   int a; //item repleshment choice

   printf("Please enter password to enter admin mode \n");
   scanf("%d" , &admincode);
   if(admincode == passcode){
    printf("Admin mode had been initiated \n");
   }
   else{
    printf("Incorrect password, please try again \n");
    return;
   }
 while(z!= 0){
    printf("1.replenish items \n");
    printf("2.Change item prices \n");
    printf("3.Display total sales \n");
    printf("4.Display item availability \n");
    printf("0.Exit Admin mode \n");
    scanf("%d" , &z );

    switch (z){

    case 1:
    printf("Choose an item to restock\n");
    printf("Item 1 has a stock of %d \n" , AQ);
    printf("Item 2 has a stock of %d \n" , BQ);
    printf("Item 3 has a stock of %d \n" , CQ);
    scanf("%d" , &a);
    switch(a){
        case 1:
        AQ = rand()% 20 + 1 + AQ ;
        break;
        case 2:
        BQ = rand()% 20 + 1 + BQ ;
        break;   
        case 3:
        CQ = rand()%20 + 1 + CQ ;
        break;
        default:
        printf("Chose a valid item ");
    }
    break;

    case 2:
    printf("Choose an item to change the price of \n");
    printf("Item 1 has a price of %.2f" , AP);
    printf("Item 2 has a price of %.2f" , BP);
    printf("Item 3 has a price of %.2f" , CP);
    scanf("%d" , &a);
    switch(a){
        case 1:
        printf("Enter new price for Item A\n");
        scanf("%f", &AP);
        break;
        case 2:
        printf("Enter new price for Item B\n");
        scanf("%f", &BP);
        break;   
        case 3:
        printf("Enter new price for Item C\n");
        scanf("%f", &CP);
        break;
        default:
        printf("Chose a valid item \n");
    }
    break;

    case 3:
    printf("Total Sale Amount: $%.2f\n", total_amount);
    printf("Would you likd to reset the total amount of sales (0/1)\n ");
    scanf("%d" , &a);
    if (a==1){
    total_amount = 0.0;
    printf("The amount has been reset, please collect the money before leaving.\n ");
    break;
    }
    case 4:
    printf("1. Snickers | %.2f aed | %d items available \n" , AP , AQ );
    printf("2. water | %.2f aed | %d items available \n" , BP, BQ );
    printf("3. Gatorade | %.2f aed | %d items available \n\n" , CP , CQ);
    break;
    default:
    printf("Please choose  a vaild option.\n ");
    
 }
 }
 }

