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
                data.day = ((int)*pch - 48);
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
                    data[i].multiplier = ((int)*pch - 48);
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

