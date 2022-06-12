#pragma once

#include <iostream>
# include <vector>
# include <memory>

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
		size_type _capacity;
		size_type _size;

		public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		//Capacity 
		void reserve (size_type n);
		void resize (size_type n, value_type val = value_type());
		size_type size() const;
		size_type capacity() const;
		bool empty() const;
		size_type max_size() const;

		// Element access
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
	};
}

#include "Vector.inl"
