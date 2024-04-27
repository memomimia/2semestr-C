#include <stdio.h>

int krat5(int arr[], int size, int index,int sum){
    if (index == size){
    return sum;
    }
    if (arr[index] % 5 == 0){
        sum += arr[index];
    }
    return krat5(arr, size, index+1, sum);
}

int main(){
    int size;
    printf("Введите размер массива:");
    scanf("%d",&size);

    int arr[size];
    printf("Введите элементы массива: ");
    for (int i = 0; i < size; i ++){
        scanf("%d",&arr[i]);
    }
    int sum = krat5(arr,size,0,0);
    printf("Сумма чисел кратных 5: %d\n",sum);
    return 0;
}
