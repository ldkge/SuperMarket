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
    FILE *file;
    char *check = NULL;
    char output[N] = {0};
    char *pch;
    char *pch2;
    char *pch3;
    char tokens1[3] = {0};
    char tokens2[20] = {0};
    static int i = 1;
    int j = 0;
    int k = 0;
    int l = 0;
    
    file = fopen(fileName, "r");
    
    
    if (file != NULL) {
        
        // Find the latest line in data table
        
        do {
            check = fgets(output, sizeof(output), file);
            l++;
        } while (check != NULL && l < i);
        
        i++;
        
        // Split the line in the first three pieces
        
        pch = strtok(output, " ");
        
        while (pch != NULL) {
            tokens1[j++] = *pch;
            strtok(NULL, " ");
        }

        j = 0;
        
        // Split the 3rd string to Product Name and quantity
        // Save them in data struct
        
        pch2 = strtok(&tokens1[3], ";");
        
        while (pch2 != NULL) {
            tokens2[j] = *pch2;
            
            pch3 = strtok(&tokens2[j++], ",");
            
            while (pch3 != NULL) {
                strcpy(&data.products[k][k%2], pch3);
                k++;
            }
            
            strtok(NULL, ";");
        }
        
        data.day = tokens1[0];
        strcpy(data.customerID, &tokens1[1]);
        

    }
    
    
    fclose(file);
    
    return data;
}
