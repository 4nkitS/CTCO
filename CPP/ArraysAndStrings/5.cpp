#include "everything.h"
struct Test{
    const char* input1;
    const char* input2;
    bool output;
};
bool IsOneAway(string t1, string t2){    
    if(t1 == t2) return true; // Zero edits
    int i = 0, j = 0;
    bool bIsOneMismatchFound = false;    
    while(i < t1.length() && j < t2.length()){
        if(t1[i] != t2[j]){
            if(bIsOneMismatchFound)
                return false;            
            bIsOneMismatchFound = true;
        }
        i++; j++;
    }
    return true;
}
int main(){
    vector<Test> vecTests = {
        {.input1= "pale", .input2= "pal", .output=true},
        {.input1= "pales", .input2= "pale", .output=true},
        {.input1= "pale", .input2= "bale", .output=true},
        {.input1= "pale", .input2= "bake", .output=false},
    };
    int count = 0;
    for(auto a : vecTests){        
        bool output = a.output, result = IsOneAway(a.input1, a.input2);
        cout << "Case#" << ++count << ": Input = {\"" << a.input1 << "\",\"" << a.input2 << "\"}, Output="<< result<< " -> " << (result == output? green : red) << (result == output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}