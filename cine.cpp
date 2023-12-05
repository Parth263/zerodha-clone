#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to store movie information
struct Movie {
    string title;
    int availableSeats;
    int showtime;
    // Add more attributes as needed
};

// Define a struct to store the seating arrangement
struct Seating {
    string seat;
    bool isAvailable;
    // Add more attributes as needed
};

int main() {
    // Create a vector of Movie objects
    vector<Movie> movies = {
        {"Movie 1", 100, 1},
        {"Movie 2", 120, 2},
        // Add more movies
    };

    // Create a vector of Seating objects to store the seating arrangement
    vector<Seating> seating;

    // Define the seating arrangement
    // For example, a 5x7 cinema hall
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            Seating seat;
            seat.seat = "A" + to_string(i) + "B" + to_string(j);
            seat.isAvailable = true;
            seating.push_back(seat);
        }
    }

    // Display the seating arrangement
    cout << "Available seats: " << endl;
    for (Seating seat : seating) {
        cout << seat.seat << " ";
    }
    cout << endl;

    // Allow the user to select a movie and showtime
    int movieIndex, showtimeIndex;
    cout << "Select a movie (1-" << movies.size() << "): ";
    cin >> movieIndex;
    cout << "Select a showtime (1-2): ";
    cin >> showtimeIndex;

    // Show the available seats for the selected movie and showtime
    // Show the available seats for the selected movie and showtime
for (int i = 0; i < seating.size(); i++) {
    if (seating[i].isAvailable) {
        cout << seating[i].seat << " ";
    }
}
cout << endl;
    

    // Allow the user to choose the number of tickets and the seating position
    int numTickets, seatRow, seatColumn;
    cout << "Enter the number of tickets: ";
    cin >> numTickets;
    cout << "Enter the seat row: ";
    cin >> seatRow;
    cout << "Enter the seat column: ";
    cin >> seatColumn;

    // Book the tickets and display a confirmation message
    for (int i = 0; i < numTickets; i++) {
        Seating selectedSeat = seating[seatRow * seating.size() + seatColumn - 1];
        if (selectedSeat.isAvailable) {
            selectedSeat.isAvailable = false;
            cout << "Ticket booked for seat " << selectedSeat.seat << endl;
        } else {
            cout << "Seat not available" << endl;
        }
    }

    return 0;
}