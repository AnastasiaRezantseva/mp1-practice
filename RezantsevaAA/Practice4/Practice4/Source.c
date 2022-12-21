#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char barcodes[10][5] = { "1001","1002","1003","1004","1005","1006","1007","1008","1009","1010" };
char products[10][16] = { "eggs","milk", "meat","tea","cheese","bread","pen","bottle of water", "crisps","honey" };
double prices[10] = { 30, 15, 200, 20, 60, 10, 5, 25, 40, 95 };
double discounts[10] = { 0.05, 0.15, 0.3, 0.25, 0.02, 0.02, 0.04, 0.1, 0.12, 0.25 };
int basket[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int findProductIndex(char* barcode)
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(barcodes[i], barcode) == 0)
        {
            return i;
        }
    }
    return -1;
}

void scanProducts() {
    char barcode[5];
    while (1) {
        printf("Scan barcode (P - print the check): ");
        scanf("%4s", barcode);
        if (strcmp(barcode, "P") == 0 || strcmp(barcode, "p") == 0) {
            break;
        }
        int productIndex = findProductIndex(barcode);
        if (productIndex == -1) {
            printf("Product with barcode %s not found\n", barcode);
            continue;
        }
        printf("Product: %s\n", products[productIndex]);
        basket[productIndex] = basket[productIndex] + 1;
    }
}

void printCheck() {
    double total = 0;
    double totalPrice = 0;
    double totalDiscount = 0;
    for (int productIndex = 0; productIndex < 10; productIndex++)
    {
        int numberOfProducts = basket[productIndex];
        if (numberOfProducts == 0) {
            continue;
        }
        double price = prices[productIndex];
        double discount = discounts[productIndex] * price;
        double priceWithDiscount = numberOfProducts * (price - discount);
        printf("Product: %s Price: %.2f Discount: %.2f Count: %i Result: %.2f\n", products[productIndex], price, discount, numberOfProducts, priceWithDiscount);

        totalPrice = totalPrice + numberOfProducts * price;
        totalDiscount = totalDiscount + numberOfProducts * discount;
        total = total + priceWithDiscount;
    }
    printf("Price: %.2f Discount: %.2f Total: %.2f\n", totalPrice, totalDiscount, total);
}

int main()
{
    printf("Hello\n");
    scanProducts();
    printCheck();
}
