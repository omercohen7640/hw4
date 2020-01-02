//
// Created by omerc on 28/12/2019.
//

#include "Theater.H"

/*********************************************************************************
Function name: Theater
Description: constructor
Parameters: rows - height dimension
            cols - weight dimension
            theaterNum - number of theater
Return value: None
**********************************************************************************/
Theater::Theater(int rows, int cols, int theaterNum) : Mat(rows, cols), theaterNum_(theaterNum) {}

/*********************************************************************************
Function name: ~Theater
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
Theater::~Theater() {}

/*********************************************************************************
Function name: getTheaterNum
Description: gets the number of the theater
Parameters: None
Return value: int - the number of the theater
**********************************************************************************/
int Theater::getTheaterNum()
{
    return theaterNum_;
}

/*********************************************************************************
Function name: Reset
Description: sets the places in the theater to zero (untaken)
Parameters: None
Return value: None
**********************************************************************************/
void Theater::Reset()
{
    for (int i = 0; i <Rows_ ; ++i) {
        for (int j = 0; j <Cols_ ; ++j) {
            matrix_[i][j] = 0;
        }
    }
}