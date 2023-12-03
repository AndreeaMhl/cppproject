#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class EventLocation {
private:
    int maxSeats;
    int zones;
    int noRows;
    int* seatsPerRow;

public:

    //Default Constructor
     
    EventLocation()
    {
        this->maxSeats = 0;
        this->zones = 0;
        this->noRows = 0;
        this->seatsPerRow = NULL;
    }

    //Constructor with all attributes
    EventLocation(int maxSeats, int zones, int noRows, int* seatsPerRow)
    {
        this->maxSeats = maxSeats;
        this->zones = zones;
        this->noRows = noRows;
        this->seatsPerRow = new int[noRows];
        for (int i = 0; i < noRows; i++)
        {
            this->seatsPerRow[i] = seatsPerRow[i];
        }
    }

    //Copy Constructor
    EventLocation(const EventLocation& obj)
    {
        this->maxSeats = obj.maxSeats;
        this->zones = obj.zones;
        this->noRows = obj.noRows;
        this->seatsPerRow = new int[obj.noRows];
        for (int i = 0; i < obj.noRows; i++)
        {
            this->seatsPerRow[i] = obj.seatsPerRow[i];
        }
    }

    //Destructor
    ~EventLocation()
    {
        delete[] seatsPerRow;
    }

    //Setters
    void setMaxSeats(int seats) {
        if (seats > 0)
        {
            maxSeats = seats;
        }
    }

    void setZones(int numZones) {
        zones = numZones;
    }

    void setNoRows(int rows) {
        if (rows > 0)
        {
            noRows = rows;
        }
    }

    void setSeatsPerRow(int* seats) {
        // Assuming seats is an array of size 'noRows'
        seatsPerRow = seats;
    }

    // Getters
    int getMaxSeats() {
        return maxSeats;
    }

    int getZones() {
        return zones;
    }

    int getNoRows() {
        return noRows;
    }

    const int* getSeatsPerRow() {
        return seatsPerRow;
    }

    //Overloaded = operator
    EventLocation& operator=(const EventLocation& obj)
    {
        if (this != &obj)
        {
            delete[] seatsPerRow;
            this->maxSeats = obj.maxSeats;
            this->zones = obj.zones;
            this->noRows = obj.noRows;
            this->seatsPerRow = new int[obj.noRows];
            for (int i = 0; i < obj.noRows; i++)
            {
                this->seatsPerRow[i] = obj.seatsPerRow[i];
            }
        }
        return *this;
    }

    //Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const EventLocation& loc)
    {
        out << "Max Seats:" << loc.maxSeats << endl;
        out << "Zones:" << loc.zones << endl;
        out << "Number of Rows:" << loc.noRows << endl;
        out << "Seats Per Row:";
        for (int i = 0; i < loc.noRows; i++)
        {
            out << loc.seatsPerRow[i] << " ";
        }
        out << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, EventLocation& loc)
    {
        cout << "Enter Max Seats:";
        in >> loc.maxSeats;

        cout << "Enter Number of Zones";
        in >> loc.zones;

        cout << "Enter Number of Rows:";
        in >> loc.noRows;

        loc.seatsPerRow = new int[loc.noRows];
        cout << "Enter seats per row:";
        for (int i = 0; i < loc.noRows; i++)
        {
            in >> loc.seatsPerRow[i];
        }
        return in;
    }
};

class Event {
private:
    string date;
    string time;
    char* name;

public:

    //Default Constructor
    Event()
    {
        this->date = "Unknown";
        this->time = "Unknown";
        this->name = NULL;
    }

    //Constructor with all attributes
    Event(string date, string time, char* eventName)
    {
        this->date = date;
        this->time = time;
        this->name = new char[strlen(eventName) + 1];
        strcpy(name, eventName);
    }

    //Copy Constructor
    Event(const Event& obj)
    {
        this->date = obj.date;
        this->time = obj.time;
        this->name = new char[strlen(obj.eventName) + 1];
        strcpy(name, obj.eventName);
    }

    //Destructor
    ~Event()
    {
        delete[] name;
    }

    // Setters
    void setDate(const string& eventDate) {
        date = eventDate;
    }

    void setTime(const string& eventTime) {
        time = eventTime;
    }

    void setName(const char* eventName) {
        name = new char[strlen(eventName) + 1];
        strcpy(name, eventName);
    }

    // Getters
    const string& getDate() {
        return date;
    }

    const string& getTime() {
        return time;
    }

    const char* getName() {
        return name;
    }

    //Overloaded = operator
    Event& operator=(const Event& other)
    {
        if (this != &other)
        {
            delete[] name;
            this->date = obj.date;
            this->time = obj.time;
            this->name = new char[strlen(obj.eventName) + 1];
            strcpy(name, obj.eventName);
        }
        return *this;
    }

    //Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const Event& event)
    {
        out << "Date:" << event.date << endl;
        out << "Time" << event.time << endl;
        out << "Name:" << event.name << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, Event& event)
    {
        cout << "Enter date (DD-MM-YYYY):";
        in >> event.date;

        cout << "Enter time:";
        in >> event.time;

        cout << "Enter name:"
        in.ignore();
        getline(in, event.name);

        return in;
    }
};

class Ticket {
private:
    static int id;
    const string type;
    string eventName;
    string date;
    string time;

public:

