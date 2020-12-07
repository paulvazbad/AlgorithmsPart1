#include "gtest/gtest.h"
#include "Percolation.h"

class Percolation_UT : public ::testing::Test
{
protected:
    Percolation_UT()
    {
        percolation = new Percolation(3);
    }
    ~Percolation_UT(){
        delete percolation;
    }
    Percolation *percolation;
};

TEST_F(Percolation_UT, InitialOpenSitesEq0)
{
    EXPECT_EQ(percolation->numberOfOpenSites(), 0);
    ASSERT_FALSE(percolation->isOpen(0,0));
}

TEST_F(Percolation_UT, ShouldNotPercolateInitially){
    ASSERT_FALSE(percolation->percolates());
}

TEST_F(Percolation_UT, NoFullSites)
{
    //*First row must be full
    EXPECT_TRUE(percolation->isFull(0, 0));
    EXPECT_FALSE(percolation->isFull(1, 1));
    EXPECT_FALSE(percolation->isFull(2, 2));
}


TEST_F(Percolation_UT, OpenSiteIncreasesCounter){
    percolation->open(2,2);
    EXPECT_EQ(percolation->numberOfOpenSites(),1);
}

TEST_F(Percolation_UT, NoFullIfFirstRowNotOpen){
    percolation->open(1,0);
    ASSERT_FALSE(percolation->isFull(1,0));
}

TEST_F(Percolation_UT, PercolationEscenario){
    percolation->open(0,0);
    ASSERT_FALSE(percolation->percolates());
    percolation->open(1,0);
    ASSERT_FALSE(percolation->percolates());
    percolation->open(2,0);
    ASSERT_TRUE(percolation->percolates());
}

