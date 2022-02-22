#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Ticket.h"

using namespace std;

Ticket::Ticket()
{
    plateID = "";
    ticket_num = 0;
    ticket_amount = 0;
    issued_by = 0;
    ticket_status = "";
    reason = "";
}
// Set functionalities
void Ticket::setCarPlate(string carPlate)
{
    plateID = carPlate;
}
void Ticket::setTicketNumber(string t_num)
{
    ticket_num = stoi(t_num);
}
void Ticket::setTicketAmount(string t_amount)
{
    ticket_amount = stoi(t_amount);
}
void Ticket::setIssuedBy(int issued)
{
    issued_by = issued;
}
void Ticket::setTicketStatus(string t_status)
{
    ticket_status = t_status;
}
void Ticket::setTicketReason(string t_reason)
{
    reason = t_reason;
}
void Ticket::setAppealStatus(string t_status)
{
    appeal_status = t_status;
}
void Ticket::setAppealDescription(string t_description)
{
    appeal_description = t_description;
}
// Get functionalities
string Ticket::getCarPlate() const
{
    return plateID;
}
int Ticket::getTicketNumber() const
{
    return ticket_num;
}
int Ticket::getTicketAmount() const
{
    return ticket_amount;
}
int Ticket::getIssuedBy() const
{
    return issued_by;
}
string Ticket::getTicketStatus() const
{
    return ticket_status;
}
string Ticket::getTicketReason() const
{
    return reason;
}
string Ticket::getAppealDescription() const
{
    return appeal_description; 
}
string Ticket::getAppealStatus() const
{
    return appeal_status;
}
// Add ticket functionality
void Ticket::add_ticket(vector<Ticket> &user_t, int mang_id) 
{
    srand(time(0));
    string plateID;
    int ticket_num;
	string ticket_amount;
	int issued_by;
	string ticket_status;
	string reason;

    cout << "Enter the car's plate ID: ";
    cin.ignore();
    getline(cin, plateID);
	ticket_num = rand() % 1000 + 50000;

    cout << "Auto generated ID for this ticket is: " << ticket_num << endl;
	cout << "Enter the amount of the ticket: ";
    getline(cin, ticket_amount);

    issued_by = mang_id;

    cout << "Enter the reason for this ticket:";
    getline(cin,reason);

    ticket_status = "Unpaid";
    
	Ticket t;
    t.setCarPlate(plateID);
    t.setTicketNumber(to_string(ticket_num));
    t.setTicketAmount(ticket_amount);
    t.setIssuedBy(issued_by);
    t.setTicketStatus(ticket_status);
    t.setTicketReason(reason);
    user_t.push_back(t);
    cout << "New ticket entry is complete." << endl;
}
// Ticket display functionality
void Ticket::ticket_info_display(vector<Ticket> &user_t, int mang_id)
{
    cout << endl; // Ticket display.
    cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
    "Issued by" << "\t\t\t" << "Ticket Status" << "\t\t\t" << "Ticket Reason" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=1;i<user_t.size();i++) // loop through the vector and print the info.
    {
        cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getTicketStatus() << "\t\t\t\t" << user_t[i].getTicketReason() << endl;
    }
}
// Search ticket functionality
void Ticket::search_ticket(vector<Ticket> &user_t)
{
    int id;
    bool found = false;
    cout << "Enter Ticket's ID Number: ";
    cin >> id;
    for(int i=0;i<user_t.size();i++)
    {
        //if(user_a[i].getID() == id)
        if(user_t[i].getTicketNumber() == id)
        {
            cout << "Ticket found" << endl; 
            //cout << "Name" << "\t\t\t\t" << "ID" << endl;
            cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
            "Issued by" << "\t\t\t" << "Ticket Status" << "\t\t\t" << "Ticket Reason" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getTicketStatus() << "\t\t\t\t" << user_t[i].getTicketReason() << endl;
            //cout << user_t[i].getName() <<"\t\t\t" << user_a[i].getID() << endl; 
            found = true;
            break;            
        }
    }
    if (found == false)
    {
        cout << "Ticket not found" << endl;
    }
} 
// Remove ticket functionality
void Ticket::remove_ticket(vector<Ticket> &user_t)
{
    int id;
    bool found = false;
    cout << "Enter ticket's id number: ";
    cin >> id;
    for(int i = 0;i < user_t.size(); i++)
    {
        //if(user_t[i].getID() == id)
        if(user_t[i].getTicketNumber() == id)
        {
            cout << "The following ticket has been deleted." << endl;
            cout << user_t[i].getTicketNumber() <<"\t\t\t" << user_t[i].getIssuedBy() << endl; 
            user_t.erase (user_t.begin()+i);
            found = true;
            break;            
        }
    }
    if(found == false)
        cout << "Ticket not found!" << endl;
}
// View user ticket functionality
void Ticket::view_user_tickets(vector<Ticket> &user_t, string user_plate)
{
    cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
    "Issued by" << "\t\t\t" << "Ticket Status" << "\t\t\t" << "Ticket Reason" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    for(int i=1;i<user_t.size();i++) // loop through the vector and print the info.
    {
        if(user_t[i].plateID == user_plate)
        {
            cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getTicketStatus() << "\t\t\t\t" << user_t[i].getTicketReason() << endl;
        }
    }
}
// Pay ticket functionality
void Ticket::pay_ticket(vector<Ticket> &user_t, string user_plate)
{
    int ticket;
    string input;
    cout << "Enter the ticket number: ";
    cin >> ticket;
    for(int i=1;i<user_t.size();i++) // loop through the vector and print the info.
    {
        if (user_t[i].getCarPlate() == user_plate)
        {
            if(user_t[i].getTicketNumber() == ticket)
            {
            cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
            "Issued by" << "\t\t\t" << "Ticket Status" << "\t\t\t" << "Ticket Reason" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getTicketStatus() << "\t\t\t\t" << user_t[i].getTicketReason() << endl;
       
            cout << "Do you want to pay $" << user_t[i].getTicketAmount() << " right now? (Type Yes or No): " << endl;
            cin.ignore();
            getline (cin, input);
            if (input == "Yes" || input == "yes" || input == "YES")
            {
                user_t[i].setTicketStatus("Paid");
                cout << "The ticket amount is paid off." << endl;
                break;
            }
            else if (input == "No" || input == "no" || input == "NO")
                break;            
            else
                cout << "Not a valid response." << endl;
            }
        }
        else
        {
            cout << "You do not have a ticket with this ticket number." << endl;
        }
    }
}
// appeal ticket functionality
void Ticket::appeal_ticket(vector<Ticket> &user_t)
{
    int id;
    bool found = false;
    string desc;
    cout << "Enter id number of the ticket you wish to appeal: ";
    cin >> id;
    for(int i = 0;i < user_t.size(); i++)
    {
        
        if(user_t[i].getTicketNumber() == id)
        {
            
            cout << "Enter the justification for your appeal:";
            cin.ignore();
            getline(cin, desc);

            //cin >> desc; 
            //cout << user_t[i].getTicketNumber() <<"\t\t\t" << user_t[i].getIssuedBy() << endl; 
            user_t[i].setAppealDescription(desc);
            user_t[i].setAppealStatus("pending");
            found = true;
            cout << "The following ticket has been appealed." << endl;
            break;            
        }
    }
    if(found == false)
        cout << "Ticket not found!" << endl;
}

