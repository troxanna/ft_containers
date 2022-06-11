#include "Vector.hpp"

template <class T, class Allocator>
ft::vector<class T, class Allocator>::vector (const allocator_type& alloc = allocator_type()) :
_arr(nullptr), _allocator(alloc), _size(0), _capacity(0)
{};

template <class T, class Allocator>
ft::vector<class T, class Allocator>::vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()) : 
{
	
}
