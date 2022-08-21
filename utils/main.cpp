#include "Tree.hpp"

bool comp(int a, int b) { return a > b; }

int	main()
{
	ft::Tree<int> tree;

	ft::Node<int> *node = new ft::Node<int>(2);
	ft::Node<int> *node2 = new ft::Node<int>(4);
	ft::Node<int> *node3 = new ft::Node<int>(1);
	ft::Node<int> *node4 = new ft::Node<int>(7);
	ft::Node<int> *node5 = new ft::Node<int>(3);

	//std::cout << node->_data;
	//std::cout << tree._nil->_data;
	tree.insert(node, comp);
	std::cout << tree._root->_data << std::endl;
	std::cout << tree._root->_isColorRed << std::endl;
	tree.insert(node2, comp);
	std::cout << tree._root->_right->_data << std::endl;
	std::cout << tree._root->_right->_isColorRed << std::endl;
	tree.insert(node3, comp);
	std::cout << tree._root->_left->_data << std::endl;
	std::cout << tree._root->_right->_isColorRed << std::endl;
	tree.insert(node4, comp);
	std::cout << tree._root->_right->_right->_data << std::endl;
	tree.insert(node5, comp);
	std::cout << tree._root->_right->_left->_data << std::endl;
		//std::cout << tree._root->_isColorRed;

}