/*Using an 8-element array of type bool for each number, convert them into binary. 
 *Each element in the array represents one bit of an 8-bit word, with false indicating a bit value of 0, true indicating a 
 *value of 1. You will also need a bool array for the sum , which you will compute in the next step.*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void binaryAdd(bool *sumArray, int* cBit, const bool n1[], const bool n2[]);

int main()
{
    int n1, n2 = 0;
    int cBit= 0;
    bool arrayOne[8];
    bool arrayTwo[8];
    bool sumArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    //Ask the user for two non-negative integers n1 and n2 . For this exercise, you can assume the largest value for either will be 127.
    
    printf("Enter a positive integer no greater than 127, 0 to stop: ");
    scanf("%d", &n1);
    if (n1 == 0)
    {
        return 0;
    }
    //Do the following as long as n1 is not 0
    do
    {
       

   
        printf("Enter a second positive integer no greater than 127: ");
        scanf("%d", &n2);
       
        int storedN1 = n1;
        int storedN2 = n2;
        
        //Compute the binary equivalent of n1 and n2 and... 
        for (int i = 7; i >= 0; i--)
        {
            int bitStorer = n1 % 2;
            arrayOne[i] = bitStorer;
            n1 = n1/2;
        }
        for (int i = 7; i >= 0; i--)
        {
            int bitStorer = n2 % 2;
            arrayTwo[i] = bitStorer;
            n2 = n2/2;
        }

        //print them to the screen.
        printf("The first number in binary is ");
        for (int i = 0; i < 8; i++)
        {
            printf("%d", arrayOne[i]);
        }
        printf("\nThe second number in binary is ");
        for (int i = 0; i < 8; i++)
        {
            printf("%d", arrayTwo[i]);
        }

        //Compute the hex equivalent of n1 and n2 and print them to the screen.
        printf("\nThe first number in hex is %02X", storedN1);
        printf("\nThe second number in hex is %02X", storedN2);
        
        /*Write this function:
         *void binaryAdd(bool sum[], int* cBit, const bool n1[], const bool n2[])
         *and call it to compute the sum of n1 and n2 . Print the sum to the screen in both binary and decimal, 
         *and print the value of the carry bit.*/
        
        binaryAdd(sumArray, &cBit, arrayOne, arrayTwo);
        printf("\nThe sum is ");
        for (int i = 0; i < 8; i++)
        {
             printf("%d", sumArray[i]);
        }
        int tally = 0;
        double index = 7;
        for (int i = 0; i < 8; i++)
        {
            tally += sumArray[i]*pow(2.0, index);
            index--;
        }
        printf("\nWhich is %d in decimal", tally);
        printf("\nThe carry bit is %d", cBit);

       //Negate n1 and represent it in 2’s comp; print this to the screen
       for (int i = 0; i < 8; i++)
       {
           if (arrayOne[i] == 0)
           {
               arrayOne[i] = 1;
           } 
           else
           {
               arrayOne[i] = 0;
           }
       }
       bool complementArray[8] = {0, 0, 0, 0, 0, 0, 0, 1};
       int temp2 = 0;
       int secondCarry = 0;
       for (int i = 7; i >= 0; i--)
       {
           temp2 = arrayOne[i] + complementArray[i] + secondCarry;
           arrayOne[i] = temp2 % 2;
           secondCarry = (temp2/2);
       }
       printf("\n-%d in 2's complement is ", storedN1);
       for(int i = 0; i < 8; i++)
       {
           printf("%d", arrayOne[i]);
       }

       //Do an ASR operation on the 2’s comp representation of n2 . Write the answer to the screen in binary and decimal.
       for (int i = 7; i > 0; i--)
       {
           arrayTwo[i] = arrayTwo[i-1];
       }
       printf("\nAfter ASR of %d: ", storedN2);
       for(int i = 0; i < 8; i++)
       {
           printf("%d", arrayTwo[i]);
       }
       int total = 0;
       double count = 7;
       for (int i = 0; i < 8; i++)
       {
            total += arrayTwo[i]*pow(2.0, count);
            count--;
       }
       printf("\nWhich is %d in decimal", total);
       
       //Do an ASL operation on your result from the previous step. Write the answer to the screen in binary and decimal.
       for (int i = 0; i < 7; i++)
       {
           arrayTwo[i] = arrayTwo[i+1];
       }
       arrayTwo[7] = 0;
       printf("\nAfter ASL: ");
       for (int i = 0; i < 8; i++)
       {
           printf("%d", arrayTwo[i]);
       }
       total = 0;
       count = 7;
       for (int i = 0; i < 8; i++)
       {
            total += arrayTwo[i]*pow(2.0, count);
            count--;
       }
       printf("\nWhich is %d in decimal", total);
       
       //Ask for another set of values for n1 and n2
       printf("\nEnter a positive integer no greater than 127, 0 to stop: ");
       scanf("%d", &n1);
    } while (n1 != 0);
    return 0;
}

void binaryAdd(bool *sumArray, int *cBit, const bool n1[], const bool n2[])
{   
    int temp = 0;
    for (int i = 7; i >= 0; i--)
    {
        temp = n1[i] + n2[i] + *cBit;
        sumArray[i] = temp % 2;
        *cBit = (temp/2);
    }
       
}
