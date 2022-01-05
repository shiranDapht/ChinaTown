#include "Manager.h"
#include <string>

namespace mtm{

Manager::Manager(int id, std::string first_name, std::string last_name, int year, int salary):
    Citizen(id, first_name, last_name, year), salary_t(0), employees_t(std::set<Employee>()), is_hired_t(false) {}

int Manager::getSalary() const{
    return salary_t;
}

bool Manager::getIsHired() const{
    return is_hired_t;
}

void Manager::setIsHired(const bool is_hired){
    is_hired_t = is_hired;
}

void Manager::addEmployee(const Employee& employee) const{
    
}

void Manager::removeEmployee(const int employee_id);
void Manager::setSalary(const int add_salary);

stream& Manager::printShort(const ostream& os);
ostream& Manager::printLong(const ostream& os);

Manager* Manager::clone();

}