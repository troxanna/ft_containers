#pragma once

#include <iostream>
#include "MapIterator.hpp"
#include "utils.hpp"

namespace ft {
	template <typename T>
	struct Node
	{
	// private:
		T		_data;
		Node	*_left;
		Node	*_right;
		Node	*_parent;
	public:
		Node(const T& data, Node* left = nullptr, Node* right = nullptr,
            Node* parent = nullptr) : _data(data), _left(left), _right(right), _parent(parent) {};
		Node(Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) : 
							_data(), _left(left), _right(right), _parent(parent) {};
		Node(const Node& other) : _data(other._data), _left(other._left), _right(other._right), _parent(other._parent) {};
		Node& operator=(const Node& other)
    	{
        	if (this != &other)
        	{
           		_data = other._data;
            	_parent = other._parent;
            	_left = other._left;
            	_right = other._right;
        	}
        	return *this;
    	}
		bool operator==(const Node& other)
    	{
        	return _data == other._data;
    	}
		~Node() {};
	};

	template <
	typename T, 
	typename Compare, 
	typename Allocator = std::allocator<Node<T> >
	> 
	class Tree
	{
	public:
		typedef T 												value_type;
		typedef Compare 										key_compare;
		typedef Allocator 										allocator_type;
		typedef std::size_t 									size_type;
		typedef std::ptrdiff_t 									difference_type;
		typedef value_type& 									reference;
		typedef const value_type& 								const_reference;
		typedef Node<value_type> 								Node;
		typedef ft::MapIterator<T, Node, Compare> 				iterator;
		typedef ft::MapIterator<const T, Node, Compare> 		const_iterator;
		typedef reverse_iterator<const_iterator> 				const_reverse_iterator;
		typedef reverse_iterator<iterator> 						reverse_iterator;
	private:
		Node* 		_root;
    	size_t 		_size;
    	Compare 	_comp;
    	Allocator	_allocator;
		
	public:
		Tree(const Compare& comp = Compare(), const allocator_type& allocator = allocator_type()) :
												_root(nullptr), _size(0), _comp(comp), _allocator(allocator)
    	{
        	_root = _allocator.allocate(1);
        	_allocator.construct(_root, Node(_root, _root, _root));
    	}
		Tree(const Tree& other) : _root(nullptr), _size(0), _comp(other._comp), _allocator(other._allocator)
    	{
			_root = _allocator.allocate(1);
			_allocator.construct(_root, Node(_root, _root, _root));
			copyRoot(other._root->_parent, other._root);
    	}
		
		~Tree() {
			_allocator.destroy(_root);
        	_allocator.deallocate(_root, 1);	
		};

		pair<iterator, bool> insert(const_reference item)
		{
			Node* prevNode = _root;
			Node * startNode = _root->_parent;
			bool side = true;
			while (startNode != _root)
			{
				prevNode = startNode;
				if (_comp(item.first, startNode->_data.first))
				{
					side = false;
					startNode = startNode->_left;
				}
				else if (_comp(startNode->_data.first, item.first))
				{
					side = true;
					startNode = startNode->_right;
				}
				else
					return pair<iterator, bool>(iterator(startNode, _root, _comp), false);
			}
			Node* newNode = _allocator.allocate(1);
			_allocator.construct(newNode, Node(item, prevNode, _root, _root));
			if (prevNode == _root)
				_root->_parent = newNode;
			else if (side == true)
				prevNode->_right = newNode;
			else
				prevNode->_left = newNode;
			//update-left-right
			if (_root->_left == _root && _root->_right == _root)
			{
				_root->_left = newNode;
				_root->_right = newNode;
			}
			else
			{
				if (_comp(newNode->_data.first, _root->_left->_data.first))
					_root->_left = newNode;
				else if (_comp(_root->_right->_data.first, newNode->_data.first))
					_root->_right = newNode;
			}
			_size++;
			return pair<iterator, bool>(iterator(newNode, _root, _comp), true);
		};
		Node* searchByKey(const_reference item) const
		{
			Node* node = _root->_parent;
			while (node != _root)
			{
				if (_comp(item.first, node->_data.first))
					node = node->_left;
				else if (_comp(node->_data.first, item.first))
					node = node->_right;
				else
					break;
			}
			return node;
		};