    //Default Constructor
    Ticket()
    {
        this->type = "Unknown";
        this->eventName = "Unknown";
        this->date = "Unknown";
        this->time = "Unknown";
    }

    //Constructor with all attributes
    Ticket(const string type, string eventName, string ticketDate, string ticketTime)
    {
        this->type = type;
        this->eventName = eventName;
        this->date = ticketDate;
        this->time = ticketTime;
    }

    //Copy Constructor
    Ticket(const Ticket& obj)
    {
        this->type = obj.type;
        this->eventName = obj.eventName;
        this->date = obj.ticketDate;
        this->time = obj.ticketTime;
    }

    //Destructor
    Ticket()
    {
        //Assuming no dynamic memory to release
    }

    // Setters
    void setEventName(const string& eventName) {
        this->eventName = eventName;
    }

    void setDate(const string& ticketDate) {
        date = ticketDate;
    }

    void setTime(const string& ticketTime) {
        time = ticketTime;
    }

    // Getters
    const string& getEventName() {
        return eventName;
    }

    const string& getDate() {
        return date;
    }

    const string& getTime() {
        return time;
    }

    static int getId() {
        return id;
    }

    //Overloaded = operator
    Ticket& operator=(const Ticket& obj)
    {
        if (this != &obj)
        {
            this->type = obj.type;
            this->eventName = obj.eventName;
            this->date = obj.ticketDate;
            this->time = obj.ticketTime;
        }
        return *this;
    }

    //Overloaded << operator for output
    friend ostream operator<<(ostream& out, const Ticket& ticket)
    {
        out << "ID:" << ticket.id << endl;
        out << "Type:" << ticket.type << endl;
        out << "Event name:" << ticket.eventName << endl;
        out << "Date:" << ticket.date << endl;
        out << "Time:" << ticket.time << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, Ticket& ticket)
    {
        cout << "Enter type:";
        in >> ticket.type;

        cout << "Enter event name:";
        in.ignore();
        getline(in, ticket.eventName);

        cout << "Enter date:";
        in >> ticket.date;

        cout << "Enter time:";
        in >> ticket.date;

        return in;
    }
};

//class TicketManager {
//private:
//    EventLocation location;
//    Event event;
//};

int Ticket::id = 0;

void main() 
{
    // Test EventLocation class
    EventLocation loc1;
    loc1.setMaxSeats(100);
    loc1.setZones(3);
    loc1.setNoRows(10);

    int seatsPerRow1[] = { 15, 20, 25, 20, 15, 10, 10, 15, 20, 25 };
    loc1.setSeatsPerRow(seatsPerRow1);

    EventLocation loc2 = loc1; // Copy constructor
    EventLocation loc3;
    loc3 = loc2; // = operator

    // Test Event class
    Event evt1;
    evt1.setDate("2023-12-25");
    evt1.setTime("18:00");
    evt1.setName("Christmas Concert");

    Event evt2 = evt1; // Copy constructor
    Event evt3;
    evt3 = evt2; // = operator

    // Test Ticket class
    Ticket::setId(0); // Reset ticket ID for testing purposes

    Ticket ticket1("VIP", "Christmas Concert", "2023-12-25", "18:00");
    Ticket ticket2 = ticket1; // Copy constructor
    Ticket ticket3;
    ticket3 = ticket2; // = operator

    // Display EventLocation details
    cout << "EventLocation 1:\n";
    cout << "Max Seats: " << loc1.getMaxSeats() << "\n";
    cout << "Zones: " << loc1.getZones() << "\n";
    cout << "Number of Rows: " << loc1.getNoRows() << "\n";

    // Display Event details
    cout << "\nEvent 1:\n";
    cout << "Date: " << evt1.getDate() << "\n";
    cout << "Time: " << evt1.getTime() << "\n";
    cout << "Name: " << evt1.getName() << "\n";

    // Display Ticket details
    cout << "\nTicket 1:\n";
    cout << "ID: " << ticket1.getId() << "\n";
    cout << "Type: " << ticket1.getType() << "\n";
    cout << "Event Name: " << ticket1.getEventName() << "\n";
    cout << "Date: " << ticket1.getDate() << "\n";
    cout << "Time: " << ticket1.getTime() << "\n";

    // Test EventLocation class
    EventLocation loc1;
    cin >> loc1; // Using overloaded >> operator
    cout << "EventLocation 1:\n" << loc1; // Using overloaded << operator

    EventLocation loc2 = loc1; // Copy constructor
    EventLocation loc3;
    loc3 = loc2; // = operator

    // Test Event class
    Event evt1;
    cin >> evt1; // Using overloaded >> operator
    cout << "\nEvent 1:\n" << evt1; // Using overloaded << operator

    Event evt2 = evt1; // Copy constructor
    Event evt3;
    evt3 = evt2; // = operator

    // Test Ticket class
    Ticket::setId(0); // Reset ticket ID for testing purposes

    Ticket ticket1;
    cin >> ticket1; // Using overloaded >> operator
    cout << "\nTicket 1:\n" << ticket1; // Using overloaded << operator

    Ticket ticket2 = ticket1; // Copy constructor
    Ticket ticket3;
    ticket3 = ticket2; // = operator

    // Display EventLocation details
    cout << "\nEventLocation 1:\n" << loc1;

    // Display Event details
    cout << "\nEvent 1:\n" << evt1;

    // Display Ticket details
    cout << "\nTicket 1:\n" << ticket1;

    return 0;
}