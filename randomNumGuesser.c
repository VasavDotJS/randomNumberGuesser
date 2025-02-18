#include <stdio.h>
#include <stdlib.h>
int getRandomNumber() {
    return (rand() % 10) + 1;
}
int main()
{
    int randomInt,userInp,gamePts=0,userAttempt=0;
    setNum:
    randomInt=getRandomNumber();
    do{
        printf("\t\t numGuesser\n");
        printf("\t\t------------\n\n");
        printf("\n'808' to end game,'420' to set new number.\n");
        printf("Attempts: %d \t\t Points: %d\n",userAttempt,gamePts);
        printf("Enter Your Guess: ");
        numInp:
        scanf("%d",&userInp);
        if(userInp==420)
            goto setNum;
        else if(userInp>10&&userInp<0){
            printf("Guess out of range! Try Again: ");
            userAttempt++;
            goto numInp;
        }
        else if(userInp==randomInt)
        {
            printf("Congratulations! Your Guess is Right!\n\n");
            userAttempt++;
            gamePts=gamePts+10;
            randomInt=getRandomNumber();
        }
        else if(userInp!=randomInt)
        {
            if(userInp==808)
            {
                goto outLoop;
            }
            printf("Wrong Guess! Try Again: ");
            userAttempt++;
            goto numInp;
        }
    }while(userInp!=808);\
    outLoop:
    return 0;
}
