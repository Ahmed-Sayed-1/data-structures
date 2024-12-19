#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int *items;
    int front;
    int rear;

public:
    Queue(int size) {
        this->size = size;
        front = rear = -1;
        items = new int[size];
    }

    bool isFull() 
    {
        return (rear == size - 1 && front == 0) || (rear + 1 == front);
    }

    bool isEmpty()
    {
        return rear == -1 && front == -1;
    }

    bool enqueue(int data) {
        if (isFull()) 
        {
            return false;
        }

        if (isEmpty()) 
        {
            front = rear = 0;
        } else if (rear == size - 1 && front > 0) 
        {
            rear = 0;
        } else {
            rear++;
        }

        items[rear] = data;
        return true;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            throw "Queue is empty";
        }

        int data = items[front];
        items[front] = 0;

        if (front == rear) 
        {
            front = rear = -1;
        } else if (front == size - 1) 
        {
            front = 0;
        } else 
        {
            front++;
        }

        return data;
    }
    void peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }else
        {
            cout<<"First element = "<<items[front]<<endl;
        }
    }
    void display()
    {
         if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else if (front > rear) {
            for (int i = front; i < size; i++) {
                cout << items[i] << " --> ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << items[i] << " --> ";
            }
        } else {
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " --> ";
            }
        }
        cout << endl;
    }
    ~Queue() {
        delete[] items;
    }
};

int main() {
    Queue q(3);

    q.enqueue(1) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.enqueue(2) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.enqueue(3) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.display();
    q.peek();
    try {
        cout << q.dequeue() << endl;
    } catch (const char *msg) {
        cout << msg << endl;
    }
    q.display();
    q.peek();
    q.enqueue(4) ? cout << "Success" << endl : cout << "Failed" << endl;
    q.display();
    q.peek();
  try {
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
    } catch (const char *msg) {
        cout << msg << endl;
    }

    return 0;
}
