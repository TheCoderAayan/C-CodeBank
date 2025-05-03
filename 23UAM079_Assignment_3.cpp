#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool isHardcover;
    float* chapterPages;
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        isHardcover = false;
        numChapters = 0;
        chapterPages = NULL;
    }

    // Parameterized Constructor
    Book(const char* bookTitle, const char* bookAuthor, int pages, bool hardcover, int chapters) {
        title = new char[strlen(bookTitle) + 1];
        strcpy(title, bookTitle);
        
        author = new char[strlen(bookAuthor) + 1];
        strcpy(author, bookAuthor);
        
        pageCount = pages;
        isHardcover = hardcover;
        numChapters = chapters;
        
        chapterPages = new float[numChapters];
        float avgPages = (numChapters > 0) ? (float)pageCount / numChapters : 0;
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = avgPages;
        }
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        
        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);
        
        pageCount = other.pageCount;
        isHardcover = other.isHardcover;
        numChapters = other.numChapters;
        
        if (numChapters > 0) {
            chapterPages = new float[numChapters];
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = other.chapterPages[i];
            }
        } else {
            chapterPages = NULL;
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Modify Chapter Pages
    void modifyChapterPages(int index, float newPageCount) {
        if (index >= 0 && index < numChapters) {
            chapterPages[index] = newPageCount;
        }
    }

    // Display Book Details
    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author;
        cout << "\nPages: " << pageCount << "\nFormat: " << (isHardcover ? "Hardcover" : "Paperback");
        cout << "\nChapters: " << numChapters << "\nChapter Pages: ";
        for (int i = 0; i < numChapters; i++) {
            cout << chapterPages[i] << " ";
        }
        cout << "\n-----------------------------\n";
    }
};

int main() {
    // Default Constructor Test
    Book book1;
    cout << "Book 1 (Default Constructor):\n";
    book1.display();
    
    // Parameterized Constructor Test
    Book book2("C++ Programming", "Bjarne Stroustrup", 500, true, 10);
    cout << "Book 2 (Parameterized Constructor):\n";
    book2.display();
    
    // Copy Constructor Test
    Book book3 = book2;
    cout << "Book 3 (Copy Constructor - Deep Copy of Book 2):\n";
    book3.display();
    
    return 0;
}

