#include <stdio.h> // mandatory include

int adder(int year){
    if (year%4==0){
        return 2;
    }
    else {
        return 1;
    }
}

int birt(int XX, int YY, int ZZZZ, int AA, int BB, int CCCC){   // function you have to implement
    int counter=-2;
    int mon=0;
    if (100*YY+XX<229){
        for (int i=ZZZZ;i<CCCC;i++){
            counter=counter+adder(i);
            if (counter%7==0){
                mon=mon+1;
                counter=0;
            }
            if (i==CCCC-1){
                if (100*BB+AA<=100*YY+XX && counter%7==0){
                    mon=mon-1;
                }
            }


        }
    }
    if (100*YY+XX>229){
        for (int i=ZZZZ+1;i<=CCCC;i++){
            counter=counter+adder(i);
            if (counter%7==0){
                mon=mon+1;
                counter=0;
            }
            if (i==CCCC){
                if (100*BB+AA<=100*YY+XX && counter%7==0){
                    mon=mon-1;
                }
            }


        }
    }
    if (100*YY+XX==229){
        for (int i=ZZZZ;i<CCCC;i++){
            counter=counter+adder(i);
            if (counter%7==0){
                mon=mon+1;
                counter=0;
            }
            if (i==CCCC-1){
                if (CCCC%4==0 && 100*BB+AA<=229 && counter%7==0){
                    mon=mon-1;
                }
                if (CCCC%4!=0 && 100*BB+AA<=301 && counter%7==0){
                    mon=mon-1;
                }
            }


        }
    }  
    int result = mon;          // sample variable - you can change this according to your need
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    return result;                 // return statment
}

int main()                       // mandatory main function
{
    int XX, YY, ZZZZ, AA, BB, CCCC;             // variable 
    scanf("%d", &XX);           // input of Date of birth
    scanf("%d", &YY);            // input of Month of birth
    scanf("%d", &ZZZZ);           // input of Year of birth
    scanf("%d", &AA);           // input of Date of death
    scanf("%d", &BB);            // input of Month of death
    scanf("%d", &CCCC);            // input of Year of death
    //printf("%d-%d-%d and %d-%d-%d \n",XX, YY, ZZZZ, AA, BB, CCCC);
    int result = birt(XX, YY, ZZZZ, AA, BB, CCCC);  // calling function
    printf("%d",result);               // printing result
    return 0;                   // return statment
}
