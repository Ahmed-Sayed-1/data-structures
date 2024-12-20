#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) 
    {
        next = NULL;
        this->data = data;
    }
};
template <class T>
class Queue
{
private:
   Node<T>* head;
   Node<T>* tail;
   int size=0;
public:
    Queue()
    {
        head=NULL;
        tail=NULL;
    }
    int enqueue(T data)
    {
        Node<T> *newNode=new Node<T>(data);
        if(head==NULL)
        {
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        size++;
        return 1;
    }
    T dequeue() {
        if (head == NULL) 
        {
            throw "Queue is empty";
        }

        Node<T>* temp = head;
        T data = head->data;
        head = head->next;

        if (head == NULL) 
        {
            tail = NULL;
        }
        delete temp;
        size--;
        return data;
    }
    T peek() {
        if (head == NULL) 
        {
            throw "Queue is empty";
        }
        return head->data;
    }
    void display() 
    {
        if (head == NULL) 
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node<T>* current = head;
        while (current != NULL) 
        {
            cout << current->data << " --> ";
            current = current->next;
        }
        cout << endl;
    }
    void reverse()
    {
        T *data=new T [size];
        int arrSize=size;
        for (int i = 0; i < arrSize; i++)
        {
            data[i]=this->dequeue();
            
        }
        for(int i=arrSize-1;i>=0;i--)
        {
            this->enqueue(data[i]);
        }
        delete data;
    }
    ~Queue()
    {
         while (head != NULL) 
         {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    Queue<int> q;

    q.enqueue(1) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.enqueue(2) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.enqueue(3) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.display();
    q.reverse();
    q.display();
/*
    try {
        cout <<q.dequeue() << endl;
        q.display();
        cout << q.dequeue() << endl;
        q.display();
        cout << q.dequeue() << endl;
        q.display();
        cout << q.dequeue() << endl; 
    } catch (const char* msg) {
        cout << msg << endl;
    }

    q.display();
*/
    return 0;
}
