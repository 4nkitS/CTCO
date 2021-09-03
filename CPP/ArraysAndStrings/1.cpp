#include "everything.h"
struct Test{
    const char* input;
    bool output;
};
bool IsAllCharUnique(const char* s){
    string t(s);
    unordered_set<char> setCharFound;
    int i = -1;    
    while(++i < t.length()){
        if(setCharFound.find(t[i]) != setCharFound.end())
            return false;
        setCharFound.insert(t[i]);
    }
    return true;
}
bool IsAllCharUnique2(const char* s){
    int i=-1;
    while(s != nullptr && *(s+ ++i) != '\0'){
        int j= i+1;
        while(*(s+ ++j) != '\0')
            if(*(s+i) == *(s+j))
                return false;
    }
    return true;
}
int main(){
    vector<Test> vecTests = {
        {.input= "", .output=true},
        {.input= "ankit", .output=true},
        {.input= "abccba", .output= false},
        {.input= "ankit shukla", .output=false},
        {.input= "12345678901", .output=false}
    };
    int count = 0;
    for(auto a : vecTests){
        bool result=IsAllCharUnique(a.input);
        cout << "Case#" << ++count << ": Input = \"" << a.input << "\", Output="<< result<< ", Result=" << (result == a.output? green : red) << (result == a.output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////
/*
Approach 1: Using Set . Time complexity: O(n)
Maintain a set for unique characters in string
Iterate over string for each character
Check if that character exist in the set
If not, then insert in set
If yes, return false
If the entire string is iterated and no repeat occurence found, return true.
 
Approach 2: Loop In a loop. Time Complexity: O(n^2)
Iterate over chars in string
Check if it repeats anywhere in later part in string
If yes, return false
If no, check for next char in next iteration
When all iteration ends without repeat occurence, return true.

Approach 3: Sort and Check for repeat. Time Complexity: O(n log n)
Sort string using heap, merge or Quick sort (Time complexity n log n)
Iterate over modified string
Check if next char is same as current char
If yes, return fail
If no, go for next iteration
When all iteration ends without repeat occurence, return true.
*/