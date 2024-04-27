5.4 сортировка массива по возрастанию
#include <stdio.h>

int main(){
  int n;
  printf("Введите размер массива:");
  scanf("%d",&n);
  int a[n],b[n],max,k,i,j;

  printf("Введите элементы массива:");
  for (j = 0;j<n;j++)
  scanf("%d",&a[j]);
  
  for(j =0,max=a[0];j<n;j++){
    if(a[j]> max){
      max = a[j];
    }
  }
  for (j = 0;j<n;j++){
    for(k =0,i = 1;i<n;i++){
      if(a[i]<a[k]){
        k = i;
      }
    }
    b[j]=a[k];
    a[k] = max+1;
  }
  printf("Сортированный массив:");
  for(j = 0;j < n;j++){
  printf("%d ",b[j]);
  }
  
  return 0;
}



