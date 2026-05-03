#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicketSystem {
private:
    const int CAPACITY = 100;

    // movieId -> set of customerIds
    unordered_map<int, unordered_set<int>> bookings;

public:

    // BOOK X Y
    bool book(int customerId, int movieId) {
        
        // Already booked
        if (bookings[movieId].find(customerId) != bookings[movieId].end()) {
            return false;
        }

        // Movie sold out
        if (bookings[movieId].size() >= CAPACITY) {
            return false;
        }

        bookings[movieId].insert(customerId);
        return true;
    }

    // CANCEL X Y
    bool cancel(int customerId, int movieId) {
        
        // Customer has not booked
        if (bookings[movieId].find(customerId) == bookings[movieId].end()) {
            return false;
        }

        bookings[movieId].erase(customerId);
        return true;
    }

    // IS_BOOKED X Y
    bool isBooked(int customerId, int movieId) {
        return bookings[movieId].find(customerId) != bookings[movieId].end();
    }

    // AVAILABLE_TICKETS Y
    int availableTickets(int movieId) {
        return CAPACITY - bookings[movieId].size();
    }
};

int main() {
    MovieTicketSystem system;

    cout << system.book(101, 1) << endl;              // 1 (true)
    cout << system.book(101, 1) << endl;              // 0 (false)
    
    cout << system.isBooked(101, 1) << endl;          // 1
    
    cout << system.availableTickets(1) << endl;       // 99
    
    cout << system.cancel(101, 1) << endl;            // 1
    
    cout << system.isBooked(101, 1) << endl;          // 0
    
    cout << system.availableTickets(1) << endl;       // 100

    return 0;
}
