#ifndef ADMIN_H_
#define ADMIN_H_
#include <string>
#include <vector>

using namespace std;

class Admin
{
private:
    std::string user_name;
    int user_id;
    std::string user_pwd;
    
public:   
    
    Admin();
    void setName(string name);
    void setID(string id);
    void setPwd(string p);

    string getName() const;
    int getID() const;
    string getPwd() const;

    void admin_info_display(vector<Admin> &user_a);
    void admin_func_display();
    void pwdChange(vector<Admin> &user_a, int);

    void add_admin(vector<Admin> &user_a); 
    void remove_admin(vector<Admin> &user_a);
    void search_admin(vector<Admin> &user_a);
};
#endif