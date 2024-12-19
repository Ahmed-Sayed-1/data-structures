#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* previous;
    Node(T data) 
    {
        previous = NULL;
        this->data = data;
    }
};
template <class T>
class Stack
{
private:
   Node<T>* tail;
public:
    Stack()
    {
        tail=NULL;
    }
    int push(T data)
    {
        Node<T> *newNode=new Node<T>(data);
        if(tail==NULL)
        {
            tail=newNode;
        }
        else
        {
            newNode->previous=tail;
            tail=newNode;
        }
        return 1;
    }
    T pop() {
        if (tail == NULL) 
        {
            throw "Stack is empty";
        }

        Node<T>* temp = tail;
        T data = tail->data;
        tail = tail->previous;

        delete temp;
        return data;
    }
    T peek() {
        if (tail == NULL) 
        {
            throw "Stack is empty";
        }
        return tail->data;
    }
    void display() 
    {
        if (tail == NULL) 
        {
            cout << "Stak is empty" << endl;
            return;
        }

        Node<T>* current = tail;
        while (current != NULL) 
        {
            cout << current->data << " --> ";
            current = current->previous;
        }
        cout << endl;
    }
    ~Stack()
    {
         while (tail != NULL) 
         {
            Node<T>* temp = tail;
            tail = tail->previous;
            delete temp;
        }
    }
};
int main() {
    Stack<int> q;

    q.push(1) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.push(2) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.push(3) ? cout << "Success" << endl : cout << "Failed" << endl;

    q.display();
    q.peek();

    try {
        cout <<q.pop() << endl;
        q.display();
        cout << q.pop() << endl;
        q.display();
        cout << q.pop() << endl;
        q.display();
        cout << q.pop() << endl; 
    } catch (const char* msg) {
        cout << msg << endl;
    }

    q.display();

    return 0;
}
