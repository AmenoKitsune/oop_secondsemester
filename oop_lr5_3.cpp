#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        cout << "\n����: " << text << endl;
        cout << "������: " << fixed << setprecision(2) << getAverageRating() << " (������: " << votes << ")" << endl;
    }

    void rateJoke(int rating, int& numUsers) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
            cout << "���������� ������ ����: " << rating;
        }
        else {
            cout << "������ ������� ���� �� 1 �� 5!" << endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    string text;
    int votes;
    int totalRating;
};

int main() {
    setlocale(LC_ALL, "ru");
    list<Joke> jokeList;

    // ��������� ����� �� ������
    jokeList.push_back(Joke("���� ���������� ��� ������ ������?\n���� �� ���� ����� ������ �� ����!"));
    jokeList.push_back(Joke("�� ������ ��������� ���� �����������?\n���������� �� ����� ����������!"));
    jokeList.push_back(Joke("�������� � �� �����. ����� ��������, �����: ���� �����!� ������� � ���� ����������� � �� ������, �� �� ������ ����� ����� �����."));

    cout << "������� ������� �� �������� ��� ���������� �����!" << endl;

    int numUsers;
    cout << "������ ������� ������������: ";
    cin >> numUsers;

    // ���������� �����
    for (int i = 1; i <= numUsers; i++)
    {
        cout << "\n���������� " << i << ":" << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();
            cout << endl;
            int userRating;
            cout << "������ (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating, numUsers);
            cout << endl;
        }
    }

    cout << "\n\n����� � ������� ���������:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}
