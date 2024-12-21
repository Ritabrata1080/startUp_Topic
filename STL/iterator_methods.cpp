/*
  Created by Ritabrata, 15/12/2024
*/

// iterator_methods.cpp 

// This file contains some methods used on a iterator object on a vector

#include <iostream>
#include <iterator>
#include <vector>
 
int main() 
{

  // advance() -->  Increments given iterator it by n elements.
  /*
      Until c++17
      template<class InputIt, class Distance >
      void advance(InputIt& it, Distance n );

      Increments given iterator it by n elements.

      Parameters : 
      it - Iterator to be advanced
      n - number of elements `it` should be advanced
  */

    std::vector<int> v{3, 1, 4};
 
    auto vi = v.begin();
    std::advance(vi, 2); // increment the vi iterator by 2 steps
    std::cout << *vi << ' '; // 4
 
    vi = v.end(); // 0
    std::cout << *vi << std::endl;
    std::advance(vi, -2); // Decrement the vi iterator by 2 steps
    std::cout << *vi << '\n'; // 1

    // Print the last element of the vector
    std::cout << *(--v.end()) << std::endl; // 4

    std::cout << "========================" << std::endl;

    // next() --> Return the nth successor (or -nth predecessor if n is negative) of iterator it.
    /*
        Until c++17
        template< class InputIt >
        InputIt next( InputIt it, typename std::iterator_traits<InputIt>::difference_type n = 1 );

        Parameters : 
        it - Iterator to be advanced
        n - number of elements `it` should be advanced
    */

      std::vector<int> c{4,5,6};
      auto it = c.begin();
      auto increment_with_next = std::next(it, 2);
      std::cout << *it << "  " << *increment_with_next << std::endl;

      it = c.end();
      increment_with_next = std::next(it, -2);
      std::cout << *increment_with_next << std::endl;

      std::cout << "========================" << std::endl;


    // prev() --> Return the nth predecessor (or -nth successor if n is negative) of iterator it.
    /*
        template< class BidirIt >
        BidirIt prev( BidirIt it, typename std::iterator_traits<BidirIt>::difference_type n = 1 );

        Parameters :
        it - an iterator
        n - number of elements `it` should be descended
    */ 

        std::vector<int> vec {3,1,4};
        auto itr = vec.end();
        auto prev = std::prev(itr, 2);
        std::cout << *prev << '\n'; // 1
    
        itr = v.begin();
        prev = std::prev(itr, -2);
        std::cout << *prev << '\n'; // 4

        std::cout << "========================" << std::endl;

    // distance() --> Returns the number of hops from first to last.
    /*
        template< class InputIt >
        typename std::iterator_traits<InputIt>::difference_type

        distance( InputIt first, InputIt last );

        Parameters :
        first - Iterator pointing to the first element
        last - Iterator pointing to the end of range 
    */

          std::vector<int> v1{3, 1, 4};
          std::cout << "distance(first, last) = "
              << std::distance(v1.begin(), v1.end()) << '\n'
              << "distance(last, first) = "
              << std::distance(v1.end(), v1.begin()) << '\n';

}
