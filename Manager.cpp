#include "Manager.h"
#include <string>

namespace mtm{

Manager::Manager(int id, std::string first_name, std::string last_name, int year, int salary):
    Citizen(id, first_name, last_name, year), salary_t(salary) {
        employees_t = std::set<Employee>();

    };

}