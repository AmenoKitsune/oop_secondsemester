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
        cout << "\nЖарт: " << text << endl;
        cout << "Оцінка: " << fixed << setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }

    void rateJoke(int rating, int& numUsers) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
            cout << "Користувач оцінив жарт: " << rating;
        }
        else {
            cout << "Оцінка повинна бути від 1 до 5!" << endl;
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

    // Додавання жартів до списку
    jokeList.push_back(Joke("Чому програмісти так погано сплять?\nТому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Що робить програміст після розставання?\nПереходить на інший репозиторій!"));
    jokeList.push_back(Joke("Інтернет – він такий. Читаєш коментарі, думаєш: “Одні ідіоти!” Починаєш з ними сперечатися й не помічаєш, як на одного ідіота стало більше."));

    cout << "Ласкаво просимо до програми для оцінювання жартів!" << endl;

    int numUsers;
    cout << "Введіть кількість користувачів: ";
    cin >> numUsers;

    // Оцінювання жартів
    for (int i = 1; i <= numUsers; i++)
    {
        cout << "\nКористувач " << i << ":" << endl;
        for (auto& joke : jokeList) {
            joke.tellJoke();
            cout << endl;
            int userRating;
            cout << "Оцінка (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating, numUsers);
            cout << endl;
        }
    }

    cout << "\n\nЖарти з високим рейтингом:" << endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}
