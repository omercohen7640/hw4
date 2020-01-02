//
// Created by omerc on 28/12/2019.
//

#include "Employee.h"
/*
Employee::Employee() : salary_(0)
{
    name_ = new
    strcpy(name_,"");
    for (int i=0;i<7;i++)
    {
        strcpy(hours_[i],"");
    }

}
*/
Employee::Employee( char *name, int salary, char **hours) : salary_(salary)
{
    name_ = name;
    hours_ = hours;
}

Employee::~Employee()
{
    for (int i = 0; i < 7; i++) {
        delete *(hours_ + i);
    }
    delete hours_;
}

char* Employee::getName() const
{
    return name_;
}

int Employee::getSalary() {
    return salary_;
}

/*********************************************************************************
Function name: calcWeeklySalary
Description: calculate the weekly salary of an employee
Parameters: -
Return value: weekly salary of an employee
**********************************************************************************/
int Employee::calcWeeklySalary(){
    const char* delimiters = "-";
    int begin, end, sum=0;
    char shift[5];
    char* hour;
    for (int i = 0; i < 7; i++)
    {
        strcpy_s(shift,5,*(hours_+i));
        hour = strtok(shift,delimiters);
        begin = atoi(strtok(NULL,delimiters));
        end = atoi(strtok(NULL,delimiters));
        if (begin > end) sum = sum + (24 - begin)*salary_ + end * salary_;
        else sum = sum + (end - begin)*salary_;
    }
    return sum;
}