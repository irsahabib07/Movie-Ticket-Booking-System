#include <iostream>
#include <vector>
using namespace std;
class Movie {
private:
    string title;
    vector<string> showtimes;
    int price;
    vector<vector<bool>> seats;

public:
		string getTitle;
    Movie(string _title, vector<string> _showtimes, int _price) 
        : title(_title), showtimes(_showtimes), price(_price) {
            seats = std::vector<std::vector<bool>>(10, std::vector<bool>(10, false)); // 10x10 seating arrangement
        }

    void displayShowtimes() {
        cout << "\nAvailable Showtimes of "<<title<<" are:"<< endl;
        for (size_t i = 0; i < showtimes.size(); ++i) {
            cout << i + 1 << ". " << showtimes[i] << endl;
        }
    }

    void displaySeats() {
        cout << "\nKindly check the availabe seats and booked it!" << endl;
        for (const auto& row : seats) {
            for (bool seat : row) {
                 cout << (seat ? 'O' : 'X') << ' ';
            }
            cout << endl;
        }
    }

    void bookTickets(int showtimeIndex, int numTickets) {
        if (showtimeIndex < 0 || showtimeIndex >= showtimes.size()) {
            cout << "Invalid time selection." << endl;
            return;
        }

        string selectedShowtime = showtimes[showtimeIndex];
        cout << "\nBooking tickets for '" << title << "' at " << selectedShowtime << endl;

        displaySeats();

        vector<std::pair<int, int>> bookedSeats;
        for (int i = 0; i < numTickets; ++i) {
            while (true) {
                int row, seat;
                cout << "\nSelect Row: ";
                cin >> row;
                cout << "Select Seat Number: ";
                cin >> seat;

                if (row >= 1 && row <= 10 && seat >= 1 && seat <= 10 && !seats[row - 1][seat - 1]) {
                    seats[row - 1][seat - 1] = true;
                    bookedSeats.emplace_back(row, seat);
                    break;
                } else {
                    cout << "\nOOps! Invalid seat selection, Seat already booked." << endl;
                }
            }
        }

        int totalCost = numTickets * price;
             cout << "\n*Booked Successfully!  \n\nYour Total Payment is: $" << totalCost << endl;
             cout << "\nYour seats are:" << std::endl;
        for (const auto& seat : bookedSeats) {
            cout << "Row " << seat.first << ", Seat " << seat.second << endl;
        }
        cout << "\t\t\t!!THANK YOU!!" << std::endl;
         cout << "If you want to book more, Do the same proccess or for exit enter 0!" << std::endl;
    }
};

int main() {

    vector<Movie> movies = {
        Movie("Avengers Endgame", {"12:00 PM", "3:00 PM", "6:00 PM"}, 10),
         Movie("Avengers Infinity War", {"11:30 AM", "2:30 PM", "5:30 PM"}, 8),
        Movie("Avengers Civil War", {"12:30 AM", "3:30 PM", "6:30 PM"}, 8),
         Movie("Black Widow", {"1:30 AM", "4:00 PM", "4:30 PM"}, 8),
          Movie("Multiverse of Madness", {"10:30 PM", "7:30 PM", "9:00 PM"}, 8)
    };

    cout << "\t\t~Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        cout << "\nSelect a movie:" << endl;
        for (size_t i = 1; i <= 1; ++i) {
            cout << "1. Avengers Endgame\n";
            cout << "2. Avengers Infinity War\n";
            cout << "3. Avengers Civil War\n";
            cout << "4. Black Widow\n";
            cout << "5. Multiverse of Madness\n";
        }

        int movieChoice;
        cout << "\nSelect the number of the movie or enter '0' to exit:";
        cin >> movieChoice;

        if (movieChoice >= 1 && movieChoice <= movies.size()) {
            Movie& selectedMovie = movies[movieChoice - 1];
            selectedMovie.displayShowtimes();

            int showtimeChoice;
            cout << "\nSelect the Showtime: ";
            cin >> showtimeChoice;

            int numTickets;
            cout << "\nHow many tickets you required?: ";
            cin >> numTickets;

            selectedMovie.bookTickets(showtimeChoice - 1, numTickets);
        } else if (movieChoice == 0) {
            cout << "\nExiting the booking system." << endl;
            break;
        } else {
            cout << "\nThis movie is not available" << endl;
        }
    }

    return 0;
}
