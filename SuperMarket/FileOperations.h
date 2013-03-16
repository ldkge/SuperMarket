//
//  FileOperations.h
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#ifndef SuperMarket_FileOperations_h
#define SuperMarket_FileOperations_h

struct Products {
    char productName[3];
    char quantity;
};

struct customerData {
    int day;
    char customerID[16];
    struct Products products[50];
};

struct multiplierData {
    int multiplier;
    char products[50];
};

typedef struct customerData CustomerData;
typedef struct multiplierData MultiplierData;

CustomerData readCustomerFile(char []);
MultiplierData readCategoriesFile(char []);
void readPricesFile();



#endif
