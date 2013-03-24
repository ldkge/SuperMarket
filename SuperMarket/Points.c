//
//  Points.c
//  SuperMarket
//
//  Created by George Lydakis on 3/16/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Points.h"
#include "FileOperations.h"

double calcPoints(char productName[], int day, int quantity, PriceData pr_data, MultiplierData mult_data[])
{
    double multiplier = 0.5;
    int i = 0;
    int i_max = -1;
    int price = 0;
    
    for (i = 0; mult_data[i].multiplier != 0; i++) {
        if (strcmp(productName, mult_data[i].product) == 0) {
            multiplier = mult_data[i].multiplier;
            break;
        }
    }
    
    i = 0;

    
    switch (day) {
        case 1: {
            do {
                
                if (strcmp(productName, pr_data.Monday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Monday[i].price != 0);
            
            if (i_max != -1 && pr_data.Monday[i_max].price != 0) {
                price = quantity * pr_data.Monday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 2: {
            do {
                
                if (strcmp(productName, pr_data.Tuesday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Tuesday[i].price != 0);
            
            if (i_max != -1 && pr_data.Tuesday[i_max].price != 0) {
                price = quantity * pr_data.Tuesday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 3: {
            do {
                
                if (strcmp(productName, pr_data.Wednesday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Wednesday[i].price != 0);
            
            if (i_max != -1 && pr_data.Wednesday[i_max].price != 0) {
                price = quantity * pr_data.Wednesday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
        break;
        case 4: {
            do {
                
                if (strcmp(productName, pr_data.Thursday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Thursday[i].price != 0);
            
            if (i_max != -1 && pr_data.Thursday[i_max].price != 0) {
                price = quantity * pr_data.Thursday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 5: {
            do {
                
                if (strcmp(productName, pr_data.Friday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Friday[i].price != 0);
            
            if (i_max != -1 && pr_data.Friday[i_max].price != 0) {
                price = quantity * pr_data.Friday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 6: {
            do {

                
                if (strcmp(productName, pr_data.Saturday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Saturday[i].price != 0);
            
            if (i_max != -1 && pr_data.Saturday[i_max].price != 0) {
                price = quantity * pr_data.Saturday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 7: {
            do {
                
                if (strcmp(productName, pr_data.Sunday[i++].productName) == 0) {
                    i_max = i - 1;
                }
                
            } while (pr_data.Sunday[i].price != 0);
            
            if (i_max != -1 && pr_data.Sunday[i_max].price != 0) {
                price = quantity * pr_data.Sunday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        default:
            price = 10 * quantity;
            break;
    }
    
    
    return price * multiplier;
}

int binarySearch(int target, PriceData data, int low, int high)
{
    int middle;
    
    while (low <= high) {
        middle = low + (high - low)/2;
        if (target < atoi(&data.maxPrices[middle].productName[1]))
            high = middle - 1;
        else if (target > atoi(&data.maxPrices[middle].productName[1]))
            low = middle + 1;
        else
            return data.maxPrices[middle].price;
    }

    
    return 10;
}

