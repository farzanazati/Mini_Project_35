#ifndef LOGINREGISTERFORGOT_HPP
#define LOGINREGISTERFORGOT_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class LoginRegisterForgot {
public:
    void registerUser();
    void loginUser();
    void forgotPassword();
    void booking();
    void cancel();
private:
    const string databaseFile = "user_data.txt"; // File to store user data
    bool checkUserExists(const string& username, string& password);
};

class FlightReservationSystem {
private:
    vector<vector<bool>> seats;
    int rows;
    int cols;

public:
    FlightReservationSystem(int rows, int cols) : rows(rows), cols(cols) {
        seats.resize(rows, vector<bool>(cols, false));
    }

    void displaySeats() {
        cout << "\nSeat Map (O = Available, X = Booked):\n";
        cout << "       ";
        for (int c = 0; c < cols; ++c) {
            cout << setw(2) << c + 1 << " ";
        }
        cout << endl;

        for (int r = 0; r < rows; ++r) {
            cout << "Row " << setw(2) << r + 1 << " ";
            for (int c = 0; c < cols; ++c) {
                cout << (seats[r][c] ? " X " : " O ");
            }
            cout << endl;
        }
    }

    void bookSeats(vector<pair<int, int>> seatSelections) {
        bool allAvailable = true;

        for (const auto& seat : seatSelections) {
            int row = seat.first;
            int col = seat.second;

            if (row < 1 || row > rows || col < 1 || col > cols || seats[row - 1][col - 1]) {
                allAvailable = false;
                cout << "Seat (Row " << row << ", Col " << col << ") is either invalid or already booked.\n";
            }
        }

        if (allAvailable) {
            for (const auto& seat : seatSelections) {
                seats[seat.first - 1][seat.second - 1] = true;
            }
            cout << "All selected seats have been successfully booked!\n";
        } else {
            cout << "Some seats could not be booked. Please try again.\n";
        }
    }

    void cancelSeats(vector<pair<int, int>> seatSelections) {
        bool allBooked = true;

        for (const auto& seat : seatSelections) {
            int row = seat.first;
            int col = seat.second;

            if (row < 1 || row > rows || col < 1 || col > cols || !seats[row - 1][col - 1]) {
                allBooked = false;
                cout << "Seat (Row " << row << ", Col " << col << ") is either invalid or not booked yet.\n";
            }
        }

        if (allBooked) {
            for (const auto& seat : seatSelections) {
                int row = seat.first;
                int col = seat.second;
                seats[row - 1][col - 1] = false;  
            }
            cout << "Seats successfully canceled!\n";
        } else {
            cout << "One or more of your selected seats could not be canceled.\n";
        }
    }
};

#endif // LOGINREGISTERFORGOT_HPP
