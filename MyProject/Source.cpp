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
    friend ostream& operator<<(ostream& out, const EventLocation& obj)
    {
        out << "Max Seats:" << obj.maxSeats << endl;
        out << "Zones:" << obj.zones << endl;
        out << "Number of Rows:" << obj.noRows << endl;
        out << "Seats Per Row:";
        for (int i = 0; i < obj.noRows; i++)
        {
            out << obj.seatsPerRow[i] << " ";
        }
        out << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, EventLocation& obj)
    {
        cout << "Enter Max Seats:";
        in >> obj.maxSeats;

        cout << "Enter Number of Zones";
        in >> obj.zones;

        cout << "Enter Number of Rows:";
        in >> obj.noRows;

        obj.seatsPerRow = new int[obj.noRows];
        cout << "Enter seats per row:";
        for (int i = 0; i < obj.noRows; i++)
        {
            in >> obj.seatsPerRow[i];
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
            return -1;
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

    static EventLocation getNewEventLocation() {
        int maxSeats, zones, noRows;

        cout << "Enter Max Seats: ";
        cin >> maxSeats;

        cout << "Enter Number of Zones: ";
        cin >> zones;

        cout << "Enter Number of Rows: ";
        cin >> noRows;

        int* seatsPerRow = new int[noRows];
        cout << "Enter seats per row: ";
        for (int i = 0; i < noRows; i++) {
            cin >> seatsPerRow[i];
        }

        return EventLocation(maxSeats, zones, noRows, seatsPerRow);
    }

    void editEventLocationDetails() {
        int choice;

        cout << "Edit Event Location Details:\n";
        cout << "1. Max Seats\n";
        cout << "2. Number of Zones\n";
        cout << "3. Number of Rows\n";
        cout << "4. Seats Per Row\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        int* newSeatsPerRow;

        switch (choice) {
        case 1:
            int newMaxSeats;
            cout << "Enter new Max Seats: ";
            cin >> newMaxSeats;
            setMaxSeats(newMaxSeats);
            break;

        case 2:
            int newZones;
            cout << "Enter new Number of Zones: ";
            cin >> newZones;
            setZones(newZones);
            break;

        case 3:
            int newNoRows;
            cout << "Enter new Number of Rows: ";
            cin >> newNoRows;
            setNoRows(newNoRows);
            break;

        case 4:
            newSeatsPerRow = new int[getNoRows()];
            cout << "Enter new Seats Per Row: ";
            for (int i = 0; i < getNoRows(); i++) {
                cin >> newSeatsPerRow[i];
            }
            setSeatsPerRow(newSeatsPerRow);
            break;

        case 5:
            cout << "Exiting edit menu.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    void displayEventLocationDetails() {
        cout << "Event Location Details:\n";
        cout << "Max Seats: " << getMaxSeats() << endl;
        cout << "Number of Zones: " << getZones() << endl;
        cout << "Number of Rows: " << getNoRows() << endl;

        const int* seatsPerRow = getSeatsPerRow();
        cout << "Seats Per Row: ";
        for (int i = 0; i < getNoRows(); i++) {
            cout << seatsPerRow[i] << " ";
        }
        cout << endl;
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
        delete[] name;
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
    friend ostream& operator<<(ostream& out, const Event& obj)
    {
        out << "Date:" << obj.date << endl;
        out << "Time" << obj.time << endl;
        out << "Name:" << obj.name << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, Event& obj)
    {
        cout << "Enter date (DD-MM-YYYY):";
        in >> obj.date;

        cout << "Enter time:";
        in >> obj.time;

        cout << "Enter name:";
        delete[] obj.name;
        obj.name = new char[100];
        in.ignore();
        in.getline(obj.name, 100);

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

    string type;
    string eventName;
    string date;
    string time;
    static int idCounter;
    int id;

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
    Ticket(string& type, string& eventName, string& ticketDate, string& ticketTime)
    {
        this->idCounter=idCounter++;
        this->type = type;
        this->eventName = eventName;
        this->date = ticketDate;
        this->time = ticketTime;
    }

    //Copy Constructor
    Ticket(const Ticket& obj)
    {
        this->idCounter += obj.idCounter;
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
    static int getIdCounter() {
        return idCounter;
    }

    int getId() const{
        return id;
    }

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

    const string& getType() const {
        return type;
    }

    static Ticket getNewTicket() {
        string type, eventName, date, time;

        cout << "Enter ticket type: ";
        cin >> type;

        cout << "Enter event name: ";
        cin.ignore();
        getline(cin, eventName);

        cout << "Enter date (DD-MM-YYYY): ";
        cin >> date;

        cout << "Enter time: ";
        cin >> time;

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
    friend ostream& operator<<(ostream& out, const Ticket& obj)
    {
        out << "ID:" << obj.id << endl;
        out << "Type:" << obj.type << endl;
        out << "Event name:" << obj.eventName << endl;
        out << "Date:" << obj.date << endl;
        out << "Time:" << obj.time << endl;
        return out;
    }

    //Overloaded >> operator for input
    friend istream& operator>>(istream& in, Ticket& obj)
    {
        cout << "Enter type:";
        in >> obj.type;

        cout << "Enter event name:";
        in.ignore();
        getline(in, obj.eventName);

        cout << "Enter date:";
        in >> obj.date;

        cout << "Enter time:";
        in >> obj.time;

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



class TicketManager
{
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
            file >> ticket;
            if (file) {
                tickets.push_back(ticket);
            }
        }

        file.close();
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
            file << ticket << "\n";
        }

        file.close();
        cout << "Tickets saved to file successfully.\n";
    }

    void handleMenuChoice() {
        int choice;
        cout << "\n-------------------------\n";
        cout << "   TICKET MANAGER MENU   \n";
        cout << "-------------------------\n";
        cout << "1. Display Tickets\n";
        cout << "2. Add a New Ticket\n";
        cout << "3. Save Tickets to File\n";
        cout << "4. Back to Main Menu\n";
        cout << "-------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n--- Displaying Tickets ---\n";
            displayTickets();
            break;
        case 2:
            cout << "\n--- Adding a New Ticket ---\n";
            addTicket(Ticket::getNewTicket());
            break;
        case 3:
            cout << "\n--- Saving Tickets to File ---\n";
            saveTicketsToFile("tickets.txt");
            break;
        case 4:
            cout << "Returning to Main Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
};

int Ticket::idCounter = 0;

void main() 
{
    TicketManager ticketManager;
    Event event;
    Ticket ticket;
    vector<EventLocation> eventLocations;
    int choice;

    bool exitRequested = false;
    cout << "Hello! I am Andreea Mihaila and I am glad to welcome you to my project! \n";
    cout << "This app can manage Events, Tickets for events and Events Locations. \n";
    cout << "Hope you like it! \n";
    cout << endl;
    cout << endl;

    while (!exitRequested) {
        cout << "Main Menu:\n";
        cout << "1. Manage Events\n";
        cout << "2. Manage Tickets\n";
        cout << "3. Manage Event Locations\n";
        cout << "4. Exit\n";

        int mainChoice;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: // Events
            cout << "Events Menu:\n";
            cout << "1. Display Events\n";
            cout << "2. Add Event\n";
            cout << "3. Back to Main Menu\n";

            int eventChoice;
            cout << "Enter your choice: ";
            cin >> eventChoice;

            switch (eventChoice) {
            case 1:
                cout << "\n--- Event Details ---\n";
                cout << event << "\n";
                break;
            case 2:
                cout << "\n--- Add a New Event ---\n";
                cin >> event;
                break;
            case 3:
                cout << "\n--- Back to Main Menu ---\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
            break;
        case 2: // Tickets
            cout << "Tickets Menu:\n";
            cout << "1. Display Tickets\n";
            cout << "2. Add Ticket\n";
            cout << "3. Save Tickets to File\n";
            cout << "4. Back to Main Menu\n";

            int ticketChoice;
            cout << "Enter your choice: ";
            cin >> ticketChoice;

            switch (ticketChoice) {
            case 1:
                ticketManager.displayTickets();
                break;
            case 2:
                ticketManager.addTicket(Ticket::getNewTicket());
                break;
            case 3:
                ticketManager.saveTicketsToFile("tickets.txt");
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
            break;
        case 3: // EventLocation
            do {
                cout << "1. Add Event Location\n"
                    << "2. Edit Event Location\n"
                    << "3. Display Event Location Details\n"
                    << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    EventLocation newEventLocation = EventLocation::getNewEventLocation();
                    eventLocations.push_back(newEventLocation);
                    cout << "Event Location added successfully!\n";
                    break;
                }
                case 2: {
                    int index;
                    cout << "Enter the index of the Event Location to edit: ";
                    cin >> index;
                    if (index >= 0 && index < eventLocations.size()) {
                        eventLocations[index].editEventLocationDetails();
                        cout << "Event Location edited successfully!\n";
                    }
                    else {
                        cout << "Invalid index.\n";
                    }
                    break;
                }
                case 3: {
                    int index;
                    cout << "Enter the index of the Event Location to display details: ";
                    cin >> index;
                    if (index >= 0 && index < eventLocations.size()) {
                        eventLocations[index].displayEventLocationDetails();
                    }
                    else {
                        cout << "Invalid index.\n";
                    }
                    break;
                }
                case 4:
                    cout << "Back to Main Menu";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                }

            } while (choice != 4); 
        case 4:
            cout << "Exit. ";
            exitRequested = true;
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    }
}