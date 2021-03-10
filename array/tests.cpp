#include <cstdlib>
#include <iostream>
#include <string>

#include "array.hpp"

int main( void ) {
  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test explicit constructor" << std::endl;
  std::cout << "/////////////////////////////////" << std::endl;
  amature::array<int, 5> arr0{ 1, 2, 3, 4, 5 };
  for( auto it = arr0.begin(); it != arr0.end(); ++it )
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test size() method" << std::endl;
  std::cout << "/////////////////////////////////" << std::endl;
  amature::array<int, 5> arr;
  std::cout << "size = " << arr.size() << std::endl;
  for( int i = 0; i < arr.size(); ++i )
    arr[ i ] = i + 1;

  try {
    for( int i = 0; i <= arr.size(); ++i )
      std::cout << arr.at( i ) << " ";
    std::cout << std::endl;
  } catch( const std::exception &exp )
  {
    std::cout << "\nError occurred: " << exp.what() << std::endl;
  }

  std::cout << "first element = " << arr.front() << std::endl;
  std::cout << "last element = " << arr.back() << std::endl;

  auto a = arr.data();
  int i = 0;
  while( i < arr.size() ) {
    std::cout << i << " -> " << *( a + i ) << " ";
    ++i;
  }
  std::cout << std::endl;

  std::cout << "arr size " << arr.size() << "| empty -> " <<  std::boolalpha << arr.empty() << std::endl;
  amature::array<double,0>arr1;
  std::cout << "arr1 size " << arr1.size() << "| empty -> " <<  std::boolalpha << arr1.empty() << std::endl;

  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test fill() method" << std::endl;
  std::cout << "/////////////////////////////////" << std::endl;
  amature::array<std::string, 5> arr2;
  arr2.fill( "filled" );
  for( int i = 0; i < arr2.size(); ++i )
    std::cout << arr2[ i ] << ( i + 1 )  << " ";
  std::cout << std::endl;

  amature::array<int, arr.size()> arr3;
  arr3.fill( -1 );

  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test swap() method" << std::endl;
  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "before swap" << std::endl;
  for( int i = 0; i < arr.size(); ++i )
    std::cout << arr.at( i ) << " ";
  std::cout << std::endl;

  arr.swap( arr3 );
  std::cout << "after swap" << std::endl;
  for( int i = 0; i < arr.size(); ++i )
    std::cout << arr.at( i ) << " ";
  std::cout << std::endl;

  amature::array<std::string,5> arr4;
  arr4.fill( "hello" );
  amature::array<std::string,5> arr5;
  arr5.fill( "world" );
  
  std::cout << "before swaping" << std::endl;
  std::cout << "arr4" << std::endl;
  for( int i = 0; i < arr4.size(); ++i )
    std::cout << arr4[ i ] << std::endl;

  std::cout << "arr5" << std::endl;
  for( int i = 0; i < arr5.size(); ++i )
    std::cout << arr5[ i ] << std::endl;

  amature::swap( arr4, arr5 );

  std::cout << "after swaping" << std::endl;
  std::cout << "arr4" << std::endl;
  for( int i = 0; i < arr4.size(); ++i )
    std::cout << arr4[ i ] << std::endl;

  std::cout << "arr5" << std::endl;
  for( int i = 0; i < arr5.size(); ++i )
    std::cout << arr5[ i ] << std::endl;

  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test get method" << std::endl;
  amature::array<int, 5> arr6;
  for( int i = 0; i < arr6.size(); ++i ) {
    arr6[ i ] = i * 8;
  }

  std::cout << "index " << 1 << " -> " << amature::get<1>( arr6 ) << std::endl;
  amature::get<1>( arr6 ) = 11;
  std::cout << "index " << 1 << " -> " << amature::get<1>( arr6 ) << std::endl;
  
  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test to_array method" << std::endl;
  const int size = 5;
  int arr7[size];
  for( int i = 0; i < size; ++i )
    arr7[ i ] = i + 1;

  auto arr8 = amature::to_array( arr7 );
  for( int i = 0; i < arr8.size(); ++i ) {
    std::cout << arr8[ i ];
    if( i < arr8.size() - 1 )
      std::cout << " ";
  }
  std::cout << std::endl;

  std::cout << "/////////////////////////////////" << std::endl;
  std::cout << "Test iterators" << std::endl;
  for( auto it = arr8.begin(); it != arr8.end(); ++it ) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
