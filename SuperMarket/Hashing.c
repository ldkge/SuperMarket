//
//  Hashing.c
//  SuperMarket
//
//  Created by George Lydakis on 3/17/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Hashing.h"
#include "FileOperations.h"
#include "Points.h"

#define S 93761
#define M 15

unsigned int MurmurHash2(const void * key, int len, unsigned int seed)
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.
    
	const unsigned int m = 0x5bd1e995;
	const int r = 24;
    
	// Initialize the hash to a 'random' value
    
	unsigned int h = seed ^ len;
    
	// Mix 4 bytes at a time into the hash
    
	const unsigned char * data = (const unsigned char *)key;
    
	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;
        
		k *= m;
		k ^= k >> r;
		k *= m;
		
		h *= m;
		h ^= k;
        
		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array
    
	switch(len)
	{
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0];
	        h *= m;
	};
    
	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.
    
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
    
	return h;
}

unsigned int KnuthHash(char v[])
{
    unsigned int out = 0;
    int i;
    
    for (i = 0; v[i] != '\0'; i++) {
        out += v[i];
        out *= 2654435761;
        
    }
    
    return out >> 16;
}

unsigned int BKDRHash(char* str, unsigned int len)
{
    unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
    unsigned int hash = 0;
    unsigned int i    = 0;
    
    for(i = 0; i < len; str++, i++)
    {
        hash = (hash * seed) + (*str);
    }
    
    return hash;
}

void addToHashTable(HashTable table[], PriceData pr_data, MultiplierData mult_data[], int mult_max)
{
    CustomerData cstm_data;
    int i = 0;
    FILE *file = NULL;
    int colision = 0;
    char fileName[M];
    unsigned int hash, prehash;
    char* check;
    int choice;
    int brk = 0;
    char output[500] = {0};
    
    
    do {
        printf("Enter the name of the first file: ");
        scanf("%s", fileName);
        
        file = fopen(fileName, "r");
    } while (file == NULL);
    
    clock_t start = clock();
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        do{
            printf("\n0)MurmurHash2\n1)KnuthHash\n2)BKDRHash\nChoose the hash function: ");
            scanf("%d", &choice);
            if (choice < 3) {
                printf("\nCalculating...\n");
            }
        } while (choice > 3);
        
        for (i = 0; check != NULL; i++) {
            cstm_data = readCustomerFile(output, pr_data, mult_data, mult_max);
            
            
            switch (choice) {
                case 0:
                    prehash = MurmurHash2(cstm_data.customerID, 15, 2);
                    break;
                    case 1:
                    prehash = KnuthHash(cstm_data.customerID);
                    break;
                    case 2:
                    prehash = BKDRHash(cstm_data.customerID, 15);
                    break;
                default:
                    break;
            }

            hash = prehash%S;
            
            if (strcmp(cstm_data.customerID, table[hash].customerID) == 0) {
                table[hash].points += cstm_data.points;
            }
            else if (strcmp("", table[hash].customerID) != 0) {
                
                while (strcmp("", table[(++hash)%S].customerID) != 0) {
                    if (strcmp(cstm_data.customerID, table[hash%S].customerID) == 0) {
                        table[hash%S].points += cstm_data.points;
                        brk = 1;
                        break;
                    }
                }
                
                if (brk != 1) {
                    colision++;
                    table[hash%S] = cstm_data;
                }
                else {
                    brk = 0;
                }
                
                
            }
            else {
                table[hash] = cstm_data;
            }

            
            
            
            
            check = fgets(output, sizeof(output), file);
            
            
        }
    }
    
    printf("\nN    Collisions Efficiency  Time Elapsed\n%d\t%d\t%f\t%f\n", i, colision, (1-((float)colision/(float)i))*100, ((double)clock() - start) / CLOCKS_PER_SEC);
    fclose(file);
    
    
    

}