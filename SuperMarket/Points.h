//
//  Points.h
//  SuperMarket
//
//  Created by George Lydakis on 3/16/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include "FileOperations.h"

#ifndef SuperMarket_Points_h
#define SuperMarket_Points_h

double calcPoints(int , int , int , PriceData , MultiplierData [], int);
int binarySearch(int , PriceData , int, int);
double binarySearch_d(int, MultiplierData [], int, int);

#endif
