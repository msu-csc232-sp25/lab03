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
    class Task3TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task3TestFixture() : numbers{new ArrayBagRecursive<int>{}}
        {
        }

        ~Task3TestFixture() override
        {
            delete numbers;
        }

    protected:
        // Reusable objects for each unit test in this test fixture
        BagInterface<int>* numbers;
    };

#if !TEST_TASK3
    TEST_F(Task3TestFixture, Bootstrap)
    {
        std::cerr << "Task 3 is not ready for evaluation; please toggle the TEST_TASK3 macro to TRUE\n";
        SUCCEED(); // Just to keep spirits up out of the box ;-)
    }

#else
    TEST_F( Task3TestFixture, ItCanCountZeroItems )
    {
        for ( int i{ 0 }; i < 6; ++i )
        {
            numbers->add( i * 10 );
        }
        const auto expected{ 0 };
        const auto actual{ numbers->getFrequencyOf( 1 ) };
        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task3TestFixture, ItCanCountOneItem )
    {
        for ( int i{ 0 }; i < 6; ++i )
        {
            numbers->add( i );
        }
        const auto expected{ 1 };
        const auto actual{ numbers->getFrequencyOf( 1 ) };
        EXPECT_EQ( expected, actual );
    }

    TEST_F( Task3TestFixture, ItCanCountSeveralItems )
    {
        for ( int i{ 0 }; i < 6; ++i )
        {
            numbers->add( 1 );
        }
        const auto expected{ 6 };
        const auto actual{ numbers->getFrequencyOf( 1 ) };
        EXPECT_EQ( expected, actual );
    }


#endif
} // end namespace csc232
