#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> calculate(vector<int> slices, int& score, int max_slices);

int main(int argc, char** argv){
    ifstream infile;
    infile.open(argv[1]);

    vector<int> slices;
    int max_slices, types;

    infile >> max_slices >> types;

    int tmp;

    while(infile >> tmp){
        slices.push_back(tmp);
    }

    infile.close();

    int score=0;

    vector<int> result = calculate(slices, score, max_slices);

    ofstream outfile;
    outfile.open(argv[2]);

    outfile << result.size() << endl;

    for(int i=0; i<result.size(); i++){
        outfile << result[i] << " ";
    }

    outfile.close();

    cout << "Max score is: " << max_slices << endl;
    cout << "Your score is: " << score << endl;

    return 0;
}

vector<int> calculate(vector<int> slices, int& score, int max_slices){
    vector<int> curr;

    for(int k=slices.size()-1; k>=0; k--){
        vector<int> slices_tmp = slices;
        slices_tmp.erase(slices_tmp.begin()+k);

        for(int i=1; i<=slices_tmp.size(); i++){
            vector<int> tmp;
            int tmpscore=0;

            for(int j=slices_tmp.size()-i; j>=0; j--){
                tmpscore += slices_tmp[j];

                if(tmpscore == max_slices){
                    tmp.insert(tmp.begin(), j);
                    curr = tmp;
                    score = tmpscore;
                    return curr;
                }

                else if(tmpscore > max_slices){
                    tmpscore -= slices_tmp[j];
                }

                else if(tmpscore < max_slices){
                    tmp.insert(tmp.begin(), j);
                }
            }

            if(tmpscore > score){
                score = tmpscore;
                curr = tmp;
            }
        }
    }

    return curr;
}

