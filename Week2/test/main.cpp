#include <memory>
#include "gtest/gtest.h"
#include "Deque-test.h"
#include "RandomizedQueue-test.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}