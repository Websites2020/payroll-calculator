//
//  p4.c
//  cAssignment4
//
//  Created by Daniel on 10/21/18.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char companyName[30], c;
    int employees = 0, i = 1, id[i];
    float rate, hours, tax = .2, overTime[i], grossPay[i], overPay[i], fedTax[i], netPay[i], totalGross = 0, totalTax = 0, totalNet = 0;
    
    printf("\nWelcome to the Button Payroll Calculator\n");
    
    printf("\nEnter the Company Name: ");
    scanf("%c", &companyName[30]);
    while ( (c = getchar() != '\n') && c != EOF);
    
    
    while(employees <= 0 || employees > 50)
    {
        printf("\nEnter the number of employees(1-50): ");
        scanf("%i", &employees);
        while ( (c = getchar() != '\n') && c != EOF);
    }
    
    for (i = 1; i <= employees; i++)
    {
        printf("\nEnter the Id Number for employee %i: ", i);
        scanf("%i", &id[i]);
        while ( (c = getchar() != '\n') && c != EOF);
        
        if (id[i] < 0)
        {
            while (id[i] < 0)
            {
                printf("employee Id must be above 0\n");
                printf("Enter the Id Number for employee %i ", i);
                scanf("%i", &id[i]);
                while ( (c = getchar() != '\n') && c != EOF);
            }
        } else
        {
            printf("Enter the number of hours employee %i worked: ", i);
            scanf("%f", &hours);
            while ( (c = getchar() != '\n') && c != EOF);
            
            if (hours < 0)
            {
                while (hours < 0)
                {
                    printf("hours must be 0 or greater\n");
                    printf("Enter the number of hours employee %i worked: ", i);
                    scanf("%f", &hours);
                    while ( (c = getchar() != '\n') && c != EOF);
                }
            } else
            {
                printf("Enter the hourly rate of employee %i: ", i);
                scanf("%f", &rate);
                while ( (c = getchar() != '\n') && c != EOF);
                
                if (rate < 0)
                {
                    while (rate < 0)
                    {
                        printf("rate must be 0 or greater\n");
                        printf("Enter the hourly rate of employee %i: ", i);
                        scanf("%f", &rate);
                        while ( (c = getchar() != '\n') && c != EOF);
                    }
                } else
                {
                    if (hours > 40)
                    {
                        overTime[i] = hours - 40;
                        overPay[i] = overTime[i] * (rate * 1.5);
                        grossPay[i] = 40 * rate + overPay[i];
                        
                        fedTax[i] = grossPay[i] * tax;
                        netPay[i] = grossPay[i] - fedTax[i];
                        printf("this\n");
                        
                    } else
                    {
                        grossPay[i] = hours * rate;
                        fedTax[i] = grossPay[i] * tax;
                        netPay[i] = grossPay[i] - fedTax[i];
                        printf("that\n");
                    }
                }
            }
        }
    } // end of for loop
    
    printf("\n %20s\n", "Payroll Report");
    
    for (i = 1; i <= employees; i++)
    {
        printf("\nEmployee %i\n", id[i]);
        printf("Gross Pay: $%14.2f\n", grossPay[i]);
        printf("Federal Tax: $%12.2f\n", fedTax[i]);
        printf("Net Pay: $%16.2f\n", netPay[i]);
        
        totalGross = totalGross + grossPay[i];
        totalTax = totalTax + fedTax[i];
        totalNet = totalNet + netPay[i];
    }
    
    printf("\n %20s \n\n", "Reports Total");
    printf("Gross Pay: $%14.2f \n", totalGross);
    printf("Federal Tax: $%12.2f \n", totalTax);
    printf("Net Pay: $%16.2f \n", totalNet);
    
    return 0;
}
