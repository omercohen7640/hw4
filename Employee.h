//
// Created by omerc on 28/12/2019.
//

#ifndef HW_4_EMPLOYEE_H
#define HW_4_EMPLOYEE_H
#include <string.h>
#include <stdlib.h>

class Employee {
public:
    /*********************************************************************************
    Function name: employee
    Description: no parameters c'tor
    Parameters: -
    Return value: -
    **********************************************************************************/
  //  Employee();

    /*********************************************************************************
    Function name: employee
    Description: with parameters c'tor
    Parameters:
    name- employee name
    salary - employee salary
     hours[] - array of 7 wth work hours string
    Return value: -
    **********************************************************************************/
    Employee( char *name, int salary, char **hours);

    /*********************************************************************************
    Function name: ~employee
    Description: d'tor
    Parameters: -
    Return value: -
    **********************************************************************************/
    virtual ~Employee();

    /*********************************************************************************
    Function name: getname
    Description: getter
    Parameters: -
    Return value: employee name
    **********************************************************************************/
    char* getName() const;

    /*********************************************************************************
    Function name: getsalary
    Description: getter
    Parameters: -
    Return value: employee salary
    **********************************************************************************/
    int getSalary();

    /*********************************************************************************
    Function name: calcWeeklySalary
    Description: calculate the weekly salary of an employee
    Parameters: -
    Return value: weekly salary of an employee
    **********************************************************************************/
    int calcWeeklySalary();
protected:
    char** hours_;
    char *name_;
    int salary_;
};
#endif //HW_4_EMPLOYEE_H
