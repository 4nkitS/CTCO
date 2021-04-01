#include "everything.h"
struct Test{
    vector<vector<int>> input;
    vector<vector<int>> output;
};
vector<vector<int>> ZeroMatrix(vector<vector<int>> t){
    set<int> zeroRows, zeroCols;
    for(int row =0; row < t.size(); row++){
        for(int col =0; col < t[0].size(); col++){
            if(t[row][col] == 0){
                zeroRows.insert(row);
                zeroCols.insert(col);
            }
        }
    }

    for(auto r : zeroRows){
        for(int c = 0; c < t[0].size(); c++)
            t[r][c] = 0;        
    }
    for(auto c : zeroCols){
        for(int r = 0; r < t.size(); r++)
            t[r][c] = 0;
    }
    return t;
}
int main(){
    vector<Test> vecTests = {
        {.input= {{1, 2, 3},{4,5,0},{7,8,9}}, .output={{1, 2, 0},{0,0,0},{7,8,0}}},
    };
    int count = 0;
    for(auto a : vecTests){        
        vector<vector<int>>  output = a.output, result = ZeroMatrix(a.input);
        bool bIsPass = match_arrays_of_arrays(a.output, ZeroMatrix(a.input));
        cout << "Case#" << ++count << " Input: {" << print_array_of_arrays<int>(a.input) << "}, Output: {" << print_array_of_arrays<int>(ZeroMatrix(a.input)) << "} : -> " << (bIsPass? green : red) << (bIsPass? "Pass" : "Fail") << def << endl;
    }
    return 0;
}
