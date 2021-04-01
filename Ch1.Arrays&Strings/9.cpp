#include "everything.h"
struct Test{
    vector<vector<int>> input;
    vector<vector<int>> output;
};
vector<vector<int>> StringRotation(vector<vector<int>> t){
    
}
int main(){
    vector<Test> vecTests = {
        {.input= {{1, 2, 3},{4,5,6},{7,8,9}}, .output={{7,4,1},{8,5,2},{9,6,3}}},
    };
    int count = 0;
    for(auto a : vecTests){        
        vector<vector<int>>  output = a.output, result = RotateMatrix(a.input);
        cout << "Case#" << ++count << ": -> " << (result == output? green : red) << (result == output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}
