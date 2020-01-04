//
// Created by omerc on 28/12/2019.
//

#ifndef HW_4_MOVIE_H
#define HW_4_MOVIE_H

#define DAYS_IN_WEEK 7

#include "Proj.H"
#include "Mat.H"


class Movie {
    public:
/*********************************************************************************
Function name: Movie
Description: constructor
Parameters: name - name of movie
            length - length of movie
            language - language of movie
            theaterNum - number of theater
Return value: None
**********************************************************************************/
        Movie (char* name, int length, char* language, int theaterNum);
/*********************************************************************************
Function name: ~Movie
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
    virtual ~Movie();
/*********************************************************************************
Function name: getName
Description: gets the movie name
Parameters: None
Return value: char* - pointer to name string
**********************************************************************************/
        char* getName();
/*********************************************************************************
Function name: getLength
Description: gets the movie length
Parameters: None
Return value: int - movie length in minutes
**********************************************************************************/
        int getLength();
/*********************************************************************************
Function name: getLanguage
Description: gets the movie language
Parameters: None
Return value: char*- pointer to movie language
**********************************************************************************/
        char* getLanguage();
/*********************************************************************************
Function name: getTheaterNum
Description: gets the Theater Number
Parameters: None
Return value: int- theater number
**********************************************************************************/
        int getTheaterNum();
/*********************************************************************************
Function name: getTicketPrice
Description: gets the movie ticket price
Parameters: None
Return value: static int- price
**********************************************************************************/
        static int getTicketPrice();
/*********************************************************************************
Function name: addScreening
Description: add a movie
Parameters: day - screening day
            hour - screening hour
Return value: BOOL - failed of succeeded
**********************************************************************************/
        BOOL addScreening(int day, int hour);
/*********************************************************************************
Function name: getNextScreening
Description: gets the next movie screening after time given
Parameters: day - screening day
            hour - screening hour
Return value: int- time of next screening
**********************************************************************************/
        int getNextScreening(int day, int hour);

    protected:
        char* movieName_;
        int movieLength_;
        char* movieLanguage_;
        static int moviePrice_;
        int movieTheaterNum_;
        Mat screeningTime_;
};


#endif //HW_4_MOVIE_H
