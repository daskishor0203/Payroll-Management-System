#include <bits/stdc++.h>
using namespace std;

class Address
{
private:
    string door_number, street, area, city, pin;

public:
    // setters
    void set_door_number(string door_number)
    {
        this->door_number = door_number;
    }
    void set_street(string street)
    {
        this->street = street;
    }
    void set_area(string area)
    {
        this->area = area;
    }
    void set_city(string city)
    {
        this->city = city;
    }
    void set_pin(string pin)
    {
        this->pin = pin;
    }

    // getters
    string get_door_number()
    {
        return this->door_number;
    }
    string get_street()
    {
        return this->street;
    }
    string get_area()
    {
        return this->area;
    }
    string get_city()
    {
        return this->city;
    }
    string get_pin()
    {
        return this->pin;
    }
};