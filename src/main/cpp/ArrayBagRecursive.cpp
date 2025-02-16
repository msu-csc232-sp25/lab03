//
// Created by jrd2112 on 2/15/2025.
//

#include "ArrayBagRecursive.h"
#include <cstddef>

namespace csc232
{
    template < class ItemType >
    ArrayBagRecursive< ItemType >::ArrayBagRecursive( ): itemCount{ 0 }, maxItems{ DEFAULT_CAPACITY }
    {
    }  // end default constructor

    template < class ItemType >
    int ArrayBagRecursive< ItemType >::getCurrentSize( ) const
    {
        return itemCount;
    }  // end getCurrentSize

    template < class ItemType >
    bool ArrayBagRecursive< ItemType >::isEmpty( ) const
    {
        return itemCount == 0;
    }  // end isEmpty

    template < class ItemType >
    bool ArrayBagRecursive< ItemType >::add( const ItemType & newEntry )
    {
        bool hasRoomToAdd = ( itemCount < maxItems );
        if ( hasRoomToAdd )
        {
            items[ itemCount ] = newEntry;
            itemCount++;
        }  // end if

        return hasRoomToAdd;
    }  // end add

    template < class ItemType >
    bool ArrayBagRecursive< ItemType >::remove( const ItemType & anEntry )
    {
        // TODO: Task 2b - call getIndexOf appropriately and assign it to locatedIndex
        const int locatedIndex = 0;
        const bool canRemoveItem = !isEmpty( ) && ( locatedIndex > -1 );
        if ( canRemoveItem )
        {
            itemCount--;
            items[ locatedIndex ] = items[ itemCount ];
        }  // end if

        return canRemoveItem;
    }  // end remove

    template < class ItemType >
    void ArrayBagRecursive< ItemType >::clear( )
    {
        itemCount = 0;
    }  // end clear

    template < class ItemType >
    bool ArrayBagRecursive< ItemType >::contains( const ItemType & anEntry ) const
    {
        // TODO: Task 2c - call getIndexOf accordingly and use its return value as needed for this method
        return false;
    }  // end contains

    template < class ItemType >
    int ArrayBagRecursive< ItemType >::getFrequencyOf( const ItemType & anEntry ) const
    {
        // TODO: Task 3b - call countFrequency accordingly and use the return value as prescribed
        return 0;
    }  // end getFrequencyOf

    template < class ItemType >
    std::vector< ItemType > ArrayBagRecursive< ItemType >::toVector( ) const
    {
        std::vector< ItemType > bagContents;
        for ( int i = 0; i < itemCount; i++ )
            bagContents.push_back( items[ i ] );

        return bagContents;
    }  // end toVector

// private methods
    // TODO: Task 2a - Implement me accordingly

    // TODO: Task 3a - Implement me accordingly

}
