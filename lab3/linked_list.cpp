
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T data) {
        prev = NULL;
        next = NULL;
        this->data = data;
    }
};
template <class T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    Node<T>* searchData(T data) {
        Node<T>* search = head;
        while (search != NULL) {
            if (search->data == data) {
                return search;
            }
            search = search->next;
        }
        return NULL;
    }

    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev=tail;
            tail = newNode;
        }
        size++;
    }

    int getCount() 
    {
        return size;
    }

    T getDataByIndex(int index) {
        Node<T>* curr = head;
        int i = 0;

        if (index > size-1)
        {
            throw"out of the range";
        }
        for (int i = 0; i < index; i++) 
        {
            curr = curr->next;
        }
        return curr->data;
    }

    void display() {
        Node<T>* curr = head;
        if (curr == NULL) {
            cout << "No Data in linkedList" << endl;
        } else {
            while (curr != NULL) {
                cout << curr->data << "->";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    int insertAfter(T data, T afterData) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr = searchData(afterData);
        if (curr == NULL) 
        {
            delete newNode;
            return 0;
        }
        size++;
        newNode->next = curr->next;
        newNode->prev = curr;

        if (newNode->next == NULL) 
        {
            tail = newNode;
        } else 
        {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        return 1;
    }

    int insertBefore(T data, T beforeData) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr = searchData(beforeData);
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
    int insertInIndex(T data, T index) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr= head;
        if(index>size-1)
        {
            return 0;
        }
        for(int i=0; i<index;i++)
        {
            curr=curr->next;
        }
        curr->data=data;
        return 1;
    }
    void reverse()
    {
        Node<T>* curr = head;
        Node<T>* prevNode = NULL;
        Node<T>* nextNode = NULL;

        while (curr != NULL) 
        {
            nextNode = curr->next;
            curr->next = prevNode;
            curr->prev = nextNode;

            prevNode = curr;
            curr = nextNode;
        }
        tail = head;
        head = prevNode;
    }
    void marge(LinkedList<T>& l) 
    {
        if (l.head == NULL)
        {
            return;
        }

        if (this->head == NULL) 
        {
            this->head = l.head;
            this->tail = l.tail;
            this->size = l.size;
        }else
        {
            this->tail->next = l.head;
            l.head->prev = this->tail;
            this->tail = l.tail;
            this->size += l.size;
        }
    }
    void sort()
    {
        int sorted=0;
        for(int i=0;sorted==0;i++)
        {
            sorted=1;
            Node<T>* curr=head;
            for (int j = 0; j < size-1-i; j++)
            {
               if(curr->data>curr->next->data)
               {
                T temp=curr->data;
                curr->data=curr->next->data;
                curr->next->data=temp;
                sorted=0;
               }
                curr=curr->next;
            }
            
        }
        
        
    }
};
template <class T>
class search
{
private:
public:
    LinkedList<T> linearSearch(T *arr,int size,T value)
    {
        LinkedList<T> list;
        int counter=0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i]==value)
            {
                list.insert(i);
            }
            counter++;   
        }
        cout<<"=========="<<counter<<"=========="<<endl;
        return list;
    }
    int binarySearch(T *arr,int size,T value)
    {
        int start = 0;
        int end = size - 1;
        int counter=0;
        while (start <= end) 
        {
            int mid = (start + end) / 2;

            if (arr[mid] == value) 
            {
                cout<<"=========="<<counter<<"=========="<<endl;
                return mid; 
            } else if (arr[mid] < value) 
            {
                start = mid + 1; 
            } else {
                end = mid - 1; 
            }
            counter++;
        }
        return -1; 
    }
};
int main() {
    LinkedList<int> list;
    LinkedList<int> list1;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.insertInIndex(5,2);
    list.display();
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    
    list.marge(list1);
    list.display();
    list.reverse();
    list.display();
    list.sort();
    list.display();
    search<int> s;
    int x[]={1,2,3,4,5,6};
    cout<<s.binarySearch(x,6,3)<<"\n";
    LinkedList<int> list2=s.linearSearch(x,6,3);
    for(int i=0;i<list2.getCount();i++)
    {
        cout<<list2.getDataByIndex(i)<<"\t";
    }
    cout<<endl;
    /*try
    {
        cout<<list.getDataByIndex(3)<<endl;
    }catch(const char *m)
    {
        cout<<m<<endl;
    }
    
    list.insertAfter(25, 20);
    list.display(); 

    list.insertBefore(5, 10);
    list.display(); 
*/

    return 0;
}
