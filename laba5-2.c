5.2 выводит простые числа из массива
#include <stdio.h>

int main(){
    int n = 10;
    int a[] = {2,3,4,5,6,7,8,9,10,11};
    int b[n];
    int j = 0;
    int m,s,i;
    
    for(j = 0,i = 0;i < n;i++){
        for(s = 0,m = 2;m < a[i];m++){
            if(a[i] % m == 0){
                s = 1;
                break;
            }
        }
        if(s == 0){
        b[j++] = a[i];
        }
    }
    b[j] = 0;
    for (i = 0;b[i] != 0;i++){
        printf("\n prost chislo =");
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}


}



