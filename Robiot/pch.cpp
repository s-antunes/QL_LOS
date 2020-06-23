//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"
#include "gtest/gtest.h"


//test comment

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    if(RUN_ALL_TESTS() != 0)
    {
        cout << "An error has occured while running some tests" << endl;
    }

    return 0;
}
