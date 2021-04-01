#include "everything.h"
struct Test{
    const char* input;
    const char* output;
};
string URLify1(string t){    
    while(1){
        int idx = t.find(" ");
        if(idx == string::npos)
            break;
        t.replace(idx,1,"%20");
    }
    return t;
}
const char* URLify2(const char* s){
    int i = -1, j = -1, nSpaces = 0, nLength = 0;
    while( s!= nullptr && *(s + ++i) != '\0'){
        nLength++;
        if(*(s+i) == ' ')
            nSpaces++;
    }
    i = -1;
    char* r = new char[nLength + (3 - 1) * nSpaces];
    while( s!= nullptr && r!= nullptr && *(s + ++i) != '\0'){        
        if(*(s+i) == ' '){
            *(r + ++j) = '%';
            *(r + ++j) = '2';
            *(r + ++j) = '0';
        }            
        else
            *(r + ++j) = *(s + i);
    }
    return r;
}
int main(){
    vector<Test> vecTests = {
        {.input= "Mr John Smith", .output="Mr%20John%20Smith"},
        {.input= "ankit shukla", .output="ankit%20shukla"},        
    };
    int count = 0;
    for(auto a : vecTests){        
        string output(a.output), result = URLify1(a.input);
        cout << "Case#" << ++count << ": Input = \"" << a.input << "\", Output=\""<< result<< "\" -> " << (result == output? green : red) << (result == output? "Pass" : "Fail") << def << endl;
    }
    return 0;
}