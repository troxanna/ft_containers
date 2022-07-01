#pragma once

#include <iostream>
# include <vector>
# include <memory>
# include "../utils/Iterator.hpp"

namespace ft
{
	// typedef vector<class T, class Allocator>		vector_class;

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

		typedef ft::VectorIterator<T>					iterator;
		typedef ft::VectorIterator<const T>				const_iterator;
		//typedef ft::reverse_iterator<iterator>			reverse_iterator;
		//typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		

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
		vector& operator=(const vector& other);
		~vector();

		//Capacity 
		void reserve (size_type n);
		void resize (size_type n, value_type val = value_type());
		size_type size() const;
		size_type capacity() const;
		bool empty() const;
		void clear();
		size_type max_size() const;

		// Element access
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		//Modifiers
		void push_back (const value_type& val);
		void pop_back();
		void assign (size_type n, const value_type& val);
		void swap (vector& x);

		//Iterators
		iterator	begin();
		iterator	end();
		const_iterator 				begin() const;
		const_iterator				end() const;
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		//enable_if
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);

		//other
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		allocator_type get_allocator() const;

	};

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#include "Vector.inl"
