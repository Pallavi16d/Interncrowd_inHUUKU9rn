#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movie {
    string title;
    int duration;
    int price;
};

class Booking {
public:
    Booking(Movie m, int n, string c): movie(m), numTickets(n), customer(c) {}
    Movie movie;
    int numTickets;
    string customer;
};

class TicketBookingSystem {
public:
    void addMovie(Movie m) {
        movies.push_back(m);
    }

    void bookTicket() {
        string movieTitle, customer;
        int numTickets;
        cout << "Enter movie title: ";
        cin >> movieTitle;
        cout << "Enter number of tickets: ";
        cin >> numTickets;
        cout << "Enter customer name: ";
        cin >> customer;

        for (int i = 0; i < movies.size(); i++) {
            if (movies[i].title == movieTitle) {
                bookings.push_back(Booking(movies[i], numTickets, customer));
                cout << numTickets << " ticket(s) booked for " << customer << " for " << movies[i].title << endl;
                return;
            }
        }
        cout << "Movie not found" << endl;
    }

    void cancelTicket() {
        string movieTitle, customer;
        int numTickets;
        cout << "Enter movie title: ";
        cin >> movieTitle;
        cout << "Enter number of tickets: ";
        cin >> numTickets;
        cout << "Enter customer name: ";
        cin >> customer;

        for (int i = 0; i < bookings.size(); i++) {
            if (bookings[i].movie.title == movieTitle && bookings[i].numTickets == numTickets && bookings[i].customer == customer) {
                bookings.erase(bookings.begin() + i);
                cout << numTickets << " ticket(s) cancelled for " << customer << " for " << movieTitle << endl;
                return;
            }
        }
        cout << "Booking not found" << endl;
    }

    void showBookings() {
        for (int i = 0; i < bookings.size(); i++) {
            cout << "Movie: " << bookings[i].movie.title << ", Duration: " << bookings[i].movie.duration << " mins, Price: " << bookings[i].movie.price << endl;
            cout << "Number of tickets: " << bookings[i].numTickets << ", Customer: " << bookings[i].customer << endl << endl;
        }
    }

private:
    vector<Movie> movies;
    vector<Booking> bookings;
};

int main() {
    TicketBookingSystem tbs;

    // Add some movies
    tbs.addMovie({"Avatar", 136, 10});
    tbs.addMovie({"Avengers", 148, 12});
    tbs.addMovie({"Forest gump", 169, 15});

    // Main loop
    int choice;
    do {
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Show Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tbs.bookTicket();
                break;
            case 2:
                tbs.cancelTicket();
                break;
            case 3:
                tbs.showBookings();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4);
}

