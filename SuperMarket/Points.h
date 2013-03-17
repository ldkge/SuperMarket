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

int calcPrice(char [], int , int , PriceData );
double findMultiplier(char [], MultiplierData []);
double calcPoints(char [], int , int , PriceData , MultiplierData []);

#endif
