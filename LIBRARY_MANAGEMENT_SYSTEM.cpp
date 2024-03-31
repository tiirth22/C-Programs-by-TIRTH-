/*This GitHub code has been crafted by TIRTH JIGNESHKUMAR DALAL from CHARUSAT UNIVERSITY with a focus on simplifying and streamlining processes. 
It offers a user-friendly approach to solving problems, ensuring accessibility and ease of use for all stakeholders. 
The code demonstrates a commitment to clarity and efficiency, providing intuitive solutions to complex challenges. 
With clear documentation and concise implementation, this code fosters collaboration and empowers users to navigate and contribute effectively. 
It reflects a dedication to enhancing the developer experience and fostering a welcoming environment for innovation and growth.*/


#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool available; // used for, if book is available or not in the form of true or false

public:
    Book(string t, string a) : title(t), author(a), available(true) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book \"" << title << "\" borrowed successfully." << endl;
        } else {
            cout << "Sorry, this book is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book \"" << title << "\" returned successfully." << endl;
        } else {
            cout << "This book is already in the library." << endl;
        }
    }
};

class Library {
private:
    Book* books[15]; // Array of pointers to books

public:
    Library() {
        // Initialize 15 books
books[0] = new Book("  (0. )    Ramayana ", " Valmiki ");
books[1] = new Book("  (1. )    Mahabharata ", " Vyasa ");
books[2] = new Book("  (2. )    Bhagavad Gita ", " Vyasa ");
books[3] = new Book("  (3. )    Mudrarakshasa ", " Vishakhadatta ");
books[4] = new Book("  (4. )    Rajtarangini ", " Kalhana ");
books[5] = new Book("  (5. )    Kathasaritsagar ", " Somadeva ");
books[6] = new Book("  (6. )    Srimad Bhagavatam ", " Vyasa ");
books[7] = new Book("  (7. )    Panchatantra ", " Vishnu Sharma ");
books[8] = new Book("  (8. )    Arthashastra ", " Chanakya ");
books[9] = new Book("  (9. )    Kamasutra ", " Vatsyayana ");
books[10] = new Book(" (10.)    Nitisara ", " Kamandaka ");
books[11] = new Book(" (11.)    Panchsidhantika ", " Varahamihira ");
books[12] = new Book(" (12.)    Shiva Purana ", " Vyasa ");
books[13] = new Book(" (13.)    Abhigyan Shakuntalam ", " Kalidasa ");
books[14] = new Book(" (14.)    Surya Sidhanta ", " AryaBhatta ");

// BOOK number given as the array indexing

        // for displaying the books
        for (int i = 15; i < 15; ++i) {
            books[i] = nullptr;
        }
    }

    /*~Library() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < 15; ++i) {
            delete books[i];
        }
    }*/

    void displayBooks() const {
        cout << "Available Books:" << endl;
        for (int i = 0; i < 15; ++i) {
            if (books[i] != nullptr && books[i]->isAvailable()) {
                cout << books[i]->getTitle() << " by " << books[i]->getAuthor() << endl;
            }
        }
    }

    void borrowBook(int bookIndex) {
        if (bookIndex >= 0 && bookIndex < 15 && books[bookIndex] != nullptr) {
            books[bookIndex]->borrowBook();
        } else {
            cout << "Invalid book index." << endl;
        }
    }

    void returnBook(int bookIndex) {
        if (bookIndex >= 0 && bookIndex < 15 && books[bookIndex] != nullptr) {
            books[bookIndex]->returnBook();
        } else {
            cout << "Invalid book index." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    int bookIndex;

    do {
        cout << "\nVedic Library, Vadodara\n";
        cout << "1. Display Available Books\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                cout << "Enter the index of the book you want to borrow: ";
                cin >> bookIndex;
                library.borrowBook(bookIndex);
                break;
            case 3:
                cout << "Enter the index of the book you want to return: ";
                cin >> bookIndex;
                library.returnBook(bookIndex);
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
