#include "gtest/gtest.h"
#include "Percolation.h"


class Percolation_UT:: public ::testing::test{
    public:
    Percolation_UT() : percolation(5){

    }
    
    protected:
        Percolation percolation;
        void TearDown() override{

        }

};