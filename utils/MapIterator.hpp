#pragma once

#include "Iterator.hpp"
//#include "Node.hpp"

namespace ft{
	template <typename T, typename Node, class Compare>
	class MapIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		typedef	T					value_type;
		typedef T*					pointer;
		typedef T&					reference;
		typedef ptrdiff_t			difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;

	private:
		Node* _node;
		Node* _root;
		Compare _comp;

	public:
		// template <typename T>
		// friend class Node;
		MapIterator(Node* node = nullptr, Node* root = nullptr,
			const Compare& comp = Compare()) : _node(node), _root(root), _comp(comp) {};
		MapIterator(const MapIterator& other) : _node(other._node), _root(other._root), _comp(other._comp) {};
		~MapIterator() {};
		MapIterator& operator=(const MapIterator& other)
		{
			if (this != &other)
			{
				_node = other._node;
				_root = other._root;
				_comp = other._comp;
			}
			return (*this);
		}
		template <typename U>
		bool operator==(const MapIterator<U, Node, Compare>& other) const
		{
			return _node == other._node;
		}
		template <typename U>
		bool operator!=(const MapIterator<U, Node, Compare>& other) const
		{
			return _node != other._node;
		}
		reference operator*() const
		{
			return _node->_data;
		}
		pointer operator->() const
		{
			return &_node->_data;
		}
		MapIterator& operator++(void)
		{
			Node* current = _node;
			if (current->_right == _root)
			{
				current = _node->_parent;
				while (current != _root && _comp(current->_data.first, _node->_data.first))
				{
					current = current->_parent;
				}
			}
			else if (current == _root)
				current = current->_right;
			else
			{
				current = _node->_right;
				while (current->_left != _root)
				{
					current = current->_left;
				}
			}
			_node = current;
			return *this;
		}
		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			operator++();
			return (tmp);
		}
		MapIterator& operator--(void)
		{
			Node* current = _node;
			if (current->_left == _root)
			{
				current = _node->_parent;
				while (current != _root && !_comp(current->_data.first, _node->_data.first))
				{
					current = current->_parent;
				}
			}
			else if (current == _root)
			{
				current = current->_right;
			}
			else
			{
				current = _node->_left;
				while (current->_right != _root)
				{
					current = current->_right;
				}
			}
			_node = current;
			return *this;
		}
		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			operator--();
			return (tmp);
		}
		//переопределение для константного итератора
		operator MapIterator<const T, Node, Compare>(void) const
		{
			return MapIterator<const T, Node, Compare>(_node, _root, _comp);
		}
	};
}
