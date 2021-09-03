#include "everything.h"
struct Test{
    const char* input1;
    const char* input2;
    bool output;
};
bool IsPermutation(const char* input1, const char* input2){
    map<char, int> mapCharFreqInput1, mapCharFreqInput2;
    int i = -1;
    while(*(input1 + ++i) != '\0') 
        mapCharFreqInput1[*(input1+i)]++;
    i = -1;
    while(*(input2 + ++i) != '\0') 
        mapCharFreqInput2[*(input2+i)]++;
    if(mapCharFreqInput1.size() !=mapCharFreqInput2.size()) 
        return false;
    for( auto a : mapCharFreqInput1){
        if(mapCharFreqInput2.find(a.first) == mapCharFreqInput2.end() || 
        mapCharFreqInput2[a.first] != a.second)
            return false;
    }
    return true;
}
int main(){
    vector<Test> vecTests = {
        {.input1 = "", .input2="", .output=true},
        {.input1 = "", .input2="ankit", .output=false},
        {.input1 = "ankit", .input2="tikan", .output=true},
        {.input1 = "ankit", .input2="tizan", .output=false},
    };
    int count = 0;
    for(auto a : vecTests){
        bool result=IsPermutation(a.input1, a.input2);
        cout << "Case#" << ++count << ": Input = {\"" << a.input1 << "\",\"" << a.input2<< "\"}, Output="<< result<< ", Result=" << (result == a.output? green : red) << (result == a.output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}

/*
/////////////////////////////////////////////////////////////////////////////////////////////
Approach 1: Use two frequency maps and compare

Approach 2: Match and Erase 
Iterate over one string
Find current char in other string and erase
If fail to find then return fail
when iteration ends, if string2 is not empty, return fail. Else return true;




*/