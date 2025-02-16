//
// Created by jrd2112 on 2/15/2025.
//

#ifndef CSC232_ARRAY_BAG_RECURSIVE_
#define CSC232_ARRAY_BAG_RECURSIVE_

#include "BagInterface.h"
#include "csc232.h"

namespace csc232
{
    template < typename ItemType >
    class ArrayBagRecursive : public BagInterface< ItemType >
    {
    private:
        static constexpr int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
        ItemType items[DEFAULT_CAPACITY];          // Array of bag items
        int itemCount;                             // Current count of bag items
        int maxItems;                              // Max capacity of the bag

        // Returns either the index of the element in the array items that
        // contains the given target or -1, if the array does not contain
        // the target.
        // TODO: Task 1a - Declare helper function as specified

        // Counts the number of occurrences of the given target in array items
        // TODO: Task 1b - Declare helper function as specified

    public:
        ArrayBagRecursive( );

        int getCurrentSize( ) const override;

        bool isEmpty( ) const override;

        bool add( const ItemType & newEntry ) override;

        bool remove( const ItemType & anEntry ) override;

        void clear( ) override;

        bool contains( const ItemType & anEntry ) const override;

        int getFrequencyOf( const ItemType & anEntry ) const override;

        std::vector< ItemType > toVector( ) const override;
    }; // end ArrayBag

}

#endif //CSC232_ARRAY_BAG_RECURSIVE_
