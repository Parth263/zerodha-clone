#include <iostream>
#include <string>
#include <vector>

// Define a struct to store movie information
struct Movie {
    std::string title;
    int availableSeats;
    int showtime;
    // Add more attributes as needed
};

// Define a struct to store the seating arrangement
struct Seating {
    std::string seat;
    bool isAvailable;
    // Add more attributes as needed
};

int main() {
    // Create a vector of Movie objects
    std::vector<Movie> movies = {
        {"Tiger 3", 100, 1},
        {"Animal", 120, 2},
        {"Avatar 3", 80, 3},
        {"Demon slayer", 150, 4}
        // Add more movies
    };

    // Create a vector of Seating objects to store the seating arrangement
    std::vector<Seating> seating;

    // Define the seating arrangement
    // For example, a 5x7 cinema hall
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            Seating seat;
            seat.seat = "A" + std::to_string(i) + "B" + std::to_string(j);
            seat.isAvailable = true;
            seating.push_back(seat);
        }
    }

    // Display the choice of movies
    std::cout << "Available movies:" << std::endl;
    for (int i = 0; i < movies.size(); i++) {
        std::cout << i+1 << ". " << movies[i].title << std::endl;
    }

    // Allow the user to select a movie
    int choice;
    std::cout << "Select a movie (1-" << movies.size() << "): ";
    std::cin >> choice;

    // Show the seating availability for the selected movie
    std::cout << "Available seats for " << movies[choice-1].title << ": " << std::endl;
    for (Seating seat : seating) {
        if (seat.isAvailable) {
            std::cout << seat.seat << " ";
        }
    }
    std::cout << std::endl;

    // Allow the user to choose the number of tickets and the seating position
    int numTickets;
    std::string selectedSeat;
    std::cout << "Enter the number of tickets: ";
    std::cin >> numTickets;

    // Book the tickets and display a confirmation message
    for (int i = 0; i < numTickets; i++) {
        std::cout << "Enter the seat number for ticket " << i + 1 << ": ";
        std::cin >> selectedSeat;

        // Validate and book the ticket
        bool ticketBooked = false;
        for (Seating& seat : seating) {
            if (seat.seat == selectedSeat && seat.isAvailable) {
                seat.isAvailable = false; // Book the seat
                ticketBooked = true;
                break;
            }
        }

        // Display confirmation or error message
        if (ticketBooked) {
            std::cout << "Ticket " << i + 1 << " booked successfully for seat " << selectedSeat << std::endl;
        } else {
            std::cout << "Invalid seat selection. Please choose an available seat." << std::endl;
            i--; // Decrement i to re-enter the seat selection for the current ticket
        }
    }

    // Display a final confirmation message
    std::cout << "Tickets for " << movies[choice-1].title << " confirmed. Enjoy the movie!" << std::endl;

    return 0;
}
