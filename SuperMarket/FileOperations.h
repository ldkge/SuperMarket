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
    int productName;
    char quantity;
};

struct customerData {
    char customerID[16];
    double points;
};

struct multiplierData {
    double multiplier;
    int product;
};

struct day {
    int productName;
    int price;
};

struct maxPrice {
    int productName;
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
    int max_size;
};

typedef struct customerData CustomerData;
typedef struct multiplierData MultiplierData;
typedef struct priceData PriceData;

CustomerData readCustomerFile(char [], PriceData , MultiplierData []);
void readCategoriesFile(char [], MultiplierData []);
PriceData readPricesFile(char []);



#endif
