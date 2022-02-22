#ifndef MANG_H_
#define MANG_H_
#include <string>
#include <vector>
using namespace std;
class Managment
{
private:
    string user_name;
    int user_id;
    string user_pwd;
    
public:
    Managment();
    void setName(string name);
    void setID(string id);
    void setPwd(string p);
    string getName() const;
    int getID() const;
    string getPwd() const;
    void print_info(int SIZE) const;

    void mang_info_display(vector<Managment> &user_m);
    void pwdChange(vector<Managment> &user_m, int);

    void add_mang(vector<Managment> &user_m);
    void search_mang(vector<Managment> &user_m);
    void remove_mang(vector<Managment> &user_m);

    void mang_func_display();
};
#endif