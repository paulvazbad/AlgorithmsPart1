#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *previous;
};

const int ERROR_CODE = -99999;

template <class T>
class Deque
{
public:
    Deque();
    bool IsEmpty();
    void addFirst(T element);
    void addLast(T element);
    T removeFirst();
    T removeLast();
    int size();
    void print();

private:
    Node<T> *head;
    Node<T> *last;
    int current_size;
};

template <class T>
Deque<T>::Deque()
{
    head = NULL;
    last = head;
    current_size = 0;
}

template <class T>
bool Deque<T>::IsEmpty()
{
    return (size() == 0);
}

template <class T>
void Deque<T>::addFirst(T element)
{
    Node<T> *newHead = new Node<T>();
    newHead->value = element;
    newHead->next = this->head;
    newHead->previous = NULL;
    // If it was empty consider this the new end and head
    if (this->head != NULL)
    {
        this->head->previous = newHead;
    }
    if (size() == 0)
    {
        this->last = newHead;
    }
    this->head = newHead;

    current_size++;
}

template <class T>
void Deque<T>::addLast(T element)
{
    Node<T> *newEnd = new Node<T>();
    newEnd->value = element;
    newEnd->next = NULL;
    newEnd->previous = NULL;
    // If it was empty consider this the new end and head
    if (size() == 0)
    {
        head = newEnd;
        last = head;
        last->next = NULL;
    }
    else
    {
        last->next = newEnd;
        newEnd->previous = last;
        last = newEnd;
    }
    current_size++;
}

template <class T>
int Deque<T>::size()
{
    return current_size;
}

template <class T>
T Deque<T>::removeFirst()
{
    if (size() == 0)
        return ERROR_CODE;
    T value_to_return = head->value;
    // move head
    if (head->next != NULL)
    {
        head->next->previous = NULL;
    }
    head = head->next;
    if(size()==1){
        //head is pointing to last so update that too
        last = head;
    }
    current_size--;
    return value_to_return;
}

template <class T>
T Deque<T>::removeLast()
{
    if (size() == 0)
        return ERROR_CODE;
    T value_to_return = last->value;
    //move last

    if (last->previous != NULL)
    {
        // At least 2 elements
        last->previous->next = NULL;
    }
    last = last->previous;
    if(size()==1){
        //head is pointing to last so update that too
        head = last;
    }
    current_size--;

    return value_to_return;
}

template <class T>
void Deque<T>::print()
{
    Node<T> *curr;
    curr = head;
    while (curr != NULL)
    {
        cout << curr->value;
        if (curr->next != NULL)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}