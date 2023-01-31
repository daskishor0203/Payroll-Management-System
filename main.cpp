#include <bits/stdc++.h>
#include "employer.cpp"
using namespace std;

vector<Employer> company_list;

int Employee::employee_id = 1;

int main()
{

    string company_name;
    int no_of_locations, no_of_bands, no_of_departments;
    cout << "\nEnter the company name: ";
    getline(cin >> ws, company_name);
    cout << "\nEnter the number of locations in the company: ";
    cin >> no_of_locations;
    vector<string> locations(no_of_locations);
    for (int i = 0; i < no_of_locations; i++)
    {
        cout << "\nEnter the name of the location: ";
        getline(cin >> ws, locations[i]);
    }
    cout << "\nEnter the number of bands in the company: ";
    cin >> no_of_bands;
    vector<string> bands(no_of_bands);
    for (int i = 0; i < no_of_bands; i++)
    {
        cout << "\nEnter the name of the band: ";
        getline(cin >> ws, bands[i]);
    }
    cout << "\nEnter the number of departments in the company: ";
    cin >> no_of_departments;
    vector<string> departments(no_of_departments);
    for (int i = 0; i < no_of_departments; i++)
    {
        cout << "\nEnter the name of the department: ";
        getline(cin >> ws, departments[i]);
    }

    // creating an object of the employer and putting all the values of the fields
    Employer cmp_obj(company_name, locations, bands, departments);
    int c1;
    cout << "\n-------Menu-------\n1. To add employee in this company\n2. To modify employee details of this company\n3. To remove employee from this company\n4. To search an employee of this company\n5. To print all the employee details of this company\n6. To genearate the pay slip of an particular employee of this company\n7. Exit\n";
    cin >> c1;
    while (c1 != 7)
    {
        if (c1 == 1)
        {
            string name, gender, door_number, street, area, city, pin, location, department, employee_type, band, pf_number, bank_account_number;
            float ctc;
            cout << "\nEnter the name of the employee: ";
            getline(cin >> ws, name);
            cout << "\nEnter the gender of the employee\n\tmale or female: ";
            getline(cin >> ws, gender);
            cout << "\nEnter the door number/gate/building where the employee lives: ";
            getline(cin >> ws, door_number);
            cout << "\nEnter the street where the employee lives: ";
            getline(cin >> ws, street);
            cout << "\nEnter the area where the employee lives: ";
            getline(cin >> ws, area);
            cout << "\nEnter the city where the employee lives: ";
            getline(cin >> ws, city);
            cout << "\nEnter the pin where the employee lives: ";
            getline(cin >> ws, pin);
            cout << "\nEnter the base location of the employee from the given locations\n";
            for (int j = 0; j < locations.size(); j++)
            {
                cout << "    " << locations[j] << "\n";
            }
            cout << "\t: ";
            getline(cin >> ws, location);
            cout << "\nEnter the band of the employee from the given bands\n";
            for (int j = 0; j < bands.size(); j++)
            {
                cout << "    " << bands[j] << "\n";
            }
            cout << "\t: ";
            getline(cin >> ws, band);
            cout << "\nEnter the department of the employee from the given departments\n";
            for (int j = 0; j < departments.size(); j++)
            {
                cout << "    " << departments[j] << "\n";
            }
            cout << "\t: ";
            getline(cin >> ws, department);
            cout << "\nEnter the employee type from the given types\n\tpermanent\n\tpart-time\n\tcontrator\n\t:";
            getline(cin >> ws, employee_type);
            cout << "\nEnter the employee pf number: ";
            getline(cin >> ws, pf_number);
            cout << "\nEnter the employee bank account number: ";
            getline(cin >> ws, bank_account_number);
            cout << "\nEnter the ctc(in Lakhs per annum) of the employee: ";
            cin >> ctc;

            cmp_obj.add_user(name, gender, door_number, street, area, city, pin, location, department, employee_type, band, pf_number, bank_account_number, ctc);
        }

        else if (c1 == 2)
        {
            int emp_id;
            cout << "\nEnter the employee id of the employee which you want to be modified:";
            cin >> emp_id;
            cmp_obj.modify_user(emp_id);
        }

        else if (c1 == 3)
        {
            int emp_id;
            cout << "\nEnter the employee id of the employee which you want to delete:";
            cin >> emp_id;
            cmp_obj.remove_employee(emp_id);
        }

        else if (c1 == 4)
        {
            int emp_id;
            cout << "\nEnter the employee id of the employee which you want to search:";
            cin >> emp_id;
            cmp_obj.search_employee(emp_id);
        }

        else if (c1 == 5)
        {
            cmp_obj.print_all_employees();
        }

        else if (c1 == 6)
        {
            int emp_id;
            cout << "\nEnter the employee id of the employee of which salary slip to be generated:";
            cin >> emp_id;
            cmp_obj.generate_pay_slip(emp_id);
        }

        cout << "-------Menu-------\n1. To add employee in this company\n2. To modify employee details of this company\n3. To remove employee from this company\n4. To search an employee of this company\n5. To print all the employee details of this company\n6. To genearate the pay slip of an particular employee of this company\n7. To Exit\n";
        cin >> c1;
    }

    cout << "\n";
    return 0;
}