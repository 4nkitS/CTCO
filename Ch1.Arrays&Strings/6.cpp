#include "everything.h"
struct Test{
    string input;
    string output;
};
string StringCompression(string t){    
    string r;
    int i = 0;
    while(i < t.length()){
        char ch = t[i];
        int count = 1;
        while(ch == t[i + 1]){
            count++;
            i++;
        }
        r += ch + to_string(count);
        i++;
    }
    return r.length() < t.length()? r : t;
}
int main(){
    vector<Test> vecTests = {
        {.input= "aabcccccaaa", .output="a2b1c5a3"},
    };
    int count = 0;
    for(auto a : vecTests){        
        string output = a.output, result = StringCompression(a.input);
        cout << "Case#" << ++count << ": Input = \"" << a.input << "\", Output="<< result<< " -> " << (result == output? green : red) << (result == output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}