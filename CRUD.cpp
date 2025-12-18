#include <iostream>
using namespace std;

int main() {
    int bookingID[10], seatNo[10];
    string name[10], busNo[10];
    float fare[10];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Booking Menu ---\n";
        cout << "1. Add Booking\n";
        cout << "2. Show All Bookings\n";
        cout << "3. Update Booking\n";
        cout << "4. Delete Booking\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // CREATE
        if (choice == 1) {
            if (count < 10) {
                cout << "Enter Booking ID: ";
                cin >> bookingID[count];
                cout << "Enter Customer Name: ";
                cin >> name[count];
                cout << "Enter Bus Number: ";
                cin >> busNo[count];
                cout << "Enter Seat Number: ";
                cin >> seatNo[count];
                cout << "Enter Fare: ";
                cin >> fare[count];

                count++;
                cout << "\nBooking Added.\n";
            } else {
                cout << "No more space.\n";
            }
        }

        // READ
        else if (choice == 2) {
            if (count == 0) {
                cout << "No bookings added yet.\n";
            } else {
                cout << "\n--- All Bookings ---\n";
                for (int i = 0; i < count; i++) {
                    cout << "ID: " << bookingID[i]
                         << " | Name: " << name[i]
                         << " | Bus: " << busNo[i]
                         << " | Seat: " << seatNo[i]
                         << " | Fare: " << fare[i] << endl;
                }
            }
        }

        // UPDATE
        else if (choice == 3) {
            int id, found = -1;
            cout << "Enter Booking ID to update: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (bookingID[i] == id) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                cout << "Enter new Customer Name: ";
                cin >> name[found];
                cout << "Enter new Bus Number: ";
                cin >> busNo[found];
                cout << "Enter new Seat Number: ";
                cin >> seatNo[found];
                cout << "Enter new Fare: ";
                cin >> fare[found];

                cout << "Booking Updated.\n";
            } else {
                cout << "Booking ID not found.\n";
            }
        }

        // DELETE
        else if (choice == 4) {
            int id, found = -1;
            cout << "Enter Booking ID to delete: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (bookingID[i] == id) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                // Shift elements left
                for (int i = found; i < count - 1; i++) {
                    bookingID[i] = bookingID[i + 1];
                    name[i] = name[i + 1];
                    busNo[i] = busNo[i + 1];
                    seatNo[i] = seatNo[i + 1];
                    fare[i] = fare[i + 1];
                }
                count--;
                cout << "Booking Deleted.\n";
            } else {
                cout << "Booking ID not found.\n";
            }
        }

    } while (choice != 5);

    return 0;
}