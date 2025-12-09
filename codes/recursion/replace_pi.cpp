#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

void replacePi(char input[]) {
	// Write your code here

	if(input[0]=='\0' || input[1]=='\0') return;

	if(input[0] != 'p' || input[1]!= 'i') replacePi(input+1);

	else {
		int li=0;
		while(input[li]!='\0'){
			li++;
		}

		input[li+2]=input[li];

		li=li+1;

		while(li>=2){
             input[li]=input[li-2];
			 li--;
		}

		input[0]='3';
		input[1]='.';
		input[2]='1';
		input[3]='4';

		replacePi(input+4);
	}

}




int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
