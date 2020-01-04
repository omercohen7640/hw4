//
// Created by omerc on 28/12/2019.
//

#include "Cashier.H"
#include "DubbedMovie.H"

/*********************************************************************************
Function name: Cashier
Description: c'tor
Parameters: -
Return value: -
**********************************************************************************/
Cashier::Cashier( char *name, int salary, char **hours) : Employee( name, salary, hours),ticket_profit_(0) {

}

Cashier::~Cashier(){}

/*********************************************************************************
    Function name: getTicketProfit
    Description: return the the profit made by the cashier
    Parameters: -
    Return value: ticket profit
    **********************************************************************************/
int Cashier::getTicketProfit() {
    return ticket_profit_;
}


int sellTicketsHelp(int movie_theater_num,int movie_price, Theater *p_theater, int tickets_num, int row, int col)
{
    if (row <=0 || col <= 0 || row > p_theater->getRowsNum() || (col+tickets_num) > p_theater->getColumnsNum()) return 0; // ilegal row or col
    if (movie_theater_num != p_theater->getTheaterNum()) return 0; // check if the movie is shown in the given theater
    for (int i = col; i < col + tickets_num; ++i) {
        if (p_theater->getElement(row,i-1) == TAKEN ) return 0;
    }
    for (int i = col ; i < col + tickets_num; i++) {
        p_theater->setElement(row,i - 1,TAKEN);
    }
    return tickets_num * movie_price;
}




/**********************************************************************************
Function name: sellTickets
Description: sell ticket for a movie in a given theater
Parameters:
p_move- pointer to wanted movie
p_theater - pointer the a wanted theater
dubbed- boolean value
tickets_num- number of wanted tickets
row- wanted row
col - collumn of the right seat.
Return value: -
**********************************************************************************/
int Cashier::sellTickets(Movie *p_movie, Theater *p_theater, BOOL dubbed, int tickets_num, int row, int col) {
    DubbedMovie* d_movie;
    int current_sell;
    if (dubbed == FALSE){
        current_sell = sellTicketsHelp(p_movie->getTheaterNum(),p_movie->getTicketPrice(),p_theater,tickets_num,row,col);
        ticket_profit_ += current_sell;
        return current_sell;
    }
    else{
        d_movie = (DubbedMovie*)p_movie;
        current_sell= sellTicketsHelp(d_movie->getHebrewTheaterNum(),d_movie->getTicketPrice(),p_theater,tickets_num,row,col);
        ticket_profit_ += current_sell;
        return current_sell;
    }
}

