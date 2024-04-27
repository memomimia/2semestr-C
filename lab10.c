#include <stdio.h>
// функция для сортировки массива по убыванию
void sortarr(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// записываем в обратном порядке главную диагональ матрицы
void reversediag(int matrix[][3],int n){
    for (int i = 0; i < n / 2; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[n - 1 - i][n - 1 - i];
        matrix[n - 1 - i][n - 1 - i] = temp;
        }
    }
int main() {
    int matrix[3][3] = {{1, 5, 3},
                        {2, 4, 6},
                        {8, 0, -7}};
    int n = 3;
    int maxPer = 0;  // количество перестановок при упорядочивании
    int columnMaxPer = 0;  // номер столбца с наибольшим количеством перестановок
    int sumOfPositiveElements = 0;  // сумма положительных элементов
void sortColumns(int matrix[][n], int n) {// функция упорядочивания столбцов по убыванию
    for (int i = 0; i < n; i++) {
        int per = 0;  // количество перестановок в текущем столбце
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (matrix[k][i] < matrix[k + 1][i]) {
                    int temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                    per++; //Обновляем счётчик перестановок
                }
            }
        }
        if (per > maxPer) {// если текущий столбец имеет больше перестановок, обновляем значения
            maxPer = per;
            columnMaxPer = i;
        }
    }
}
sortColumns(matrix,3);//выводим сортированные столбцы по убыванию
// считаем сумму положительных элементов в столбце с наибольшим количеством перестановок
for (int i = 0; i < n; i++) {
    if (matrix[i][columnMaxPer] > 0) {
        sumOfPositiveElements += matrix[i][columnMaxPer];
    }
}
reversediag(matrix,3);//переворачиваем диагональ
printf("Матрица после упорядочивания столбцов и переворачивании диагонали:\n");//выводим результат после упорядочивания
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Сумма положительных элементов в столбце с наибольшим количеством перестановок: %d \n", sumOfPositiveElements);
    return 0;
}
