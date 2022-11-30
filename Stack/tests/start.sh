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

c++ empty.cpp 
echo -e "\033[36mempty\033[0m"
echo -e "\033[92m"
./a.out


c++ push_pop.cpp 
echo -e "\033[36mpush_pop\033[0m"
echo -e "\033[92m"
./a.out

c++ top.cpp 
echo -e "\033[36mempty\033[0m"
echo -e "\033[92m"
./a.out

c++ size.cpp 
echo -e "\033[36msize\033[0m"
echo -e "\033[92m"
./a.out



fi