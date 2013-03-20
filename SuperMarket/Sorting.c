//
//  Sorting.c
//  SuperMarket
//
//  Created by George Lydakis on 3/20/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include "Sorting.h"
#include "Hashing.h"

#define S 1000003

void quickSort(HashTable *arr, int elements) {
    
#define  MAX_LEVELS  300
    
    int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R, swap ;
    
    beg[0] = 0;
    end[0] = elements;
    
    while (i >= 0) {
        L = beg[i];
        R = end[i] - 1;
        if (L<R) {
            piv = arr[L].points;
            while (L<R) {
                while (arr[R].points >= piv && L < R) {
                    R--;
                }
                if (L<R) {
                    arr[L++] = arr[R];
                }
                while (arr[L].points <= piv && L < R) {
                    L++;
                }
                if (L < R) {
                    arr[R--] = arr[L];
                }
            }
            
            arr[L].points = piv;
            beg[i+1] = L+1;
            end[i+1] = end[i];
            end[i++] = L;
            
            if (end[i] - beg[i] > end[i-1] - beg[i-1]) {
                swap = beg[i];
                beg[i] = beg[i-1];
                beg[i-1] = swap;
                swap = end[i];
                end[i] = end[i-1];
                end[i-1] = swap;
            }
        }
        else {
            i--;
        }
    }
}

void top10(HashTable *table, int size)
{
    int i, j = 0;
    HashTable top[10], temp = {0};
    
    for (i = 0; i < S; i++) {
        if ((int)table[i].points != 0) {
            if (j < 10) {
                if (top[i].points < table[i].points) {
                    if (j != 0) {
                        temp = top[j-1];
                        top[j-1] = table[i];
                        top[j] = temp;
                        j++;
                    }
                    else {
                        top[j] = table[i];
                        j++;
                    }
                }
            }
            else {
                if (top[9].points < table[i].points) {
                    top[9] = table[i];
                }
            }
        }
    }
    
    for (i = 0; i < 10; i++) {
        printf("%s\t%f\n", top[i].customerID, top[i].points);
    }
}