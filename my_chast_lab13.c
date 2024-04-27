#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {//функция перестановки элементов между собой
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[], int n, int* c, int* m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                (*m)++; // увеличиваем количество перестановок
            }
            (*c)++; // увеличиваем количество сравнений
        }
    }
}

//функция заполнения массива рандомными числами
void arrayrandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 501;
    }
}

//функция сортировки массива по возрастанию
void arraysortedhigh(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

//функция сортировки массива по убыванию
void arraysortedlow(int arr[], int n) {
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        arr[j] = i;
        j++;
    }
}

int main() {
    int m = 0; // количество перестановок
    int c = 0; // количество сравнений
    int size = 100; // размер массива

    // рандомные числа
    for (size = 100; size <= 500; size += 100) {
        int* arr = malloc(size * sizeof(int));
        arrayrandom(arr, size);
        bubblesort(arr, size, &c, &m);
        printf("массив из %d элементов:\n", size);
        printf("количество c: %d\n", c);
        printf("количество m: %d\n", m);
        printf("сумма m+c: %d\n\n", m + c);
        free(arr);
        c = 0;
        m = 0;
    }

    // по возрастанию
    for (size = 100; size <= 500; size += 100) {
        int* arr = malloc(size * sizeof(int));
        arraysortedhigh(arr, size);
        bubblesort(arr, size, &c, &m);
        printf("массив из %d элементов (отсортирован по возрастанию):\n", size);
        printf("количество c: %d\n", c);
        printf("количество m: %d\n", m);
        printf("сумма m+c: %d\n\n", m + c);
        free(arr);
        c = 0;
        m = 0;
    }

    // по убыванию
    for (size = 100; size <= 500; size += 100) {
        int* arr = malloc(size * sizeof(int));
        arraysortedlow(arr, size);
        bubblesort(arr, size, &c, &m);
        printf("массив из %d элементов (отсортирован по убыванию):\n", size);
        printf("количество c: %d\n", c);
        printf("количество m: %d\n", m);
        printf("сумма m+c: %d\n\n", m + c);
        free(arr);
        c = 0;
        m = 0;
    }
    
    return 0;
}
