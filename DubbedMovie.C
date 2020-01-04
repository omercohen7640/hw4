//
// Created by omerc on 28/12/2019.
//

#include "DubbedMovie.H"


/*********************************************************************************
Function name: DubbedMovie
Description: constructor
Parameters: HEBtheaterNum - number of theater
Return value: None
**********************************************************************************/
DubbedMovie::DubbedMovie(char *name, int length, char *language, int theaterNum, int HEBtheaterNum) :
                            Movie(name, length, language, theaterNum), HEBTheaterNum_(HEBtheaterNum), HEBScreeningTime_(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY) {}
/*********************************************************************************
Function name: ~DubbedMovie
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
DubbedMovie::~DubbedMovie(){}
/*********************************************************************************
Function name: getHebrewTheaterNum
Description: gets the theater number of this movie
Parameters: None
Return value: int - the number of the theater
**********************************************************************************/
int DubbedMovie::getHebrewTheaterNum()
{
    return HEBTheaterNum_;
}
/*********************************************************************************
Function name: getNextHebrewScreening
Description: gets the next screening
Parameters: date - the day
            hour - the time
Return value: int - the hour of the next screening
**********************************************************************************/
int DubbedMovie::getNextHebrewScreening(int date, int hour)
{
    for (int i = 0; i <MAX_SCREENINGS_PER_DAY ; ++i) {
        if (HEBScreeningTime_.getElement(date, i+1) > hour)
        {
            return HEBScreeningTime_.getElement(date, i+1);
        }
    }
    return FALSE;
}
/*********************************************************************************
Function name: addHebrewScreening
Description: adds a screening
Parameters: day - the day
            hour - the time
Return value: BOOL - adding failed or succeeded
**********************************************************************************/
BOOL DubbedMovie::addHebrewScreening(int day, int hour)
{
    //if all the screening at this day are taken, don't insert
    if (HEBScreeningTime_.getElement(day, MAX_SCREENINGS_PER_DAY) != FREE)
    {
        return FALSE;
    }
    double len_in_hours = static_cast<double>(movieLength_)/60;
    for (int i = 0; i <MAX_SCREENINGS_PER_DAY ; ++i) {
        //if the slot is empty (no screening scheduled)
        if (HEBScreeningTime_.getElement(day, i+1) == FREE) {
            //if its not the first slot we can check in comparison to prev screening
            if (i > 0) {
                if ((HEBScreeningTime_.getElement(day, i ) + len_in_hours) > static_cast<double>(hour)) {
                    return FALSE;
                } else {
                    HEBScreeningTime_.setElement(day, i + 1, hour);
                    return TRUE;
                }
            }
                //if its the first slot and its empty then insert the screening
            else if (i == 0) {
                HEBScreeningTime_.setElement(day, i + 1, hour);
                return TRUE;
            }
        }
    }
    return FALSE;
}