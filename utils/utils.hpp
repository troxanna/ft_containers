#pragma once

# include <memory>

namespace ft {

	template <class T1, class T2>
	struct pair {
		typedef T1		first_type;
		typedef T2		second_type;

		pair() : first(first_type()), second(second_type()) {};

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};

		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		pair& operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		};

		first_type		first;
		second_type 	second;
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) {
		return ft::pair<T1,T2>(x, y);
	}
	
	template<bool Cond, class T = void>
	struct enable_if {};
	
    template<class T>
	struct enable_if<true, T> { typedef T type; };


	template <bool is_integral, typename T>
	class is_integral_struct {
		public:
			typedef T type;
			static const bool value = is_integral;
	};

	template <typename>
	class is_integral : public is_integral_struct<false, bool> {};

	template <>
	class is_integral<bool> : public is_integral_struct<true, bool> {};

	// template <class T1, class T2>
	// class is_integral<ft::pair<T1, T2> > : public is_integral_struct<true, ft::pair<T1, T2> > {};

	template <>
	class is_integral<int> : public is_integral_struct<true, int> {};

	template <>
	class is_integral<char> : public is_integral_struct<true, char> {};

	template <>
	class is_integral<unsigned char> : public is_integral_struct<true, unsigned char> {};

	template <>
	class is_integral<signed char> : public is_integral_struct<true, signed char> {};

	template <>
	class is_integral<short int> : public is_integral_struct<true, short int> {};

	template <>
	class is_integral<long int> : public is_integral_struct<true, long int> {};

	template <>
	class is_integral<long long int> : public is_integral_struct<true, long long int> {};

	template <>
	class is_integral<unsigned int> : public is_integral_struct<true, unsigned int> {};

	template <>
	class is_integral<unsigned long int> : public is_integral_struct<true, unsigned long int> {};

	template <>
	class is_integral<unsigned long long int> : public is_integral_struct<true, unsigned long long int> {};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1) {
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp) {
		while (first1!=last1) {
			if (first2==last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	};



	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		  while (first1 != last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

}

