#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdio.h>

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

    //Overloading indexing operator [] for showing the seatsPerRow for a specific Row
    int operator[](int index) 
    {
        if (index > 0 && index < noRows)
        {
            return seatsPerRow[index];
        }
        else
        {
            return -1; //exception to be developed soon
        }
    }

    //Overloading arithmetic operator + for adding more seats on a row
    EventLocation operator+(const EventLocation& obj)
    {
        for (int i = 0; i < noRows; i++)
        {
            this->seatsPerRow[i] += obj.seatsPerRow[i];
        }
        return *this;
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
        this->name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
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
    Event& operator=(const Event& obj)
    {
        if (this != &obj)
        {
            delete[] name;
            this->date = obj.date;
            this->time = obj.time;
            this->name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name);
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

        cout << "Enter name:";
        in >> event.name;

        return in;
    }

    //Overloaded ++ operator (prefix) to increment date by one day
    Event& operator++()
    {
        int day, month, year;
        sscanf(date.c_str(), "%d-%d-%d", &day, &month, &year);
        ++day;
        char newDate[11];
        snprintf(newDate, sizeof(newDate), "%04d-%02d-%02d", day, month, year);
        date = newDate;
        return *this;
    }

    //Overloaded -- operator (postfix) to decrement event date by one day
    Event operator--(int)
    {
        int day, month, year;
        sscanf(date.c_str(), "%d-%d-%d", &day, &month, &year);
        --day;
        char newDate[11];
        snprintf(newDate, sizeof(newDate), "%04d-%02d-%02d", day, month, year);
        date = newDate;
        return *this;
    }
};

class Ticket {
private:
    static int id;
    string type;
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
        this->date = obj.date;
        this->time = obj.time;
    }

    //Destructor
    ~Ticket()
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

    void setType(const string& ticketType) {
        type = ticketType;
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

    const string& getType() const {
        return type;
    }

    static Ticket getNewTicket() {
        string type, eventName, date, time;

        cout << "Enter ticket type: ";
        cin >> type;

        cout << "Enter event name: ";
        cin.ignore(); // Consume newline character left in the buffer
        getline(cin, eventName);

        cout << "Enter date (DD-MM-YYYY): ";
        cin >> date;

        cout << "Enter time: ";
        cin >> time;

        // Create and return a new Ticket object
        return Ticket(type, eventName, date, time);
    }

    //Overloaded = operator
    Ticket& operator=(const Ticket& obj)
    {
        if (this != &obj)
        {
            this->type = obj.type;
            this->eventName = obj.eventName;
            this->date = obj.date;
            this->time = obj.time;
        }
        return *this;
    }

    //Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const Ticket& ticket)
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
        in >> ticket.time;

        return in;
    }

    //Overloaded negation operator !
    //Assuming an empty event name means the ticket is not valid
    bool operator!()
    {
        return eventName.empty();
    }

    //Overloaded less than operator <
    //To check which ticket was issued first (based on their unique ID)
    bool operator<(const Ticket& obj)
    {
        return id < obj.id;
    }
};

class TicketManager {
private:
    vector<Ticket> tickets;

public:
    // Function to read data from a file and process it
    void processFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Unable to open file '" << filename << "'\n";
            return;
        }

        // Read data from the file and populate the tickets vector
        while (file) {
            Ticket ticket;
            // Read ticket data from the file
            file >> ticket; 
            if (file) {
                tickets.push_back(ticket);
            }
        }

        file.close();
    }

    // Function to display the menu
    void displayMenu() {
        cout << "Menu:\n";
        cout << "1. Display Tickets\n";
        cout << "2. Add Ticket\n";
        cout << "3. Save Tickets to File\n";
        cout << "4. Exit\n";
    }

    // Function to display tickets
    void displayTickets() const {
        if (tickets.empty()) {
            cout << "No tickets to display.\n";
        }
        else {
            cout << "Tickets:\n";
            for (const Ticket& ticket : tickets) {
                cout << ticket << "\n";
            }
        }
    }

    void addTicket(const Ticket& newTicket) {
        tickets.push_back(newTicket);
        cout << "Ticket added successfully.\n";
    }

    // Function to save tickets to a file
    void saveTicketsToFile(const string& filename) const {
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Unable to open file '" << filename << "' for writing.\n";
            return;
        }

        for (const Ticket& ticket : tickets) {
            // Assuming you have an appropriate operator<< defined for Ticket
            file << ticket << "\n";
        }

        file.close();
        cout << "Tickets saved to file successfully.\n";
    }

    void handleMenuChoice() {
        int choice;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayTickets();
            break;
        case 2:
            addTicket(Ticket::getNewTicket());
            break;
        case 3:
            saveTicketsToFile("tickets.txt");
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    // Function to start the ticket management system
    void start() {
        int menuChoice;

        // Check for the presence of a command-line argument (filename)
        if (argc > 1) {
            // A filename is provided as a command-line argument
            processFile(argv[1]);
        }

        do {
            displayMenu();
            handleMenuChoice();

            // Ask the user if they want to continue
            cout << "Do you want to continue? (1 for yes, 0 for no): ";
            cin >> menuChoice;

        } while (menuChoice != 0);
    }
};

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

    // Test indexing operator []
    cout << "Seats in the first row of EventLocation 1: " << loc1[0] << "\n";

    // Test arithmetic operator +
    EventLocation locSum = loc1 + loc2;
    cout << "\nEventLocation sum (element-wise addition):\n" << locSum;

    // Test ++ operator (prefix)
    ++evt1;
    cout << "\nEvent 1 after prefix increment:\n" << evt1;

    // Test -- operator (postfix)
    evt2--;
    cout << "Event 2 after postfix decrement:\n" << evt2;

    // Test negation operator !
    if (!ticket1) {
        cout << "Ticket 1 is not valid (eventName is empty)\n";
    }
    else {
        cout << "Ticket 1 is valid\n";
    }

    // Test relational operators
    if (ticket1 < ticket2) {
        cout << "Ticket 1 is less than Ticket 2\n";
    }
    else {
        cout << "Ticket 1 is not less than Ticket 2\n";
    }

}