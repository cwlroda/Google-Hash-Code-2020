#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv){
    ifstream infile;
    infile.open(argv[1]);

    int total;
    infile >> total;

    vector<int> index;
    int tmp, result=0;

    while(infile >> tmp){
        index.push_back(tmp);
    }

    infile.close();
    infile.open(argv[2]);

    infile >> tmp >> tmp;
    vector<int> slices;

    while(infile >> tmp){
        slices.push_back(tmp);
    }

    infile.close();

    for(int i=0; i<index.size(); i++){
        result += slices[index[i]];
    }

    cout << "Confirming score: " << result << endl;

    return 0;
}