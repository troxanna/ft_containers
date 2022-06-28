#include "Vector.hpp"

namespace ft {
	template <class T, class Allocator>
	vector<T,  Allocator>::vector (const allocator_type& alloc) :
					_arr(nullptr), _allocator(alloc), _size(0), _capacity(0)
	{};

	template <class T, class Allocator>
	vector<T,  Allocator>::vector (size_type n, const value_type& val,
				const allocator_type& alloc) : _arr(nullptr), _allocator(alloc), _size(n), _capacity(n)
	{
		if (n < 0)
			throw std::out_of_range("Invalid size");
		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(_arr + i, val);
	}

	template <class T, class Allocator>
	vector<T,  Allocator>::vector (const vector& other) : _arr(nullptr), _allocator(other._allocator), _size(other._size), _capacity(other._capacity)
	{
		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(_arr + i, other._arr[i]);
	}

	template <class T, class Allocator>
	vector<T,  Allocator>& vector<T,  Allocator>::operator=(const vector& other)
	{
		// добавить обработку кейса если не удалось скопировать 
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::reserve (size_type n)
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
	void vector<T,  Allocator>::resize (size_type n, value_type val)
	{
		if (n > _capacity) reserve(n);
		for (size_t i = _size; i < n; i++)
			 _allocator.construct(_arr + i, val);
		// А почему только если n < size?
		if (n < _size)
			_size = n;
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::size_type vector<T,  Allocator>::size() const
	{
		return _size;
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::size_type vector<T,  Allocator>::capacity() const
	{
		return _capacity;
	}

	template <class T, class Allocator>
	bool vector<T,  Allocator>::empty() const
	{
		return _size == 0 ? true : false;
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::size_type vector<T,  Allocator>::max_size() const
	{
		return _allocator.max_size();
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::reference vector<T,  Allocator>::operator[] (size_type n)
	{
		return _arr[n];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::const_reference vector<T,  Allocator>::operator[] (size_type n) const
	{
		return _arr[n];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::reference vector<T,  Allocator>::at (size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("Invalid size");
		return _arr[n];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::const_reference vector<T,  Allocator>::at (size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("Invalid size");
		return _arr[n];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::reference vector<T,  Allocator>::front(){
		return this->_arr[0];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::const_reference vector<T,  Allocator>::front() const{
		return this->_arr[0];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::reference vector<T,  Allocator>::back(){
		return this->_arr[this->_size - 1];
	}

	template <class T, class Allocator>
	typename vector<T,  Allocator>::const_reference vector<T,  Allocator>::back() const{
		return this->_arr[this->_size - 1];
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::push_back (const value_type& val)
	{
		if (_size + 1 > _capacity)
			reserve(_size * 2);
		//std::cout << val << std::endl;
		_allocator.construct((this->_arr + this->_size), val);
		//std::cout << this->_arr[val] << std::endl;
		_size++;
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::pop_back()
	{
		_size--;
		_allocator.destroy(_arr + _size);
	}


	template <class T, class Allocator>
	void vector<T,  Allocator>::assign (size_type n, const value_type& val)
	{
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_arr + i);
		if (_capacity <= n)
		{
			_allocator.deallocate(_arr, _capacity);
			_arr = _allocator.allocate(n);
			//
			_capacity = n;
		}
		for (size_type i = 0; i < n; i++)
			_arr[i] = _allocator.construct(_arr + i, val);
		_size = n;
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::swap (vector& x)
	{
		if (x == *this)
			return ;
		pointer			arrTmp = x._arr;
		size_type 		sizeTmp = x._size;
		size_type 		capacityTmp = x._capacity;
		allocator_type	allocatorTmp = x._allocator;

		x._arr = this->_arr;
		x._size = this->_size;
		x._capacity = this->_capacity;
		x._allocator = this->_allocator;

		_arr = arrTmp;
		_size = sizeTmp;
		_capacity = capacityTmp;
		_allocator = allocatorTmp;
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::clear ()
	{
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_arr + i);
		_size = 0;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin() {
		return iterator(_arr);
	}

	// template <class T, class Allocator>
	// typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const {
	// 	return const_iterator(_arr);
	// }

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end() {
		return iterator(_arr + _size);
	}

	// template <class T, class Allocator>
	// typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const {
	// 	return const_iterator(_arr + _size);
	// }

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase (iterator position){
		iterator tmp = position;

		//iterator(this->_arr + this->_size)
		if (1 + position == this->end())
			this->_allocator.destroy(&(*position));
		else{
			this->_allocator.destroy(&(*position));
			for (size_t i = 0; i < --iterator(this->end()) - position; i++)
			{
				//iterator(this->_arr + (this->_size - 1))
				//std::cout << this->_arr[i];
				this->_allocator.construct(((&(*position)) + i), *(position + (i + 1)));
				this->_allocator.destroy(((i + 1) + &(*position)));
			}
		}
		this->_size--;
		return (tmp);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase (iterator first, iterator last){
		if (last == this->end()) {
			while (first != last)
				erase(--last);
			return last;
		}
		iterator tmp = first;
		while (first != last)
		{
			tmp = erase(tmp);
			++first;
		}
		return tmp;
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::insert (iterator position, size_type n, const value_type& val){
		//вызвать в цикле уже реализованный insert
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::insert (iterator position, const value_type& val){
		iterator tmp = position;

		//выделить память, если _capacity == 0 || _capacity < _size + 1
		for (iterator it = this->end(); it > this->begin(); it--)
		{
			this->_allocator.construct(((&(*it)) + 1), *(it));
			this->_allocator.destroy((&(*it)));
		}
		this->_allocator.construct(((&(*tmp))), val);
		return (tmp);
	}
}

