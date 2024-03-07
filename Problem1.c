#include <stdio.h>
#include <stdlib.h>
char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

float find_max(float arr[12]){
    float max = arr[0];
    for(int i=1; i<12; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
float find_min(float arr[12]){
    float min = arr[0];
    for(int i=1; i<12; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
float average(float arr[], int size){
    float avg = 0;
    for(int i=0; i<size; i++){
        avg += arr[i];
    }
    return avg/size;
}
int find_month(float sale, float sales[12]){
    for(int i=0; i<12; i++){
        if(sales[i] == sale){
            return i;
        }
    }
}
int main(){
    char filename[50];
    printf("Enter file name here: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    float sales[12];
    for(int i=0; i<12; i++){
        char str_sale[10], str_sale2[10];
        fgets(str_sale, 20, fp);
        sscanf(str_sale, "%s", str_sale2);
        sales[i] = atof(str_sale2);
    }
    printf("Monthly sales report for 2022:\nMonth\t\tSales\n");
    for(int i=0; i<12; i++){
        printf("%-10s\t$%0.2f\n", months[i], sales[i]);
    }
    printf("\nSales Summary:\n");
    printf("Minimum sales: $%0.2f (%s)\n", find_min(sales), months[find_month(find_min(sales), sales)]);
    printf("Maximum sales: $%0.2f (%s)\n", find_max(sales), months[find_month(find_max(sales), sales)]);
    printf("Average sales: $%0.2f\n", average(sales, 12));

    printf("\nSix-Month Moving Average Report:\n");
    for(int i=0; i<7; i++){
        float six_months[6] = {sales[i], sales[i+1], sales[i+2], sales[i+3], sales[i+4], sales[i+5]};
        printf("%-10s-  %-10s\t$%0.2f\n", months[i], months[i+5], average(six_months, 6));
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\t  Sales\n");
    float new_sales[12] = {sales[0], sales[1], sales[2], sales[3], sales[4], sales[5], sales[6], sales[7], sales[8], sales[9], sales[10], sales[11]};
    for(int i=0; i<12; i++){
        for(int j=i+1; j<12; j++){
            if (new_sales[i]<new_sales[j]){
                float temp = new_sales[i];
                new_sales[i] = new_sales[j];
                new_sales[j] = temp;
            }
        }
    }
    for(int i=0; i<12; i++){
        printf("%-10s%0.2f\n", months[find_month(new_sales[i], sales)], new_sales[i]);
    }
    return 0;
}