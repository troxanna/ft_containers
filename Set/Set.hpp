#pragma once

# include <memory>
// # include "utils.hpp"
# include "../utils/TreeSet.hpp"
# include "../utils/SetIterator.hpp"
// # include "../utils/Iterator.hpp"
// # include "../utils/ReverseIterator.hpp"
# include "../utils/utils.hpp"

namespace ft {

	template <class Key, class Compare = std::less<Key>, class Alloc = std::allocator< Key > >
	class set {
		public:
			typedef Key														key_type;
			// typedef T														mapped_type;
			// typedef	ft::pair<const key_type, mapped_type>					value_type;
			typedef	Key														value_type;
			typedef Compare													key_compare;
			typedef Compare													value_compare;
			typedef	Alloc													allocator_type;

			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;

			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;

			typedef SetIterator<value_type, key_compare,
				allocator_type>												iterator;
			typedef SetIterator<value_type, key_compare, 
				allocator_type>												const_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef	size_t													size_type;

			// class value_compare;

			/*
			** Constructor
			*/
			set();
			explicit set(const key_compare& comp,
						const allocator_type& alloc = allocator_type());	// empty

			template <class InputIterator>
			set(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());			// range

			set(const set& x);												// copy

			set& operator=(const set& x);

			/*
			** Destructor
			*/

			~set();

			/*
			** Iterators
			*/

			iterator				begin();
			const_iterator			begin() const;
			iterator 				end();
			const_iterator 			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			/*
			** Capacity
			*/

			bool 					empty() const;
			size_type				size() const;
			size_type				max_size() const;
		
			/*
			** Modifiers
			*/

			ft::pair<iterator,bool> insert(const value_type& val);						// single element
			iterator 				insert(iterator position, const value_type& val);	// with hint
			template <class InputIterator>
			void 					insert(InputIterator first, InputIterator last);	// range
			void 					erase(iterator position);
			size_type 				erase(const key_type& k);
			void 					erase(iterator first, iterator last);
			void 					swap(set& x);
			void					clear();

			/*
			** Observers
			*/

			key_compare				key_comp() const;
			value_compare 			value_comp() const;

			/*
			** Operations
			*/

			iterator 					find(const key_type& k);
			const_iterator				find(const key_type& k) const;
			size_type 					count(const key_type& k) const;
			iterator					lower_bound(const key_type& k);
			const_iterator				lower_bound(const key_type& k) const;
			iterator 					upper_bound(const key_type& k);
			const_iterator				upper_bound(const key_type& k) const;
			ft::pair<const_iterator,
				const_iterator>			equal_range(const key_type& k) const;
			ft::pair<iterator,iterator> equal_range(const key_type& k);

			/*
			** Allocator
			*/

			allocator_type 			get_allocator() const;

		private:
			allocator_type						_allocator;
			key_compare							_keyComp;
			value_compare						_valueComp;
			Tree<value_type, 
				allocator_type>					_tree;
	};

	// template <class Key, class Compare, class Alloc>
	// class map<Key,T,Compare,Alloc>::value_compare {
	// 	friend class map;

	// 	protected:
	// 		Compare comp;
	// 		value_compare(Compare c) : comp(c) {}

	// 	public:
	// 		typedef bool		result_type;
	// 		typedef value_type	first_argument_type;
	// 		typedef value_type	second_argument_type;
			
	// 		bool operator()(const value_type& x, const value_type& y) const {
	// 			return comp(x.first, y.first);
	// 		}
	// };

	/*
	** Non-member overloads
	*/

	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
	bool operator< (const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
	bool operator> (const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key,Compare,Alloc>& lhs,
						const set<Key,Compare,Alloc>& rhs);

	template <class Key, class Compare, class Alloc>
  	void swap(set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y);
}

# include "Set.inl"
