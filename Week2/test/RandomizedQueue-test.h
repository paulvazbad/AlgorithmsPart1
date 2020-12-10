#include "gtest/gtest.h"
#include "RandomizedQueue.h"

class RandomizedQueue_UT : public ::testing::Test
{
protected:
    RandomizedQueue_UT()
    {
        randoq = new RandomizedQueue<int>();
    }
    ~RandomizedQueue_UT()
    {
        delete randoq;
    }
    RandomizedQueue<int> *randoq;
};

TEST_F(RandomizedQueue_UT, InitialSize0)
{
    ASSERT_EQ(randoq->size(), 0);
}
TEST_F(RandomizedQueue_UT, enqueueMultiple)
{
    for (int i = 0; i < MAX_TEST_SIZE; i++)
    {
        randoq->enqueue(i);
    }
    ASSERT_EQ(randoq->size(), MAX_TEST_SIZE);
}

TEST_F(RandomizedQueue_UT, resizingTest)
{
    randoq->enqueue(10);
    ASSERT_EQ(randoq->total_size, 1);
    randoq->enqueue(20);
    ASSERT_EQ(randoq->total_size, 2);
    randoq->enqueue(30);
    ASSERT_EQ(randoq->total_size, 4);
    randoq->enqueue(40);
    ASSERT_EQ(randoq->total_size, 4);
    randoq->enqueue(50);
    ASSERT_EQ(randoq->total_size, 8);
}

TEST_F(RandomizedQueue_UT, resizingShrinkTest)
{
    randoq->enqueue(10);
    ASSERT_EQ(randoq->total_size, 1);
    randoq->enqueue(20);
    ASSERT_EQ(randoq->total_size, 2);
    randoq->enqueue(30);
    ASSERT_EQ(randoq->total_size, 4);
    randoq->enqueue(40);
    ASSERT_EQ(randoq->total_size, 4);

    cout << randoq->dequeue() << endl;
    cout << randoq->dequeue() << endl;
    cout << randoq->dequeue() << endl;
    cout << randoq->dequeue() << endl;
    randoq->enqueue(30);
    cout << randoq->dequeue() << endl;
}
TEST_F(RandomizedQueue_UT, trydequeueOnEmpty)
{
    randoq->enqueue(10);

    cout << randoq->dequeue() << endl;
    EXPECT_THROW(randoq->dequeue(), std::invalid_argument);
}

TEST_F(RandomizedQueue_UT, fillingAndEmptying)
{
    for (int i = 0; i < MAX_TEST_SIZE; i++)
    {
        randoq->enqueue(i);
        EXPECT_EQ(randoq->size(), i + 1);
    }
    for (int i = 0; i < MAX_TEST_SIZE - 1; i++)
    {
        randoq->dequeue();
        EXPECT_EQ(randoq->size(), MAX_TEST_SIZE - i - 1);
    }
    EXPECT_EQ(randoq->total_size, 2);
    randoq->dequeue();
    EXPECT_EQ(randoq->total_size, 2);
}
TEST_F(RandomizedQueue_UT, sampleOneElement)
{
    
    randoq->enqueue(10);
    EXPECT_EQ(randoq->sample(), 10);
    EXPECT_EQ(randoq->sample(), 10);
    EXPECT_EQ(randoq->sample(), 10);
    EXPECT_EQ(randoq->sample(), 10);
}