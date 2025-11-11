/*banana pattern*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i =1 ; i <= n; i++)
    {
        for(int s = 1 ; s <= n -i; s++){
            printf("  ");
        }
        for (int j = 1; j <=i; j++)
        {
            printf("%d ", j);
        }
        // int a = i -1;
        for(int k = i-1; k >= 1; k--){
            printf("%d ", k);
        }
        
        printf("\n");
    }

    for (int i =n-1; i >= 1; i--)
    {
        for(int s = 1 ; s <= n -i; s++){
            printf("  ");
        }
        for (int j = 1; j <=i; j++)
        {
            printf("%d ", j);
        }
        for(int j=i-1;j>=1;j--)
        {
            printf("%d ",j);
        }

        printf("\n");
    }
    return 0;
}