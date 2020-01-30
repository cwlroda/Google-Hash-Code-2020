#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> calculate(vector<int> slices, long& total_score, long max_slices);

int main(int argc, char** argv){
    ifstream infile;
    infile.open(argv[1]);

    vector<int> slices;
    long max_slices;
    int types;

    infile >> max_slices >> types;

    int tmp;

    while(infile >> tmp){
        slices.push_back(tmp);
    }

    infile.close();

    long total_score=0;

    vector<int> result = calculate(slices, total_score, max_slices);

    ofstream outfile;
    outfile.open(argv[2]);

    outfile << result.size() << endl;

    for(int i=0; i<result.size(); i++){
        outfile << result[i] << " ";
    }

    outfile.close();

    cout << "Max score is: " << max_slices << endl;
    cout << "Your score is: " << total_score << endl;

    return 0;
}

vector<int> calculate(vector<int> slices, long& total_score, long max_slices){
    vector<int> sol_index, sol_val, curr_index, curr_val;
    int score=0;
    int start = slices.size();

    while((curr_index.size() > 0 && curr_index[0] != 0) || curr_index.size() == 0){
        start -= 1;

        for(int i=start; i>=0; i--){
            int tmp = score + slices[i];

            if(tmp == max_slices){
                score = tmp;
                curr_index.push_back(i);
                curr_val.push_back(slices[i]);
                break;
            }

            else if(tmp > max_slices){
                continue;
            }

            else if(tmp < max_slices){
                score = tmp;
                curr_index.push_back(i);
                curr_val.push_back(slices[i]);
            }
        }

        if(total_score < score){
            total_score = score;

            sol_index = curr_index;
            sol_val = curr_val;
        }

        if(total_score == max_slices){
            break;
        }

        if(curr_val.size() != 0){
            int last = curr_val[curr_val.size()-1];
            curr_val.pop_back();
            score = score - last;
        }

        if(curr_index.size() != 0){
            int last = curr_index[curr_index.size()-1];
            curr_index.pop_back();
            start = last;
        }

        if(curr_index.size() == 0 && start == 0){
            break;
        }
    }

    return sol_index;
}

