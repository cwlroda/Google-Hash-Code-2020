#include "../include/lib.hpp"

int Lib::getID(){
    return id;
}

int Lib::getTotal(){
    int points = 0;

    for(int i=0; i<Books.size(); i++){
        points += Books[i].second;
    }

    return (points * scanRate / numSignupDays);
}