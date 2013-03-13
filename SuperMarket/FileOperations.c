//
//  FileOperations.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "FileOperations.h"

char readFile(char fileName[], char *output)
{
    FILE *file;
    char *check = NULL;
    
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        check = fgets(output, sizeof(output), file);
    }
    
    
    fclose(file);
    
    return *check;
}

void parseData(char input[], char output[][100])
{
    char *check = NULL;
    int i = 0;
    
    do {
        check = readFile("file1.txt", output[i]);
    } while (check != NULL);
}