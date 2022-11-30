#pragma once

# include "../Vector/vector.hpp"
# include "utils.hpp"

// namespace ft {

	typedef enum { BLACK, RED } nodeColor;

	template <class value_type>
	struct Node {
		value_type*	data;
		Node*		left;
		Node*		right;
		Node*		parent;
		bool		color;
	};

	template <class value_type, class Alloc>
	class Tree {
		public:
			typedef Node<value_type>*		NodePtr;

		private:
			NodePtr		_root;
			NodePtr		_NIL;
			NodePtr		_end;
			size_t		_size;
			Alloc		_allocator;

		public:
			Tree() {}

			template <class ValueAlloc>
			Tree(ValueAlloc) {
				_NIL = createNilNode();
				_end = createNilNode();
				_root = _end;

				_size = 0;
			}

			~Tree() {}

			Tree&	operator=(const Tree& other) {
				_allocator = other._allocator;
				_size = other._size;
				_end = other._end;
				_NIL = other._NIL;
				_root = other._root;
				return *this;
			}

		public:

			NodePtr		createNode(value_type& value, NodePtr parent) {
				NodePtr node = new Node<value_type>;

				node->left = _NIL;
				node->right = _NIL;
				node->parent = parent;

				node->data = _allocator.allocate(1);
				_allocator.construct(node->data, value);

				node->color = parent ? RED : BLACK;

				return node;
			};

			NodePtr		createNilNode() {
				NodePtr node = new Node<value_type>;

				node->left = nullptr;
				node->right = nullptr;
				node->parent = nullptr;

				node->data = _allocator.allocate(1);
				_allocator.construct(node->data, value_type());

				node->color = BLACK;

				return node;
			};

			void		clearTree() {
				if (_root == _end) {
					clearNode(_NIL);
					clearNode(_end);
					return;
				}
			
				ft::vector<NodePtr> queue;
			
				queue.push_back(_root);
				while (!queue.empty())
				{
					NodePtr node = queue.front();
					queue.erase(queue.begin());
			
					if (node->left != _NIL)
						queue.push_back(node->left);
					if (node->right != _NIL)
						queue.push_back(node->right);
			
					clearNode(node);
				}
				clearNode(_NIL);
				clearNode(_end);
			}

			void		clearNode(NodePtr node) {
				_allocator.destroy(node->data);
				_allocator.deallocate(node->data, 1);
				delete node;
			}

			void		rotateLeft(NodePtr node) {
				NodePtr y = node->right;

				node->right = y->left;
				if (y->left != _NIL)
					y->left->parent = node;

				if (y != _NIL)
					y->parent = node->parent;

				if (node->parent) {
					if (node == node->parent->left)
						node->parent->left = y;
					else
						node->parent->right = y;
				} else {
					_root = y;
				}

				y->left = node;
				if (node != _NIL)
					node->parent = y;
			}

			void		rotateRight(NodePtr node) {
				NodePtr y = node->left;

				node->left = y->right;
				if (y->right != _NIL)
					y->right->parent = node;

				if (y != _NIL)
					y->parent = node->parent;
				if (node->parent) {
					if (node == node->parent->right)
						node->parent->right = y;
					else
						node->parent->left = y;
				} else {
					_root = y;
				}

				y->right = node;
				if (node != _NIL)
					node->parent = y;
			}

			void		swapColors(NodePtr node, NodePtr uncle) {
				node->parent->color = BLACK;
				if (uncle)
					uncle->color = BLACK;
				node->parent->parent->color = RED;
			}

			template <class Comp>
			ft::pair<NodePtr, bool>		insert(value_type data, Comp comp) {
				NodePtr node = find(data, comp);
				bool	isInserted;

				if (node != _NIL && node != _end)
					isInserted = false;
				else {
					node = insertNewNode(data, comp);
					isInserted = true;
				}

				return (ft::make_pair(node, isInserted));
			}

			// template <class Comp>
			// ft::pair<NodePtr, bool>		insertKey(value_type data, Comp comp) {
			// 	NodePtr node = find(data, comp);
			// 	bool	isInserted;

			// 	if (node != _NIL && node != _end)
			// 		isInserted = false;
			// 	else {
			// 		node = insertNewNodeKey(data, comp);
			// 		isInserted = true;
			// 	}

			// 	return (ft::make_pair(node, isInserted));
			// }

			template <class Comp>
			void		deleteNode(value_type data, Comp& comp) {
				NodePtr tmp = find(data, comp);

				if (!tmp || tmp == _NIL || tmp == _end)
					return;

				NodePtr successor = getSuccessor(tmp);
				NodePtr	successorChild;

				if (successor->left != _NIL)
					successorChild = successor->left;
				else
					successorChild = successor->right;

				successorChild->parent = successor->parent;

				if (successor->parent)
					if (successor == successor->parent->left)
						successor->parent->left = successorChild;
					else
						successor->parent->right = successorChild;
				else
					_root = successorChild;

				if (successor != tmp)
					swapNodeData(tmp, successor);

				if (successor->color == BLACK)
					deleteFixup(successorChild);

				clearNode(successor);
				_size--;
				if (!_size) {
					_end->parent = nullptr;
					_root = _end;
				} else {
					_end->parent = max(_root);
				}
			}

			void		insertFixup(NodePtr node) {
				while (node != _root && node->parent->color == RED) {
					if (node->parent == node->parent->parent->left) {
						NodePtr uncle = node->parent->parent->right;

						if (uncle && uncle->color == RED) {
							swapColors(node, uncle);
							node = node->parent->parent;
						} else {
							if (node == node->parent->right) {
								node = node->parent;
								rotateLeft(node);
							}
							swapColors(node, nullptr);
							rotateRight(node->parent->parent);
						}
					} else {
						NodePtr uncle = node->parent->parent->left;

						if (uncle && uncle->color == RED) {
							swapColors(node, uncle);
							node = node->parent->parent;
						} else {
							if (node == node->parent->left) {
								node = node->parent;
								rotateRight(node);
							}
							swapColors(node, nullptr);
							rotateLeft(node->parent->parent);
						}
					}
				}
				_root->color = BLACK;
			};

			void		deleteFixup(NodePtr node) {
				while (node != _root && node->color == BLACK) {
					if (node == node->parent->left) {
						deleteFixupParentLeft(node);
					} else {
						deleteFixupParentRight(node);
					}
				}
				node->color = BLACK;
			}

			template <class Comp>
			NodePtr		find(value_type data, Comp comp) {
				NodePtr tmp = _root;

				if (tmp == _end)
					return _NIL;

				while (tmp != _NIL && getNodeKey(tmp) != data.first) {
					if (comp(data, getNodeData(tmp)))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (tmp == _NIL)
					return _end;
				return tmp;
			}

			template <class Comp>
			const NodePtr		find(value_type data, Comp comp) const {
				NodePtr tmp = _root;

				if (tmp == _end)
					return _NIL;

				while (tmp != _NIL && getNodeData(tmp).first != data.first) {
					if (comp(data, getNodeData(tmp)))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (tmp == _NIL)
					return _end;
				return tmp;
			}

			// template <class Comp>
			// NodePtr		findKey(value_type data, Comp comp) {
			// 	NodePtr tmp = _root;

			// 	if (tmp == _end)
			// 		return _NIL;

			// 	while (tmp != _NIL && getNodeData(tmp) != data) {
			// 		if (comp(data, getNodeData(tmp)))
			// 			tmp = tmp->left;
			// 		else
			// 			tmp = tmp->right;
			// 	}
			// 	if (tmp == _NIL)
			// 		return _end;
			// 	return tmp;
			// }

		

			NodePtr		min(NodePtr node) {
				NodePtr tmp = node;
				while (tmp->left != _NIL && tmp->left)
					tmp = tmp->left;
				return tmp;
			}

			const NodePtr		min(NodePtr node) const {
				NodePtr tmp = node;
				while (tmp->left != _NIL && tmp->left)
					tmp = tmp->left;
				return tmp;
			}

			NodePtr				max(NodePtr node) {
				NodePtr tmp = node;
				while (tmp->right != _NIL && tmp->right)
					tmp = tmp->right;
				return tmp;
			}

			NodePtr				getRoot() {
				return _root;
			}

			const NodePtr		getRoot() const {
				return _root;
			}

			NodePtr				getNil() {
				return _NIL;
			}

			NodePtr				getEnd() {
				return _end;
			}

			const NodePtr		getEnd() const {
				return _end;
			}

			size_t				getSize() const {
				return _size;
			}

			typename value_type::first_type&	getNodeKey(const NodePtr& node) {
				return node->data->first;
			}

			typename value_type::second_type&	getNodeValue(const NodePtr& node) {
				return node->data->second;
			}

			// typename value_type&	getNodeKeyValue(const NodePtr& node) {
			// 	return node->data;
			// }


			// typename value_type::second_type&	getNodeNilValue(const NodePtr& node) {
			// 	return node->data->second;
			// }

			class CopyTree {
				public:

					template <class A>
					static NodePtr	createNilNode(A alloc) {
						NodePtr node = new Node<value_type>;

						node->left = nullptr;
						node->right = nullptr;
						node->parent = nullptr;

						node->data = alloc.allocate(1);
						alloc.construct(node->data, value_type());

						node->color = BLACK;

						return node;
					}

					template <class A>
					static NodePtr	createNewNode(value_type& value, NodePtr parent, NodePtr& NIL, A alloc, int color) {
						NodePtr node = new Node<value_type>;

						node->left = NIL;
						node->right = NIL;
						node->parent = parent;

						node->data = alloc.allocate(1);
						alloc.construct(node->data, value);

						node->color = color;

						return node;
					}

					template <class A>
					static void 	copyLeft(NodePtr& newRoot, NodePtr& original, NodePtr NIL,A alloc) {
						newRoot->left = createNewNode(*original->left->data, newRoot, NIL, alloc, original->left->color);
						original = original->left;
						newRoot = newRoot->left;
					}

					template <class A>
					static void 	copyRight(NodePtr& newRoot, NodePtr& original, NodePtr NIL,A alloc) {
						newRoot->right = createNewNode(*original->right->data, newRoot, NIL, alloc, original->right->color);
						original = original->right;
						newRoot = newRoot->right;
					}

					template <class A>
					static void copy(Tree& originalTree, Tree& newTree, A alloc) {
						NodePtr NIL = originalTree.getNil();

						NodePtr	newRoot = newTree._root;
						NodePtr	original = originalTree._root;

						newRoot = createNewNode(*original->data, nullptr, newTree._NIL, alloc, original->color);
					
						while (true) {
							if (original->left != NIL && newRoot->left == newTree._NIL)
								copyLeft(newRoot, original, newTree._NIL, alloc);
							else if (original->right != NIL && newRoot->right == newTree._NIL)
								copyRight(newRoot, original, newTree._NIL, alloc);
							else {
								if (original->parent) {
									original = original->parent;
									newRoot = newRoot->parent;
								} else {
									break ;
								}
							}
						}
						newTree._root = newRoot;
						newTree._end->parent = newTree.max(newTree._root);
					}

					template <class A>
					static Tree								copyTree(Tree otherTree, A alloc) {
						if (otherTree._root == otherTree._end) {
							return nullptr;
						}
						Tree<value_type, Alloc> tree;
						tree._NIL = createNilNode(alloc);
						tree._end = createNilNode(alloc);
						tree._root = tree._end;
						tree._size = otherTree.getSize();
						
						copy(otherTree, tree, alloc);
						return tree;
					}

			};

			

		private:
			void								updateNodeDate(NodePtr& node, value_type data) {
				node->data->second = data.second;
			}

			value_type& 						getNodeData(const NodePtr& node) const {
				return *(node->data);
			}

			template <class Comp>
			NodePtr								getNewNodeParent(value_type data, Comp comp) {
				NodePtr current;
				NodePtr parent;

				current = _root;
				parent = nullptr;

				while (current != _NIL && current != _end) {
					if (getNodeKey(current) == data.first)
						return nullptr;
					parent = current;
					current = comp(data, getNodeData(current)) ?
						current->left : current->right;
				}
				
				return parent;
			}

			// template <class Comp>
			// NodePtr								getNewNodeParentKey(value_type data, Comp comp) {
			// 	NodePtr current;
			// 	NodePtr parent;

			// 	current = _root;
			// 	parent = nullptr;

			// 	while (current != _NIL && current != _end) {
			// 		if (getNodeData(current) == data)
			// 			return nullptr;
			// 		parent = current;
			// 		current = comp(data, getNodeData(current)) ?
			// 			current->left : current->right;
			// 	}
				
			// 	return parent;
			// }

			template <class Comp>
			NodePtr								insertNewNode(value_type data, Comp comp) {
				NodePtr parent = getNewNodeParent(data, comp);
				NodePtr newNode = createNode(data, parent);

				if (parent) {
					if (comp(data, getNodeData(parent)))
						parent->left = newNode;
					else
						parent->right = newNode;
				} else {
					_root = newNode;
				}
				_size++;

				insertFixup(newNode);

				if (newNode == max(_root))
					_end->parent = newNode;
				return newNode;
			}

			// template <class Comp>
			// NodePtr								insertNewNodeKey(value_type data, Comp comp) {
			// 	NodePtr parent = getNewNodeParentKey(data, comp);
			// 	NodePtr newNode = createNode(data, parent);

			// 	if (parent) {
			// 		if (comp(data, getNodeData(parent)))
			// 			parent->left = newNode;
			// 		else
			// 			parent->right = newNode;
			// 	} else {
			// 		_root = newNode;
			// 	}
			// 	_size++;

			// 	insertFixup(newNode);

			// 	if (newNode == max(_root))
			// 		_end->parent = newNode;
			// 	return newNode;
			// }

			NodePtr								getSuccessor(NodePtr node) {
				NodePtr successor;

				if (node->left == _NIL || node->right == _NIL) {
					successor = node;
				} else {
					successor = node->right;
					while (successor->left != _NIL)
						successor = successor->left;
				}

				return successor;
			}

			void								swapNodeData(NodePtr& node1, NodePtr& node2) {
				value_type* copy = node1->data;
				node1->data = node2->data;
				node2->data = copy;
			}

			void								deleteFixupParentLeft(NodePtr& node) {
				NodePtr sibling = node->parent->right;

				if (sibling->color == RED) {
					sibling->color = BLACK;
					node->parent->color = RED;
					rotateLeft(node->parent);
					sibling = node->parent->right;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
					sibling->color = RED;
					node = node->parent;
				} else {
					if (sibling->right->color == BLACK) {
						sibling->left->color = BLACK;
						sibling->color = RED;
						rotateRight(sibling);
						sibling = node->parent->right;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->right->color = BLACK;
					rotateLeft(node->parent);
					node = _root;
				}
			}

			void								deleteFixupParentRight(NodePtr& node) {
				NodePtr sibling = node->parent->left;

				if (sibling->color == RED) {
					sibling->color = BLACK;
					node->parent->color = RED;
					rotateRight(node->parent);
					sibling = node->parent->left;
				}
				if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
					sibling->color = RED;
					node = node->parent;
				} else {
					if (sibling->left->color == BLACK) {
						sibling->right->color = BLACK;
						sibling->color = RED;
						rotateLeft(sibling);
						sibling = node->parent->left;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->left->color = BLACK;
					rotateRight(node->parent);
					node = _root;
				}
			}
};



// }

