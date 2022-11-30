namespace ft
{
	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::set(void)
	: _allocator(allocator_type()), _keyComp(key_compare()), _valueComp(key_compare()), _tree(allocator_type()) {}	

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _keyComp(comp), _valueComp(comp), _tree(alloc) {}

	template <class Key, class Compare, class Alloc>
	template <class InputIterator>
	set<Key, Compare, Alloc>::set (InputIterator first, InputIterator last,
		const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _keyComp(comp), _valueComp(comp), _tree(alloc) {
		insert(first, last);
	}

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::set (const set& x) 
		: _allocator(x._allocator), _keyComp(x._keyComp), _valueComp(x._valueComp), _tree() {
		_tree = Tree<typename set<Key, Compare, Alloc>::value_type,
			typename set<Key,Compare, Alloc>::allocator_type>::CopyTree::copyTree(x._tree, _allocator);
	}

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>& set<Key, Compare, Alloc>::operator=(const set& x) {
		if (&x != this) {
			_allocator = x._allocator;
			_keyComp = x._keyComp;
			_valueComp = x._valueComp;
			_tree.clearTree();
			_tree = Tree<typename set<Key, Compare, Alloc>::value_type,
				typename set<Key, Compare, Alloc>::allocator_type>::CopyTree::copyTree(x._tree, _allocator);
		}
		return *this;
	}

	template <class Key, class Compare, class Alloc>
	set<Key, Compare, Alloc>::~set() {
		_tree.clearTree();
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator 					set<Key, Compare, Alloc>::begin() {
		return iterator(_tree.min(_tree.getRoot()), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_iterator 			set<Key, Compare, Alloc>::begin() const {
		return const_iterator(_tree.min(_tree.getRoot()), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator 					set<Key, Compare, Alloc>::end() {
		return iterator(_tree.getEnd(), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_iterator 			set<Key, Compare, Alloc>::end() const {
		return const_iterator(_tree.getEnd(), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::reverse_iterator			set<Key, Compare, Alloc>::rbegin() {
		return reverse_iterator(end());
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_reverse_iterator	set<Key, Compare, Alloc>::rbegin() const {
		return const_reverse_iterator(end());
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::reverse_iterator			set<Key, Compare, Alloc>::rend() {
		return reverse_iterator(begin());
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_reverse_iterator	set<Key, Compare, Alloc>::rend() const {
		return const_reverse_iterator(begin());
	}


	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::size_type					set<Key, Compare, Alloc>::size() const {
		return _tree.getSize();
	}

	template <class Key, class Compare, class Alloc>
	bool 															set<Key, Compare, Alloc>::empty() const {
		return size() == 0;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::size_type					set<Key, Compare, Alloc>::max_size() const {
		return _allocator.max_size();
	}

	template <class Key, class Compare, class Alloc>
	ft::pair<typename set<Key, Compare, Alloc>::iterator,bool> 	set<Key, Compare, Alloc>::insert(const value_type& val) 
	{
		ft::pair<typename Tree<value_type, Alloc>::NodePtr, bool> pair = _tree.insert(val, _valueComp);
		return (ft::make_pair(iterator(pair.first, _tree, _keyComp), pair.second));
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator	set<Key, Compare, Alloc>::insert(iterator , const value_type& val) {
		ft::pair<typename Tree<value_type, Alloc>::NodePtr, bool> pair = _tree.insert(val, _valueComp);

		return (iterator(pair.first, _tree, _keyComp));
	}

	template <class Key, class Compare, class Alloc>
	template <class InputIterator>
	void 					set<Key, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
		while (first != last)
			insert(*first++);
	}


	template <class Key, class Compare, class Alloc>
	void 					set<Key, Compare, Alloc>::erase(iterator position) {
		_tree.deleteNode(*position, _valueComp);
	}

	
	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::size_type 				set<Key, Compare, Alloc>::erase(const key_type& k) {
		_tree.deleteNode(k, _valueComp);
		return 1;
	}

	template <class Key, class Compare, class Alloc>
	void 					set<Key, Compare, Alloc>::erase(iterator first, iterator last) {
		if (!size())
			return ;
	
		while (first != last)
			erase(first++);
	}


	template <class Key, class Compare, class Alloc>
	void 					set<Key, Compare, Alloc>::swap(set& x) {
		if (x == *this)
			return ;
		
		allocator_type		allocatorTmp = x._allocator;
		key_compare			keyCompareTMP = x._keyComp;
		value_compare		valueCompareTMP = x._valueComp;
		Tree<value_type, Alloc>	treeTmp = x._tree;

		x._allocator = _allocator;
		x._keyComp = _keyComp;
		x._valueComp = _valueComp;
		x._tree = _tree;

		_allocator = allocatorTmp;
		_keyComp = keyCompareTMP;
		_valueComp = valueCompareTMP;
		_tree = treeTmp;
	}

	template <class Key, class Compare, class Alloc>
	void					set<Key, Compare, Alloc>::clear() {
		erase(begin(), end());
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::key_compare				set<Key, Compare, Alloc>::key_comp() const {
		return _keyComp;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::value_compare 			set<Key, Compare, Alloc>::value_comp() const {
		return _valueComp;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator 				set<Key, Compare, Alloc>::find(const key_type& k) {
		return iterator(_tree.find(k, _valueComp), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_iterator		set<Key, Compare, Alloc>::find(const key_type& k) const {
		return const_iterator(_tree.find(k, _valueComp), _tree, _keyComp);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::size_type 			set<Key, Compare, Alloc>::count(const key_type& k) const {
		return ((_tree.getSize() && _tree.find(k, _valueComp) != _tree.getEnd()) ? 1 : 0);
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator				set<Key, Compare, Alloc>::lower_bound(const key_type & k) {
		iterator	it	= this->begin();
		iterator	end	= this->end();

		while (it != end && _keyComp(*it, k))
			++it;
		return it;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_iterator			set<Key, Compare, Alloc>::lower_bound(const key_type & k) const {
		const_iterator	it	= this->begin();
		const_iterator	end	= this->end();

		while (it != end && _keyComp(*it, k))
			++it;
		return it;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::iterator				set<Key, Compare, Alloc>::upper_bound(const key_type & k) {
		iterator it = this->begin();
		iterator end = this->end();

		while (it != end) {
			if (_keyComp(k, *it))
				break;
			it++;
		}
		return it;
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::const_iterator			set<Key, Compare, Alloc>::upper_bound(const key_type & k) const {
		const_iterator it = this->begin();
		const_iterator end = this->end();

		while (it != end) {
			if (_keyComp(k, *it))
				break;
			it++;
		}
		return it;
	}

	template <class Key, class Compare, class Alloc>
	ft::pair< 
		typename set<Key, Compare, Alloc>::const_iterator, 
		typename set<Key, Compare, Alloc>::const_iterator > set<Key, Compare, Alloc>::equal_range(const key_type & k) const  {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}

	template <class Key, class Compare, class Alloc>
	ft::pair< 
		typename set<Key, Compare, Alloc>::iterator, 
		typename set<Key, Compare, Alloc>::iterator > set<Key, Compare, Alloc>::equal_range(const key_type & k) {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}

	template <class Key, class Compare, class Alloc>
	typename set<Key, Compare, Alloc>::allocator_type 		set<Key, Compare, Alloc>::get_allocator() const {
		return _allocator;
	}

	template <class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare,Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
		  	return false;

		typedef typename ft::set<Key, Compare, Alloc>::const_iterator const_iterator;

		const_iterator lBegin = lhs.begin();
		const_iterator lEnd = lhs.end();

		const_iterator rBegin = rhs.begin();

		return ft::equal(lBegin, lEnd, rBegin);
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !operator==(lhs, rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !operator<(rhs, lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !operator>(rhs, lhs);
	}
	
	template <class Key, class Compare, class Alloc>
  	void swap(set<Key, Compare, Alloc>& x, set<Key, Compare, Alloc>& y) {
		  x.swap(y);
	}

}
 // namespace ft
