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

#define N 100

int main(int argc, const char * argv[])
{
    PriceData pr_data;
    MultiplierData mult_data[N];
    HashTable table[11] = {0};
    int price;
    double mult;
    double points;
    
    readCategoriesFile("file2.txt", mult_data);
    
    mult = findMultiplier("P7", mult_data);
    pr_data = readPricesFile("file3.txt");
    price = calcPrice("P7", 1, 2, pr_data);
    
    points = calcPoints("P7", 1, 2, pr_data, mult_data);
    
    addToHashTable(table, pr_data, mult_data);
    
    return 0;
}

