#include <stdio.h>

int main(){
    double numb[] = {1.1, 2.2, 3.3, 4.4, 5.5,12.3 , 132.4, 0.1};
    int size = sizeof(numb) / sizeof(numb[0]);

    FILE *file = fopen("numb.txt", "w");
    if (file == NULL){
        printf("не удалось открыть файл\n");
        return 1;
    }

    double sum = 0.0;
    for(int i = 0; i < size; i++){
        fprintf(file, "%f\n", numb[i]);
        sum += numb[i];
    }
    fclose(file);

    double avg = sum / size;
    int k = 0;
    for(int i = 0; i < size; i++){
        if(numb[i] < avg){
            k++;
        }
    }
    printf("Cреднее арифметическое чисел: %f\n", avg);
    printf("Количество чисел меньше avg: %d", k);
    return 0;
}
