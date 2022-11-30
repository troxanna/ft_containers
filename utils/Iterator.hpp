#pragma once

# include <memory>
//#include "utils.hpp"

namespace ft
{

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	//vactor iterator
	template<class T>
	class VectorIterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
		typedef	T					value_type;
		typedef T*					pointer;
		typedef T&					reference;
		typedef ptrdiff_t			difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		//private:
		T* _pointer;

		public:
		VectorIterator( void );
		VectorIterator( T* ptr );
		~VectorIterator();
		//сделать через enable if
		// template <class U> VectorIterator(const VectorIterator<U>& other,
		// 	typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
		// 		: _pointer(other.base()) {};
		template <class U>
		VectorIterator(const VectorIterator<U>& other)  : _pointer(other._pointer) {};
		VectorIterator & operator=(const VectorIterator& other);

		reference			operator*() const;
		pointer				operator->() const;
		VectorIterator &	operator++();
		VectorIterator &	operator--();
		VectorIterator		operator++(int);
		VectorIterator		operator--(int);

		bool				operator==(const VectorIterator& other) const;
        bool				operator!=(const VectorIterator& other) const;
		bool 				operator>(const VectorIterator& other) const;
        bool 				operator>=(const VectorIterator& other) const;
        bool 				operator<(const VectorIterator& other) const;
        bool 				operator<=(const VectorIterator& other) const;
		VectorIterator&		operator-=(difference_type diff);
		VectorIterator&		operator+=(difference_type diff);
		VectorIterator 		operator-(difference_type diff) const;
		VectorIterator 		operator+(difference_type diff) const;
		reference			operator[](difference_type diff) const;
		difference_type		operator-(const VectorIterator<T> & other);
	};

	template <typename Iterator>
	class reverse_iterator {
		private:
			Iterator _iterator;

		public:
			typedef Iterator																iterator_type;
			typedef typename	ft::iterator_traits<Iterator>::iterator_category		iterator_category;
			typedef typename	ft::iterator_traits<Iterator>::value_type				value_type;
			typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iterator>::pointer					pointer;
			typedef typename	ft::iterator_traits<Iterator>::reference				reference;

			reverse_iterator();
			explicit reverse_iterator (iterator_type it);
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it);

			iterator_type base() const;

			reference			operator*() const;
			pointer				operator->() const;
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator &  operator++();
			reverse_iterator	operator++(int);
			reverse_iterator & 	operator+=(difference_type n);
			reverse_iterator 	operator-(difference_type n) const;
			reverse_iterator & 	operator--();
			reverse_iterator	operator--(int);
			reverse_iterator &	operator-=(difference_type n);
			reference	operator[](difference_type n) const;
			
	};

	// VectorIterator

	// Перенесла в методы
	// template <typename T>
	// ptrdiff_t operator-(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
	// 	return lhs.operator->() - rhs.operator->();
	// }

	template <typename T>
	VectorIterator<T> operator+(size_t n, const VectorIterator<T> &iter) {
		return iter + n;
	}

	// Reverse Iterator
	template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return (lhs.base() == rhs.base());
	}

	template <class Iterator>
 	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		 return !(lhs == rhs);
	 }

	template <class Iterator>
  	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
  	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
  	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
  	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return rev_it + n;
	};

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		return (lhs.base() - rhs.base());
	}
	

}

#include "Iterator.inl"
#include "ReverseIterator.inl"

