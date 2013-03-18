//
//  main.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "FileOperations.h"
#include "Points.h"
#include "Hashing.h"

#define N 500
#define S 340000

int main(int argc, const char * argv[])
{
    PriceData pr_data;
    MultiplierData mult_data[N];
    HashTable table[S] = {0};
    
    readCategoriesFile("arxeio2.txt", mult_data);
    pr_data = readPricesFile("arxeio3.txt");
    
    
    addToHashTable(table, pr_data, mult_data);
    
    return 0;
}

