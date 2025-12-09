#include <iostream>
using namespace std;

class car{
    public :

    void print();
};

class vehicle{
    private:
    int topspeed;
    int gares;

    public:

    friend void car::print();

};

void car:: print(){
    vehicle v;
    v.topspeed=200;
    v.gares=7;
    cout << v.topspeed <<" " << v.gares << endl;
}

int main(){
    car c;
    c.print();
}