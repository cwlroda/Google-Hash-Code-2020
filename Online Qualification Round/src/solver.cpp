#include "../include/lib.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

multimap<int, int> MasterList;
vector<Lib> AllLibs;

bool sortLibs(Lib l1, Lib l2);
bool sortBooks(const pair<int, int>& x, const pair<int, int>& y);

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "Please provide input and output files as arguments!" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        cout << "Error opening input file!" << endl;
        exit(EXIT_FAILURE);
    }

    int totalBooks;
    int totalLibs;
    int totalDays;
    infile >> totalBooks >> totalLibs >> totalDays;

    for(int i=0; i<totalBooks; i++){
        int score;
        infile >> score;
        MasterList.insert(pair<int, int>(i, score));
    }

    for(int i=0; i<totalLibs; i++){
        int numBooks;
        int signup;
        int scan;
        infile >> numBooks >> signup >> scan;

        Lib l(i, scan, signup);

        for(int j=0; j<numBooks; j++){
            int id;
            infile >> id;

            multimap<int, int>::iterator it = MasterList.find(id);
            l.Books.push_back(pair<int, int>(id, it->second));
        }

        sort(l.Books.begin(), l.Books.end(), sortBooks);
        AllLibs.push_back(l);
    }

    sort(AllLibs.begin(), AllLibs.end(), sortLibs);

    infile.close();

    ofstream outfile;
    outfile.open(argv[2]);

    if(!outfile.is_open()){
        cout << "Error opening output file!" << endl;
        exit(EXIT_FAILURE);
    }

    outfile << AllLibs.size() << endl;

    for(int i=0; i<AllLibs.size(); i++){
        int booksInLib = AllLibs[i].Books.size();
        outfile << AllLibs[i].getID() << " " << booksInLib << endl;

        for(int j=0; j<booksInLib; j++){
            outfile << AllLibs[i].Books[j].first << " ";
        }

        outfile << endl;
    }

    outfile.close();

    cout << "Libraries: " << AllLibs.size() << endl;

    return 0;
}

bool sortLibs(Lib l1, Lib l2){
    return (l1.getTotal() > l2.getTotal());
}

bool sortBooks(const pair<int, int>& x, const pair<int, int>& y){
    return (x.second > y.second);
}