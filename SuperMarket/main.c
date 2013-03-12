//
//  main.c
//  SuperMarket
//
//  Created by George Lydakis on 3/12/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "FileOperations.h"

#define N 25

int main(int argc, const char * argv[])
{
    char outStream[] = {0};
    
    readFile("file1.rtf", outStream);
    
    printf("%s", outStream);
    
    
    
    return 0;
}

