#include <iostream>
#include <string>
#include <vector>
#include "Mang.h"
using namespace std;

Managment::Managment()
{
    user_name = "";
    user_id = 0;
    user_pwd = "";
}
void Managment::setName(string name)  // set manager name
{
    user_name = name;
}
void Managment::setID(string id)      // set manager id
{
    user_id = stoi(id);
}
void Managment::setPwd(string p)      // set manager pwd
{
    user_pwd = p;
}
string Managment::getName() const    // get manager name
{
    return user_name;
}
int Managment::getID() const         // get manager id
{
    return user_id;
}
string Managment::getPwd() const    // get manager pwd
{
    return user_pwd;
}
void Managment::mang_info_display(vector<Managment> &user_m)
{
    cout << endl; // Management Dispaly
    cout << "------All Management Information------" << endl;
    cout << "------------------------------------" << endl;
    cout << "Name" << "\t\t\t\t" << "ID" << endl;
    cout << "------------------------------------" << endl;
    for(int i=0;i<user_m.size();i++)
    {
        cout << user_m[i].getName() << "\t\t\t" << user_m[i].getID() << endl;
    }
}
void Managment::add_mang(vector<Managment> &user_m)
{
    string name, pwd;
    int id;
    cout << "Enter management employee name: ";
    cin.ignore();
    getline(cin, name);
    id = rand() % 399 + 101;
    for(int i=1;i<user_m.size();i++) // randomize manager id
    {
        if(id == user_m[i].getID())
        {
            id = rand() % 399 + 101;
        }
    }
    cout << "Auto generated id for this Management employee account is: " << id << endl;
    cout << "Set a password for this Management employee account: ";
    cin.ignore();
    getline(cin, pwd);
    Managment a;
    a.setName(name);
    a.setID(to_string(id));
    a.setPwd(pwd);
    user_m.push_back(a);     // add manager to vector 
    cout << "Management employee entry is complete." << endl;
}
void Managment::search_mang(vector<Managment> &user_m)
{
    int id;
    bool found = false;
    cout << "Enter Management employee's id: ";
    cin >> id;
    for(int i=0;i<user_m.size();i++)
    {
        if(user_m[i].getID() == id)
        {
            cout << "Management found" << endl; 
            cout << "Name" << "\t\t\t\t" << "ID" << endl;
            cout << "-----------------------------------------" << endl;
            cout << user_m[i].getName() <<"\t\t\t" << user_m[i].getID() << endl; 
            found = true;
            break;            
        }
    }
        if (found == false)
            cout << "Management not found" << endl;
}
void Managment::remove_mang(vector<Managment> &user_m)
{
    int id;
            bool found = false;
            cout << "Enter management employee's id: ";
            cin >> id;
            for(int i=0;i<user_m.size();i++)
                {
                    if(user_m[i].getID() == id)
                    {
                        cout << "The following user has been deleted." << endl;
                        cout << user_m[i].getName() <<"\t\t\t" << user_m[i].getID() << endl; 
                        user_m.erase (user_m.begin()+i);   // remove manager from vector
                        found = true;
                        break;            
                    }
                }
            if(found == false)
                cout << "Management employee not found!" << endl;

}
void Managment::mang_func_display()
{
    cout << endl;
        cout << "Select the following option for a particular task." << endl; // user asking input
        cout << "Select 1 to remove a user." << endl;
        cout << "Select 2 to view all users." << endl;
        cout << "Select 3 to search for a specific user." << endl;
        cout << "Select 4 to issue a ticket." << endl;
        cout << "Select 5 to view all ticket information."<< endl;
        cout << "Select 6 to view info on a specific ticket."<< endl;
        cout << "Select 7 to remove a ticket."<< endl;
        cout << "Select 8 to change this account's password."<< endl;
        cout << "Select 9 to log out of account."<< endl;
}
void Managment::pwdChange(vector<Managment> &user_m, int user_id) // Changes password for only the management logged in.
{
    bool found = false;
    string newPwd;

    for(int i=0;i<user_m.size();i++) // Searchs for the Management's ID in the vector and changes password
    {
        if(user_m[i].getID() == user_id)
        {
            cout << "Please enter the new password" << endl;
            cin >> newPwd;
            user_m[i].setPwd(newPwd);
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