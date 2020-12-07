#include "gtest/gtest.h"
#include "Deque.h"

const int MAX_TEST_SIZE = 5;
class Deque_UT : public ::testing::Test
{
protected:
    Deque_UT()
    {
        dq = new Deque<int>();
    }
    ~Deque_UT(){
        delete dq;
    }
    Deque<int> *dq;
};

TEST_F(Deque_UT, InitialSize0)
{
    ASSERT_EQ(dq->size(), 0);
    
}
TEST_F(Deque_UT, addFirstMultiple)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        dq->addFirst(i);
    }
    
    ASSERT_EQ(dq->size(), MAX_TEST_SIZE);
    for(int i=0; i < MAX_TEST_SIZE; i++){
        ASSERT_EQ(dq->removeFirst(), MAX_TEST_SIZE - 1 - i);
    }
}
TEST_F(Deque_UT, addLastMultiple)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        dq->addLast(i);
    }
    
    ASSERT_EQ(dq->size(), MAX_TEST_SIZE);
    for(int i=0; i < MAX_TEST_SIZE; i++){
        ASSERT_EQ(dq->removeLast(), MAX_TEST_SIZE - 1 - i);
    }
}

TEST_F(Deque_UT, AddFirstThenRemoveLast)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        dq->addFirst(i);
    }
    dq->print();
    ASSERT_EQ(dq->size(), MAX_TEST_SIZE);
    for(int i=0; i < MAX_TEST_SIZE; i++){
        ASSERT_EQ(dq->removeLast(), i);
    }
}

TEST_F(Deque_UT, AddLastThenRemoveFirst)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        dq->addLast(i);
    }
    dq->print();
    ASSERT_EQ(dq->size(), MAX_TEST_SIZE);
    for(int i=0; i < MAX_TEST_SIZE; i++){
        ASSERT_EQ(dq->removeFirst(), i);
    }
}
TEST_F(Deque_UT, RemovingFromEmptyShouldFail)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        dq->addLast(i);
    }
    
    ASSERT_EQ(dq->size(), MAX_TEST_SIZE);
    for(int i=0; i < MAX_TEST_SIZE; i++){
        ASSERT_EQ(dq->removeFirst(), i);
    }
    dq->print();
    ASSERT_EQ(dq->removeFirst(), ERROR_CODE);
}

TEST_F(Deque_UT, AddingAndRemovingImmediatelyAfter)
{
    for(int i=0; i < MAX_TEST_SIZE; i++){
        if(i%2){
            dq->addLast(i);
        }
        else{
            dq->addFirst(i);
        }
        dq->print();
        ASSERT_EQ(dq->removeFirst(), i);
    }
    ASSERT_EQ(dq->removeFirst(), ERROR_CODE);
}

