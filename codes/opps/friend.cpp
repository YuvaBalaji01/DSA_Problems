#include <iostream>
#include<string>
using namespace std;

//Write your code here

 class parent{
   public:
   int  returnandprint();
   friend class  isFriend;
    
 };

 class isFriend{
   private:
   string x;
   protected:
   string y;

   public :

   void print(){
    cout <<"hello " << endl;
   }

   friend int parent::returnandprint();

 };

int parent:: returnandprint()
{
    isFriend t;
    t.x="Rishabh";
    t.y="Harshit";
    cout<<t.x<<" "<<t.y;
    return 15;
}

int main()
{
    // int n;
    // cin>>n;
    parent b;
    int ans =b.returnandprint();
  
    cout<<endl<<ans<<endl;;
    isFriend f1;
    f1.print();
   
    
    return 0;
}