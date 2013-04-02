//
//  Hashing.h
//  SuperMarket
//
//  Created by George Lydakis on 3/17/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include "FileOperations.h"

#ifndef SuperMarket_Hashing_h
#define SuperMarket_Hashing_h

typedef CustomerData HashTable;

unsigned int MurmurHash2(const void * , int , unsigned int );
void addToHashTable(HashTable [], PriceData , MultiplierData [], int);

#endif
