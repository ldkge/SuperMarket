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
    char customerID[16];
    double points;
};

struct multiplierData {
    double multiplier;
    char product[3];
};

struct day {
    char productName[3];
    int price;
};

struct priceData {
    struct day Monday[50];
    struct day Tuesday[50];
    struct day Wednesday[50];
    struct day Thursday[50];
    struct day Friday[50];
    struct day Saturday[50];
    struct day Sunday[50];
};

typedef struct customerData CustomerData;
typedef struct multiplierData MultiplierData;
typedef struct priceData PriceData;

CustomerData readCustomerFile(char [], PriceData , MultiplierData []);
void readCategoriesFile(char [], MultiplierData []);
PriceData readPricesFile(char []);



#endif
