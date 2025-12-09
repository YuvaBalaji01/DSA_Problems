#include <iostream>
using namespace std;

class student{
    public:

    int age;


};

int main (){
    int i=5;

    int const j=i;
    i=6;

    student s1;

    s1.age=19;

    student const s2=s1;

    s1.age=18;

    cout << s1.age << " " << s2.age << endl;

    cout << i << " " << j << endl;
}