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

#define N 100

int main(int argc, const char * argv[])
{
    CustomerData outData;
    MultiplierData multData[50];
    
    outData = readCustomerFile("file1.txt");

    readCategoriesFile("file2.txt", multData);
    
    return 0;
}

