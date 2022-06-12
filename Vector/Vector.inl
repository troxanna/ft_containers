#include "Vector.hpp"

template <class T, class Allocator>
ft::vector<class T, class Allocator>::vector (const allocator_type& alloc = allocator_type()) :
_arr(nullptr), _allocator(alloc), _size(0), _capacity(0)
{};

template <class T, class Allocator>
ft::vector<class T, class Allocator>::vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()) : _arr(nullptr), _allocator(alloc), _size(n), _capacity(n)
{
	if (n < 0)
		throw std::out_of_range("Invalid size");
	_arr = _allocator.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_arr[i] = _allocator.construct(_arr + i, val);
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::vector (const vector& other) : _arr(nullptr), _allocator(other._allocator), _size(other._size), _capacity(other._capacity)
{
	_arr = _allocator.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_arr[i] = _allocator.construct(_arr + i, other._arr[i]);
}

template <class T, class Allocator>
void ft::vector<class T, class Allocator>::reserve (size_type n)
{
	if (n < _capacity) return;
	T* newarr = _allocator.allocate(n);
	//Имеет смысл добавить эту обработку в перегрузку оператора присваивания
	try{
		std::uninitialized_copy(_arr, _arr + _size, newarr);
	} catch(...){
		_allocator.deallocate(newarr, n);
		throw;
	}
	// for (size_type i = 0; i < _size; i++)
	// 	newarr[i] = _allocator.construct(newarr + i, _arr[i]);
	for (size_type i = 0; i < _size; i++)
		_allocator.destroy(_arr + i);
	_allocator.deallocate(_arr, _capacity);
	_arr = newarr;
	_capacity = n;
}

template <class T, class Allocator>
void ft::vector<class T, class Allocator>::resize (size_type n, value_type val = value_type())
{
	if (n > _capacity) reserve(n);
	for (size_t i = _size; i < n; i++)
		_arr[i] = _allocator.construct(_arr + i, val);
	// А почему только если n < size?
	if (n < _size)
		_size = n;
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::size_type ft::vector<class T, class Allocator>::size() const
{
	return _size;
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::size_type ft::vector<class T, class Allocator>::capacity() const
{
	return _capacity;
}

template <class T, class Allocator>
bool ft::vector<class T, class Allocator>::empty() const
{
	return _size == 0 ? true : false
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::size_type ft::vector<class T, class Allocator>::max_size() const
{
	return _allocator.max_size();
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::reference ft::vector<class T, class Allocator>::operator[] (size_type n)
{
	return _arr[n];
}

template <class T, class Allocator>
ft::vector<class T, class Allocator>::const_reference ft::vector<class T, class Allocator>::operator[] (size_type n) const
{
	return _arr[n];
}