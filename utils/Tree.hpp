#pragma once

#include <iostream>

namespace ft
{
	template <typename T>
	class Node
	{
	//private
	public:
		T		_data;
		Node	*_parent;
		Node	*_left;
		Node	*_right;
		bool	_isColorRed;
	public:
		explicit Node(const T& data = T(), Node	*parent = nullptr) :
			_data(data), _parent(parent), _left(nullptr), _right(nullptr)
		{
			_isColorRed = _parent ? true : false;
		};
		Node(const Node& other) : 
			_data(other._data), _left(other._left), _right(other._right), _parent(other._parent), _isColorRed(other._isColorRed) {};	
		Node& operator=(const Node& other)
    	{
        	if (this != &other)
        	{
           		_data = other._data;
            	_parent = other._parent;
            	_left = other._left;
            	_right = other._right;
				_isColorRed = other._isColorRed;
        	}
        	return *this;
    	}
		bool operator==(const Node& other)
    	{
        	return _data == other._data;
    	}
		~Node();
	};

	template <class T, class Alloc = std::allocator<Node<T> >
	>
	class Tree
	{
	//private
	public:
		Alloc		_allocator;
		Node<T>*	_nil;
		Node<T>*	_root;	
		size_t		_size;
	public:
		Tree() {
			_nil = new Node<T>(333);
			_root = _nil;
			// _root->_parent = _nil;
			// _root->_left = _nil;
			// _root->_right = _nil;
			_size = 0;
			_allocator = Alloc();
		};

		Tree & operator=(const Tree& other){
			if (this != &other)
        	{
           		_nil = other._nil;
				_root = other._root;
				_size = other._size;
				_allocator = other._allocator;
        	}
        	return *this;
		}

		~Tree() {};

		void		clearNode(Node<T>* node) {
			_allocator.destroy(node->_data);
			_allocator.deallocate(node->_data, 1);
			delete node;
		}

		void		leftRotate(Node<T>* node) {
			Node<T>* y = node->_right;

			node->_right = y->_left;
			if (y->_left != _nil)
				y->_left->_parent = node;
			if (y != _nil)
				y->_parent = node->_parent;

			if (node->_parent) {
				if (node == node->_parent->_left)
					node->_parent->_left = y;
				else
					node->_parent->_right = y;
			} 
			else {
				_root = y;
			}
			y->_left = node;
			if (node != _nil)
				node->_parent = y;
		}

		void		rotateRight(Node<T>* node) {
			Node<T>* y = node->_left;

			node->_left = y->_right;
			if (y->_right != _nil)
				y->_right->_parent = node;

			if (y != _nil)
				y->_parent = node->_parent;
			if (node->_parent) {
				if (node == node->_parent->_right)
					node->_parent->_right = y;
				else
					node->_parent->_left = y;
			} else {
				_root = y;
			}

			y->_right = node;
			if (node != _nil)
				node->_parent = y;
		}

		template <typename Comp>
		void	insert(Node<T>* node, Comp comp)
		{
			Node<T>* tmp = getEndNode(node->_data, comp);

			node->_parent = tmp;
			//std::cout << tmp->_data;
			if (tmp == _nil)
				_root = node;
			else if (!comp(node->_data, tmp->_data))
				tmp->_left = node;
			else
				tmp->_right = node;
			node->_left = _nil;
			node->_right = _nil;
			node->_isColorRed = (_root == node) ? false : true;

			//предусмотерть, что не можем добавлять одинаковые значения
			// insertFixup()

		}

		template <typename Comp>
		Node<T>* getEndNode(const T & data, Comp comp)
		{
			Node<T>* y = _nil;
			Node<T>* x = _root;
			//std::cout << y->_data;

			while (x != _nil)
			{
				y = x;
				if (!comp(data, x->_data))
					x = x->_left;
				else
					x = x->_right;
			}
			//std::cout << y->_data;
			return (y);
		}

		void	insertFixup()
		{

		}
	
	};
	
	


} // namespace ft
