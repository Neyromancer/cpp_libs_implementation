#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <string>

#include "algorithms/algorithms.hpp"

namespace amature {

template<class T, std::size_t N>
class array {
  T storage[ N ];

public:
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;
  // using reverse_iterator = T *; // std::reverse_iterator<iterator>;  // TODO: rewrite std::reverse_iterator
  // using const_reverse_iterator = const T *; // std::reverse_iterator<const_iterator>; // TODO: rewrite std::reverse_iterator

  array() = default;
  explicit array( const std::initializer_list<T> &lst );

  constexpr T &at( size_type pos );
  constexpr const T &at( size_type pos ) const;

  constexpr T &operator[]( size_type pos );
  constexpr const T &operator[]( size_type pos ) const;
  
  constexpr T &front();
  constexpr const T &front() const;

  constexpr T &back();
  constexpr const T &back() const;

  constexpr T *data() noexcept;
  constexpr const T *data() const noexcept;

  constexpr iterator begin() noexcept;
  constexpr const_iterator cbegin() const noexcept;

  constexpr iterator end() noexcept;
  constexpr const_iterator cend() noexcept;

  // constexpr reverse_iterator rbegin() noexcept;
  // constexpr const_reverse_iterator crbegin() const noexcept;
  
  // constexpr reverse_iterator rend() noexcept;
  // constexpr const_reverse_iterator crend() const noexcept;

  constexpr bool empty() const noexcept;
  
  constexpr size_type size() const noexcept;

  constexpr size_type max_size() const noexcept;

  void fill( const T &value );

