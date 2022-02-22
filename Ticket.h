#ifndef TICKET_H_
#define TICKET_H_
#include <string>
#include <vector>

using namespace std;

class Ticket
{
private:
    string plateID;
    int ticket_num;
    int ticket_amount;
    int issued_by;
    string ticket_status;
    string reason;

    string appeal_status;
    int processor_id;
    string appeal_description;

public:
    Ticket();
    // set ticket info
    void setCarPlate(string carPlate);
    void setTicketNumber(string t_num);
    void setTicketAmount(string t_amount);
    void setAppealStatus(string t_status);
    void setAppealDescription(string t_description);
    void setIssuedBy(int issued);
    void setTicketStatus(string t_status);
    void setTicketReason(string t_reason);
    // get ticket info
    string getCarPlate() const;
    int getTicketNumber() const;
    int getTicketAmount() const;
    int getIssuedBy() const;
    string getTicketStatus() const;
    string getTicketReason() const;
    string getAppealStatus() const;
    string getAppealDescription() const;
    // ticket funcnalites
    void ticket_func_display();
    void pwdChange(vector<Ticket> &user_t, int);
    void remove_ticket(vector<Ticket> &user_t);
    void add_ticket(vector<Ticket> &user_t, int mang_id);
    void ticket_info_display(vector<Ticket> &user_t, int mang_id);
    void search_ticket(vector<Ticket> &user_t);
    void view_user_tickets(vector<Ticket> &user_t, string user_plate);
    void pay_ticket(vector<Ticket> &user_t, string user_plate);
    void appeal_ticket(vector<Ticket> &user_t);
    void view_all_appeals(vector<Ticket> &user_t);
    void view_appeals(vector<Ticket> &user_t, string user_plate);
    void process_appeal(vector<Ticket> &user_t);
};
#endif
