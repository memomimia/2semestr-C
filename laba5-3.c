5.3 зеркалит массив
#include <stdio.h>

void mas(int c[],int n){
  int i,j,k;
  k = c[i];
  c[i] = c[j];
  c[j] = k;
  
  for (i = 0,j= n - 1; i < j; i++,j--){
    k = c[i];
    c[i] = c[j];
    c[j] = k;
  }
}

int main(){
  int n,i;
  printf("vvedite size massiva: ");
  scanf("%d ",&n);

  int c[n];
  printf("vvedite elements: \n");
  for( i=0;i< n;i++)
  scanf("%d",&c[i]);

  mas(c,n);

  printf("izm massive: \n");
  for(i =0;i <n;i ++)
  printf("%d ",c[i]);
  return 0;
}




