#include<iostream>
using namespace std;

class stack{

    int* data;
    int capacity;
    int index;
    public:
    
    stack(){
        data=new int[5];
        capacity=5;
        index=0;
    }

    void push(int d){
        if(index>=capacity){
            int* newdata= new int(capacity*2);
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
    stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout << s1.size() << endl;
    cout << s1.isempty() << endl;
    s1.top();
    s1.pop();
    s1.top();

}