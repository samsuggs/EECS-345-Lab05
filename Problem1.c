#include <stdio.h>
int main(){
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022:\nMonth\t\tSales\n");
    for(int i=0; i<12; i++){
        printf("%-10s%14.2f\n", months[i], sales[i]);
    };
    printf("Sales Summary:\n");
    for(int i=0; i<12; i++){
        
    };
    return 0;
}