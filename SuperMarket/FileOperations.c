//
//  FileOperations.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "FileOperations.h"
#include "Points.h"

#define N 500

CustomerData readCustomerFile(char output[], PriceData pr_data, MultiplierData mult_data[])
{
    CustomerData data;
    char *pch;
    static int i = 1;
    int j = 0;
    int day;
    char productName[16] = {0};
    int quantity = 0;
    
    i++;
    
    data.points = 0;
    
    
    day = (atoi(strtok(output, " ,;\r\n")));
    
    strcpy(data.customerID, strtok(NULL, " ,;\r\n"));
    
    pch = strtok(NULL, " ,;\r\n");
    
    while (pch != NULL) {
        
        
        strcpy(productName, pch);
        
        pch = strtok(NULL, " ,;\r\n");
        quantity = atoi(pch);
        data.points += calcPoints(productName, day, quantity, pr_data, mult_data);
        pch = strtok(NULL, " ,;\r\n");
        
    }
    
    j++;
    
    
    j = 0;
    
    

    
        // Find the latest line in data table
    
    

    
    return data;
}

void readCategoriesFile(char fileName[], MultiplierData data[])
{
    FILE *file = NULL;
    char output[N] = {0};
    char *check = NULL;
    char *pch;
    int i = 0;
    double mult;
    
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        do {
            
            
            pch = strtok(output, ":,\r\n");
            
            mult = (atof(strtok(NULL, ":,\r\n")));
            
            pch = strtok(NULL, ":,\r\n");
            
            while (pch != NULL) {
                data[i].multiplier = mult;
                strcpy(data[i++].product, pch);
                
                pch = strtok(NULL, ":,\r\n");
                
            }
            check = fgets(output, sizeof(output), file);
            
        } while (check != NULL);
    }
    
    fclose(file);
}

PriceData readPricesFile(char fileName[])
{
    PriceData data;
    FILE *file = NULL;
    char output[N] = {0};
    char *check = NULL;
    char *pch;
    int mon = 0, tue = 0, wed = 0, thu = 0, fri = 0, sat = 0, sun = 0;
    char productName[16];
    int price;
    
    file = fopen(fileName, "r");
    
    
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        do {
            
            
            pch = strtok(output, " \t\r\n");
            
            strcpy(productName, pch);
            
            price = atoi(strtok(NULL, " \t\r\n"));
            
            pch = strtok(NULL, " \t\r\n");
            
            while (pch != NULL) {
                if (pch != NULL && atoi(pch) == 1)
                {
                    data.Monday[mon].price = price;
                    strcpy(data.Monday[mon++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 2)
                {
                    data.Tuesday[tue].price = price;
                    strcpy(data.Tuesday[tue++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 3)
                {
                    data.Wednesday[wed].price = price;
                    strcpy(data.Wednesday[wed++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 4)
                {
                    data.Thursday[thu].price = price;
                    strcpy(data.Thursday[thu++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 5)
                {
                    data.Friday[fri].price = price;
                    strcpy(data.Friday[fri++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 6)
                {
                    data.Saturday[sat].price = price;
                    strcpy(data.Saturday[sat++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 7)
                {
                    data.Sunday[sun].price = price;
                    strcpy(data.Sunday[sun++].productName, productName);
                    pch = strtok(NULL, " \t\r\n");
                }


                
                if (pch != NULL && atoi(pch) != 1  && atoi(pch) != 2  && atoi(pch) != 3  && atoi(pch) != 4  && atoi(pch) != 5  && atoi(pch) != 6  && atoi(pch) != 7) {
                    pch = strtok(NULL, " \t\r\n");
                }
                
                
            }
            
            check = fgets(output, sizeof(output), file);
            
        } while (check != NULL);
        
    }
    
    fclose(file);
    
    return data;
}