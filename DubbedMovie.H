//
// Created by omerc on 28/12/2019.
//

#ifndef HW_4_DUBBEDMOVIE_H
#define HW_4_DUBBEDMOVIE_H

#include "Movie.H"
#include "Theater.H"
#include "Mat.H"


//class Cashier : public Employee
class DubbedMovie : public Movie{
    public:
/*********************************************************************************
Function name: DubbedMovie
Description: constructor
Parameters: HEBtheaterNum - number of theater
Return value: None
**********************************************************************************/
        DubbedMovie (char* name, int length, char* language, int theaterNum, int HEBtheaterNum);
/*********************************************************************************
Function name: ~DubbedMovie
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
    ~DubbedMovie();
/*********************************************************************************
Function name: getHebrewTheaterNum
Description: gets the theater number of this movie
Parameters: None
Return value: int - the number of the theater
**********************************************************************************/
        int getHebrewTheaterNum();
/*********************************************************************************
Function name: getNextHebrewScreening
Description: gets the next screening
Parameters: date - the day
            hour - the time
Return value: int - the hour of the next screening
**********************************************************************************/
        int getNextHebrewScreening(int date, int hour);
/*********************************************************************************
Function name: addHebrewScreening
Description: adds a screening
Parameters: day- the day
            hour - the time
Return value: BOOL - adding failed or succeeded
**********************************************************************************/
        BOOL addHebrewScreening(int day, int hour);

    protected:
        int HEBTheaterNum_;
        Mat HEBScreeningTime_;



};


#endif //HW_4_DUBBEDMOVIE_H
