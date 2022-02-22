#include "Admin.h"
#include "Mang.h"
#include "User.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdlib>
#include <ctime>


using namespace std; 
// Decleration
void file_intialize();
void display_parking_lot(int data_array[], int array_size);

void intialize_admin(string file_01);
void intialize_management(string file_02);
void intialize_user(string file_03);

void admin_func(int admin_id);
void user_func();

void display_info_user();
void login();

void user_registration();

// global arrays.
const int SIZE_a =2;
vector <Admin> user_a(SIZE_a); // class array to hold data
const int SIZE_m =10;
vector <Managment> user_m(SIZE_m); // class array to hold management user data.
const int SIZE_u =11;
vector <User> user_u(SIZE_u); // class array to hold users data.
int SIZE_t = 1;
vector <Ticket> user_t(SIZE_t); // class array to ticket data

int main() // main function
{

    file_intialize(); // function call to open files.
    login(); // user authentication.
    
    return 0;
}

void file_intialize() // opens input file and intialize
{
    string file_name; // stores file name
    int array_size = 7;
    int data_array[array_size]; // array to hold file info
    string temp_data; // to hold data from file temp.

    string file_01, file_02, file_03; // stores .csv file name

    cout << "Enter file name: ";
    cin >> file_name;

    ifstream file(file_name); // opens input file

    for(int i=0; i<array_size;i++) // loop to store file data (only stores parking info)
    {
        getline(file, temp_data);
        data_array[i] = stoi(temp_data);
    }
    for(int i=1;i<11;i++) // loop to store file data (only stores .csv files)
    {

        if(i==8) // so whatever is in line 8 gets stored in file 1.
        {
            getline(file, file_01);
        }
        else if(i==9) // so whatever is in line 8 gets stored in file 2.
        {
            getline(file, file_02);
        }
        else if(i==10) // so whatever is in line 8 gets stored in file 3.
        {
            getline(file, file_03);
        }
    }


    display_parking_lot(data_array, array_size); // dispaly function call
    intialize_admin(file_01); // calls to intailize admin file.
    intialize_management(file_02); // calls to intialize management file.
    intialize_user(file_03); // calls to initalize user file.

}
void display_parking_lot (int data_array[], int array_size) // open .csv fil and intailize.
{
    // declare and store parking lot data.
    int total_01;
    int reg_01 = data_array[1];
    int motorcycle_01 = data_array[2];
    int disability_01 = data_array[3];
    int total_02;
    int reg_02 = data_array[4];
    int motorcycle_02 = data_array[5];
    int disability_02 = data_array[6];

    total_01 = reg_01 + motorcycle_01 + disability_01;
    total_02 = reg_02 + motorcycle_02 + disability_02;

    cout << "Parking lot number: 1" << endl; // Dispaly
    cout << "Number of parking space: " << total_01 << endl;
    cout << "Number of regualar parking space: " << reg_01 << endl;
    cout << "Number of motorcycle parking space: " << motorcycle_01 << endl;
    cout << "Number of disability parking space: " << disability_01 << endl;
    cout << "Parking space layout is shown below." << endl;
    cout << "---------------------------------" << endl << "|";

    int count = 0;
    for (int i=motorcycle_01; i>0; i--) // display parking lot 1.
    {
        cout << " M |";
        count++;
        if(count % 8 == 0)
            cout << endl << "---------------------------------" << endl << "|";
    }

    for (int i=disability_01; i>0; i--)
    {
        cout << " D |";
        count++;
        if(count % 8 == 0)
            cout << endl << "---------------------------------" << endl << "|";
    }

    for (int i=reg_01; i>0; i--)
    {
        cout << " R |";
        count++;
        if(count % 8 == 0)
            cout << endl << "---------------------------------" << endl << "|";
    }
    cout << "\n\n";

    cout << "Parking lot number: 2" << endl; // Display
    cout << "Number of parking space: " << total_02 << endl;
    cout << "Number of regualar parking space: " << reg_02 << endl;
    cout << "Number of motorcycle parking space: " << motorcycle_02 << endl;
    cout << "Number of disability parking space: " << disability_02 << endl;
    cout << "Parking space layout is shown below." << endl;
    cout << "-------------------------------------" << endl << "|";

    count = 0;
    for (int i=motorcycle_02; i>0; i--) // display parking lot 2
    {
        cout << " M |";
        count++;
        if(count % 9 == 0)
            cout << endl << "-------------------------------------" << endl << "|";
    }

    for (int i=disability_02; i>0; i--)
    {
        cout << " D |";
        count++;
        if(count % 9 == 0)
            cout << endl << "-------------------------------------" << endl << "|";
    }

    for (int i=reg_02; i>0; i--)
    {
        cout << " R |";
        count++;
        if(count % 9 == 0)
            cout << endl << "-------------------------------------" << endl << "|";
    }
    cout << "\n\n";
}
void display_info_user() // Displays all user info
{
    cout << endl; 
    cout << "-------------------------------------------------------------All User Information-----------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Name\t\t\tID\t\t\tMake\t\t\tModel\t\t\tYear\t\t\tLicense Plate Number" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for(int i = 1;i < user_u.size(); i++) // Runs through the User class vector and prints all user info
    {
        cout << user_u[i].getName() << "\t\t" << user_u[i].getID() << "\t\t" << user_u[i].getMake() << "\t\t\t" << user_u[i].getModel() << "\t\t\t" << user_u[i].getYear() << "\t\t\t" << user_u[i].getPlate() << endl;
    }
}

