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
    struct day Monday[500];
    struct day Tuesday[500];
    struct day Wednesday[500];
    struct day Thursday[500];
    struct day Friday[500];
    struct day Saturday[500];
    struct day Sunday[500];
    struct maxPrice maxPrices[1000];
    int max_size;
};

struct teamPointsData {
    int prize;
    int points;
};

typedef struct customerData CustomerData;
typedef struct multiplierData MultiplierData;
typedef struct priceData PriceData;
typedef struct teamPointsData TeamPointsData;

CustomerData readCustomerFile(char [], PriceData , MultiplierData [], int);
int readCategoriesFile(MultiplierData []);
PriceData readPricesFile();
void readTeamPointsFile(TeamPointsData []);


#endif
