//
//  Teams.c
//  SuperMarket
//
//  Created by George Lydakis on 4/9/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Teams.h"
#include "Hashing.h"
#include "FileOperations.h"

#define S 1000003

void calcPrizes(char filename[], TeamPointsData data[], HashTable table[])
{
    FILE *file;
    char *check = NULL;
    int chk = 0;
    char output[16] = {0};
    int prehash, hash;
    double points = 0;
    int i;
    
    file = fopen(filename, "r");
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        for (i = 0; check != NULL; i++) {
            prehash = MurmurHash2(output, 15, 2);
            hash = prehash%S;
            
            while (strcmp(output, table[hash].customerID) != 0)
            {
                if (strcmp("", table[hash].customerID) == 0) {
                    chk = 1;
                    break;
                }
                hash++;
            }
            
            if (chk == 0) {
                points += table[hash].points;
            }
            else {
                printf("Card %s does not exist.\n", output);
                chk = 0;
            }
            

            
            check = fgets(output, sizeof(output), file);
        }
        
        printf("You are eligible for:\n");
        
        for (i = 0; data[i].prize != 0; i++) {
            if (data[i].points <= points) {
                printf("Gift G%d\n", data[i].prize);
            }
        }
        
        
    }
}