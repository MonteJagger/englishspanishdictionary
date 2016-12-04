//
//  test.c
//  algorithmsHW5
//
//  Created by Hiumathy Lam on 12/4/16.
//  Copyright © 2016 Hiumathy Lam. All rights reserved.
//

#include <stdio.h>

int main(){
    FILE *fp;

    printf("Two words\n");
    
    
    
    fp = fopen("Spanish.txt", "r");

    
    
    char *first = (char*)malloc(1000*sizeof(char));
    char *second = (char*)malloc(1000*sizeof(char));
    while (fscanf(fp, "%s %[^\n]", first, second) == 2) {
        
        if (first[0] == '#')
            continue;
        printf("%10s \t %40s\n", first, second);
        //root = Insert(root, first, second);
    }
    fclose(fp);
}