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

void readFile(char fileName[], char *output)
{
    FILE * file;
    
    file = fopen(fileName, "r");
    
    if (file != NULL) {
        fgets(output, sizeof(output), file);
    }
    
    
    fclose(file);
}