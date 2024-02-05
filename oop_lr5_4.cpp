#include <iostream>
#include <map>
#include <string>
#include <conio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Створення словника для зберігання середніх балів студентів
    map<string, double> studentGrades;

    // Створення словника для зберігання журналу пошукових запитів користувача
    map<string, double> browsingHistory;

    // Додавання даних до словника
    studentGrades["Anna"] = 4.5;
    studentGrades["Boris"] = 3.8;
    studentGrades["Katerina"] = 4.2;
    studentGrades["Dmitro"] = 4.0;

    // Вивід даних про студентів
    cout << "Інформація про студентів:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }

    // Пошук і вивід середнього балу для певного студента (користувач сам вводить ім'я студента), поки користувач не натисне Esc
    char choice;
    string searchStudent;
    do {
        cout << "\nВведіть ім'я студента для пошуку середнього балу: ";
        cin >> searchStudent;

        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "Середній бал студента " << searchStudent << ": " << it->second << endl;
            browsingHistory[searchStudent] = it->second;
        }
        else {
            cout << "Студент з іменем " << searchStudent << " не знайдений." << endl; // Якщо такого студента немає
            browsingHistory[searchStudent] = -1.0;  // Негативний бал для незнайдених студентів
        }
        choice = _getch();
    } while (choice != 27);

    // Вивід журналу пошукових запитів користувача
    cout << "\nЖурнал пошукових запитів користувача:" << endl;
    for (const auto& history : browsingHistory) {
        if (history.second == -1.0)
        {
            cout << history.first << ": " << "cтудент з іменем " << history.first << " не знайдений." << endl;
        }
        else
        {
            cout << history.first << ": " << history.second << endl;
        }
    }

    return 0;
}
