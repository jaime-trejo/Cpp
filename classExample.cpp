/*
 An example of using classes in cpp by using a certificate of deposit example.
 
 */

#include<iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance();
    double get_balance_at_maturity();
    double get_interest_rate();
    int get_term();
    void input(istream &istr);
    void output(ostream &ostr);
private:
    double balance;
    double interest_rate;
    int term;
    
};

int main(int argc, const char * argv[]) {
    CDAccount account(100,10.0,6);//create account object, new bal = 100, new interest rate = 10, new term = 6
    account.output(cout);
    cout << "Enter account balance, interest rate, months: " << endl;
    account.input(cin);
    cout << endl;
    account.output(cout);
    
    return 0;
}

CDAccount::CDAccount()
{
    balance = 0;
    interest_rate = 0;
    term = 0;
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    balance = new_balance;
    interest_rate = new_interest_rate;
    term = new_term;
}

double CDAccount::get_initial_balance()
{
    return balance;
}

double CDAccount::get_balance_at_maturity()
{
    double interest = balance * (interest_rate / 100) * (term /12.0);
    return balance + interest;
}

double CDAccount::get_interest_rate()
{
    return interest_rate;
}

int CDAccount::get_term()
{
    return term;
}

void CDAccount::input(istream &istr)
{
    istr >> balance;
    istr >> interest_rate;
    istr >> term;
}

void CDAccount::output(ostream &ostr)
{
    ostr.setf(ios::fixed);
    ostr.setf(ios::showpoint);
    ostr.precision(2);
    ostr << "CDAccount initial balance: " << get_initial_balance() << endl;
    ostr << "CDAccount interest rate: " << get_interest_rate() << endl;
    ostr << "When your CDAccount matures in " << get_term() << " months " << endl;
    ostr << "it will have a balance of " << get_balance_at_maturity() << " dollars." << endl;
    ostr << endl;
}