  void swap( array<T, N> &other ) noexcept;
};

template <class T, std::size_t N>
inline
array<T,N>::array( const std::initializer_list<T> &lst )
{
  int i = 0;
  for( auto it = lst.begin(); it != lst.end(); ++it )
    storage[ i++ ] = *it;
}

template <class T, std::size_t N>
inline
constexpr T &array<T, N>::at( std::size_t pos )
{
  if( pos >= size() )
    throw std::out_of_range( std::to_string( pos ) + " >= " + std::to_string( size() ) );

  return storage[ pos ];
}

template <class T, std::size_t N>
inline
constexpr const T &array<T, N>::at( std::size_t pos ) const
{
  if( pos >= size() )
    throw std::out_of_range( std::to_string( pos ) + " >= " + std::to_string( size() ) );

  return storage[ pos ];
}

template<class T, std::size_t N>
inline
constexpr T &array<T, N>::operator[]( std::size_t pos )
{
  return storage[ pos ];
}

template<class T, std::size_t N>
inline
constexpr const T &array<T, N>::operator[]( std::size_t pos ) const
{
  return storage[ pos ];
}

template<class T, std::size_t N>
inline
constexpr T &array<T, N>::front()
{
  return *storage;
}

template<class T, std::size_t N>
inline
constexpr const T &array<T, N>::front() const
{
  return *storage;
}

template<class T, std::size_t N>
inline
constexpr T &array<T, N>::back()
{
  return storage[ size() - 1 ];
}

template<class T, std::size_t N>
inline
constexpr const T &array<T, N>::back() const
{
  return storage[ size() - 1 ];
}

template<class T, std::size_t N>
inline
constexpr T *array<T, N>::data() noexcept
{
  return storage;
}

template<class T, std::size_t N>
inline
constexpr const T *array<T, N>::data() const noexcept
{
  return storage;
}

template<class T, std::size_t N>
inline
constexpr typename array<T,N>::iterator array<T,N>::begin() noexcept
{
  return iterator( data() );
}

template<class T, std::size_t N>
inline
constexpr typename array<T,N>::const_iterator array<T,N>::cbegin() const noexcept
{
  return const_iterator( data() );
}

template<class T, std::size_t N>
inline
constexpr typename array<T,N>::iterator array<T,N>::end() noexcept
{
  return iterator( data() + size() );
}

template<class T, std::size_t N>
inline
constexpr typename array<T,N>::const_iterator array<T,N>::cend() noexcept
{
  return const_iterator( data() + size() );
}

//template<class T, std::size_t N>
//inline
//constexpr typename array<T,N>::reverse_iterator array<T,N>::rbegin() noexcept
//{
//  
//}

//template<class T, std::size_t N>
//inline
//constexpr typename array<T,N>::const_reverse_iterator array<T,N>::crbegin() const noexcept
//{}
//
//template<class T, std::size_t N>
//inline  
//constexpr typename array<T,N>::reverse_iterator array<T,N>::rend() noexcept
//{}
//
//template<class T, std::size_t N>
//inline
//constexpr typename array<T,N>::const_reverse_iterator array<T,N>::crend() const noexcept
//{}

template<class T, std::size_t N>
inline
constexpr bool array<T, N>::empty() const noexcept
{
  return size() == 0;
}

template<class T, std::size_t N>
inline
constexpr typename array<T, N>::size_type array<T, N>::size() const noexcept
{
  return N;
}

template<class T, std::size_t N>
inline
constexpr typename array<T, N>::size_type array<T, N>::max_size() const noexcept
{
  return N;
}

template<class T, std::size_t N>
void array<T, N>::fill( const T &value )
{
  std::fill_n( begin(), size(), value );
}

template<class T, std::size_t N>
void array<T, N>::swap( array<T, N> &other ) noexcept
{
  std::swap_ranges( begin(), end(), rhs.begin() );
}

template<class T, std::size_t N>
bool operator==( const array<T,N> &lhs, const array<T, N> &rhs )
{
  for( std::size_t i = 0; i < N; ++i )
    if( lhs[ i ] != rhs[ i ] )
      return false;

  return true;
}

template<class T, std::size_t N>
bool operator!=( const array<T, N> &lhs, const array<T, N> &rhs )
{
  return !( lhs == rhs );
}

template<class T, std::size_t N>
bool operator<( const array<T,N> &lhs, const array<T,N> &rhs )
{
  for( std::size_t i = 0; i < N; ++i ) {
    if( lhs[ i ] >= rhs[ i ] )
      return false;
  }

  return true;
}

template<class T, std::size_t N>
bool operator<=( const array<T,N> &lhs, const array<T,N> &rhs ) 
{
  for( std::size_t i = 0; i < N; ++i ) {
    if( lhs[ i ] > rhs[ i ] )
      return false;
  }

  return true;
}

template<class T, std::size_t N>
bool operator>( const array<T, N> &lhs, const array<T, N> &rhs ) 
{
  for( std::size_t i = 0; i < N; ++i ) {
    if( lhs[ i ] <= rhs[ i ] )
      return false;
  }

  return true;
}

template<class T, std::size_t N>
bool operator>=( const array<T, N> &lhs, const array<T, N> &rhs )
{
  for( std::size_t i = 0; i < N; ++i ) {
    if( lhs[ i ] < rhs[ i ] )
      return false;
  }

  return true;
}

template<class T, std::size_t N>
void swap( array<T, N> &lhs, array<T, N> &rhs ) noexcept
{
  for( int i = 0; i < lhs.size(); ++i )
    std::swap( lhs[ i ], rhs[ i ] );
}

template<std::size_t I, class T, std::size_t N>
constexpr T &get( array<T,N> &arr ) noexcept
{
  static_assert( I < N, "index out of scope" );

  return arr[ I ];
}

template<std::size_t I, class T, std::size_t N>
constexpr const T &get( const array<T,N> &arr ) noexcept
{
  static_assert( I < N, "index out of scope" );

  return arr[ I ];
}

template<std::size_t I, class T, std::size_t N>
constexpr T &&get( array<T, N> &&arr ) noexcept
{
  static_assert( I < N, "index out of scope" );

  return std::move( arr[ I ] );
}

template<class T, std::size_t N>
constexpr array<std::remove_cv_t<T>,N> to_array( T(&a)[N] )
{
  array<T,N> arr;
  for( typename array<T, N>::size_type i = 0; i < N; ++i )
    arr[ i ] = a[ i ];

  return arr;
}

} // amature
