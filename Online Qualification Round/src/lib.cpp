#include "../include/lib.hpp"

int Lib::getID(){
    return id;
}

int Lib::getDays(){
    return numSignupDays;
}

int Lib::getTotal(){
    return totalPoints;
}

void Lib::refresh(){
    for(int i=0; i<Books.size(); i++){
        if(MasterList.find(Books[i].first) == MasterList.end()){
            Books.erase(Books.begin()+i);
            i--;
        }
    }

    updatePts();
}

void Lib::updatePts(){
    int points = 0;

    for(int i=0; i<Books.size(); i++){
        points += Books[i].second;
    }

    totalPoints = (points * scanRate / numSignupDays);
}