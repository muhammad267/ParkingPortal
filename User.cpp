#include <iostream>
#include <string>
#include "User.h"
#include <vector>
using namespace std;
User::User()
{
    user_name = "";
    user_id = 0;
    user_pwd = "";
    car_make = "";
    car_model = "";
    car_year = 0;
    car_plate = "";
}
void User::setName(string name) // sets user name
{
    user_name = name;
}
void User::setID(string id) // sets user ID
{
    user_id = stoi(id);
}
void User::setPwd(string p) // sets user ID
{
    user_pwd = p;
}
void User::setMake(string make) // Sets user vehicle make
{
    car_make = make;
}
void User::setModel(string model) // Sets user vehicle model
{
    car_model = model;
}
void User::setYear(int year) // Sets user vehicle year
{
    car_year = year;
}
void User::setPlate(string plate) // Sets user vehicle plate number
{
    car_plate = plate;
}
string User::getName() const // gets user name
{
    return user_name;
}
int User::getID() const // gets user id
{
    return user_id;
}
string User::getPwd() const // gets user pwd
{
    return user_pwd;
}
string User::getMake() const // gets user car make
{
    return car_make;
}
string User::getModel() const // gets user car model
{
    return car_model;
}
int User::getYear() const // gets user car year
{
    return car_year;
}
string User::getPlate() const // gets user car plate
{
    return car_plate;   
}
void User::user_func_display() // displays user functionality menu
{
    cout << "\nSelect the following option for a particular task." << endl;
    cout << "Select 1 to change password." << endl;
    cout << "Select 2 to change vehicle information." << endl;
    cout << "Select 3 to view vehicle information." << endl;
    cout << "Select 4 to view all ticket information." << endl;
    cout << "Select 5 to pay a ticket amount." << endl;
    cout << "Select 6 to appeal against a ticket." << endl;
    cout << "Select 7 to view appeal information." << endl;
    cout << "Select 8 to Log out." << endl;
}
void User::pwdChange(vector<User> &user_u, int user_id) // Changes password for only the user logged in.
{
    bool found = false;
    string newPwd;

    for(int i=1;i<user_u.size();i++) // Searchs for the user's ID in the vector and changes password
    {
        if(user_u[i].getID() == user_id)
        {
            cout << "Please enter the new password" << endl;
            cin >> newPwd;
            user_u[i].setPwd(newPwd);
            cout << "The new password has been set." << endl; 
            found = true;
            break;            
        }
    }
    if (found == false) // If ID not found in vector
    {
        cout << "User not found" << endl;
    }
}
void User::edit_vehicle_info(vector<User> &user_u, int user_id) // Edit user vehicle info
{
    bool found = false;
    string Make, Model, Plate_num;
    int Year;

    for(int i=1;i<user_u.size();i++) // Search for the user element in vector by ID
    {
        if(user_u[i].getID() == user_id) // If ID found, get new vehicle info and change in vector
        {
            cout << "Please enter the new vehicle information." << endl;
            cout << "\nMake: ";
            cin >> Make;
            cout << "Model: ";
            cin >> Model;
            cout << "Year(yyyy): ";
            cin >> Year;
            while(Year<1000 || Year>9999)
            {
                cout << "Please enter a valid year." << endl;
                cout << "Year(yyyy): ";
                cin >> Year;
            }
            cout << "License Plate number: ";
            cin >> Plate_num;

            user_u[i].setMake(Make);
            user_u[i].setModel(Model);
            user_u[i].setYear(Year);
            user_u[i].setPlate(Plate_num);

            cout << "\nVehicle information has been updated." << endl; 
            found = true;
            break;            
        }
    }
    if (found == false) // If ID not found
    {
        cout << "User not found" << endl;
    }
}
void User::view_vehicle_info(vector<User> &user_u, int user_id) // View info of the user logged in
{
    bool found = false;
    string Make, Model, Plate_num;
    int Year;

    for(int i=1;i<user_u.size();i++) // Loop through the vector to find user
    {
        if(user_id == user_u[i].getID()) // If ID found, display user info
        {
            cout << "Make\t\t\tModel\t\t\tYear\t\t\tLicense Plate Number" << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << user_u[i].getMake() << "\t\t\t" << user_u[i].getModel() << "\t\t\t" << user_u[i].getYear() << "\t\t\t" << user_u[i].getPlate() << endl;
            
            found = true;
            break;            
        }
    }
    if (found == false) // If ID not found
    {
        cout << "User not found" << endl;
    }
}
void User::user_info_display(vector<User> &user_u) // Display all user from Admin functionality
{
    cout << endl; 
    cout << "-------------------------------------------------------------All User Information-----------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Name\t\t\tID\t\t\tMake\t\t\tModel\t\t\tYear\t\t\tLicense Plate Number" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i = 1;i < user_u.size(); i++)
    {
        cout << user_u[i].getName() << "\t\t" << user_u[i].getID() << "\t\t" << user_u[i].getMake() << "\t\t\t" << user_u[i].getModel() << "\t\t\t" << user_u[i].getYear() << "\t\t\t" << user_u[i].getPlate() << endl;
    }
}
void User::remove_user(vector<User> &user_u) // Remove user from Admin functionality
{
    int id;
    bool found = false;
    cout << "Enter user id: ";
    cin >> id;
    for(int i = 1;i < user_u.size(); i++) // Loop through the vector to find ID
    {
        if(user_u[i].getID() == id) // If ID found, remove that element from vector
        {
            cout << "The following user has been deleted." << endl;
            cout << user_u[i].getName() <<"\t\t\t" << user_u[i].getID() << endl; 
            user_u.erase (user_u.begin()+i);
            found = true;
            break;            
        }
    }
    if(found == false)
        cout << "User not found!" << endl;
}
void User::search_user(vector<User> &user_u) // Search for specific user from Admin functionality
{
    int id;
    bool found = false;
    cout << "Enter desired user's id: ";
    cin >> id;
    for(int i = 1;i < user_u.size(); i++) // Loop through vector to find ID
    {
        if(user_u[i].getID() == id) // If ID matches, display user info
        {
            cout << "Name" << "\t\t\t\t" << "ID" << endl;
            cout << "-----------------------------------------" << endl;
            cout << user_u[i].getName() <<"\t\t\t" << user_u[i].getID() << endl; 
            found = true;
            break;            
        }
    }
    if (found == false) // If ID not found
        cout << "User not found" << endl;
}
string User::search_plate(vector<User> &user_u , int user_id) // Search for specific user from Admin functionality
{
    string user_plate;
    for(int i = 1;i < user_u.size(); i++) // Loop through vector to find ID
    {
        if(user_u[i].getID() == user_id) // If ID matches, display user info
        {
            user_plate = user_u[i].getPlate();
        }
    }
    return user_plate;
}