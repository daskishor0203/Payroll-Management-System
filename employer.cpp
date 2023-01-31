#include <bits/stdc++.h>
#include "employee.cpp"
using namespace std;

class Employer : protected Employee
{
private:
    string company_name;
    vector<string> locations, bands, departments;
    map<int, Employee> employee_dictionary;

public:
    Employer() = default;
    Employer(string company_name, vector<string> locations, vector<string> bands, vector<string> departments)
    {
        this->company_name = company_name;
        this->locations = locations;
        this->bands = bands;
        this->departments = departments;
    }
    void add_user(string name, string gender, string door_number, string street, string area, string city, string pin, string location, string department, string employee_type, string band, string pf_number, string account_number, float ctc)
    {
        int e_id = Employee::employee_id;
        Employee emp(name, gender, door_number, street, area, city, pin, location, department, employee_type, band, pf_number, account_number, ctc);
        employee_dictionary[e_id] = emp;
    }
    void print_all_employees()
    {
        if (employee_dictionary.size() == 0)
        {
            cout << "\nThe employee list is empty\n";
        }
        else
        {
            cout << "\n";
            int i = 1;
            for (auto x : employee_dictionary)
            {
                cout << i << ".";
                cout << "\nEmployee Id: " << x.second.get_id() << "\n";
                cout << "\nEmployee Name: " << x.second.get_name() << "\n";
                cout << "\nEmployee Gender: " << x.second.get_gender() << "\n";
                cout << "\nEmployee Door Number: " << x.second.get_door_number() << "\n";
                cout << "\nEmployee street: " << x.second.get_street() << "\n";
                cout << "\nEmployee area: " << x.second.get_area() << "\n";
                cout << "\nEmployee city: " << x.second.get_city() << "\n";
                cout << "\nEmployee pin: " << x.second.get_pin() << "\n";
                cout << "\nEmployee location: " << x.second.get_location() << "\n";
                cout << "\nEmployee department: " << x.second.get_department() << "\n";
                cout << "\nEmployee type: " << x.second.get_employee_type() << "\n";
                cout << "\nEmployee band: " << x.second.get_band() << "\n";
                cout << "\nEmployee pf number: " << x.second.get_pf_number() << "\n";
                cout << "\nEmployee bank account number: " << x.second.get_bank_account_number() << "\n";
                cout << "\nEmployee CTC: " << x.second.get_ctc() << "\n";
                i++;
            }
        }
    }
    void modify_user(int emp_id)
    {
        if (employee_dictionary.find(emp_id) == employee_dictionary.end())
        {
            cout << "\nEmployee does not exist.\n\n";
        }
        else
        {
            cout << "\n-------Menu--------";
            cout << "\n1. Change name of the employee\n2. Change address of the employee\n3. Change location of the employee\n4. Change department of the employee\n5. Change employee type of the employee\n6. Change band of the employee\n7. Change bank account number of the employee\n8. Change CTC of the employee\n";
            int ch;
            cout << "\nEnter your choice: ";
            cin >> ch;
            if (ch == 1)
            {
                cout << "\n Enter the name of the employee: ";
                string n;
                getline(cin >> ws, n);
                employee_dictionary[emp_id].set_name(n);
            }
            else if (ch == 2)
            {
                cout << "\n Enter the door number of the employee: ";
                string dn;
                getline(cin >> ws, dn);
                employee_dictionary[emp_id].set_door_number(dn);
                cout << "\n Enter the street of the employee: ";
                string st;
                getline(cin >> ws, st);
                employee_dictionary[emp_id].set_street(st);
                cout << "\n Enter the area of the employee: ";
                string ar;
                getline(cin >> ws, ar);
                employee_dictionary[emp_id].set_area(ar);
                cout << "\n Enter the city of the employee: ";
                string cy;
                getline(cin >> ws, cy);
                employee_dictionary[emp_id].set_city(cy);
                cout << "\n Enter the pin of the employee: ";
                string pi;
                getline(cin >> ws, pi);
                employee_dictionary[emp_id].set_city(pi);
            }
            else if (ch == 3)
            {
                cout << "\n Enter the location of the employee: ";
                string lc;
                getline(cin >> ws, lc);
                employee_dictionary[emp_id].set_location(lc);
            }
            else if (ch == 4)
            {
                cout << "\n Enter the department of the employee: ";
                string dp;
                getline(cin >> ws, dp);
                employee_dictionary[emp_id].set_department(dp);
            }
            else if (ch == 5)
            {
                cout << "\n Enter the employee type of the employee: ";
                string etp;
                getline(cin >> ws, etp);
                employee_dictionary[emp_id].set_employee_type(etp);
            }
            else if (ch == 6)
            {
                cout << "\n Enter the band of the employee: ";
                string bn;
                getline(cin >> ws, bn);
                employee_dictionary[emp_id].set_band(bn);
            }
            else if (ch == 7)
            {
                cout << "\n Enter the bank account number of the employee: ";
                string bacn;
                getline(cin >> ws, bacn);
                employee_dictionary[emp_id].set_band(bacn);
            }
            else if (ch == 8)
            {
                cout << "\n Enter the CTC of the employee: ";
                string cc;
                getline(cin >> ws, cc);
                employee_dictionary[emp_id].set_band(cc);
            }

            cout << "\nAfter Changes of the employee details the employee list is as follows: \n";
            print_all_employees();
        }
    }

