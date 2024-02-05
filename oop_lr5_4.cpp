#include <iostream>
#include <map>
#include <string>
#include <conio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // ��������� �������� ��� ��������� ������� ���� ��������
    map<string, double> studentGrades;

    // ��������� �������� ��� ��������� ������� ��������� ������ �����������
    map<string, double> browsingHistory;

    // ��������� ����� �� ��������
    studentGrades["Anna"] = 4.5;
    studentGrades["Boris"] = 3.8;
    studentGrades["Katerina"] = 4.2;
    studentGrades["Dmitro"] = 4.0;

    // ���� ����� ��� ��������
    cout << "���������� ��� ��������:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << endl;
    }

    // ����� � ���� ���������� ���� ��� ������� �������� (���������� ��� ������� ��'� ��������), ���� ���������� �� ������� Esc
    char choice;
    string searchStudent;
    do {
        cout << "\n������ ��'� �������� ��� ������ ���������� ����: ";
        cin >> searchStudent;

        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            cout << "������� ��� �������� " << searchStudent << ": " << it->second << endl;
            browsingHistory[searchStudent] = it->second;
        }
        else {
            cout << "������� � ������ " << searchStudent << " �� ���������." << endl; // ���� ������ �������� ����
            browsingHistory[searchStudent] = -1.0;  // ���������� ��� ��� ����������� ��������
        }
        choice = _getch();
    } while (choice != 27);

    // ���� ������� ��������� ������ �����������
    cout << "\n������ ��������� ������ �����������:" << endl;
    for (const auto& history : browsingHistory) {
        if (history.second == -1.0)
        {
            cout << history.first << ": " << "c������ � ������ " << history.first << " �� ���������." << endl;
        }
        else
        {
            cout << history.first << ": " << history.second << endl;
        }
    }

    return 0;
}
