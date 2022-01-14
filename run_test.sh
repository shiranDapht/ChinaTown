#!/bin/bash
echo -e "\033[0;33mCompiling and diff for city_test\033[37m"
g++ -std=c++11 -g -Wall -Werror -pedantic-errors -DNDEBUG -o prog -Isolution -Iprovided solution/provided/city_test.cpp solution/*.cpp && ./prog > out.txt && diff ./out.txt solution/provided/city_test_output.txt
echo "\033[0;33mRunning valgrind for city_test\033[37m"
valgrind --leak-check=full ./prog

echo -e "\033[0;33mCompiling and diff for manager_print_test\033[37m"
g++ -std=c++11 -g -Wall -Werror -pedantic-errors -DNDEBUG -o prog -Isolution -Iprovided solution/provided/manager_print_test.cpp solution/*.cpp && ./prog > out.txt && diff ./out.txt solution/provided/manager_print_output.txt
echo -e "\033[0;33mRunning valgrind for manager_print_test\033[37m"
valgrind --leak-check=full ./prog

echo -e "\033[0;33mCompiling and diff for employee_print_test\033[37m"
g++ -std=c++11 -g -Wall -Werror -pedantic-errors -DNDEBUG -o prog -Isolution -Iprovided solution/provided/employee_print_test.cpp solution/*.cpp && ./prog > out.txt && diff ./out.txt solution/provided/employee_print_output.txt
echo -e "\033[0;33mRunning valgrind for employee_print_test"
valgrind --leak-check=full ./prog

echo -e "\033[0;33mCompiling and diff for workplace_print_test\033[37m"
g++ -std=c++11 -g -Wall -Werror -pedantic-errors -DNDEBUG -o prog -Isolution -Iprovided solution/provided/workplace_print_test.cpp solution/*.cpp && ./prog > out.txt && diff ./out.txt solution/provided/workplace_print_output.txt
echo -e "\033[0;33mRunning valgrind for workplace_print_test\033[37m"
valgrind --leak-check=full ./prog
