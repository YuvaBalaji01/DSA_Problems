#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
	stack<char> s;
	for(int i=0;expression[i]!='\0';i++){
		
		if(expression[i]==')'){
			int cnt=0;
			while(!(s.empty())){
				if(s.top()=='(') {s.pop(); break;}
				cnt++;
				s.pop();
			}
			if(cnt<3) return true;
		}
		else s.push(expression[i]);
	}

	return false;
	
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}