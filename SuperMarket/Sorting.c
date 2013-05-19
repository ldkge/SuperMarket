//
//  Sorting.c
//  SuperMarket
//
//  Created by George Lydakis on 3/20/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Sorting.h"
#include "Hashing.h"
#include "FileOperations.h"

#define S 93761

int quickSort(MultiplierData * arr, int elements) {
    
#define  MAX_LEVELS  1000
    
    int beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R ;
    MultiplierData piv;
    
    beg[0]=0;
    end[0]=elements;
    while (i>=0) {
        L=beg[i];
        R=end[i]-1;
        if (L<R) {
            piv=arr[L];
            if (i==MAX_LEVELS-1)
                return 0;
            while (L<R) {
                while (arr[R].product>=piv.product && L<R)
                    R--;
                if (L<R)
                    arr[L++]=arr[R];
                while (arr[L].product<=piv.product && L<R)
                    L++;
                if (L<R)
                    arr[R--]=arr[L];
            }
            arr[L]=piv;
            beg[i+1]=L+1;
            end[i+1]=end[i];
            end[i++]=L;
        }
        else {
            i--;
        }
    }
    return 1;
}

void top10(HashTable *table, int size)
{
    int i, j = 0;
    HashTable top[10] = {0};
    
    for (i = 0; i < S; i++) {
        if (table[i].points > 0.1 && table[i].points > top[j].points) {
            top[j] = table[i];
            
            
            if (j < 9) {
                j++;
            }
            
            bubbleSort(top, 10);
            
        }
    }

    printf("Top 10 Cards\n");
    
    for (i = 0; i < 10; i++) {
        printf("%s\t%f\n", top[i].customerID, top[i].points);
    }
    
    printf("\n");
}


void bubbleSort(HashTable numbers[], int array_size)
{
    int i, j;
    HashTable temp;
    
    for (i = (array_size - 1); i > 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (numbers[j-1].points < numbers[j].points)
            {
                temp = numbers[j-1];
                numbers[j-1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}