//
// Created by omerc on 28/12/2019.
//

#include "Mat.H"

/*********************************************************************************
Function name: Mat
Description: constructor with no parameters
Parameters: None
Return value: None
**********************************************************************************/
Mat::Mat() : Rows_(2), Cols_(2)
{
    matrix_ = new int*[Rows_];
    for (int i=0; i<Rows_; i++)
    {
        matrix_[i] = new int[Cols_];
        for (int j=0; j<Cols_; j++)
        {
            matrix_[i][j] = 0;
        }
    }
}

/*********************************************************************************
Function name: Mat
Description: constructor
Parameters: rows - height dimension
            cols - weight dimension
Return value: None
**********************************************************************************/
Mat::Mat(int rows, int cols) : Rows_(rows), Cols_(cols)
{
    matrix_ = new int*[Rows_];
    for (int i=0; i<Rows_; i++)
    {
        matrix_[i] = new int[Cols_];
        for (int j=0; j<Cols_; j++)
        {
            matrix_[i][j] = 0;
        }
    }
}

/*********************************************************************************
Function name: ~Mat
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
Mat::~Mat()
{
    for(int i=0; i<Rows_; i++)
    {
        delete []matrix_[i];
    }
    delete []matrix_;
}

//----------------------------------------getters------------------------------------------//
/*********************************************************************************
Function name: getRowsNum
Description: gets the number of rows
Parameters: None
Return value: int - the height dimension
**********************************************************************************/
int Mat::getRowsNum()
{
    return Rows_;
}

/*********************************************************************************
Function name: getColumnsNum
Description: gets the number of columns
Parameters: None
Return value: int - the weight dimension
**********************************************************************************/
int Mat::getColumnsNum()
{
    return Cols_;
}

/*********************************************************************************
Function name: getElement
Description: gets value of the element in the indices given
Parameters: row - index of row
            col - index of column
Return value: int - the value of element
**********************************************************************************/
int Mat::getElement(int row, int col)
{
    cout << matrix_[row-1][col-1] << endl;
    return matrix_[row-1][col-1];
}

//----------------------------------------setters------------------------------------------//
/*********************************************************************************
Function name: setElement
Description: changes the value of an element in the indices given
Parameters: row - index of row
            col - index of column
            val - the value to put in the matrix
Return value: None
**********************************************************************************/
void Mat::setElement(int row, int col, int val)
{
    matrix_[row-1][col-1] = val;
}