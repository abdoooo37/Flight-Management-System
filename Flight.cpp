#include "Flight.h"

int Flight::booked_seats = 0;

Flight::Flight() {
}

Flight::Flight(int nom, string dest, int capacity) {
    seating_capacity = capacity;
    flight_nom = nom;
    destination = dest;
    n_list = new string[seating_capacity];

    for (int l = 0; l < seating_capacity; l++) {
        n_list[l] = " ";
    }
    int columns = seating_capacity / 10;
    seats = new bool* [rows];

    for (int i = 0; i < rows; i++) {
        seats[i] = new bool[columns];
        for (int j = 0; j < columns; j++) {
            seats[i][j] = true;
        }
    }

    arr = new Passenger[seating_capacity];
}

Flight::Flight(const Flight& fl) {
    flight_nom = fl.flight_nom;
    destination = fl.destination;
    departure_time = fl.departure_time;
    seating_capacity = fl.seating_capacity;
    rows = fl.rows;

    n_list = new string[seating_capacity];
    arr = new Passenger[seating_capacity];
    seats = new bool* [rows];

    for (int i = 0; i < seating_capacity; ++i)
        n_list[i] = fl.n_list[i];

    for (int i = 0; i < seating_capacity; ++i)
        arr[i] = fl.arr[i];

    for (int i = 0; i < rows; ++i) {
        seats[i] = new bool[seating_capacity / rows];
        for (int j = 0; j < seating_capacity / rows; ++j) {
            seats[i][j] = fl.seats[i][j];
        }
    }

    booked_seats = fl.booked_seats;
}

void Flight::simplify_seatno(int n) {
    int r = 0;
    while (n > 3) {
        n -= 3;
        ++r;
    }
    r -= 1;
    seats[r][n] = false;
}

void Flight::Add_pass(int nomber) {
    if (nomber > seating_capacity) {
        seating_capacity += nomber;
    }

    for (int i = 0; i < nomber; i++) {
        cout << "Enter name, Id and seat number for passenger " << endl;
        int id, seatno;
        string name;
        getline(cin, name);
        cin >> id >> seatno;
        arr[i] = Passenger(id, name, seatno);
        n_list[i] = name;
        simplify_seatno(seatno);
    }
    booked_seats += nomber;
}


bool const Flight::Search_passenger(string namee) {
    bool found = 0;
    for (int j = 0; j < seating_capacity; j++) {
        if (namee == n_list[j]) {
            found = 1;
            break;
        }
    }
    return found;
}

bool Flight::search_seat(int seat) {
    bool empty = 1;
    int r = 0;
    while (seat > 3) {
        seat -= 3;
        ++r;
    }
    r -= 1;
    if (seats[r][seat] == 1)
        empty = 1;
    else
        empty = 0;
    return empty;
}

void Flight::set_dep_time(float time) {
    departure_time = time;
}

void Flight::Display() const {
    cout << "Flight number: " << flight_nom << endl;
    cout << "Destination: " << destination << endl;
    cout << "Departure time: " << departure_time << endl;
    cout << "**" << endl;

    for (int i = 0; i < arr->get_count(); i++) {
        cout << "Passenger " << i + 1 << ": " << n_list[i] << endl <<
            "ID:" << arr[i].get_Id() << endl << "Seat no: " << arr[i].get_seatno() << endl;
    }

    cout << "Diagram for booked and non-booked seats: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (seating_capacity / 10); j++) {
            cout << "R" << i + 1 << ": " << seats[i][j];
        }
        cout << endl;
    }
}

Flight& Flight::operator++() {
    int extraRows = rows + 1;
    bool** extraSeats = new bool* [extraRows];
    for (int i = 0; i < rows; i++) {
        extraSeats[i] = seats[i];
    }
    extraSeats[rows] = new bool[seating_capacity / extraRows];
    for (int j = 0; j < seating_capacity / extraRows; j++) {
        extraSeats[rows][j] = true;
    }
    delete[] seats;
    seats = extraSeats;
    rows++;
    seating_capacity += (seating_capacity / 10);
    return *this;
}

Flight Flight::operator+=(Passenger const& pass) {
    if (booked_seats < seating_capacity) {
        arr[booked_seats] = pass;
        n_list[booked_seats] = pass.get_name();
        booked_seats++;
        simplify_seatno(pass.get_seatno());
    }
    return *this;
}

Flight Flight::operator--() {
    for (int i = 0; i < seating_capacity; i++) {
        n_list[i] = n_list[i + 1];
        arr[i] = arr[i + 1];
}
    return *this;
}

Flight Flight::operator-=(int n) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n / rows; j++) {
            seats[i][j] = true;
        }
    }
    for (int l = 0; l < n; l++) {
        n_list[l] = " ";
    }
    booked_seats -= n;
    return *this;
}

void Flight::Remove_passenger(Passenger const& pass) {
    bool found = false;
    int x;
    for (int i = 0; i < seating_capacity; i++) {
        if (arr[i].get_name() == pass.get_name()) {
            found = 1;
            x = i;
            break;
        }
    }

    if (found == 1) {
        for (int j = x; j < booked_seats - 1; j++) {
            arr[j] = arr[j + 1];
            n_list[j] = n_list[j + 1];
        }
    }

    int r = 0;
    int n = pass.get_seatno();
    while (n > 3) {
        n -= 3;
        ++r;
    }
    r -= 1;
    seats[r][n] = true;
    booked_seats--;
}

ostream& operator<<(ostream& out, const Flight& flight) {
    flight.Display();
    return out;
}

Flight::~Flight() {
    delete[] n_list;
    delete[] arr;

    for (int i = 0; i < rows; ++i) {
        delete[] seats[i];
    }
    delete[] seats;
}