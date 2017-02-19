/*
 Random inheritance example from a school assignment.
 */

#include <iostream>


class Employee
{
public:
    Employee();
    Employee(std::string the_name, std::string the_ssn,double the_net_pay);
    std::string get_name() const;
    std::string get_ssn() const;
    double get_net_pay() const;
    void set_name(std::string new_name);
    void set_ssn(std::string new_ssn);
    void set_net_pay(double new_net_pay);
    virtual void print_check() const;
private:
    std::string name;
    std::string ssn;
    double net_pay;
};

class AdminEmployee: public Employee
{
public:
    AdminEmployee();
    AdminEmployee(std::string the_name,std::string the_ssn,double the_net_pay,std::string the_title,std::string the_responsibility,std::string the_supervisor);
    std::string get_responsibility() const;
    std::string get_supervisor() const;
    std::string get_title() const;
    void print_check( );
    void set_responsibility(std::string new_responbility);
    void set_supervisor(std::string  new_supervisor);
    void set_title(std::string new_title);
    void to_string();
protected:
    double annual_salary;
private:
    std::string responsibility;
    std::string supervisor;
    std::string title;
};

int main(int argc, const char * argv[]) {
    
    Employee man;
    man.print_check();
    Employee firstEmployee("Chris", "222-33-4444",15);
    firstEmployee.print_check();
    AdminEmployee employee;
    employee.print_check();
    employee.to_string();
    AdminEmployee smith("Tobias Sammett" , "111-11-1111" , 20000.00, "General Manager" , "Slack off" , "B.B. King");
    smith.print_check();
    smith.to_string();
    return 0;
}

Employee::Employee( ) : name("No name yet "), ssn(" No number yet "), net_pay(0)
{
    //deliberately empty
}

Employee::Employee(std::string the_name, std::string the_number,double the_net_pay ) : name(the_name), ssn(the_number), net_pay(the_net_pay)
{
    //deliberately empty
}

std::string Employee::get_name( ) const
{
    return name;
}

std::string Employee::get_ssn( ) const
{
    return ssn;
}

double Employee::get_net_pay( ) const
{
    return net_pay;
}

void Employee::set_name(std::string new_name)
{
    name = new_name;
}

void Employee::set_ssn(std::string new_ssn)
{
    ssn = new_ssn;
}

void Employee::set_net_pay (double new_net_pay)
{
    net_pay = new_net_pay;
}

void Employee::print_check( ) const
{
    //If I wanted to know what they held
    //cout << "Name: " << name << " SSN: " << ssn << " Net Pay: " << net_pay << endl;
    
    std::cout << "\nERROR: print_check FUNCTION CALLED FOR AN \n"
    << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
    << "Check with the author of the program about this bug.\n" << std::endl;
    
}

AdminEmployee::AdminEmployee()
{
    Employee();
    annual_salary = 0.0;
    title = "no title";
    responsibility =  "no responsibility";
    supervisor = " no supervisor";
}

AdminEmployee::AdminEmployee(std::string the_name,std::string the_ssn,double the_net_pay,std::string the_title,std::string the_responsibility,std::string the_supervisor):
Employee(the_name,the_ssn,the_net_pay),title(the_title),responsibility(the_responsibility),supervisor(the_supervisor)
{
    
    // delibirately empty
}

std::string AdminEmployee::get_responsibility() const
{
    return responsibility;
}

std::string AdminEmployee::get_supervisor() const
{
    return supervisor;
}

std::string AdminEmployee::get_title() const
{
    return title;
}

void AdminEmployee::set_responsibility(std::string new_responsibility)
{
    responsibility = new_responsibility;
}

void AdminEmployee::set_supervisor(std::string new_supervisor)
{
    supervisor = new_supervisor;
}

void AdminEmployee::set_title(std::string new_title)
{
    title = new_title;
}

void AdminEmployee::print_check( )
{
    std::cout << "\n________________________________________________\n";
    std::cout << "Pay to the order of " << get_name( ) << std::endl;
    std::cout << "The sum of " << get_net_pay( ) << " Dollars\n";
    std::cout << "________________________________________________\n";
    std::cout << "Check Stub: NOT NEGOTIABLE\n";
    std::cout << "Employee Number: " << get_ssn( ) << std::endl;
    std::cout << "Pay: " << get_net_pay( ) << std::endl;
    std::cout << "_________________________________________________\n";
    
}

void AdminEmployee::to_string()
{
    annual_salary = get_net_pay() * 0.5;
    std::cout << "Annual salary: " << annual_salary << std::endl;
    std:: cout << "Title: " << get_title() << std::endl;
    std::cout << "Responsibility: " << get_responsibility() << std::endl;
    std::cout << "Supervisor: " << get_supervisor() << "\n" << std::endl;
}
