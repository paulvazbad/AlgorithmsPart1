#ifndef RANDOMIZEDQUEUE_H
#define RANDOMIZEDQUEUE_H

#include <stdlib.h> /* srand, rand */

#define FRIEND_TEST(test_case_name, test_name) \
    friend class test_case_name##_##test_name##_Test

template <class T>
class Element
{
public:
    T data;
    bool valid;
    Element() { valid = false; }
};

template <class T>
class RandomizedQueue
{
public:
    RandomizedQueue();
    bool isEmpty();
    int size();
    void enqueue(T);
    T dequeue();
    T sample();

private:
    // Methods
    void resize(int);
    int find_random();

    // For testing purposes
    FRIEND_TEST(RandomizedQueue_UT, resizingTest);
    FRIEND_TEST(RandomizedQueue_UT, resizingShrinkTest);
    FRIEND_TEST(RandomizedQueue_UT, fillingAndEmptying);
    // Members
    Element<T> *arr;
    int total_size;
    int current_size;
};

template <class T>
RandomizedQueue<T>::RandomizedQueue()
{
    arr = new Element<T>[1];
    total_size = 1;
    current_size = 0;
}

template <class T>
bool RandomizedQueue<T>::isEmpty()
{
    return (current_size == 0);
}

template <class T>
int RandomizedQueue<T>::size()
{
    return current_size;
}

template <class T>
void RandomizedQueue<T>::enqueue(T element)
{
    if (current_size == total_size)
    {
        // Resize and grow
        resize(total_size * 2);
    }
    //Append element
    Element<T> e;
    e.data = element;
    e.valid = true;
    arr[current_size++] = e;
}

template <class T>
void RandomizedQueue<T>::resize(int new_size)
{
    if (new_size <= 0)
        throw std::invalid_argument("Size of array 0");

    Element<T> *new_arr = new Element<T>[new_size];
    for (int i = 0; i < total_size; i++)
    {
        if (arr[i].valid)
            new_arr[i] = arr[i];
    }
    arr = new_arr;
    total_size = new_size;
}

template <class T>
T RandomizedQueue<T>::sample()
{
    int index = find_random();
    return arr[index].data;
}

template <class T>
T RandomizedQueue<T>::dequeue()
{
    int index = find_random();
    arr[index].valid = false;
    T value_to_return = arr[index].data;
    current_size--;
    if (current_size == total_size / 4 && current_size > 0)
    {
        // Resize and shrink
        resize(total_size / 2);
    }
    return value_to_return;
}

template <class T>
int RandomizedQueue<T>::find_random()
{
    bool found = false;
    int random_index;
    int current_tries = 0;
    if (size() == 0)
        throw std::invalid_argument("Empty RandomizedQueue 0");
    ;
    while (current_tries < total_size)
    {
        random_index = rand() % total_size;
        if (arr[random_index].valid == true)
        {
            return random_index;
        }
        current_tries++;
    }
    return -1;
}

#endif