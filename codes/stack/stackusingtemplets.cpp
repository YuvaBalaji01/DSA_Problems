#include<iostream>
using namespace std;
template<typename T>

class stack{

    T* data;
    int capacity;
    int index;
    public:
    
    stack(){
        data=new T[5];
        capacity=5;
        index=0;
    }

    void push(T d){
        if(index>=capacity){
            T* newdata= new T(capacity*2);
            for(int i=0;i<capacity;i++) newdata[i]=data[i];
             capacity*=2;
            
             delete data;
             data=newdata;
        }
        data[index]=d;
        index++;
        
    }

    void pop(){
        index--;
    }

    int size(){
        return index;
    }

    bool isempty(){
        if(index==0) return true;
        else return false;
    }

    void top(){
        cout << data[index-1] << endl;
    }

    
};


int main (){
    stack<char> s1;

    s1.push(65);
    s1.push(66);
    s1.push(67);
    s1.push(68);
    s1.push(69);
    s1.push(70);
    cout << s1.size() << endl;
    cout << s1.isempty() << endl;
    s1.top();
    s1.pop();
    s1.top();

}