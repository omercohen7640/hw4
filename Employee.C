//
// Created by omerc on 28/12/2019.
//

#include "Employee.H"
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
Employee::Employee( char *name, int salary, char **hours) :name_(name),hours_(hours),salary_(salary)
{
    //name_ = name;
    //hours_ = hours;
}

Employee::~Employee(){}

char* Employee::getName() const
{
    return name_;
}

int Employee::getSalary() {
    return salary_;
}

void shift_cpy(char* dest, const char* src){
    int i;
    for (i = 0; i < 5; ++i) {
        *(dest + i) = *(src + i);
    }
    *(dest + i) = '\0';
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
    char shift[6];
    char* hour;
    for (int i = 0; i < 7; i++)
    {
        shift_cpy(shift,*(hours_+i));
        hour = strtok(shift,delimiters);
        begin = atoi(hour);
        hour = strtok(NULL,delimiters);
        end = atoi(hour);
        if (begin > end) sum = sum + (24 - begin)*salary_ + end * salary_;
        else sum = sum + (end - begin)*salary_;
    }
    return sum;
}