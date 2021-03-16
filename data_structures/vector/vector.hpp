#include <memory>

namespace amature {

template <class T, class Allocator = std::allocator<T>>
class vector {
  size_type m_size{ 10 };
public:
 using value_type = T;
 using allocator_type = Allocator;
 using size_type = std::size_t;
 using reference = T &;
 using const_reference = const T &;
 using iterator = T *;
 using const_iterator = const T *;

 /// \@brief Default constructor.
 vector() noexcept( noexcept( Allocator() ) ) = default;
 explicit vector( const Allocator &alloc ) noexcept;
 explicit vector( size_type size, const Allocator &alloc = Allocator() );
 vector( size_type size, const T &val, const Allocator &alloc = Allocator() );
 template<typename InputIterator>
 vector( InputIterator first, InputIterator last, const Allocator &alloc = Allocator() );
 vector( const vector &other );
 vector( const vector &other, const Allocator &alloc );
 vector( vector &&other ) noexcept;
 vector( vector &&other, const Allocator &alloc );
 vector( std::initializer_list<T> init, const Allocator &alloc = Allocator() );
 
 ~vector() = default;

 /// \@brief Copy assignment operator.
 vector<T> &operator=( const vector<T> &other );

 /// \@brief Move assignment operator.
 vector<T> &operator=( vector<T> &&other ) noexcept( 
    std::allocator_traits<Allocator>::propagate_on_container_move_assignment::value || 
    std::allocator_traits<Allocator>::is_always_equal::value );
 vector<T> &operator=( std::initializer_list<T> list );

 /// \@brief Replaces the contents with count copies of value value.
 /// Time complexity: Linear in count.
 void assign( size_type count, const T &value );
 
 /// \@brief Replaces the contents with copies of thoes in the range [begin, end).
 /// Time complexity: Linear in the distance between [begin, end).
 template<typename InputIter>
 void assign( InputIter begin, InputIter end );

 /// \@brief Replaces the contents with the elements from the initializer list.
 /// Time complexity: Linear in the size of the list.
 void assign( std::initializer_list<T> list );

 /// \@brief Returns the allocator assosiated with the container.
 /// Time complexity: constant
 allocator_type get_allocator() const noexcept;

 /// \@brief Returns a reference to the element at specified location index,
 /// with bounds checking.
 /// Time complexity: Constant
 /// Exception: std::out_of_range
 reference at( size_type index );
 const_reference at( size_type index ) const;

 /// \@brief Returns a reference to the element at specified location pos.
 /// No bounds checking is performed.
 /// Time complexity: Constant
 reference operator[ size_type index ];
 const_reference operator[ size_type index ] const;

 /// \@brief Returns reference to the 1st element in the container.
 /// Time complexity: constant
 reference front();
 const_reference front() const;

 /// \@brief Returns a reference to the last element in the container.
 /// Time complexity: constant.
 reference back();
 const_reference back() const;

 /// \@brief Returns a pointer to the underlying array serving as element storage.
 /// Time complexity: constant
 T *data() noexcept;
 const T *data() const noexcept;

 /// \@brief Returns an iterator to the 1st element of the vector.
 /// Time complexity: constant
 iterator begin() noexcept;
 const_iterator cbegin() const noexcept;

 /// \@brief Returns an iterator to the element following the last element
 /// of the vector.
 /// Time complexity: constant.
 iterator end() noexcept;
 const_iterator cend() const noexcept;

 // reverse_iterator rbegin() noexcept;
 // const_reverse_iterator crbegin() const noexcept;
 // reverse_iterator rend() noexcept;
 // const_reverse_iterator crend() const noexcept;

 /// \@brief Checks if the container has no elements.
 /// Time complexity: constant.
 bool empty() const noexcept;

 /// \@brief Returns the number of elements in the container.
 /// Time complexity: constant.
 size_type size() const noexcept;

 /// \@brief Returns the maximum number of elements the container is able to hold
 /// due to system limitations.
 /// Time complexity: constant
 size_type max_size() const noexcept;

 /// \@brief Increase the capacity of the vector to a value that is greater or equal
 /// to new_cap. If size is less than the current capacity the method does nothing.
 /// Time complexity: Linear in the size of the container.
 /// Exceptions: 
 ///   - std::length_error if new_cap > max_size
 ///   - any exceptions thrown by Allocator::allocate()
 /// If exception is throw this function has no effect.
 void reserve( size_type new_cap );
};

namespace pmr {

}  // pmr
}  // amature
