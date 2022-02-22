#include "Admin.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Admin::Admin() 
{
    user_name = "";
    user_id = 0;
    user_pwd = "";
    
}
void Admin::setName(string name)  // set admin name
{
    user_name = name;
}
void Admin::setID(string id)      // set admin id
{
    user_id = stoi(id);
}
void Admin::setPwd(string p)      // set admin pwd
{
    user_pwd = p;
}
string Admin::getName() const     // get admin name
{
    return user_name;
}
int Admin::getID() const          // get admin id
{
    return user_id;
}
string Admin::getPwd() const      // get admin pwd
{
    return user_pwd;
}
void Admin::admin_func_display()
{
    cout << endl;
        cout << "Select the following option for a particular task." << endl; // user asking input
        cout << "Select 1 to add new administrative employee." << endl;
        cout << "Select 2 to remove an administrative employee." << endl;
        cout << "Select 3 to view all administrative employee information." << endl;
        cout << "Select 4 to search information of a specific administrative employee." << endl;
        cout << "Select 5 to change password."<< endl;
        cout << "Select 6 to add new management employee."<< endl;
        cout << "Select 7 to remove a management employee."<< endl;
        cout << "Select 8 to view all management employee information."<< endl;
        cout << "Select 9 to search information of a specific management employee."<< endl;
        cout << "Select 10 to remove an user."<< endl;
        cout << "Select 11 to view all user information."<< endl;
        cout << "Select 12 to search information of a specific user."<< endl;
        cout << "Select 13 to view appeal information."<< endl;
        cout << "Select 14 to process an appeal."<< endl;
        cout << "Select 15 to Log out."<< endl;
}
void Admin::add_admin(vector<Admin> &user_a) 
{
    string name, pwd;
    int id;
    cout << "Enter admin employee name: ";
    cin.ignore();
    getline(cin, name);
    id = rand() % 399 + 101;        
    for(int i=1;i<user_a.size();i++)
    {
        if(id == user_a[i].getID())
        {
            id = rand() % 399 + 101; // randomize and assign proper admin value
        }
    }
    cout << "Auto generated id for this administrative employee account is: " << id << endl;
    cout << "Set a password for this administrative employee account: ";
    cin.ignore();
    getline(cin, pwd);
    Admin a;
    a.setName(name);
    a.setID(to_string(id));
    a.setPwd(pwd);
    user_a.push_back(a);   // add new admin to vector
    cout << "administrative employee entry is complete." << endl;
}
void Admin::admin_info_display(vector<Admin> &user_a)
{
    cout << endl; // Admin display.
    cout << "-All Administrative Employee Information-" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Name" << "\t\t\t\t" << "ID" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i=0;i<user_a.size();i++) // loop through the vector and print the info.
    {
        cout << user_a[i].getName() << "\t\t\t" << user_a[i].getID() << endl;
    }

}
void Admin::search_admin(vector<Admin> &user_a)
{
    int id;
    bool found = false;
    cout << "Enter administrative employee's id: ";
    cin >> id;
    for(int i=0;i<user_a.size();i++)
    {
        if(user_a[i].getID() == id)
        {
            cout << "Administrator found" << endl; 
            cout << "Name" << "\t\t\t\t" << "ID" << endl;
            cout << "-----------------------------------------" << endl;
            cout << user_a[i].getName() <<"\t\t\t" << user_a[i].getID() << endl; 
            found = true;
            break;            
        }
    }
    if (found == false)
    {
        cout << "Administrator not found" << endl;
    }
}
void Admin::remove_admin(vector<Admin> &user_a)
{
    int id;
    bool found = false;
    cout << "Enter admin employee's id: ";
    cin >> id;
    for(int i=0;i<user_a.size();i++)
    {
        if(user_a[i].getID() == id)
        {
            cout << "The following user has been deleted." << endl;
            cout << user_a[i].getName() <<"\t\t\t" << user_a[i].getID() << endl; 
            user_a.erase (user_a.begin()+i);
            found = true;
            break;            
        }
    }
    if(found == false)
        cout << "Adminstrator employee not found!" << endl;
}
void Admin::pwdChange(vector<Admin> &user_a, int user_id) // Changes password for only the Admin logged in.
{
    bool found = false;
    string newPwd;

    for(int i=1;i<user_a.size();i++) // Searchs for the Admin's ID in the vector and changes password
    {
        if(user_a[i].getID() == user_id)
        {
            cout << "Please enter the new password" << endl;
            cin >> newPwd;
            user_a[i].setPwd(newPwd);
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