void intialize_admin(string file_01) // open .csv file and intialize
{
    Admin a;
    //ifstream file_a(file_01.substr(0, file_01.length()-1)); // opens file and remove '\n' and then open files.
    int temp_f = file_01.length() - 16;
    file_01.erase(16, temp_f);
    ifstream file_a(file_01);
    if(!file_a.good()) // check to see if the file open.
    {
        cout << temp_f<< endl;
        cout << file_01.length() << endl;
        cout << "File failed" << endl;
    }

    string temp_name ,temp_id, temp_pwd; // temp data

    for(int i=0; i<SIZE_a; i++) // loop runs and store info from file to class array.
    {
        getline(file_a, temp_name, ',');
        getline(file_a, temp_id, ',');
        getline(file_a, temp_pwd, '\n');

        user_a[i].setName(temp_name);
        user_a[i].setID(temp_id);
        user_a[i].setPwd(temp_pwd);
    }
    a.admin_info_display(user_a); // call func to dispaly admin user info.

}
void intialize_management(string file_02) // open .csv file and intialize
{
    Managment m;
    int temp_f = file_02.length() - 21;
    file_02.erase(21,temp_f);
    ifstream file_m(file_02);
    if(!file_m.good())  // check to see if the file open.
    {
        cout << "File Failed" << endl;
        cout << file_02.length();
    }

    string temp_name, temp_id, temp_pwd; // temp data

    for(int i=0; i<SIZE_m; i++) // loop runs and store info from file to class array.
    {
        getline(file_m, temp_name, ',');
        getline(file_m, temp_id, ',');
        getline(file_m, temp_pwd, '\n');

        user_m[i].setName(temp_name);
        user_m[i].setID(temp_id);
        user_m[i].setPwd(temp_pwd);
    }
    m.mang_info_display(user_m);
    
}
void intialize_user(string file_03) // open .csv file and intialize
{
    int temp_f = file_03.length() - 15;
    file_03.erase(15, temp_f);
    ifstream file_u(file_03); // open .csv file

    if(!file_u.good()) // check to see if file open.
    {
        cout << "File failed" << endl;
    }

    string temp_name, temp_id, temp_pwd; // temp data
    string temp_make, temp_model, temp_plate, temp_year;

    for(int i=1; i<SIZE_u; i++) // loop runs and store info from file to class array.
    {
        getline(file_u, temp_name, ',');
        getline(file_u, temp_id, ',');
        getline(file_u, temp_pwd, ',');
        getline(file_u, temp_make, ',');
        getline(file_u, temp_model, ',');
        getline(file_u, temp_year, ',');
        getline(file_u, temp_plate, '\n');

        user_u[i].setName(temp_name);
        user_u[i].setID(temp_id);
        user_u[i].setPwd(temp_pwd);
        user_u[i].setMake(temp_make);
        user_u[i].setModel(temp_model);
        user_u[i].setYear(stoi(temp_year));
        user_u[i].setPlate(temp_plate);
    }
    display_info_user();
   
}

