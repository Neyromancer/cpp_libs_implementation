#pragma once
#include <iterator>

namespace amature {

template<typename T>
inline void swap( T &a, T &b )
{
  auto tmp = a;
  a = b;
  b = tmp;
}

template<typename T>
void swap( T &a, T &b ) noexcept( std::is_move_constructible_v<T>,
                                  std::is_move_assignable_v<T> )
{
  swap( a, b );
}

template<typename T, std::size_t N>
void swap( T (&a)[N], T (&b)[N] ) noexcept( std::is_nothrow_swappable_v<T> )
{
  for( int i = 0; i < N; ++i )
    swap( a[ i ], b[ i ] ); 
}

template <typename ForwadIter1, typename ForwardIter2>
inline void swap_range( ForwardIter1 begin1, ForwardIter1 end1, ForwardIter2 begin2 )
{
  while( begin1 != end1 )
    std::iter_swap( begin1++, begin2++ );
}

}  // amature
