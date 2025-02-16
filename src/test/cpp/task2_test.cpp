/**
* CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    task1_test.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Task 1 test fixture.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

#include <gtest/gtest.h>
#include "csc232_test_utils.h"
#include "ArrayBagRecursive.h"

namespace csc232
{
    class Task2TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task2TestFixture() : names{new ArrayBagRecursive<std::string>{}}
        {
            EXPECT_TRUE(names->add( "CSC120" ));
            EXPECT_TRUE(names->add( "CSC131" ));
            EXPECT_TRUE(names->add( "CSC232" ));
            EXPECT_TRUE(names->add( "MTH100" ));
            EXPECT_TRUE(names->add( "MTH200" ));
            EXPECT_TRUE(names->add( "MTH300" ));
        }

        ~Task2TestFixture() override
        {
            delete names;
        }

    protected:
        // Reusable objects for each unit test in this test fixture
        BagInterface<std::string>* names;
    };

#if !TEST_TASK2
    TEST_F(Task2TestFixture, Bootstrap)
    {
        std::cerr << "Task 2 is not ready for evaluation; please toggle the TEST_TASK2 macro to TRUE\n";
        SUCCEED(); // Just to keep spirits up out of the box ;-)
    }

#else

    TEST_F( Task2TestFixture, ItCanNotRemoveNonExistentItem )
    {
        EXPECT_FALSE( names->remove( "CSC000" ) );
    }

    TEST_F( Task2TestFixture, ItCanRemoveFirstItem )
    {
        EXPECT_TRUE( names->remove( "CSC120" ) );
    }

    TEST_F( Task2TestFixture, ItCanRemovMiddleItem )
    {
        EXPECT_TRUE( names->remove( "CSC232" ) );
    }

    TEST_F( Task2TestFixture, ItCanRemoveLastItem )
    {
        EXPECT_TRUE( names->remove( "MTH300" ) );
    }

    TEST_F( Task2TestFixture, ItCanInformUsOfMissingItem )
    {
        EXPECT_FALSE( names->contains( "CSC333" ) );
    }

    TEST_F(Task2TestFixture, ItCanFindAnItemAtBeginning)
    {
        EXPECT_TRUE(names->contains("CSC120"));
    }

    TEST_F(Task2TestFixture, ItCanFindAnItemInMiddle)
    {
        EXPECT_TRUE(names->contains("CSC232"));
    }

    TEST_F(Task2TestFixture, ItCanFindAnItemAtEnd)
    {
        EXPECT_TRUE(names->contains("MTH300"));
    }

#endif
} // end namespace csc232
