This is a console-based C++ project that simulates a simple flight reservation system using Object-Oriented Programming (OOP) principles.

Key Features
Flight Creation: Each flight is initialized with a flight number, destination, departure time, and seating capacity.

Passenger Management:

Add passengers by ID, name, and seat number.

Remove or search for passengers by name.

Seat Management:

Check seat availability.

Expand the flight with additional seats using operator overloading.

Decrease seating capacity by removing unused seats.

Operator Overloading:

+= to add passengers.

++ to increase seating capacity.

-- to shift passengers.

-= to remove seats.

Visual Output:

Displays flight and passenger details.

Diagrammatic output for booked/unbooked seats.

OOP Concepts Used
Classes & Objects: Flight and Passenger classes encapsulate all data and logic.

Encapsulation: Data members are private or protected with appropriate getters/setters.

Dynamic Memory Allocation: Used for seat arrangement and passenger arrays.

Operator Overloading: For intuitive operations on flights.

Deep Copy Constructor: Ensures proper copying of dynamically allocated memory.
