//
//  main.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileOperations.h"
#include "Points.h"
#include "Hashing.h"
#include "Sorting.h"

#define N 250
#define S 1000003

int main(int argc, const char * argv[])
{
    PriceData pr_data = {0};
    MultiplierData mult_data[N] = {0};
    HashTable *table = malloc(S * sizeof(HashTable));
    
    readCategoriesFile("arxeio2.txt", mult_data);
    pr_data = readPricesFile("arxeio3.txt");
    
    
    addToHashTable(table, pr_data, mult_data);
    
    top10(table, S);
    
    
    
    free(table);
    
    return 0;
}


