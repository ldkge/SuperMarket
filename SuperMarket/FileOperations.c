//
//  FileOperations.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//
/* Posa sou vale?
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "FileOperations.h"
#include "Points.h"

#define N 1000
#define M 15

CustomerData readCustomerFile(char output[], PriceData pr_data, MultiplierData mult_data[], int mult_max)
{
    CustomerData data = {0};
    char *pch;
    int day;
    int productName;
    int quantity = 0;
    
    
    day = (atoi(strtok(output, " ,;\r\n")));
    
    strcpy(data.customerID, strtok(NULL, " ,;\r\n"));
    
    pch = strtok(NULL, " ,;\r\n");
    
    while (pch != NULL) {
        
        
        productName = atoi(&pch[1]);
        
        pch = strtok(NULL, " ,;\r\n");
        quantity = atoi(pch);
        data.points += calcPoints(productName, day, quantity, pr_data, mult_data, mult_max);
        pch = strtok(NULL, " ,;\r\n");
        
    }
    
    
    

    
    return data;
}

int readCategoriesFile(MultiplierData data[])
{
    FILE *file = NULL;
    char output[N] = {0};
    char fileName[M];
    char *check = NULL;
    char *pch;
    int i = 0;
    double mult;
    
    do {
        printf("Enter the name of the second file: ");
        scanf("%s", fileName);
        
        file = fopen(fileName, "r");
    } while (file == NULL);
    
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        do {
            
            
            pch = strtok(output, "P:,\r\n");
            
            mult = (atof(strtok(NULL, "P:,\r\n")));
            
            pch = strtok(NULL, "P:,\r\n");
            
            while (pch != NULL) {
                data[i].multiplier = mult;
                data[i++].product = atoi(pch);
                
                pch = strtok(NULL, "P:,\r\n");
                
            }
            check = fgets(output, sizeof(output), file);
            
        } while (check != NULL);
    }
    
    fclose(file);
    
    return i;
}

PriceData readPricesFile()
{
    PriceData data = {0};
    FILE *file = NULL;
    char output[N] = {0};
    char *check = NULL;
    char fileName[M];
    int brk = 0;
    int i;
    char *pch;
    int mon = 0, tue = 0, wed = 0, thu = 0, fri = 0, sat = 0, sun = 0;
    int productName;
    int price;
    
    do {
        printf("Enter the name of the third file: ");
        scanf("%s", fileName);
        
        file = fopen(fileName, "r");
    } while (file == NULL);
    
    
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        do {
            pch = strtok(output, "P \t\r\n");
            
            productName = atoi(pch);
            
            price = atoi(strtok(NULL, "P \t\r\n"));
            
            for (i = 0; productName != data.maxPrices[i].productName; i++) {
                if (data.maxPrices[i].price == 0) {
                    brk = 1;
                    break;
                }
            }
            
            if (brk == 1) {
                data.maxPrices[data.max_size].price = price;
                data.maxPrices[data.max_size++].productName = productName;
                brk = 0;
            }
            else if (brk == 0 && data.maxPrices[i].price < price) {
                data.maxPrices[i].price = price;
            }
            
            pch = strtok(NULL, "P \t\r\n");
            
            while (pch != NULL) {
                if (pch != NULL && atoi(pch) == 1)
                {
                    data.Monday[mon].price = price;
                    data.Monday[mon++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 2)
                {
                    data.Tuesday[tue].price = price;
                    data.Tuesday[tue++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 3)
                {
                    data.Wednesday[wed].price = price;
                    data.Wednesday[wed++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 4)
                {
                    data.Thursday[thu].price = price;
                    data.Thursday[thu++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 5)
                {
                    data.Friday[fri].price = price;
                    data.Friday[fri++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 6)
                {
                    data.Saturday[sat].price = price;
                    data.Saturday[sat++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                if (pch != NULL && atoi(pch) == 7)
                {
                    data.Sunday[sun].price = price;
                    data.Sunday[sun++].productName = productName;
                    pch = strtok(NULL, "P \t\r\n");
                }


                
                if (pch != NULL && atoi(pch) != 1  && atoi(pch) != 2  && atoi(pch) != 3  && atoi(pch) != 4  && atoi(pch) != 5  && atoi(pch) != 6  && atoi(pch) != 7) {
                    pch = strtok(NULL, "P \t\r\n");
                }
                
                
            }
            
            check = fgets(output, sizeof(output), file);
            
        } while (check != NULL);
        
    }
    
    fclose(file);
    
    return data;
}

void readTeamPointsFile(TeamPointsData data[])
{
    FILE *file;
    char *check = NULL;
    char *pch;
    char output[N] = {0};
    char fileName[M];
    int i;
    
    do {
        printf("Enter the name of the fifth file: ");
        scanf("%s", fileName);
        
        file = fopen(fileName, "r");
    } while (file == NULL);
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        for (i = 0; check != NULL; i++) {
            pch = strtok(output, "G \t\r\n");
            
            data[i].prize = atoi(pch);
            
            pch = strtok(NULL, "G \t\r\n");
            data[i].points = atoi(pch);
            
            check = fgets(output, sizeof(output), file);
        }
    }
}