void admin_func(int admin_id)
{
    int user_input;
    srand(time(0));
    Admin a;
    Managment m;
    User u;
    Ticket t;
    do
    {
        a.admin_func_display();
        cin >> user_input;
        while(user_input<1||user_input>15)
        {
            cout << "Input out of range! Please try again: " << endl;
            cin >> user_input;
        }
        if(user_input == 1) // add admin.
        {
            a.add_admin(user_a);
        }
        else if(user_input == 2) // remove admin.
        {
           a.remove_admin(user_a);
        }
        else if(user_input == 3) // display admin.
        {
            a.admin_info_display(user_a);
        }
        else if(user_input == 4) // search admin.
        {
           a.search_admin(user_a);
        }
        else if(user_input == 5) // change pwd.
        {
            a.pwdChange(user_a, admin_id);
        }
        else if(user_input == 6) // add management.
        {
            m.add_mang(user_m);
        }
        else if(user_input == 7) // remove managmnet.
        {
            m.remove_mang(user_m);
        }
        else if(user_input == 8) // display managment.
        {
            m.mang_info_display(user_m);
        }
        else if(user_input == 9) // search mang.
        {
            m.search_mang(user_m);
        }
        else if(user_input == 10) // remove user.
        {
            u.remove_user(user_u);
        }
        else if(user_input == 11) // view user info.
        {
            u.user_info_display(user_u);
        }
        else if(user_input == 12) // search user.
        {
            u.search_user(user_u);
        }
        else if(user_input == 13) // view appeal info.
        {
            t.view_all_appeals(user_t);    
        }
        else if(user_input == 14) // process an appeal.
        {
            t.process_appeal(user_t);
        }
        else if(user_input == 15)
        {
            break;
        }

        
    }while (user_input >=1 && user_input <=15);


}
void management_func(int mang_id)
{
    int user_input;
    srand(time(0));
    Admin a;
    Managment m;
    User u;
    Ticket t;
    do
    {
        m.mang_func_display();
        cin >> user_input;
        if(user_input<1||user_input>9)
        {
            cout << "Input out of range! try again" << endl;
        }
        if(user_input == 1) // remove user.
        {
            u.remove_user(user_u);
        }
        else if(user_input == 2) // view all user info.
        {
            u.user_info_display(user_u);
        }
        else if(user_input == 3) // search for user.
        {
            u.search_user(user_u);
        }
        else if(user_input == 4) // issue ticket.
        {
            t.add_ticket(user_t, mang_id);
        }
        else if(user_input == 5) // view all ticket info.
        {
            t.ticket_info_display(user_t, mang_id);
        }
        else if(user_input == 6) // view details of specific ticket.
        {
            t.search_ticket(user_t);
        }
        else if(user_input == 7) // remove a ticket.
        {
           t.remove_ticket(user_t);
        }
        else if(user_input == 8) // change password for current account.
        {
            m.pwdChange(user_m, mang_id);
        }
        else if(user_input == 9)
        {
            break;
        }

        
    }while (user_input >=1 && user_input <=9);
}
void user_func(int user_id) // User functionalities. ID of user logged in is passed to this function.
{
    int user_input;
    srand(time(0));
    User u;
    Ticket t;
    do
    {
        u.user_func_display();
        cin >> user_input;
        while(user_input<1||user_input>15) // Checks user input bounds
        {
            cout << "Input out of range! Please try again: " << endl;
            cin >> user_input;
        }
        if(user_input == 1) // Change password
        {
            u.pwdChange(user_u, user_id);
        }
        else if(user_input == 2) // Change Vehicle info
        {
           u.edit_vehicle_info(user_u, user_id);
        }
        else if(user_input == 3) // View vehicle info
        {
            u.view_vehicle_info(user_u, user_id);
        }
        else if(user_input == 4) // View ticket info
        {
            string user_plate;
            user_plate = u.search_plate(user_u, user_id);
            t.view_user_tickets(user_t, user_plate);
        }
        else if(user_input == 5) // Pay ticket
        {
            string user_plate;
            user_plate = u.search_plate(user_u, user_id);
            t.pay_ticket(user_t, user_plate);
        }
        else if(user_input == 6) // Appeal Ticket
        {
            t.appeal_ticket(user_t);
        }
        else if(user_input == 7) // View appeal info
        {
            string user_plate;
            user_plate = u.search_plate(user_u, user_id);
            t.view_appeals(user_t, user_plate);
        }
        else if(user_input == 8) // Log out
        {
            cout << "User logged out." << endl;
            break;
        }
                
    }while (user_input >=1 && user_input <=8);
}

