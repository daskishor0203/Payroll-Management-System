#include <bits/stdc++.h>
#include "address.cpp"
using namespace std;

class Employee : public Address
{
private:
    string name, gender, location, department, employee_type, band, pf_number, bank_account_number;
    int id;
    float ctc;
    map<string, map<string, float>> salary_slips;

public:
    static int employee_id;
    Employee() {}
    Employee(string name, string gender, string d_num, string srt, string ar, string ct, string pn, string location, string department, string employee_type, string band, string pf_number, string bank_account_number, float ctc)
    {
        this->id = employee_id;
        this->name = name;
        this->gender = gender;
        set_door_number(d_num);
        set_street(srt);
        set_area(ar);
        set_city(ct);
        set_pin(pn);
        this->location = location;
        this->department = department;
        this->band = band;
        this->pf_number = pf_number;
        this->bank_account_number = bank_account_number;
        this->employee_type = employee_type;
        this->ctc = ctc;
        employee_id++;
    }

    // setters
    void set_name(string name)
    {
        this->name = name;
    }
    void set_location(string location)
    {
        this->location = location;
    }
    void set_department(string department)
    {
        this->department = department;
    }
    void set_employee_type(string employee_type)
    {
        this->employee_type = employee_type;
    }
    void set_band(string band)
    {
        this->band = band;
    }
    void set_pf_number(string pf_number)
    {
        this->pf_number = pf_number;
    }
    void set_bank_account_number(string bank_account_number)
    {
        this->bank_account_number = bank_account_number;
    }
    void set_ctc(float ctc)
    {
        this->ctc = ctc;
    }

    // getters
    int get_id()
    {
        return this->id;
    }
    string get_name()
    {
        return this->name;
    }
    string get_gender()
    {
        return this->gender;
    }
    string get_location()
    {
        return this->location;
    }
    string get_department()
    {
        return this->department;
    }
    string get_employee_type()
    {
        return this->employee_type;
    }
    string get_band()
    {
        return this->band;
    }
    string get_pf_number()
    {
        return this->pf_number;
    }
    string get_bank_account_number()
    {
        return this->bank_account_number;
    }
    float get_ctc()
    {
        return this->ctc;
    }

    map<string, map<string, float>> get_pay_slip()
    {
        return this->salary_slips;
    }

    void show_pay_slip(string month_of_pay, Employee obj)
    {
        if (obj.salary_slips.find(month_of_pay) == salary_slips.end())
        {
            cout << "\nSalary slip of this month " << month_of_pay << " is not generated\n";
        }
        else
        {
            cout << "\nSalary slip of this month " << month_of_pay << " is as followed\n";
            cout << "Basic salary: " << obj.salary_slips[month_of_pay]["Basic salary"] << "\n";
            cout << "VPP: " << obj.salary_slips[month_of_pay]["VPP"] << "\n";
            cout << "PF: " << obj.salary_slips[month_of_pay]["PF"] << "\n";
            cout << "Other allowances: " << obj.salary_slips[month_of_pay]["Other allowances"] << "\n";
            cout << "Income tax: " << obj.salary_slips[month_of_pay]["Income tax"] << "\n";
            cout << "Mess bill: " << obj.salary_slips[month_of_pay]["Mess bill"] << "\n";
            cout << "Net pay: " << obj.salary_slips[month_of_pay]["Net pay"] << "\n";
            cout << "Gross pay: " << obj.salary_slips[month_of_pay]["Gross pay"] << "\n";
        }
    }

    void generate_salary_slip(string month_of_pay, float mess_bill, Employee obj)
    {
        float c_t_c = obj.ctc * 100000.0;
        cout << c_t_c << "\n";
        float ctcPermonth = c_t_c / 12;
        float basicSalary = (ctcPermonth * 60) / 100;
        float vpp = (ctcPermonth * 30) / 100;
        float pf = (ctcPermonth * 5) / 100;
        float otherAllowance = (ctcPermonth * 5) / 100;
        float incomeTex = 0;
        if (c_t_c < 500000)
        {
            incomeTex = 0;
        }
        else if (c_t_c >= 500000 && c_t_c <= 1000000)
        {
            incomeTex = (ctcPermonth * 5) / 100;
        }
        else if (c_t_c > 1000000 && c_t_c <= 1500000)
        {
            incomeTex = (ctcPermonth) / 10;
        }
        else if (c_t_c > 1500000 && c_t_c <= 2000000)
        {
            incomeTex = (ctcPermonth * 15) / 100;
        }
        else
        {
            incomeTex = (ctcPermonth) / 5;
        }
        float grossPay = basicSalary + vpp + pf + otherAllowance;
        float netPay = grossPay - incomeTex - mess_bill;
        obj.salary_slips[month_of_pay]["Basic salary"] = basicSalary;
        obj.salary_slips[month_of_pay]["VPP"] = vpp;
        obj.salary_slips[month_of_pay]["PF"] = pf;
        obj.salary_slips[month_of_pay]["Other allowances"] = otherAllowance;
        obj.salary_slips[month_of_pay]["Income tax"] = incomeTex;
        obj.salary_slips[month_of_pay]["Mess bill"] = mess_bill;
        obj.salary_slips[month_of_pay]["Net pay"] = netPay;
        obj.salary_slips[month_of_pay]["Gross pay"] = grossPay;

        show_pay_slip(month_of_pay, obj);
    }
};