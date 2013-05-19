//
//  Teams.c
//  SuperMarket
//
//  Created by George Lydakis on 4/9/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Teams.h"
#include "Hashing.h"
#include "FileOperations.h"

#define S 93761
#define M 15

void calcPrizes(TeamPointsData data[], HashTable table[], int choice)
{
    FILE *file;
    char *check = NULL;
    int chk = 0;
    char fileName[M];
    char output[16] = {0};
    int prehash, hash;
    double points = 0;
    int i;
    
    do {
        printf("Enter the name of the fourth file: ");
        scanf("%s", fileName);
        
        file = fopen(fileName, "r");
    } while (file == NULL);
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        for (i = 0; check != NULL; i++) {
            switch (choice) {
                case 0:
                    prehash = abs(BKDRHash(output, 15));
                    break;
                case 1:
                    prehash = abs(MurmurHash2(output, 15, 2));
                    break;
                case 2:
                    prehash = abs(KnuthHash(output));
                    break;
                default:
                    break;
            }
            
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
                printf("\nCard %s does not exist.\n", output);
                chk = 0;
            }
            

            
            check = fgets(output, sizeof(output), file);
            if (strcmp(output, "\r\n") == 0) {
                check = fgets(output, sizeof(output), file);
            }
        }
        
        printf("\nYou are eligible for:\n");
        
        
        for (i = 0; data[i].prize != 0; i++) {
            if (data[i].points <= points) {
                printf("Gift G%d\n", data[i].prize);
            }
        }
        
        
    }
}