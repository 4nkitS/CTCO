#include "everything.h"
struct Test{
    const char* input;
    bool output;
};
bool CheckPalindromePermutation(string t){    
    while(1){
        int idx = t.find(" ");
        if(idx == string::npos)
            break;
        t.replace(idx,1,"");
    }

    map<char, int> mapCharFreq;
    for(auto c: t){
        if(c >= 'a')
            c = c + 'A' - 'a';
        mapCharFreq[c]++;
    }
    
    bool bIsFirstOddFound = false;
    for(auto k: mapCharFreq){
        if(k.second%2 != 0)
            if(bIsFirstOddFound)
                return false;
            else
                bIsFirstOddFound = true;
    }
    return true;
}
int main(){
    vector<Test> vecTests = {
        {.input= "Tact Coa", .output=true},
        {.input= "ankit", .output=false},
        {.input= "abccba", .output=true},
        {.input= "abcocba", .output=true},
        {.input= "shukla", .output=false},
    };
    int count = 0;
    for(auto a : vecTests){        
        bool output = a.output, result = CheckPalindromePermutation(a.input);
        cout << "Case#" << ++count << ": Input = \"" << a.input << "\", Output="<< result<< " -> " << (result == output? green : red) << (result == output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}