void Ticket::view_all_appeals(vector<Ticket> &user_t)
{
    cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
    "Issued by" << "\t\t\t" << "Appeal Status" << "\t\t\t" << "Appeal description" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=1;i<user_t.size();i++) // loop through the vector and print the info.
    {
        if((user_t[i].getAppealStatus() == "pending")||(user_t[i].getAppealStatus() == "accepted")||(user_t[i].getAppealStatus() == "denied"))
        { 
            cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getAppealStatus() << "\t\t\t\t" << user_t[i].getAppealDescription() << endl;
        }
    }
}
void Ticket::view_appeals(vector<Ticket> &user_t, string user_plate)
{
    cout << "Ticket number" << "\t\t\t" << "Ticket amount" << "\t\t\t" <<
    "Issued by" << "\t\t\t" << "Appeal Status" << "\t\t\t" << "Appeal description" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i=1;i<user_t.size();i++) 
    {
        for(int j=1;i<user_t.size();i++)
        {
            if ((user_t[i].plateID == user_plate)&&((user_t[i].getAppealStatus() == "pending")||(user_t[i].getAppealStatus() == "accepted")||(user_t[i].getAppealStatus() == "denied")))
            {
                cout << user_t[i].getTicketNumber() << "\t\t\t\t$" << user_t[i].getTicketAmount() << "\t\t\t\t" << user_t[i].getIssuedBy() << "\t\t\t\t" << user_t[i].getAppealStatus() << "\t\t\t\t" << user_t[i].getAppealDescription() << endl;
            }
        }
    }
}

void Ticket::process_appeal(vector<Ticket> &user_t)
{
    int id;
    char accept;
    bool found = false;
    string desc;
    cout << "Enter id number of the ticket being processed: ";
    cin >> id;
    for(int i = 0;i < user_t.size(); i++)
    {
        //if(user_t[i].getID() == id)
        if(user_t[i].getTicketNumber() == id)
        {
            //cout << "The following ticket has been appealed." << endl;
            if (user_t[i].getAppealStatus() == "pending")
            {
            //cout << user_t[i].getTicketNumber() <<"\t\t\t" << user_t[i].getIssuedBy() << endl; 
                cout << "Accept appeal? (Y/N):";
                cin >> accept;
                if ((accept == 'y')||(accept == 'Y'))
                {
                    user_t[i].setAppealStatus("accepted");
                }
                else if ((accept == 'n')||(accept == 'N'))
                {
                    user_t[i].setAppealStatus("denied");
                }
                else
                {
                    cout << "Invalid input." << endl;
                }

                found = true;
                break;
            }
            else
            {
                cout << "Ticket exists but there was no appeal to process." << endl;
                found = true;
                break;
            }
                        
        }
    }
    if(found == false)
        cout << "Ticket not found!" << endl;
}