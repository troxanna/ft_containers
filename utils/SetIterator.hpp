// #pragma once

# include "TreeSet.hpp"
# include "Iterator.hpp"
//# include "Iterator.hpp"

namespace ft {
	template <class value_type, class Compare, class Alloc>
	class SetIterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {
		public:
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef Node<value_type>*				NodePointer;
			typedef ptrdiff_t						difference_type;
			typedef typename ft::iterator<
				ft::bidirectional_iterator_tag,
				value_type>::iterator_category		iterator_category;

		private:
			NodePointer				_ptr;
			Tree<value_type, Alloc>	_tree;
			NodePointer				_NIL;
			Compare					_comp;
		
		public:
			SetIterator() : _ptr(nullptr), _tree(), _comp() {}

			SetIterator(const NodePointer& ptr, const Tree<value_type, Alloc>& tree, const Compare& comp) : _ptr(ptr), _tree(tree), _comp(comp) {
				_NIL = _tree.getNil();
			}

			template <class _V, class _C, class _A>
			SetIterator(const SetIterator<_V, _C, _A>& other)
				: _ptr(other._ptr), _tree(other._tree), _NIL(other._NIL), _comp(other._comp) {}

			SetIterator &operator=(const SetIterator &other) {
				_ptr = other._ptr;
				_tree = other._tree;
				_NIL = other._NIL;
				_comp = other._comp;
				return (*this);
			};

			~SetIterator() {}

			bool operator==(const SetIterator &other) {
				return _ptr == other._ptr;
			};
			bool operator!=(const SetIterator &other) {
				return !operator==(other);
			};

			reference			operator*() const {
				return *(_ptr->data);
			}

			value_type*			operator->() const {
				return _ptr->data;
			}

			SetIterator&		operator++() {
				this->next();
				return *this;
			}
			SetIterator&		operator--() {
				this->prev();
				return *this;
			}
			SetIterator		operator++(int) {
				SetIterator	tmp = *this;
				operator++();
				return tmp;
			}
			SetIterator		operator--(int) {
				SetIterator	tmp = *this;
				operator--();
				return tmp;
			}

			NodePointer getNodePointer() const {
				return _ptr;
			}

			// bool		operator==(const SetIterator& other) const {
			// 	return _ptr == other._ptr;
			// }

			private:
				void	next() {
					if (_ptr->right != _NIL && _ptr->right) {
						_ptr = _tree.min(_ptr->right); //find the minimum relative to _ptr->left
					} else if (_ptr == _tree.getEnd()->parent) {
						_ptr = _tree.getEnd(); // if _ptr == max of Tree
					} else {
						if (_ptr->parent) {
							while (_comp(_ptr->parent->data, _ptr->data)) {
								_ptr = _ptr->parent;
							}
							_ptr = _ptr->parent;
						}
					}
				}

				void	prev() {
					if (_ptr == _tree.getEnd()) {
						_ptr = _ptr->parent; // if _ptr == end
					} else if (_ptr->left != _NIL) {
						_ptr = _tree.max(_ptr->left); // find the maximum relative to _ptr->left
					} else {
						if (_ptr->parent) {
							while (_comp(_ptr->data, _ptr->parent->data)) {
								_ptr = _ptr->parent;
							}
							_ptr = _ptr->parent;
						}
					}
				}
	};

	/*
	** Non-member overloads
	*/

	template <class value_type, class Compare, class Alloc>
	bool operator==(const SetIterator<value_type, Compare, Alloc> &lhs,
		const SetIterator<value_type, Compare, Alloc> &rhs) {
		return lhs.getNodePointer() == rhs.getNodePointer();
	};

	template <class value_type, class Compare, class Alloc>
	bool operator!=(const SetIterator<value_type, Compare, Alloc> &lhs,
		const SetIterator<value_type, Compare, Alloc> &rhs) {
		return !operator==(lhs, rhs);
	};


}