		void removeByKey(const_reference item)
		{
			Node* node = searchByKey(item);
			if (node == _root)
				return ;
			if (node->_left != _root && node->_right != _root)
			{
				Node* tmp = getLeftNode(node->_right);
				replaceDoubleChildren(node, tmp);
			}
			else if (node->_left != _root)
				replaceNodeParent(node, node->_left);
			else if (node->_right != _root)
				replaceNodeParent(node, node->_right);
			else
				replaceNodeParent(node, _root);
		};
		size_type size(void) const
		{
			return _size;
		}
		Node* begin(void)
		{
			return _root->_left;
		}
		Node* begin(void) const
		{
			return _root->_left;
		}
		Node* end(void)
		{
			return _root;
		}
		Node* end(void) const
		{
			return _root;
		}

		void swap(Tree& other)
		{
			if (this != &other)
			{
				Node* tmpRoot = _root;
				size_t tmpSize = _size;
				Compare tmpComp = _comp;
				Allocator tmpAlloc = _allocator;
				
				_root = other._root;
				_size = other._size;
				_comp = other._comp;
				_allocator = other._allocator;
				
				other._root = tmpRoot;
				other._size = tmpSize;
				other._comp = tmpComp;
				other._allocator = tmpAlloc;
			}
		}

	private:
		void copyRoot(Node *node, Node *other)
    	{
			if (node != other)
			{
				this->insert(node->_data);
				this->copyRoot(node->_left, other);
				this->copyRoot(node->_right, other);
			}
    	}

		Node* getLeftNode(Node* root)
		{
			while (root != _root && root->_left != _root)
				root = root->_left;
			return (root);
		}

		Node* getRightNode(Node* root)
		{
			while (root != _root && root->_right != _root)
				root = root->_right;
			return (root);
		}

		void replaceNodeParent(Node* node, Node* newNode)
		{
			if (node->_parent != _root)
			{
				if (node == node->_parent->_left)
					node->_parent->_left = newNode;
				else
					node->_parent->_right = newNode;
			}

			if (newNode != _root)
				newNode->_parent = node->_parent;


			if (node == _root->_parent)
				_root->_parent = newNode;

			if (node == _root->_left)
				_root->_left = getLeftNode(_root->_parent);
			if (node == _root->_right)
				_root->_right = getRightNode(_root->_parent);

			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
			_size--;
		}

		void replaceDoubleChildren(Node*& node, Node* newNode)
		{
			if (newNode->_parent != _root)
			{
				if (newNode->_parent != node)
					newNode->_parent->_left = newNode->_right;
			}
			newNode->_parent = node->_parent;
			if (node->_left != newNode)
				newNode->_left = node->_left;
			if (node->_right != newNode)
				newNode->_right = node->_right;
			if (node->_parent != _root)
			{
				if (node->_parent->_left == node)
					node->_parent->_left = newNode;
				else if (node->_parent->_right == node)
					node->_parent->_right = newNode;
			}
			else
				_root->_parent = newNode;

			if (node->_left != _root && node->_left != newNode)
				node->_left->_parent = newNode;
			if (node->_right != _root && node->_right != newNode)
				node->_right->_parent = newNode;

			if (node->_parent != _root)
			{
				node->_left = _root;
				node->_right = _root;
				node->_parent = newNode;
			}

			if (node == _root->_left)
				_root->_left = getLeftNode(_root->_parent);
			if (node == _root->_right)
				_root->_right = getRightNode(_root->_parent);

			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
			_size--;
		}
	};
}

#include "Node.inl"