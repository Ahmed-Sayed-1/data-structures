#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * Right;
    Node * Left;
    Node(int _data){
        data=_data;
        Right=Left=NULL;
    }
};
class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current =root;
        while(current != NULL ){
            if(data == current->data){
                return current;
            }else if(data > current->data){
                current=current->Right;
            }else{
                current=current->Left;
            }
        }
        return NULL;
    }
    Node * getParent(Node * node){
        Node * parent=root;
        while(parent != NULL){
            if(node == parent->Right ||node == parent->Left  ){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->Right;
            }else{
                parent=parent->Left;
            }
        }
        return NULL;

    }
    Node * getMaxRight(Node * node){
        Node * current=node;//Start Point
        while(current->Right != NULL){
            current=current->Right;
        }
        return current;
    }

        void display(Node *node){
            if(node == NULL){
                return ;
            }
            display(node->Left);
            cout<<node->data<<" : ";
            display(node->Right);


        }


    public:
    Tree(){
        root=NULL;
    }
    void add(int data){
        //Create Node
        Node * newNode=new Node(data);
        if(root == NULL){
            root=newNode;
        }
        else{
            Node * current = root;
            Node * parent = NULL;
            while(current != NULL){
                parent=current; //Before Current Jumping
                if(data > current->data){
                    /*if(current->Right == NULL){
                        current->Right=newNode;
                        return;
                    }*/
                    current=current->Right;//
                }else{
                    /*if(current->Left == NULL){
                        current->Left=newNode;
                        return;
                    }*/
                    current=current->Left;
                }
            }
            if(data>parent->data){
               parent->Right=newNode;
            }else{
                parent->Left=newNode;
            }

        }
    }
    int findDataInTree(int data)
    {
        if(getNodeByData(data)== NULL){
            return 0;
        }
            return 1;
    }
    int getParentBydata(int data)
    {
        Node * node = getNodeByData(data);
        if(node == root){
            throw "The Node is Root Not Have Parent";
        }
        if(node != NULL ){
            Node * parent=getParent(node);
            if(parent != NULL){
                return parent->data;
            }
        }else{
            throw " Node Not Found , Not Have Parent";
        }

    }
    int getMaxRightByData(int data){
        Node * node=getNodeByData(data);
        if(node == NULL){
            throw " Node Not Found";
        }
        Node * maxR= getMaxRight(node);
        return maxR->data;
    }

    void displayAll(){
        display(root);
    }
    int minelment()
    {
        if(root==NULL)
        {
            throw"there are no elment";
        }
        Node* temp=root;
        while(temp->Left!=NULL)
        {
            temp=temp->Left;
        }
        return temp->data;
    }
    int maxelment()
    {
        if(root==NULL)
        {
            throw"there are no elment";
        }
        Node* temp=root;
        while(temp->Right!=NULL)
        {
            temp=temp->Right;
        }
        return temp->data;
    }
    void remove(int data){
        Node * node = getNodeByData(data);
        if (node == nullptr){
            throw "Error: not found can not remove";
        }
        if (node == root){
            if (root->Left == nullptr&&root->Right == nullptr){
                root->Right == nullptr;
            }
           
            else if (root->Left == nullptr){  
                root = root->Right;
            }
            else if (root->Right == nullptr){  
                root = root->Left;
            }
            
            else {
                
                Node * newRoot = root->Left;
           
                Node * maxR = getMaxRight(newRoot);
      
                maxR->Right = root->Right;
                root = newRoot;
        }
        }
        else{
           
            Node * perant = getParent(node);
            Node * newChild = nullptr;
            if (node->Left == nullptr&&node->Right == nullptr){
                newChild == nullptr;
            }
          
            else if (node->Left == nullptr){  
                newChild = node->Right;
            }
            else if (node->Right == nullptr){  
                newChild = node->Left;
            }
            
            else {
              
                Node * newPerant = root->Left;
               
                Node * maxR = getMaxRight(newPerant);
             
                maxR->Right = node->Right;
                newChild = newPerant;
        }
    if(perant->Right ==node){
                perant->Right =newChild;
            }
            else{
                perant->Left =newChild;
            }
        }
        delete node;
    }
};

int main()
{
    Tree t;
    t.add(50);
    t.add(40);
    t.add(70);
    t.add(30);
    t.add(65);
    t.add(60);
    t.add(35);
    t.add(42);
    t.add(45);
    t.add(48);
    t.add(25);
    t.add(22);
    t.findDataInTree(70)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(35)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(40)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(50)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(30)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(80)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    t.findDataInTree(90)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    try{
        //t.getParentBydata(50);
        cout<<"Parent : "<<t.getParentBydata(35)<<endl;
        cout<<"Max Right : "<<t.getMaxRightByData(50)<<endl;
    }catch(const char * msg){
        cout<<msg;
    }
    //t.Remove(48);
    t.remove(48);
    cout<<"min : "<<t.minelment()<<endl;
    cout<<"max : "<<t.maxelment()<<endl;
    t.displayAll();
    return 0;
}

