#pragma once

#include <iostream>
#include "../Vector/vector.hpp"
# include <memory>


namespace ft
{
	template <class T, class Container = ft::vector<T> > class stack
	{
		public:		
		typedef T	value_type;
		typedef Container	container_type;
		typedef size_t	size_type;

		private:
		container_type _container;

		//typedef stack stack<T, Container>;

		public:	
		explicit stack(const container_type& ctnr = container_type());
		~stack();
		size_t size() const;
		bool empty() const;
		T& top();
		const T& top() const;
		void push (const T& val);
		void pop();

	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& l, const stack<T,Container>& r);

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& l, const stack<T,Container>& r);

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& l, const stack<T,Container>& r);

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& l, const stack<T,Container>& r);

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& l, const stack<T,Container>& r);

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& l, const stack<T,Container>& r);

}

#include "Stack.inl"
