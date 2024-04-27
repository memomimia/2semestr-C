5.1 проверяет,есть ли отрицательные числа в массиве
#include <stdio.h>

int otrchisla(int a[],int n){
    int s = 0;
    for(int i = 0;i <n; i++){
        if (a[i]<0){
        s = 1;
        break;
        }
    }
    return s;
}

int main(){
    int n;
    printf("введите колво элементов");
    scanf("%d",&n);
    int a[n];
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
}
int result = otrchisla(a,n);
if (result){
    printf("est' negative");
}
else{
    printf("net negative");
}
return 0;
}



