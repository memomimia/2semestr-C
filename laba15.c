#include <stdio.h>
#include <string.h>

typedef struct{//Стуктура из 3 полей ФИО,знак зодиака и день рождение из 3 символов
    char fio[30];
    char zodiak[15];
    int birthday[3];
} person;

int main(){
    FILE *file = fopen("znak.dat", "w");
    
    if (file == NULL){
        printf("не удалось открыть файл.\n");
        return 1;
    }
    
    person people[10]= {//Заполнение нашей структуры данными о 10 людях
        {"первушина у.й.", "близнецы", {12, 4, 2000}},
        {"заельцова а.х.", "рыбы", {13, 12, 1995}},
        {"чуванов и.и.", "телец", {1, 4, 1980}},
        {"леший п.с.", "рак", {19, 9, 1950}},
        {"юбаева и.в", "дева", {8, 8, 1994}},
        {"поручкин е.у.", "козерог", {13, 2, 1988}},
        {"шалунчик е.с.", "лев", {22, 8, 2008}},
        {"горяев с.и.", "овен", {11, 4, 1998}},
        {"паручкин н.е.", "весы", {13, 10, 2004}},
        {"юлькин х.е.", "дева", {23, 5, 2005}}
    };

    for(int i = 0; i < 10; i++){
        fwrite(&people[i], sizeof(person), 1, file);//Функция fwrite() предназначена для записи в файл блоков данных,записываются данные из переменной с адресом &people[i], 1 элемент размером sizeof(person)
    }

    fclose(file);

    char found_zodiak[15];//Переменная знака зодиака который мы будем вводить для поиска людей
    printf("введите знак зодиака из перечисленных (овен, телец, близнецы, рак, лев, дева, весы, скорпион, стрелец, козерог, водолей, рыбы): ");
    scanf("%s", found_zodiak);

    file = fopen("znak.dat", "r");
    
    if (file == NULL){
        printf("не удалось открыть файл.\n");
        return 1;
    }

    person current_person;
    int found = 0;//Переменная для найденного человека

    while(fread(&current_person, sizeof(person), 1, file)){//Функция fread() предназначена для чтения блоков данных из потока
        if(strcmp(current_person.zodiak, found_zodiak) == 0){// strcmp функция для сравнения символов из 2 строк
            printf("фамилия и инициалы: %s\n", current_person.fio);
            printf("день рождения: %d.%d.%d\n", current_person.birthday[0], current_person.birthday[1], current_person.birthday[2]);
            found = 1;
        }
    }

    if (!found){// ! логическое отрицание, т.е  "если не найдено"
        printf("нет людей с таким знаком зодиака: %s\n", found_zodiak);
    }

    fclose(file);

    return 0;
}
