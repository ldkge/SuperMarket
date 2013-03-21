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
    char productName[5];
    char quantity;
};

struct customerData {
    char customerID[16];
    double points;
};

struct multiplierData {
    double multiplier;
    char product[5];
};

struct day {
    char productName[5];
    int price;
};

struct maxPrice {
    char productName[5];
    int price;
};

struct priceData {
    struct day Monday[150];
    struct day Tuesday[150];
    struct day Wednesday[150];
    struct day Thursday[150];
    struct day Friday[150];
    struct day Saturday[150];
    struct day Sunday[150];
    struct maxPrice maxPrices[250];
};

typedef struct customerData CustomerData;
typedef struct multiplierData MultiplierData;
typedef struct priceData PriceData;

CustomerData readCustomerFile(char [], PriceData , MultiplierData []);
void readCategoriesFile(char [], MultiplierData []);
PriceData readPricesFile(char []);



#endif
