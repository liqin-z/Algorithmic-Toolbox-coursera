#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int num;
    string input;
    vector <int>nums;
    while(getline(cin,input)&&!input.empty()){
        istringstream iss;
        iss.str(input);
        cout<<"iss="<<iss.str()<<endl;
        while(iss>>num) {
            cout<<"push back "<<num<<endl;
            nums.push_back(num);
        }
    }
    vector<int>::iterator it;
    for(it=nums.begin();it!=nums.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}
