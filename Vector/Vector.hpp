#pragma once

#include <iostream>
# include <vector>
# include <memory>

//разобарться с typedef

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public:
		typedef Alloc									allocator_type;
		typedef T										value_type;
		typedef std::size_t 							size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef T*										pointer;
		typedef const T*								const_pointer;

		private:
		value_type* _arr;
		allocator_type _allocator;
		size_t _capacity;
		size_t _size;

		public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
	};
}

#include "Vector.inl"
