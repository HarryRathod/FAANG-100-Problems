#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    int sum=0;
    int flag=0;
    vector<int> integers;
	for(int i=0;str[i]!='\0';i++)
    {
        if (str[i]=='-') {
            flag=1;
            }
        if(str[i]==','){
            if(flag==1){
                integers.push_back(-sum);
                flag=0;

            }
            else
                integers.push_back(sum);
            sum=0;
        }
        else {  
        sum=sum*10;
        sum+=(str[i]-'0');
        if(str[i+1]=='\0'){
            if(flag==1){
                integers.push_back(-sum);
                flag=0;
            }
            else {
            integers.push_back(sum);
            }
        }
        }
    }
    return integers;
}

int main() {
    string str="871,166,-433,-917,-846,461";
    
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}