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
#include "Teams.h"

#define N 100
#define S 1000003

int main(int argc, const char * argv[])
{
    PriceData pr_data = {0};
    MultiplierData mult_data[N] = {0};
    TeamPointsData team_data[N] = {0};
    HashTable *table = malloc(S * sizeof(HashTable));
    int size;
    
    size = readCategoriesFile("arxeio2.txt", mult_data);
    
    pr_data = readPricesFile("arxeio3.txt");
    
    readTeamPointsFile("arxeio5.txt", team_data);
    
    quickSort(mult_data, size);
    
    addToHashTable(table, pr_data, mult_data, size);
    
    top10(table, S);
    
    calcPrizes("arxeio4.txt", team_data, table);
    
    free(table);
    
    return 0;
}


