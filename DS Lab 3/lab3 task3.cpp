#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    string name;
    Passenger* next;
    Passenger(string n) : name(n), next(nullptr) {}
};

class Flight {
private:
    Passenger* head;

public:
    Flight() : head(nullptr) {}

    //Reserve a ticket
    void reserveTicket(string name) {
        Passenger* newPassenger = new Passenger(name);

        //insert at beginning
        if (!head || name < head->name) {
            newPassenger->next = head;
            head = newPassenger;
            cout << name << " reserved successfully.\n";
            return;
        }

        //Find  position
        Passenger* temp = head;
        while (temp->next && temp->next->name < name) {
            temp = temp->next;
        }

        //check for duplicates
        if (temp->name == name || (temp->next && temp->next->name == name)) {
            cout << "Error: " << name << " already has a reservation.\n";
            delete newPassenger;
            return;
        }

        newPassenger->next = temp->next;
        temp->next = newPassenger;
        cout << name << " reserved successfully.\n";
    }

    //Cancel reservation
    void cancelReservation(string name) {
        if (!head) {
            cout << "No reservations found.\n";
            return;
        }

        if (head->name == name) {
            Passenger* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << name << "'s reservation cancelled.\n";
            return;
        }

        Passenger* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Error: No reservation found for " << name << ".\n";
            return;
        }

        Passenger* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << name << "'s reservation cancelled.\n";
    }

    //Check reservation
    void checkReservation(string name) {
        Passenger* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << name << " has a reservation.\n";
                return;
            }
            temp = temp->next;
        }
        cout << name << " does not have a reservation.\n";
    }

    //Display passengers
    void displayPassengers() {
        if (!head) {
            cout << "No passengers reserved.\n";
            return;
        }
        cout << "Passenger List:\n";
        Passenger* temp = head;
        while (temp) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Flight flight;
    int choice;
    string name;

    do {
        cout << "\n--- Airline Ticket Reservation Menu ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.reserveTicket(name);
            break;
        case 2:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.cancelReservation(name);
            break;
        case 3:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.checkReservation(name);
            break;
        case 4:
            flight.displayPassengers();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