void login()
{
    bool exit = false;
    while(exit == false) // Reprints the menu every time a user logs out
    {
    int login_choice = 0; // user choice.
    int temp_id; // to check with user input.
    string temp_pwd; // to check with user input.
    cout << endl;
    cout << "+-----------------LOGIN---------------+" << endl; // login menu.
    cout << "| Type in 1 to log in to the system   |" << endl;
    cout << "| Type in 2 to register to the system |" << endl;
    cout << "| Tpye in 3 to exit the system        |" << endl;
    cout << "+-----------------LOGIN---------------+" << endl;
    cin >> login_choice;
   switch(login_choice) // switch statment that checks user input and call appropriate functions. 
   {
        case 1:
        {
            bool temp = false;
            cout << "option 1" << endl;           
            do
            {
                cout << "Enter ID: ";
                cin >> temp_id;
                cout << "Enter password: ";
                cin >> temp_pwd;
                for(int i=0;i<user_a.size();i++) // Checks for the ID and password in Admin Vector
                {
                    if(user_a[i].getID() == temp_id && user_a[i].getPwd() == temp_pwd )
                    {
                        admin_func(temp_id);
                        temp = true;;
                        break;                        
                    }
                }
                for(int i=0;i<user_m.size();i++) // Checks for the ID and password in Management Vector
                {
                    if(user_m[i].getID() == temp_id && user_m[i].getPwd() == temp_pwd )
                    {
                        management_func(temp_id);
                        temp = true;
                        break;                        
                    }
                }
                for(int i=0; i<user_u.size(); i++) // Checks for the ID and password in User Vector
                {
                    if(user_u[i].getID() == temp_id && user_u[i].getPwd() == temp_pwd)
                    {
                        user_func(temp_id);
                        temp = true;
                        break;                        
                    }
                }
                if (temp == false)
                    cout << "ID or Password you entered did not match! Please try again." << endl;
            }while(temp == false);
            break;
        }
        case 2: // Registration
            user_registration();
            break;
        case 3: // Shut down the program
            cout << "Program closing." << endl;
            exit = true;
            break;
        default: // Input validation
            cout << "Error! Wrong input." << endl;
            break;
    }
    }
}
void user_registration() // 
{
    string Name, Id, Make, Model, Plate_num, Pwd;
    int Year;
    User u;
    bool id_check = true;
    
    // Get user info for registration
    cout << "Please enter your information." << endl;
    cout << "\nName: ";
    cin.ignore();
    getline(cin, Name);

    do // Input validation for ID. Must be unique and 8 digits.
    {
        cout << "\nID(Must be 8 digits): ";
        cin >> Id;
        if(Id.length() == 8)
        {
            id_check = true;
        }
        else
        {
            cout << "\nID must be 8 digits. Please try again.";
            id_check = false;
        }
        

        for(int i=0; i<user_u.size(); i++)
        {
            if(user_u[i].getID() == stoi(Id))
            {
                id_check = false;
                cout << "\nThis ID is already in use, please try another ID.";
            }
        }

    }while(id_check == false);

    cout << "Password(Case Sensitive): ";
    cin >> Pwd;
    cout << "Make: ";
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


    // Add user to the User vector
    u.setName(Name);
    u.setID(Id);
    u.setPwd(Pwd);
    u.setMake(Make);
    u.setModel(Model);
    u.setYear(Year);
    u.setPlate(Plate_num);
    user_u.push_back(u);
    cout << "\nVehicle information has been updated." << endl;
}