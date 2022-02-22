#ifndef USER_H_
#define USER_H_
#include <string>
#include <vector>
using namespace std;
class User
{
private:
    string user_name;
    int user_id;
    string user_pwd;
    string car_make;
    string car_model;
    int car_year;
    string car_plate;

public:
    User();
    // set user info
    void setName(string name);
    void setID(string id);
    void setPwd(string p);
    void setMake(string make);
    void setModel(string model);
    void setYear(int year);
    void setPlate(string plate);
    // gets user info
    string getName() const;
    int getID() const;
    string getPwd() const;
    string getMake() const;
    string getModel() const;
    int getYear() const;
    string getPlate() const;
    // user funcnalities.
    void user_func_display();
    void pwdChange(vector<User> &user_u, int);
    void edit_vehicle_info(vector<User> &user_u, int);
    void view_vehicle_info(vector<User> &user_u, int);
    void user_info_display(vector<User> &user_u);
    void remove_user(vector<User> &user_u);
    void search_user(vector<User> &user_u);
    string search_plate(vector<User> &user_u, int user_id);
};
#endif
