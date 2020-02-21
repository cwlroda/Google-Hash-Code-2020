#ifndef LIB_HPP
#define LIB_HPP

#include <vector>
using namespace std;

class Lib{
    public:
        Lib(int _id, int _scan, int _signup):
            id(_id),
            scanRate(_scan),
            numSignupDays(_signup)
        {}

        int getID();
        int getTotal();

        vector<pair<int, int> > Books;

    private:
        int id;
        int scanRate;
        int numSignupDays;
};

#endif