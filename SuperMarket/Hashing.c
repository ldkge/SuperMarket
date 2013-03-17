//
//  Hashing.c
//  SuperMarket
//
//  Created by George Lydakis on 3/17/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Hashing.h"
#include "FileOperations.h"
#include "Points.h"

#define S 300000

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
    int colision = 0;
    unsigned int hash;
    
    cstm_data = readCustomerFile("arxeio1.txt", pr_data, mult_data);
    for (i = 0; strcmp("done", cstm_data.customerID) != 0; i++) {
        hash = MurmurHash2(cstm_data.customerID, S, 34523452);
        
        if (strcmp("", table[hash%S].customerID) != 0) {
            
            table[(hash%S+1)%S] = cstm_data;
            colision++;
        }
        
        table[hash%S] = cstm_data;
        
        cstm_data = readCustomerFile("arxeio1.txt", pr_data, mult_data);
        
        printf("%d\t%d\n", i, colision);
    }
}