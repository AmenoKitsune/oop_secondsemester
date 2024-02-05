#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void Menu();
void inputFruits(vector<string>& favoriteFruits);
void sortedFruits(vector<string>& favoriteFruits);
void reverseSort(vector<string>& favoriteFruits);

int main() {
    setlocale(LC_ALL, "ru");

    vector<string> favoriteFruits;

    cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << endl;
    char choice;

    do {
        Menu();
        choice = _getch();
        system("cls");
        switch (choice) {
        case '1':
            inputFruits(favoriteFruits);
            break;
        case '2':
            sortedFruits(favoriteFruits);
            break;
        case '3':
            reverseSort(favoriteFruits);
            break;
        default:
            break;
        }
    } while (choice != 27);

    cout << "Гра завершена. Дякуємо за участь!" << endl;

    return 0;
}

void Menu() {
    cout << "\n1 - Введіть свої улюблені фрукти" << endl;
    cout << "2 - Ваші улюблені фрукти в алфавітному порядку" << endl;
    cout << "3 - Ваші улюблені фрукти проти алфавітного порядку" << endl;
    cout << "4 - Esc-вихід" << endl;
}

void inputFruits(vector<string>& favoriteFruits) {
    cout << "Введіть свої улюблені фрукти (введіть 'stop', щоб завершити введення):" << endl;
    string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;

        // Перевірка на вихід з гри
        if (fruit == "stop") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }
}
void sortedFruits(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());

    cout << "\nВаші улюблені фрукти в алфавітному порядку: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << endl << favoriteFruit;
    }
}
void reverseSort(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());
    reverse(favoriteFruits.begin(), favoriteFruits.end());
    cout << "\nВаші улюблені фрукти проти алфавітного порядку: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << endl << favoriteFruit;
    }
}
