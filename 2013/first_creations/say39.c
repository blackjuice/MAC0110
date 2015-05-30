//
//  main.c
//  test1-triangular
//
//  Created by Limbo on 3/13/13.
//  Copyright (c) 2013 Computation. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int saying;

    do {
    printf("Say '39' to me and I'll reply: ");
    scanf("%d",&saying);

        if (saying==39)
            printf ("Thanks!");
        else
            printf ("fuck you. I told you to say 39 to me and you didn't\n");
    }
    while (saying!=39);

            return 0;
}
