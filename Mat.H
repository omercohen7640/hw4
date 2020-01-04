//
// Created by omerc on 28/12/2019.
//

#ifndef HW_4_MAT_H
#define HW_4_MAT_H
#include <iostream>

using namespace std;

class Mat {

    public:
/*********************************************************************************
Function name: Mat
Description: constructor with no parameters
Parameters: None
Return value: None
**********************************************************************************/
        Mat ();
/*********************************************************************************
Function name: Mat
Description: constructor
Parameters: rows - height dimension
            cols - weight dimension
Return value: None
**********************************************************************************/
        Mat(int rows, int cols);
/*********************************************************************************
Function name: ~Mat
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
        virtual ~Mat();
        //getters:
/*********************************************************************************
Function name: getRowsNum
Description: gets the number of rows
Parameters: None
Return value: int - the height dimension
**********************************************************************************/
        int getRowsNum();
/*********************************************************************************
Function name: getColumnsNum
Description: gets the number of columns
Parameters: None
Return value: int - the weight dimension
**********************************************************************************/
        int getColumnsNum();
/*********************************************************************************
Function name: getElement
Description: gets value of the element in the indices given
Parameters: row - index of row
            col - index of column
Return value: int - the value of element
**********************************************************************************/
        int getElement(int row, int col);
        //setters:
/*********************************************************************************
Function name: setElement
Description: changes the value of an element in the indices given
Parameters: row - index of row
            col - index of column
            val - the value to put in the matrix
Return value: None
**********************************************************************************/
        void setElement(int row, int col, int val);

    protected:
        int Rows_;
        int Cols_;
        int** matrix_;

};


#endif //HW_4_MAT_H
