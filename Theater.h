//
// Created by omerc on 28/12/2019.
//

#ifndef HW_4_THEATER_H
#define HW_4_THEATER_H

#include "Mat.H"

class Theater: public Mat {

    public:
/*********************************************************************************
Function name: Theater
Description: constructor
Parameters: rows - height dimension
            cols - weight dimension
            theaterNum - number of theater
Return value: None
**********************************************************************************/
        Theater(int rows, int cols, int theaterNum);
/*********************************************************************************
Function name: ~Theater
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
        ~Theater();
/*********************************************************************************
Function name: getTheaterNum
Description: gets the number of the theater
Parameters: None
Return value: int - the number of the theater
**********************************************************************************/
        int getTheaterNum();
/*********************************************************************************
Function name: Reset
Description: sets the places in the theater to zero (untaken)
Parameters: None
Return value: None
**********************************************************************************/
        void Reset();
    protected:
        int theaterNum_;
};


#endif //HW_4_THEATER_H
