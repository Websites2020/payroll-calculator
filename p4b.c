/* ----------------------------------------------------------------------------------------------------------
 
 Program file: p4.c
 Author:       Daniel
 Course:       INFO.2110-062
 Date:         October 28, 2018
 Assignment:   #4
 Objective:    This program takes a company and calculates the payroll for each employee.
 
 ----------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /* Declare Variables */
    /*-------------------*/
    
    char companyName[30], c;
    int employees = 0, i = 1, id[i];
    float rate, hours, tax = .2, overTime[i], grossPay[i], overPay[i], fedTax[i], netPay[i], totalGross = 0, totalTax = 0, totalNet = 0;
    
    printf("\nWelcome to the Button Payroll Calculator\n");
    
    /* use gets to get user input */
    /*----------------------------*/
    
    printf("\nEnter the Company Name: ");
    scanf("%30[^\n]", companyName);
    while ( (c = getchar() != '\n') && c != EOF);
    
    /* While loop to make sure user selects a number between 1 and 50 */
    /*----------------------------------------------------------------*/
    
    while(employees <= 0 || employees > 50)
    {
        printf("\nEnter the number of employees(1-50): ");
        scanf("%i", &employees);
        while ( (c = getchar() != '\n') && c != EOF);
    }
    
    /* For loop that cycles through employees number */
    /*-----------------------------------------------*/
    
    for (i = 1; i <= employees; i++)
    {
        printf("\nEnter the Id Number for employee %i: ", i);
        scanf("%i", &id[i]);
        while ( (c = getchar() != '\n') && c != EOF);
        
        /* If/else statements to check that numbers are in proper range */
        /*--------------------------------------------------------------*/
        
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
                    } else
                    {
                        grossPay[i] = hours * rate;
                        fedTax[i] = grossPay[i] * tax;
                        netPay[i] = grossPay[i] - fedTax[i];
                    } // End else
                } // End if/else
            } // End if/else
        } // End if/else
    } // End for loop
    
    /* Print to screen results from user input */
    /*-----------------------------------------*/
    
    printf("\n %20s\n", "Payroll Report");
    printf(" %22s\n", companyName);
    
    for (i = 1; i <= employees; i++)
    {
        printf("\nEmployee %i\n", id[i]);
        printf("Gross Pay: $%14.2f\n", grossPay[i]);
        printf("Federal Tax: $%12.2f\n", fedTax[i]);
        printf("Net Pay: $%16.2f\n", netPay[i]);
        
        totalGross = totalGross + grossPay[i];
        totalTax = totalTax + fedTax[i];
        totalNet = totalNet + netPay[i];
    } // End for loop
    
    printf("\n %20s \n\n", "Reports Total");
    printf("Gross Pay: $%14.2f \n", totalGross);
    printf("Federal Tax: $%12.2f \n", totalTax);
    printf("Net Pay: $%16.2f \n\n", totalNet);
    
    return 0;
} // End program
