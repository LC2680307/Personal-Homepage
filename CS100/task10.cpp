#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
bool testPalindrome(const string s){
    int i = 0;
    int j = s.size() - 1;
    for(; i < j; i++, j--){
        if(s[i] != s[j])
            break;
    }
    if(i >= j)
        return 1;
    else
        return 0;
}

int main()
{
    string strinput;
	cin >> strinput;
	strinput.push_back(',');
	int num = count(strinput.begin(),strinput.end(),',');
	int head = 0;
	int tail = 0;
	for(int i=0;i<num;i++){
		tail = strinput.find_first_of(',',head);
		string newstring;
		newstring = strinput.substr(head,tail-head);
		if(testPalindrome(newstring)){
			cout << newstring << '\n';
		}
		head = tail+1;
		//strinput = strinput.erase(head,tail);
	}
	return 0;
}