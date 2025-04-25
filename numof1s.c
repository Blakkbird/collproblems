#include <stdio.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[]) // 100
{
    int l=strlen(argv[1]);
    int d=0;
    for(int i=0;i<l;i++)
    {
        d+=(pow(2,i)*((int)argv[1][i] - 48)); // convert string of binary to decimal
    }
    
    int arr[l];
    for(int i=0;i<l;i++)
    {
        arr[i]=d^(1<<i); // toggle bit
       // printf("%d\n",arr[i]);
    }
    int grid[l][l];
    for(int i=0;i< l;i++)
    {
        int num=arr[i];
        int j;
        while(num != 0)
        {
            j=log(num)/log(2);
            grid[i][j]=1;
            num-=pow(2,j);
        }
    }

    int count=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            int digit=grid[i][j];
            if(digit == 1){count++;}
        }
    }
    
    printf("Num of 1s is %d\n", count);

}
