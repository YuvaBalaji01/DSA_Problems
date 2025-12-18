
class Node{

    public:
    char data;
    //bool isterminal;
    int cnt ;
    Node * child[26];

    Node(char data){
        this->data = data;
        //isterminal  = false;
        cnt = 0;
        for(int i=0;i<26;i++) this->child[i] = nullptr;
    }
};