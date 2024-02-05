#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Book {
public:
    Book(std::string title, std::string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() {
        std::cout << "Book: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }

    void setTitle(string newTitle) {
        title = newTitle;
    }
    void setAuthor(string newAuthor) {
        author = newAuthor;
    }
    void setYear(int newYear) {
        year = newYear;
    }
    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }

private:
    std::string title;
    std::string author;
    int year;
};

int main() {
    std::vector<Book> library;

    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.push_back(Book("1984", "George Orwell", 1949));
    library.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    std::cout << "Books information:" << std::endl;
    for (auto& book : library) {
        book.displayInfo();
    }

    bool flag = 1;
    do
    {

        int num;
        string title;
        string author;
        int year;
        cout << "Book to edit: ";
        cin >> num;
        cout << "Input title: ";
        cin >> title;
        cout << "Input author: ";
        cin >> author;
        cout << "Input year: ";
        cin >> year;
        library[num].setTitle(title);
        library[num].setAuthor(author);
        library[num].setYear(year);
        cout << "Books: " << endl;
        for (auto& book : library) {
            book.displayInfo();
        }
        cout << "Continue? (1) - yes, (0) - no: ";
        cin >> flag;
    } while (!flag);
    // Використовуємо std::sort для сортування за назвою книги
    std::sort(library.begin(), library.end());

    std::cout << "\nLibrary after sorting:" << std::endl;
    for (auto& book : library) {
        book.displayInfo();
    }

    return 0;
}
