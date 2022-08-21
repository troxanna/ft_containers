#include "Stack.hpp"

namespace ft 
{
	//constructor

	template <class T, class Container>
	stack<T, Container>::stack(const container_type& ctnr) : _container(ctnr)
	{};

	//destructor

	template <class T, class Container>
	stack<T, Container>::~stack()
	{};

	//member-functions

	template <class T, class Container>
	size_t stack<T, Container>::size() const{
		return (this->_container.size());
	}

	template <class T, class Container>
	bool stack<T, Container>::empty() const{
		return (this->_container.empty());
	}

	template <class T, class Container>
	T& stack<T, Container>::top(){
		return (this->_container.back());
	}

	template <class T, class Container>
	const T& stack<T, Container>::top() const{
		return (this->_container.back());
	}

	template <class T, class Container>
	void stack<T, Container>::push(const T& val){
		this->_container.push_back(val);
	}

	template <class T, class Container>
	void stack<T, Container>::pop(){
		this->_container.pop_back();
	}

	//overload operator functions

	template <class T, class Container>
	bool operator== (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return l == r;
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return l._container != r._container;
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return l._container < r._container;
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return r > l;
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return l._container > r._container;
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& l, const stack<T,Container>& r)
	{
		return r < l;
	}
}
