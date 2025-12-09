#include <iostream>
using namespace std;

class vehicle{
    private:
    int gares;
    protected:
    int topspeed;
    public:
    string color;

    vehicle(){
        cout << "vehicle constructor" << endl;
    }

    vehicle(int gares){
        cout << "parameterised vehicle constructor"<< endl;
        this->gares=gares;

    }

    ~vehicle(){
        cout << "vehicle destructor" << endl;
    }
};

class car : public vehicle{
    public:
    string model;

    car():vehicle(){ //if there is no default contructor to the parent class we must mention 
        //which consrtuctor to be called
      cout << "car constructor" << endl;
    }

    ~car(){
        cout << "car destructor" << endl;
    }
};

class ferrari : public car{
    public:
    string type;

    ferrari(){
        cout << "ferrari constructor" << endl;
    }

    ~ferrari(){
        cout << "ferrari owned" << endl;
    }
};


int main (){
    vehicle v1(3);
    car c1;
    ferrari f1;
}