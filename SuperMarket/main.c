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

#define N 100

int main(int argc, const char * argv[])
{
    PriceData pr_data;
    MultiplierData mult_data[N];
    int price;
    double mult;
    
    readCategoriesFile("file2.txt", mult_data);
    
    mult = findMultiplier("P7", mult_data);
    
    
    pr_data = readPricesFile("file3.txt");
    
    price = calcPrice("P6", 2, 1, pr_data);
    
    return 0;
}

