5.6 Делает проверку,есть ли в массиве отрицательные числа, если есть, то прекращает программу, если нет, то выводит good
#include <stdio.h>

int main(){
  int n;
  printf("Введите размер массива:");
  scanf("%d",&n);

  int a[n];
  printf("Введите элементы массива:");
  for ( int i = 0; i < n;i++){
  scanf("%d",&a[i]);
  }

  int i;
  for(i = 0;i<n;i++){
    if(a[i]<0){
      printf("Есть отрицательные");
      break;
    }
  }
  if (i == n){
  puts("Good");
  }

return 0;
}



