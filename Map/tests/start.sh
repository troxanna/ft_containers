if [ -n "$1" ] ; then
c++ $1 
echo -e "\033[36m$1\033[0m"
echo -e "\033[92m"
./a.out
else
c++ constructors.cpp 
echo -e "\033[36mconstructors\033[0m"
echo -e "\033[92m"
./a.out

c++ at.cpp 
echo -e "\033[36mat\033[0m"
echo -e "\033[92m"
./a.out

c++ clear.cpp 
echo -e "\033[36mclear\033[0m"
echo -e "\033[92m"
./a.out

c++ count.cpp 
echo -e "\033[36mcount\033[0m"
echo -e "\033[92m"
./a.out

c++ empty.cpp 
echo -e "\033[36mempty\033[0m"
echo -e "\033[92m"
./a.out

c++ equal_range.cpp 
echo -e "\033[36mequal_range\033[0m"
echo -e "\033[92m"
./a.out

c++ erase.cpp 
echo -e "\033[36merase\033[0m"
echo -e "\033[92m"
./a.out

c++ find.cpp 
echo -e "\033[36mfind\033[0m"
echo -e "\033[92m"
./a.out

c++ insert.cpp 
echo -e "\033[36minsert\033[0m"
echo -e "\033[92m"
./a.out

c++ iterators.cpp 
echo -e "\033[36miterators\033[0m"
echo -e "\033[92m"
./a.out

c++ lower_bound.cpp 
echo -e "\033[36mlower_bound\033[0m"
echo -e "\033[92m"
./a.out

c++ max_size.cpp 
echo -e "\033[36mmax_size\033[0m"
echo -e "\033[92m"
./a.out

c++ op_assignment.cpp 
echo -e "\033[36mop_assignment\033[0m"
echo -e "\033[92m"
./a.out

c++ op_dereference.cpp 
echo -e "\033[36mop_dereference\033[0m"
echo -e "\033[92m"
./a.out

c++ size.cpp 
echo -e "\033[36msize\033[0m"
echo -e "\033[92m"
./a.out

c++ swap.cpp 
echo -e "\033[36mswap\033[0m"
echo -e "\033[92m"
./a.out

c++ upper_bound.cpp 
echo -e "\033[36mupper_bound\033[0m"
echo -e "\033[92m"
./a.out


fi

