#include <memory>
#include "gtest/gtest.h"
#include "Percolation-tests.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}