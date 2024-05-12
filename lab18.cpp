#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class GroupSibguti {
public:
    string student;
    string group;

public:
    GroupSibguti(string namestudent, string groupsibguti) {
        student = namestudent;
        group = groupsibguti;
    }

    void outputTo() {
        cout << "Имя студента: " << student << endl;
        cout << "Номер группы: " << group << endl;
    }

    string get_student() const {
        return student;
    }

    string get_typesob() const {
        return group;
    }

    void set_student(string f) {
        student = f;
    }

    // Оператор для сортировки по  номеру группы
    bool operator<(const GroupSibguti& other) const {
        return student < other.student;
    }
};

int main() {
    // Создаем исходный вектор объектов ManagementOrganization
    vector<GroupSibguti> student_group;
    student_group.push_back(GroupSibguti("Мелентьев Владимир", "ИА332"));
    student_group.push_back(GroupSibguti("Алдакимов Кирилл", "ИА331"));
    student_group.push_back(GroupSibguti("Овчаров Ярослав", "ИА332"));
    student_group.push_back(GroupSibguti("Молостова Валерия", "ИА332"));
    student_group.push_back(GroupSibguti("Провкин Алексей", "ИА332"));
    student_group.push_back(GroupSibguti("Гмыря Ярослав", "ИА331"));
    student_group.push_back(GroupSibguti("Починкин Кирилл", "ИА332"));

    // Создаем новый вектор и переписываем в него объекты с номером группы "ИА332"
    vector<GroupSibguti> newStudentGroup;
    for ( int i=0;i<(int)student_group.size();i++) {
        if (student_group[i].group== "ИА332") {
            newStudentGroup.push_back(student_group[i]);
        }
    }

    // Проверяем, не оказался ли новый вектор пустым
    if (newStudentGroup.empty()) {
        cout << "Новый вектор пуст." << endl;
    } else {
        // Сортируем объекты в новом векторе по номеру группы
        sort(newStudentGroup.begin(), newStudentGroup.end());

        // Выводим отсортированные объекты
        cout << "Отсортированные объекты:" << endl;
         printf("\n");
        for (int i=0;i<(int)newStudentGroup.size();i++) {
            newStudentGroup[i].outputTo();
            printf("\n");
        }
    }

    return 0;
}
