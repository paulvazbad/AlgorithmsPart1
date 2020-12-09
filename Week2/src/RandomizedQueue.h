#ifndef RANDOMIZEDQUEUE_H
#define RANDOMIZEDQUEUE_H

#define FRIEND_TEST(test_case_name, test_name)\
friend class test_case_name##_##test_name##_Test

template <class T>
class Element{
    public:
    T data;
    bool valid;
};


template <class T>
class RandomizedQueue
{
public:
    RandomizedQueue();
    bool isEmpty();
    int size();
    void enqueue(T);

private:
    // Methods
    void resize(int);

    // For testing purposes
    FRIEND_TEST(RandomizedQueue_UT, resizingTest);

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
    if (current_size == total_size / 4 && current_size > 0)
    {
        // Resize and shrink
        resize(total_size / 2);
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
    Element<T> *new_arr = new Element<T>[new_size];
    for (int i = 0; i < total_size; i++)
    {
        new_arr[i] = arr[i];
    }
    arr = new_arr;
    total_size = new_size;
}

#endif