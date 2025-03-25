// Syed Haris Hussain Shah
// L1F23BSCS0697
#include <iostream>
using namespace std;

// abstract base class 
class LibraryItem {
protected:
    string title;
public:
    LibraryItem(string t) : title(t) {}
    // Pure virtual function 
    virtual void display() const = 0;  
    string getTitle() const { return title; }

};

// derived book class 
class Book : public LibraryItem {
private:
    string author;
    int pages;
public:
    // Default constructor
    Book() : LibraryItem(""), author(""), pages(0) {} 
    Book(string t, string a, int p) : LibraryItem(t), author(a), pages(p) {}

    void display() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    int getPages() const { return pages; }
};

// derived Newspaper class 
class Newspaper : public LibraryItem {
private:
    string date;
    int edition;
public:
    Newspaper() : LibraryItem(""), date(""), edition(0) {} // Default constructor
    Newspaper(string t, string d, int e) : LibraryItem(t), date(d), edition(e) {}

    void display() const override {
        cout << "Newspaper Name: " << title << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    int getEdition() const { return edition; }
};

// Library Class
class Library {
private:
    // Maximum capacity for books and newspapers
    static const int maxSize = 20; 
    Book books[maxSize];
    Newspaper newspapers[maxSize];
    int bookCount;
    int newspaperCount;

public:
    Library() : bookCount(0), newspaperCount(0) {}
   
    void addBook(const Book& book) {
        if (bookCount < maxSize) {
            books[bookCount++] = book;
        }
        else {
            cout << "Book storage is full" << endl;
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (newspaperCount < maxSize) {
            newspapers[newspaperCount++] = newspaper;
        }
        else {
            cout << "Newspaper storage is full " << endl;
        }
    }

    void displayCollection() const {
        cout << "Books Collection: " << endl;
        for (int i = 0; i < bookCount; i++) 
        {
            books[i].display();
        }    
        cout << "Newspapers Collection: " << endl;
        for (int i = 0; i < newspaperCount; i++) 
        {
            newspapers[i].display();
        }
          
    }

    // Sorting books by pages using Bubble Sort
    void sortBooksByPages() {

        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {

                if (books[j].getPages() > books[j + 1].getPages()) {

                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    // Sorting newspapers by edition using Bubble Sort
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {

            for (int j = 0; j < newspaperCount - i - 1; j++) {

                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {

                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    // Searching for a book by title using Linear Search
    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title)
            {
                return &books[i];
            }
        }
        return nullptr;
    }

    // Searching for a newspaper by name using Linear Search
    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getTitle() == name)
            {
                return &newspapers[i];
            }
        }
        return nullptr;
    }
};

// Main Function
int main() {
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", 11);
    Newspaper newspaper2("The Times", "2024-10-12", 14);

    
    Library library;

    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display the entire collection before sorting
    cout << "Before Sorting: " << endl;
    library.displayCollection();

    // Sort books by pages and newspapers by edition
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << " After Sorting: " << endl;;
    library.displayCollection();

    // Search for a book by title
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << " Found Book: " << endl ;
        foundBook->display();
    }
    else {
        cout << "Book not found! " << endl;
    }

    // Search for a newspaper by name
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << " Found Newspaper: "<<endl;
        foundNewspaper->display();
    }
    else {
        cout << "Newspaper not found." << endl;
    }

    return 0;
}