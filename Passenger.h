
#include <iostream>
#include <string>
using namespace std;

class Passenger {
private:
    int Id;
    string name;
    int seat_nomber;
    static int passCount;

public:
    Passenger() ;
    Passenger(int i, string nam, int seatno);

    void Display() const;

    static int get_count();

    string get_name() const;
    int get_Id() const;
    int get_seatno() const;

    friend ostream& operator<<(ostream& out, const Passenger pass);
    Passenger(int id, const string& namee, int seatnomber)
    {
        
    }
};