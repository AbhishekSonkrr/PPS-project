/*banana pattern*/
#include <stdio.h>

int main(){
    int n=4;
    int nsp = n-1;
    int nst =1;

    for (int i =1 ; i < (2*n-1); i++)
    {
        for (int j = 1; j < nsp; j++)
        {
            printf("  ");
        }
        for (int k= 1; k<=i; k++)
        {
            printf("%d ", k);
        }
        int a=i-1;
        for (int l = 1; l < l-1; l++)
        {
            printf("%d",a);
        }
        if(i<4)
        {
        nsp--;
        nst +=2;
        }
        else 
        {
        nsp++;
        nst -=1;
        }   
        printf("\n");
    }
        
    
    
    return 0;
}