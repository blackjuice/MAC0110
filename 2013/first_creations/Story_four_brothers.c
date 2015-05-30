//
//  First_Story.c
//  FirstObj_C2013
//
//  Created by Limbo on 3/17/13.
//  Copyright (c) 2013 Limbo. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[])
{
    int brothers;
    printf("Once upon a time, there were four brothers:\n 1.Bo\n 2.Dah\n 3.Line\n 4.Lu\nWhich one of them do you want to choose?: \n");
    scanf("%d",&brothers);

    if (brothers==1) {
        printf("Bo was the eldest of the brothers, the lousiest and the most bad-tempered.\n");
    }
    if (brothers==2) {
        printf("Dah was the second, yet, the one with the body of an old woman.\n");
    }
    if (brothers==3) {
        printf("Line was the third daugther and everyone new she had a smile to hide her true face.\n");
    }
    if (brothers==4) {
        printf("Lu was the last of the four and the creator of this little story.\n");
    }
    printf("And with that, this little story has come to the first ending...\n Hit 'command+R' to run this story again.\n");

    return 0;
}
