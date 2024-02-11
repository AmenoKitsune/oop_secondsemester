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

    cout << "������� ������� �� ��� '���������� ������'!" << endl;
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

    cout << "��� ���������. ������ �� ������!" << endl;

    return 0;
}

void Menu() {
    cout << "\n1 - ������ ��� ������� ������" << endl;
    cout << "2 - ���� ������� ������ � ���������� �������" << endl;
    cout << "3 - ���� ������� ������ ����� ���������� �������" << endl;
    cout << "4 - Esc-�����" << endl;
}

void inputFruits(vector<string>& favoriteFruits) {
    cout << "������ ��� ������� ������ (������ 'stop', ��� ��������� ��������):" << endl;
    string fruit;
    while (true) {
        cout << "�����: ";
        cin >> fruit;

        // �������� �� ����� � ���
        if (fruit == "stop") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }
}
void sortedFruits(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());

    cout << "\n���� ������� ������ � ���������� �������: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << endl << favoriteFruit;
    }
}
void reverseSort(vector<string>& favoriteFruits) {
    sort(favoriteFruits.begin(), favoriteFruits.end());
    reverse(favoriteFruits.begin(), favoriteFruits.end());
    cout << "\n���� ������� ������ ����� ���������� �������: ";
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << endl << favoriteFruit;
    }
}
