#include "Iterator.hpp"

namespace ft{
	template <typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator() : _iterator(nullptr) {}
	
	template <typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator (iterator_type it) : _iterator(it) {}

	template <typename Iterator>
	template <class Iter>
	reverse_iterator<Iterator>::reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.iterator) {}
		
	template <typename Iterator>
	reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const{
		return _iterator
	}

	template <typename Iterator>
	reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const {
		Iterator tmp(_iterator);
		return (*--tmp);
	};

	template <typename Iterator>
	reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->() const {
		return &(this->operator*());
	}

	template <typename Iterator>
	typename reverse_iterator<Iterator>::reverse_iterator reverse_iterator<Iterator>::operator+(difference_type n) const {
		return reverse_iterator(this->_iterator - n);
	}



}