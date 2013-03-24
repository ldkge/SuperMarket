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

#define S 1000003

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

void addToHashTable(HashTable table[], PriceData pr_data, MultiplierData mult_data[])
{
    CustomerData cstm_data;
    int i = 0;
    FILE *file = NULL;
    int colision = 0;
    unsigned int hash;
    char* check;
    char output[500] = {0};
    
    file = fopen("arxeio1.txt", "r");
    
    clock_t start = clock();
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
        
        
        for (i = 0; check != NULL; i++) {
            cstm_data = readCustomerFile(output, pr_data, mult_data);
            
            //if (strcmp("AFASDHQZHZNLDGS", cstm_data.customerID) == 0) {
            //    printf("");
            //}
            
            hash = MurmurHash2(cstm_data.customerID, 15, 2);
            
            
            if (strcmp("", table[hash%S].customerID) != 0) {
                colision++;
                while (strcmp("", table[++hash%S].customerID) != 0) {
                    
                }
                
                if (strcmp(cstm_data.customerID, table[hash%S].customerID) == 0) {
                    table[hash%S].points += cstm_data.points;
                }
                
                table[hash%S] = cstm_data;
                
            }
            else {
                table[hash%S] = cstm_data;
            }

            
            
            
            
            check = fgets(output, sizeof(output), file);
            
            //if (i%10000 == 0) {
            //    printf("%d\t%d\t%f\t%f\n", i, colision, (1-((float)colision/(float)i))*100, ((double)clock() - start) / CLOCKS_PER_SEC);
            //}
            
        }
    }
    
    printf("%d\t%d\t%f\t%f\n", i, colision, (1-((float)colision/(float)i))*100, ((double)clock() - start) / CLOCKS_PER_SEC);
    fclose(file);
    
    
    

}