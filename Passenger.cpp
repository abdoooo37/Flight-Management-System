#include "Passenger.h"

int Passenger::passCount = 0;
Passenger::Passenger(int iD, const string& namee, int seatnomber)
   
{
    {
        Id = iD;
        name = namee;
        seat_nomber = seat_nomber;
    }
}
Passenger::Passenger() {
    passCount++;
    Id = 0;
    name = "";
    seat_nomber = 0;
}

Passenger::Passenger(int i, string nam, int seatno) {
    Id = i;
    name = nam;
    seat_nomber = seatno;
    passCount++;
}

void Passenger::Display() const {
    cout << "Passenger's name: " << name << endl;
    cout << "Id: " << Id << endl;
    cout << " seat nomber: " << seat_nomber << endl;
    cout << "***" << endl;
}

 int Passenger::get_count() {
    return passCount;
}

string Passenger::get_name() const {
    return name;
}
int Passenger::get_Id() const {
    return Id;
}

int Passenger::get_seatno() const {
    return seat_nomber;
}

ostream& operator<<(ostream& out, const Passenger pass) {
    pass.Display();
    return out;
}


