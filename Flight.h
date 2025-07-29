#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;

class Flight {
private:
    int flight_nom;
    string destination;
    float departure_time;
    int seating_capacity;
    static int booked_seats;
    string* n_list;
    bool** seats;
    Passenger* arr;
    int rows = 10;

public:
    Flight();
    Flight(int nom, string dest, int capacity);
    Flight(const Flight& fl);

    void simplify_seatno(int n);
    void Add_pass(int nomber);
    bool const Search_passenger(string namee);
    bool search_seat(int seat);
    void set_dep_time(float time);
    void Display() const;

    Flight& operator++();
    Flight operator+=(Passenger const& pass);
    Flight operator--();
    Flight operator-=(int n);

    void Remove_passenger(Passenger const& pass);

    friend ostream& operator<<(ostream& out, const Flight& flight);

    ~Flight();
};

#endif // FLIGHT_H