    void search_employee(int emp_id)
    {
        if (employee_dictionary.find(emp_id) == employee_dictionary.end())
        {
            cout << "\nEmployee does not exist\n\n";
        }
        else
        {
            cout << "\nThe employee details is given below:\n\n";
            cout << "\nEmployee Id: " << employee_dictionary[emp_id].get_id() << "\n";
            cout << "\nEmployee Name: " << employee_dictionary[emp_id].get_name() << "\n";
            cout << "\nEmployee Gender: " << employee_dictionary[emp_id].get_gender() << "\n";
            cout << "\nEmployee Door Number: " << employee_dictionary[emp_id].get_door_number() << "\n";
            cout << "\nEmployee street: " << employee_dictionary[emp_id].get_street() << "\n";
            cout << "\nEmployee area: " << employee_dictionary[emp_id].get_area() << "\n";
            cout << "\nEmployee city: " << employee_dictionary[emp_id].get_city() << "\n";
            cout << "\nEmployee pin: " << employee_dictionary[emp_id].get_pin() << "\n";
            cout << "\nEmployee location: " << employee_dictionary[emp_id].get_location() << "\n";
            cout << "\nEmployee department: " << employee_dictionary[emp_id].get_department() << "\n";
            cout << "\nEmployee type: " << employee_dictionary[emp_id].get_employee_type() << "\n";
            cout << "\nEmployee band: " << employee_dictionary[emp_id].get_band() << "\n";
            cout << "\nEmployee pf number: " << employee_dictionary[emp_id].get_pf_number() << "\n";
            cout << "\nEmployee bank account number: " << employee_dictionary[emp_id].get_bank_account_number() << "\n";
            cout << "\nEmployee CTC: " << employee_dictionary[emp_id].get_ctc() << "\n";
        }
    }

    void remove_employee(int emp_id)
    {
        if (employee_dictionary.find(emp_id) == employee_dictionary.end())
        {
            cout << "\nEmployee does not exist\n";
        }
        else
        {
            search_employee(emp_id);
            employee_dictionary.erase(emp_id);
            cout << "\nEmployee with id: " << emp_id << " deleted successfully\n";
        }
    }

    void generate_pay_slip(int emp_id)
    {
        if (employee_dictionary.find(emp_id) == employee_dictionary.end())
        {
            cout << "\nEmployee does not exist\n";
        }
        else
        {
            cout << "\nEnter the month and year in the mm-yyyy format: ";
            string mon_year;
            getline(cin >> ws, mon_year);
            if (employee_dictionary[emp_id].get_pay_slip().find(mon_year) == get_pay_slip().end())
            {
                cout << "\nSalary slip is already exist of this month\n";
                show_pay_slip(mon_year, employee_dictionary[emp_id]);
            }
            else
            {
                cout << "\nEnter mess bill of the month: ";
                float m_bill;
                cin >> m_bill;
                generate_salary_slip(mon_year, m_bill, employee_dictionary[emp_id]);
            }
        }
    }
};