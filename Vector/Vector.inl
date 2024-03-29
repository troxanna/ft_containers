#include "vector.hpp"

namespace ft {
	template <class T, class Allocator>
	vector<T,  Allocator>::vector (const allocator_type& alloc) :
					_arr(nullptr), _allocator(alloc), _capacity(0), _size(0)
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
	vector<T,  Allocator>::vector (const vector& other) : _arr(nullptr), _allocator(other._allocator), _capacity(other._capacity), _size(other._size)
	{
		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(_arr + i, other._arr[i]);
	}

	template <class T, class Allocator>
	vector<T,  Allocator>::~vector(){
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_arr + i);
		_allocator.deallocate(_arr, _capacity);
		_arr = nullptr;
		_capacity = 0;
		_size = 0;
	}

	template <class T, class Allocator>
	template <class InputIterator>
    vector<T, Allocator>::vector(InputIterator first, InputIterator last, const  allocator_type& alloc,
		   typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type*)
		: _arr(nullptr), _size(0), _capacity(0), _allocator(alloc) {
		size_type size = last - first;
		_capacity = size;
		_arr = _allocator.allocate(_capacity);

		insert(_arr, first, last);
	}

	template <class T, class Allocator>
	vector<T,  Allocator>& vector<T,  Allocator>::operator=(const vector& other)
	{
		if (this == &other)
			return *this;
		T* newarr = _allocator.allocate(other._capacity);
		try{
			std::uninitialized_copy(other._arr, other._arr + other._size, newarr);
		} catch(...){
			_allocator.deallocate(newarr, other._capacity);
			throw;
		}
		// for (size_type i = 0; i < _size; i++)
		// 	newarr[i] = _allocator.construct(newarr + i, _arr[i]);
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_arr + i);
		_allocator.deallocate(_arr, _capacity);
		_arr = newarr;
		_capacity = other._capacity;
		_size = other._size;
		_allocator = other._allocator;
		return *this;
	}

	template <class T, class Allocator>
	void vector<T,  Allocator>::reserve (size_type n)
	{
		if (n < _capacity) 
			return ;
		T* newarr = _allocator.allocate(n);
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

		if (n < _size)
			erase(_arr + n, this->end());
		else
			insert(this->end(), n - _size, val);
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
			_size > 0 ? reserve(_size * 2) : reserve(1);
		_allocator.construct((this->_arr + this->_size), val);
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
			_allocator.construct(_arr + i, val);
		_size = n;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void vector<T, Allocator>::assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
		size_type newSize = 0;
		InputIterator position = first;
		while (position != last) {
			newSize++;
			position++;
		}

		this->~vector();
		_size = newSize;

		if (newSize > _capacity)
			_capacity = newSize;

		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < newSize; i++) {
			_allocator.construct(_arr + i, *first);
			first++;
		}

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

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const {
		return const_iterator(_arr);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end() {
		return iterator(_arr + _size);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const {
		return const_iterator(_arr + _size);
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin() {
		return reverse_iterator(this->end());
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator	vector<T, Allocator>::rbegin() const {
		return const_reverse_iterator(this->end());
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend() {
		return reverse_iterator(this->begin());
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator	vector<T, Allocator>::rend() const {
		return const_reverse_iterator(this->begin());
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase (iterator position){
		iterator tmp = position;

		//iterator(this->_arr + this->_size)
		if (1 + position == this->end())
			this->_allocator.destroy(&(*position));
		else{
			this->_allocator.destroy(&(*position));
			for (long i = 0; i < --iterator(this->end()) - position; i++)
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
	typename vector<T, Allocator>::iterator vector<T, Allocator>::insert (iterator position, const value_type& val){	

		if (this->_size + 1 > this->_capacity)
		{
			difference_type offset = iterator(this->_arr + this->_size) - position;
			!this->_capacity ? this->reserve(1) : this->reserve(this->_capacity * 2);
			position = this->_arr + this->_size - offset;
		}
		//std::cout << this->_capacity << std::endl;
		for (iterator it = this->end(); it != position; it--)
		{
			this->_allocator.construct(((&(*(it)))), *(it - 1));
			this->_allocator.destroy((&(*(it - 1))));
		}
		this->_allocator.construct(((&(*position))), val);
		this->_size++;
		return (position);
	}

	template <class T, class Allocator>
	void  vector<T, Allocator>::insert (iterator position, size_type n, const value_type& val)
	{
		while (n--)
			position = this->insert(position, val);
	}

	template <class T, class Allocator>
	template <class InputIterator>
    void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
		while (first != last) {
			position = insert(position, *first) + 1;
			first++;
		}
	}


	template <class T, class Allocator>
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const{
		return this->_allocator;
	}

	//non-members overload

	template <class T, class Alloc>
  	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
  	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc> &rhs) {
		size_t count = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
		for (size_t i = 0; i < count; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return lhs[i] < rhs[i] ? true : false;
				//std::cout << "check";
			}
		}
		return (lhs.size() >= rhs.size()) ? false : true;
	};

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc> &rhs) {
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc> &rhs) {
		return !(rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc> &rhs) {
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
}

