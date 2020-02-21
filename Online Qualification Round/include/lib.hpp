#ifndef LIB_HPP
#define LIB_HPP

#include <vector>
#include <map>
using namespace std;

extern multimap<int, int> MasterList;

class Lib{
    public:
        Lib(int _id, int _scan, int _signup):
            id(_id),
            scanRate(_scan),
            numSignupDays(_signup)
        {}
        ~Lib(){}

        int getID();
        int getDays();
        int getTotal();
        void refresh();
        void updatePts();

        vector<pair<int, int> > Books;

    private:
        int id;
        int scanRate;
        int numSignupDays;
        int totalPoints;
};

#endif