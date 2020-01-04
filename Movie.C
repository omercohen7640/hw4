//
// Created by omerc on 28/12/2019.
//

#include "Movie.H"

int Movie::moviePrice_ = 35;

/*********************************************************************************
Function name: Movie
Description: constructor
Parameters: name - name of movie
            length - length of movie
            language - language of movie
            theaterNum - number of theater
Return value: None
**********************************************************************************/
Movie::Movie (char* name, int length, char* language, int theaterNum):
        movieName_(name), movieLength_(length), movieLanguage_(language), movieTheaterNum_(theaterNum), screeningTime_(DAYS_IN_WEEK, MAX_SCREENINGS_PER_DAY) {}

/*********************************************************************************
Function name: ~Movie
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
Movie::~Movie() {}
/*********************************************************************************
Function name: getName
Description: gets the movie name
Parameters: None
Return value: char* - pointer to name string
**********************************************************************************/
char* Movie::getName()
{
    return movieName_;
}

/*********************************************************************************
Function name: getLength
Description: gets the movie length
Parameters: None
Return value: int - movie length in minutes
**********************************************************************************/
int Movie::getLength()
{
    return movieLength_;
}

/*********************************************************************************
Function name: getLanguage
Description: gets the movie language
Parameters: None
Return value: char*- pointer to movie language
**********************************************************************************/
char* Movie::getLanguage()
{
    return movieLanguage_;
}

/*********************************************************************************
Function name: getTheaterNum
Description: gets the Theater Number
Parameters: None
Return value: int- theater number
**********************************************************************************/
int Movie::getTheaterNum()
{
    return movieTheaterNum_;
}

/*********************************************************************************
Function name: getTicketPrice
Description: gets the movie ticket price
Parameters: None
Return value: int- price
**********************************************************************************/
int Movie::getTicketPrice()
{
    return moviePrice_;
}

/*********************************************************************************
Function name: addScreening
Description: add a movie
Parameters: day - screening day
            hour - screening hour
Return value: BOOL - failed of succeeded
**********************************************************************************/
BOOL Movie::addScreening(int day, int hour)
{
    //if all the screening at this day are taken, don't insert
    if (screeningTime_.getElement(day, MAX_SCREENINGS_PER_DAY) != FREE)
    {
        return FALSE;
    }
    double len_in_hours = static_cast<double>(movieLength_)/60;
    for (int i = 0; i <MAX_SCREENINGS_PER_DAY ; ++i) {
        //if the slot is empty (no screening scheduled)
        if (screeningTime_.getElement(day, i+1) == FREE)
        {
            //if its not the first slot we can check in comparison to prev screening
            if (i > 0)
            {
                if ((screeningTime_.getElement(day, i) + len_in_hours) > static_cast<double>(hour))
                {
                    return FALSE;
                }
                else
                {
                    screeningTime_.setElement(day, i + 1, hour);
                    return TRUE;
                }
            }
            //if its the first slot and its empty then insert the screening
            else if (i == 0)
            {
                screeningTime_.setElement(day, i+1, hour);
                return TRUE;
            }
        }
    }
    return FALSE;
}

/*********************************************************************************
Function name: getNextScreening
Description: gets the next movie screening after time given
Parameters: day - screening day
            hour - screening hour
Return value: int- time of next screening
**********************************************************************************/
int Movie::getNextScreening(int day, int hour)
{
    for (int i = 0; i <MAX_SCREENINGS_PER_DAY ; ++i) {
        if (screeningTime_.getElement(day, i + 1) > hour)
        {
            return screeningTime_.getElement(day, i + 1);
        }
    }
    return FALSE;
}