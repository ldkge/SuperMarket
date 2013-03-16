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

#define N 100

CustomerData readCustomerFile(char fileName[])
{
    CustomerData data;
    FILE *file = NULL;
    char *check = NULL;
    char output[N] = {0};
    char *pch;
    static int i = 1;
    int j = 0;
    int k = 0;
    int l = 0;
    
    if (fileName != NULL) {
        file = fopen(fileName, "r");
    }
    else {
        i = 1;
    }
    
    if (file != NULL) {
        
        // Find the latest line in data table
        
        do {
            check = fgets(output, sizeof(output), file);
            l++;
        } while (check != NULL && l < i);
        
        if (check == NULL) {
            strcpy(data.customerID, "done");
            return data;
        }
        
        i++;
        
        pch = strtok(output, " ,;");
        
        // Split each line and store data
        
        while (pch != NULL) {
            if (!strcmp(pch, "\r\n")) {
                break;
            }
            
            if (j == 0) {
                data.day = (atoi(pch));
            }
            else if (j == 1) {
                strcpy(data.customerID, pch);
            }
            else {
                if ((j%2) == 0) {
                    strcpy(data.products[k].productName, pch);
                }
                if ((j%2) == 1) {
                    data.products[k++].quantity = *pch;
                }
            }
            
            pch = strtok(NULL, " ,;");
            
            j++;
        }

        j = 0;
        
    }
    
    
    fclose(file);
    
    return data;
}

void readCategoriesFile(char fileName[], MultiplierData data[])
{
    FILE *file = NULL;
    char output[N] = {0};
    char *check = NULL;
    char *pch;
    char *str;
    int i = 0;
    int j = 0;
    int k = 0;
    
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        do {
            check = fgets(output, sizeof(output), file);
            
            pch = strtok(output, ":,");
            
            while (pch != NULL) {
                
                str = strstr(pch, "\r\n");
                if (str != NULL) {
                    str[0] = '\0';
                }
                
                if (j == 0) {
                    data[i].category = *pch;
                }
                else if (j == 1) {
                    data[i].multiplier = (atof(pch));
                }
                else {
                    data[i].products[k++] = pch;
                }
                
                pch = strtok(NULL, ":,");
                
                j++;
                
            }
            
            i++;
            j = 0;
            k = 0;
            
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
    char *token[N] = {0};
    char *pch;
    char *str;
    int i = 0;
    int j = 0;
    
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        pch = strtok(output, " \t");
        
        while (pch != NULL) {
            str = strstr(pch, "\r\n");
            if (str != NULL) {
                str[0] = '\0';
            }
            
            token[i++] = pch;
            
            pch = strtok(NULL, " \t");
        }
        
        for (i = 2; token[i] != NULL; i++) {
            if (atoi(token[i]) == 1)
            {
                data.Monday[j].price = (atoi(token[1]));
                strcpy(data.Monday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 2)
            {
                data.Tuesday[j].price = (atoi(token[1]));
                strcpy(data.Tuesday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 3)
            {
                data.Wednesday[j].price = (atoi(token[1]));
                strcpy(data.Wednesday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 4)
            {
                data.Thursday[j].price = (atoi(token[1]));
                strcpy(data.Thursday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 5)
            {
                data.Friday[j].price = (atoi(token[1]));
                strcpy(data.Friday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 6)
            {
                data.Saturday[j].price = (atoi(token[1]));
                strcpy(data.Saturday[j].productName, token[0]);
            }
            
            if (atoi(token[i]) == 7)
            {
                data.Sunday[j].price = (atoi(token[1]));
                strcpy(data.Sunday[j].productName, token[0]);
            }
        }
        
        j++;
        
    }
    
    fclose(file);
    
    return data;
}