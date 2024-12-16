#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        prev = NULL;
        next = NULL;
        this->data = data;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
//================================================================
    Node* searchData(int data)
    {
        Node* search = head;
        while (search != NULL) {
            if (search->data == data) {
                return search;
            }
            search = search->next;
        }
        return NULL;
    }
//================================================================
    int insertBefore(int data, int beforeData)
    {
        Node* newNode = new Node(data);
        Node* curr = searchData(beforeData);
        if (curr == NULL) {
            delete newNode;
            return -1;
        }
        size++;
        newNode->next = curr;
        newNode->prev = curr->prev;

        if (curr->prev == NULL) {
            head = newNode;
        } else {
            curr->prev->next = newNode;
        }
        curr->prev = newNode;
        return 1;
    }
//================================================================
    int getDataByIndex(int index, int& result)
    {
        Node* curr = head;
        int size = getCount();

        if (index < size) {
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            result = curr->data;
            return 1;
        } else {
            cout << "Out of Range" << endl;
            return -1;
        }
    }
     int getCount()
    {
        return size;
    }
//================================================================
    int insertAfter(int data, int afterData)
    {
        Node* newNode = new Node(data);
        Node* curr = searchData(afterData);
        if (curr == NULL) {
            delete newNode;
            return -1;
        }
        size++;
        newNode->next = curr->next;
        newNode->prev = curr;

        if (newNode->next == NULL) {
            tail = newNode;
        } else {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        return 1;
    }
//================================================================
     void display()
    {
        int len = getCount();
        Node* curr = head;
        if (curr == NULL) {
            cout << "No Data in linkedList" << endl;
        } else {
            while (curr != NULL) {
                cout << curr->data << "\t";
                curr = curr->next;
            }
            cout << endl;
        }
    }
 //================================================================
    void createHead(int data)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        size++;
    }
};










int main() {
    LinkedList list;
    int test, result;

    list.createHead(100);
    list.display();

    list.insertAfter(200, 100);
    list.display();

    list.insertBefore(50, 100);
    list.display();


    test = list.getDataByIndex(2, result);
    (test == 1)? cout << "Data at index 2: " << result << endl:cout << result << endl;

    test = list.getDataByIndex(10, result);
    (test == -1)? cout << "Invalid index " << endl:cout << result << endl;

    list.display();
    cout << " Size = " << list.getCount() << endl;

    return 0;
}
