#include <iostream>
#include "Flight.h"
#include "Passenger.h"
using namespace std;
int main() {
    Flight flight1(123, "New York", 30);
    flight1.set_dep_time(15.3);

    int num_ofPassengers;
    cout << "Enter the number of passengers to add to flight: " << endl;
    cin >> num_ofPassengers;

    for (int i = 0; i < num_ofPassengers; i++) {
        cout << "Enter details for passenger " << (i + 1) << endl;
        int id, seatno;
        string pass_name;

        cout << "Enter passenger's name " << endl;
        getline(cin, pass_name);

        cout << "Enter passenger's ID " << endl;
        cin >> id;

        cout << "Enter passenger's seat number " << endl;
        cin >> seatno;

        Passenger passenger(id, pass_name, seatno);
        flight1 += passenger;
    }
    cout << "************************************" << endl;
    cout << "Flight Information and passenger Details on it:"<<endl;
    cout << flight1 << endl;
    cout << "*********************************" << endl;
    string passenger_name_to_search;
    cout << "Enter a passenger name to search about him  " << endl;
    getline(cin, passenger_name_to_search);
    if (flight1.Search_passenger(passenger_name_to_search)) {
        cout << "Passenger " << passenger_name_to_search << " found on flight." << endl;
    }
    else {
        cout << "Passenger " << passenger_name_to_search << " not found" << endl;
    }

    int checked_seat;
    cout << "Enter a seat number to check availability: " << endl;
    cin >> checked_seat;
    if (flight1.search_seat(checked_seat)) {
        cout << "Seat " << checked_seat << " is available." << endl;
    }
    else {
        cout << "Seat " << checked_seat << " is already booked."<<endl;
    }
    cout << "************************************" << endl;
    ++flight1;//adding seats to flight

    cout << "Flight Information after expanding seats : "<<endl;
    cout << flight1 << endl;
    cout << "************************************" << endl;

    flight1 -= 5;//removing 5 seats;

    cout << "Final Flight Information:" << endl;;
    cout << flight1 << endl;
    return 0;
}
