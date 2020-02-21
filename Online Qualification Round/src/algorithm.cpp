#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// map<int, int> MasterList;
int DaysLeft;

struct library{
    int ShipRate;
    map<int, int> Books;
    int SignupDay;
    int totalUniquePoints;

    bool operator > (const library& Lib) const{
        return(totalUniquePoints > Lib.totalUniquePoints);
    }
    void refresh(map<int, int> BookMasterList);
    int calcTotalUniquePoints(map<int, int> BookMasterList);
    void eliminateDup();
    bool checkValidDays();
    int calcMaxScorePossible();
};

/* void generateMaster(){
    vector<library> allLib;

    for(int i=0; i<allLib.size(); i++){
        map<int, int>::iterator it = allLib[i].Books.begin();

        while(it != allLib[i].Books.end()){
            if(MasterList.find(it->first) != MasterList.end()){
                continue;
            }

            else{
                MasterList[it->first] = it->first;
            }
        }
    }
} */

bool library::checkValidDays(){
    int maxShipDays = Books.size()/ShipRate;

    return (SignupDay + maxShipDays) < DaysLeft;
}

int library::calcMaxScorePossible(){
    int NumBooks = (DaysLeft - SignupDay) * ShipRate;

    int totalPoints = 0;

    map<int, int>::iterator it = Books.begin();

    for(int i=0; i<NumBooks; i++){
        totalPoints += it->first;
        it++;
    }

    return totalPoints;
}

int library::calcTotalUniquePoints(map<int, int> MasterBookList){
    if(checkValidDays()){
        int totalPoints = 0;

        map<int, int>::iterator it = Books.begin();

        while(it != Books.end()){
            if(MasterBookList.find(it->first) != MasterBookList.end()){
                totalPoints += it->first;
            }

            else{
                Books.erase(it);
            }

            it++;
        }

        return totalPoints/Books.size()*ShipRate;
    }

    else{
        map<int, int>::iterator it = Books.begin();

        while(it != Books.end()){
            if(MasterBookList.find(it->first) == MasterBookList.end()){
                Books.erase(it);
            }

            it++;
        }

        return calcMaxScorePossible();
    }
}

void library::refresh(map<int, int> MasterBookList){
    totalUniquePoints = calcTotalUniquePoints(MasterBookList);
}

