#include <iostream>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here

    if (input[1] == '\0')
        return input[0] - '0';

     int smallOutput = stringToNumber(input + 1);
    int digit = input[0] - '0';
    int power = 1;

    // Compute power of 10 corresponding to position
    int len = 0;
    while (input[len] != '\0') {
        len++;
    }
    for (int i = 1; i < len; i++) {
        power *= 10;
    }

    return digit * power + smallOutput;

}




int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
