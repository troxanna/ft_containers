#include "Iterator.hpp"

namespace ft{
	template <class T>
	VectorIterator<T>::VectorIterator( void ) : _pointer(nullptr) {};

	template <class T>
	VectorIterator<T>::VectorIterator( T* ptr ) : _pointer(ptr) {};

	template <class T>
	VectorIterator<T>::~VectorIterator() {};

	//template <class T>
	// template <class U>
	// VectorIterator<T>::VectorIterator(const VectorIterator<U> & other) : _pointer(other._pointer) {};

	template <class T>
	VectorIterator<T> & VectorIterator<T>::operator=(const VectorIterator& other)  {
		if (this != &other)
			_pointer = other._pointer;
		return *this;
	}

	template <class T>
	typename VectorIterator<T>::reference	VectorIterator<T>::operator*() const {
		return *(_pointer);
	}

	template <class T>
	typename VectorIterator<T>::pointer	VectorIterator<T>::operator->() const {
		return _pointer;
	}

	template <class T>
	VectorIterator<T> &	VectorIterator<T>::operator++() {
		_pointer++;
		return *this;
	}

	template <class T>
	VectorIterator<T> &	VectorIterator<T>::operator--() {
		_pointer--;
		return *this;
	}

	template <class T>
	VectorIterator<T>	VectorIterator<T>::operator++(int) {
		VectorIterator tmp = VectorIterator(*this);
		_pointer++;
		return tmp;
	}

	template <class T>
	VectorIterator<T> 	VectorIterator<T>::operator--(int) {
		VectorIterator tmp = VectorIterator(*this);
		_pointer--;
		return tmp;
	}
	
	template <class T>
	bool	VectorIterator<T>::operator==(const VectorIterator& other) const {
		return _pointer == other._pointer;
	}

	template <class T>
	bool	VectorIterator<T>::operator!=(const VectorIterator& other) const {
		return !(*this == other);
	}

	template <class T>
	bool	VectorIterator<T>::operator<(const VectorIterator& other) const {
		return _pointer < other._pointer;
	}

	template <class T>
	bool	VectorIterator<T>::operator>(const VectorIterator& other) const {
		return other < *this;
	}

	template <class T>
	bool	VectorIterator<T>::operator>=(const VectorIterator& other) const {
		return !(*this < other);
	}

	template <class T>
	bool	VectorIterator<T>::operator<=(const VectorIterator& other) const {
		return !(other < *this);
	}

	template <class T>
	VectorIterator<T> &	VectorIterator<T>::operator-=(difference_type diff) {
		_pointer -= diff;
		return *this;
	}

	template <class T>
	VectorIterator<T> &	VectorIterator<T>::operator+=(difference_type diff) {
		_pointer += diff;
		return *this;
	}

	template <class T>
	VectorIterator<T>	VectorIterator<T>::operator-(difference_type diff) const {
		return VectorIterator(_pointer - diff);
	}

	template <class T>
	VectorIterator<T>	VectorIterator<T>::operator+(difference_type diff) const {
		return VectorIterator(_pointer + diff);
	}

	template <class T>
	typename VectorIterator<T>::reference	VectorIterator<T>::operator[] (difference_type diff) const {
		return (*(operator+(diff)));
	}


	template <class T>
	typename VectorIterator<T>::difference_type	VectorIterator<T>::operator-(const VectorIterator<T> & other){
		return operator->() - other.operator->();
	}

}
