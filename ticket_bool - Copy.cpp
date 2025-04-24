#include <iostream>
#include <string>
using namespace std;

class BookBus {
private:
    string From_city;
    string To_city;
    int No_of_tickets;
    static int ticket_available;

public:
    BookBus(string s = "Source", string d = "Destination", int n = 1) {
        From_city = s;
        To_city = d;
        No_of_tickets = n;
    }

    void showBookings() {
        try {
            if (No_of_tickets <= 0) {
                throw ("Number of tickets must be greater than 0.");
            }

            if (No_of_tickets <= ticket_available) {
                cout << From_city << " -> " << To_city << " : " << No_of_tickets << " ticket(s)" << endl;
                ticket_available -= No_of_tickets;
                cout << "Tickets remaining: " << ticket_available << endl;
            } else {
                throw ("Not enough tickets available!");
            }
        }
        catch (const exception &e) {
            cout << "Exception: " << e.what() << endl;
        }
    }
};

int BookBus::ticket_available = 35;

int main() {
    BookBus b1("Kolhapur", "Pune", 3);
    b1.showBookings();

    BookBus b2("Mumbai", "Bangalore", 40);
    b2.showBookings();

    return 0;
}

