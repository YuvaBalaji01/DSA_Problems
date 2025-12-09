#include<iostream>
using namespace std;
template<typename T>

class mapnode{

    public:

    string key;
    T value;
    int count;
    mapnode<T>* next;

    mapnode(string key,T value){

        this->key=key;
        this->value=value;
        count =0;
        next=NULL;

    }

    ~mapnode(){
        delete next;
    }


};
template<typename T>

class hashmap{

    private:

    int hashcode(string key){
      
        int hc =0;
        int p =1;
        for(int i=0;key[i]!='\0';i++){
           hc+=key[i]*p;
           hc%=bucketsize;
           p*=37;
           p%=bucketsize;
        }

        return hc%bucketsize;

    }

    public:
    mapnode<T>** bucket;
    int bucketsize;
    int cnt;
    string key;
    T value;


    void rehashing (){

        mapnode<T> ** temp=bucket;
        bucket = new mapnode<T>*[2*bucketsize];

        for(int i=0;i<2*bucketsize;i++) bucket[i]=NULL;
        int oldbsize = bucketsize;
        bucketsize*=2;

        for(int i=0;i<oldbsize;i++){
            mapnode<T>* head = temp[i];

            while(head!=NULL){
                insertion(head->key,head->value);
               
                 mapnode<T>* temp1 = head;
                 head = head->next;
            temp1->next = NULL;  // Prevent recursive delete
            delete temp1;
            }
        }

        delete [] temp;
    }
    hashmap(){
        bucketsize=5;
        cnt=0;
        bucket=new mapnode<T>*[bucketsize];
        for(int i=0;i<bucketsize;i++) bucket[i]=NULL;
       
    }

    void insertion(string key,T value){

        int hc = hashcode(key);

        mapnode<T>* head = bucket[hc];

        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }

        head = bucket[hc];
        mapnode<T>* node = new mapnode<T>(key,value);
        node->next=head;
        bucket[hc]=node;
        cnt++;

        double lf = (1.0*cnt)/bucketsize;

        if(lf > 0.7) rehashing();
        

    }

    T deletion(string key){
       int hc= hashcode(key);
       mapnode<T>* head = bucket[hc];
       mapnode<T>* pre = NULL;

       while(head!=NULL){

        if(head->key==key){

            
            if(pre==NULL) bucket[hc]=head->next;
            else pre->next=head->next;
            T val = head->value;
            head->next=NULL;
            delete head;
            cnt--;
            return val;

        }
        pre=head;
        head=head->next;
       }

       return 0;

    }

    T getvalue(string key){
        int hc = hashcode(key);
        mapnode<T>* head= bucket[hc];

        while(head!=NULL){
            if(head->key==key) return head->value;
            head=head->next;
        }

        return 0;
    }

    ~hashmap(){
        for(int i=0;i<bucketsize;i++) delete bucket[i];

        delete [] bucket;
    }


};


int main(){

    hashmap<int> h;
    
    h.insertion("abc",3);
    h.insertion("abcd",2);
    h.insertion("abce",1);
    h.insertion("abcf",4);
    h.insertion("abcg",5);

    int ans  = h.getvalue("abc");

    cout << ans << endl;
    

}
