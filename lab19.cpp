#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Apartment {
    int rooms;//Комнаты
    double area;//Площадь квартиры
    string address;//Адрес квартиры
    string repair_request_date;//Дата подачи заявления
    string repair_end_date;//Дата окончания ремонта
};

vector<Apartment> apartments;
vector<Apartment> repaired;

void addapartment() {//Функция заполнения данных для заявки
    Apartment newapartment;
    cout << "введите количество комнат: ";
    cin >> newapartment.rooms;
    cout << "введите площадь: ";
    cin >> newapartment.area;
    cout << "введите адрес: ";
    cin.ignore(); 
    getline(cin, newapartment.address);
    cout << "введите дату подачи заявления на ремонт: ";
    cin >> newapartment.repair_request_date;
    apartments.push_back(newapartment);
}

void repairapartment() {//Функция заполнения данных о ремонте
    int num;
    cout << "введите индекс квартиры для ремонта: ";
    cin >> num;
    if (num < 0 || num >= apartments.size()) {
        cout << "Неверный индекс. Попробуйте еще раз." << endl;
        return;
    }
    cout << "введите дату окончания ремонта: ";
    cin >> apartments[num].repair_end_date;
    repaired.push_back(apartments[num]);
    apartments.erase(apartments.begin() + num);//Удаление элемента из вектора 
    sort(repaired.begin(), repaired.end(), [](Apartment a, Apartment b) {return a.repair_end_date < b.repair_end_date; });
}

void printapartments(vector<Apartment> &apts) {//Функция вывода сведений о заявках
    for (int i = 0; i < apts.size(); i++) {
        cout << "Квартира " << i << ":" << endl;
        cout <<" Количество комнат: "  << apts[i].rooms << endl;
        cout << "Площадь,м2: " << apts[i].area << endl;
        cout << "Адрес: " << apts[i].address << endl;
        cout << "Дата подачи заявления на ремонт: " << apts[i].repair_request_date << endl;
        cout << "Дата окончания ремонта: " << apts[i].repair_end_date << endl;
        cout << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Добавить заявку на ремонт \n2. Ремонт квартиры\n3. Показать все заявки\n4. Показать отремонтированные квартиры\n5. Выход\nвыберите действие: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addapartment();//Выполняется функция для добавления заявки на ремонт
                break;
            case 2:
                repairapartment();//Выполянется функция для заполнения данных о ремонте
                break;
            case 3:
                printapartments(apartments);//Выполняется функция вывода сведений о заявках
                break;
            case 4:
                printapartments(repaired);//Выполняется функция вывода сведений о ремонте
                break;
            case 5:
                return 0;//Происходит выход из программы
        }
    }
    return 0;
}
