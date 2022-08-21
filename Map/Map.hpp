#pragma once

#include <iostream>
# include <memory>
# include "../utils/Node.hpp"

namespace ft{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
			> 
	class map
	{
	public:
		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef ft::pair<const Key, T> 														value_type;
		typedef Compare																		key_compare;
		typedef	Alloc																		allocator_type;
		typedef std::size_t 																size_type;
		typedef std::ptrdiff_t 																difference_type;
		typedef value_type& 																reference;
		typedef const value_type& 															const_reference;
		typedef T*																			pointer;
		typedef const T*																	const_pointer;
		typedef typename Tree<value_type, key_compare>::iterator 							iterator;
		typedef typename Tree<value_type, key_compare>::const_iterator 						const_iterator;
		typedef typename Tree<value_type, key_compare>::const_reverse_iterator 				const_reverse_iterator;
		typedef typename Tree<value_type, key_compare>::reverse_iterator 					reverse_iterator;

		class value_compare;

	private:
		key_compare 						_keyComp;
    	allocator_type						_allocator;
    	Tree <value_type, key_compare>		_tree; 
		
	public:
		explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) : _keyComp(comp), _allocator(alloc), _tree(comp, alloc) {};
		template< class InputIterator >
		map( InputIterator first, InputIterator last,
			const Compare& comp = Compare(),
			const Alloc& alloc = Alloc() ) : _keyComp(comp), _allocator(alloc), _tree(comp, alloc)
		{
			insert(first, last);
		};

		map( const map& other ) : _keyComp(other._keyComp), _allocator(other._allocator), _tree(other._tree) {};
		~map()
		{
			clear();
		}

		map& operator=(const map& other)
		{
			if (this != &other)
			{
				_allocator = other._allocator;
				_keyComp = other._keyComp;
				clear();
				insert(other.begin(), other.end());
			}
			return *this;
		}
		allocator_type get_allocator() const { 
			return _allocator; 
		}
		T& operator[] (const key_type& k)
		{
			iterator tmp = find(k);
        	if (tmp == end())
            	return insert(value_type(k, mapped_type())).first->second;
        	return tmp->second;
		}
		iterator begin(){
			return iterator(_tree.begin(), _tree.end()); 
		};
		const_iterator begin() const {
			return const_iterator(_tree.begin(), _tree.end());
		};
		iterator end() { 
			if (_tree.size() == 0)
				return this->begin();
			return iterator(_tree.end(), _tree.end()); 
		}
		const_iterator end() const { 
			if (_tree.size() == 0)
				return this->begin();
			return const_iterator(_tree.end(), _tree.end()); 
		}
		reverse_iterator rbegin() { 
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const { 
			return const_reverse_iterator(end()); 
		}
		reverse_iterator rend() { 
			return reverse_iterator(begin()); 
		}
		const_reverse_iterator rend() const { 
			return const_reverse_iterator(begin()); 
		}
		bool empty() const { 
			return _tree.size() == 0; 
		}
		size_type size() const { 
			return _tree.size(); 
		}
		size_type max_size() const { 
			return _allocator.max_size(); 
		}
		void clear()
		{
			erase(begin(), end());
		}
		pair<iterator,bool> insert (const value_type& val)
		{
			return _tree.insert(val);
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return insert(val).first;
		}
		template< class InputIterator >
		void insert( InputIterator first, InputIterator last )
		{
			for (; first != last; ++first)
			{
				insert(*first);
			}
		}

		void erase( iterator position )
		{
			erase(position->first);
		}
		void erase( iterator first, iterator last )
		{
			for (; first != last; first++)
			{
				erase(first);
			}
		}
		size_type erase (const key_type& k)
		{
			if (find(k) == end())
				return (0);
			_tree.removeByKey(value_type(k, mapped_type()));
			return (1);
		}

		void swap( map& other )
		{
			_tree.swap(other._tree);

			Compare tmpKeyComp = _keyComp;
			allocator_type tmpAllocator = _allocator;
			
			_keyComp = other._keyComp;
			_allocator = other._allocator;

			other._keyComp = tmpKeyComp;
			other._allocator = tmpAllocator;
		}

		size_type count (const key_type& k) const
		{
			if (find(k) == end())
				return (0);
			return (1);
		}

		iterator find (const key_type& k)
		{
			return iterator(_tree.searchByKey(value_type(k, mapped_type())), _tree.end());
		}
		const_iterator find( const Key& key ) const
		{
			return const_iterator(_tree.searchByKey(value_type(key, mapped_type())), _tree.end());
		}
		pair<iterator,iterator> equal_range( const Key& key )
		{
			return make_pair(lower_bound(key), upper_bound(key));
		}
		pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			return make_pair(lower_bound(key), upper_bound(key));
		}
		iterator lower_bound( const Key& key )
		{
			iterator begin = iterator(_tree.begin(), _tree.end());
			iterator end = iterator(_tree.end(), _tree.end());
			for ( ; begin != end; ++begin)
			{
				if (!_keyComp(begin->first, key))
					break;
			}
			return begin;
		}
		const_iterator lower_bound( const Key& key ) const
		{
			const_iterator begin = const_iterator(_tree.begin(), _tree.end());
			const_iterator end = const_iterator(_tree.end(), _tree.end());
			for ( ; begin != end; ++begin)
			{
				if (!_keyComp(begin->first, key))
					break;
			}
			return begin;
		}
		iterator upper_bound( const Key& key )
		{
			iterator begin = iterator(_tree.begin(), _tree.end());
			iterator end = iterator(_tree.end(), _tree.end());
			for ( ; begin != end; ++begin)
			{
				if (_keyComp(key, begin->first))
					break;
			}
			return begin;
		}
		const_iterator upper_bound( const Key& key ) const
		{
			const_iterator begin = const_iterator(_tree.begin(), _tree.end());
			const_iterator end = const_iterator(_tree.end(), _tree.end());
			for ( ; begin != end; ++begin)
			{
				if (_keyComp(key, begin->first))
					break;
			}
			return begin;
		}
		key_compare key_comp() const
		{
			return _keyComp;
		}
		value_compare value_comp() const
		{
			return value_compare(_keyComp);
		}
	};

	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare {
		friend class map;

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}

		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			
			bool operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return rhs < lhs;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
			map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

}

#include "Map.inl"
