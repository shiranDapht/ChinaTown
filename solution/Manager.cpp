#include "Manager.h"
#include "Employee.h"
#include "exceptions.h"
#include <string>

namespace mtm{

Manager::Manager(int id, std::string first_name, std::string last_name, int year):
    CitizenPlus(id, first_name, last_name, year), employees_t(std::set<const Employee*>()), is_hired_t(false) {}


bool Manager::getIsHired() const{
    return is_hired_t;
}

void Manager::setIsHired(const bool is_hired){
    is_hired_t = is_hired;
}

void Manager::addEmployee(const Employee* employee){
    if(employees_t.find(employee) == employees_t.end()){
        employees_t.insert(employee);
    }
    else{
        throw EmployeeAlreadyExists();
    }
}

void Manager::removeEmployee(const int employee_id){
    for(const Employee* employee : employees_t){
        if(employee->getId() == employee_id){
            employees_t.erase(employee);
            return;
        }
    }
    throw EmployeeIsNotHired();
}


ostream& Manager::printShort(ostream& os) const{
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") + std::string("Salary: ") 
        + std::to_string(getSalary()) << std::endl;
    return os;
}

ostream& Manager::printEmployees(ostream& os) const{
    for(const Employee* employee : employees_t){
        employee->printShort(os);
    }
    return os;
}

ostream& Manager::printLong(ostream& os) const{
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") +
        std::string("id - ") + std::to_string(getId()) + std::string("birth_year - ") + std::to_string(getBirthYear()) 
        + std::string("\n") + std::string("Salary: ") + std::to_string(getSalary()) + std::string("\n") +
        std::string("Employees:") + std::string("\n") << std::endl;
    printEmployees(os);
    return os;
}

Manager* Manager::clone() const{
    return new Manager(*this);
}

bool Manager::isEmployeeHere(int id) const{
    return getEmployeeById(id) != nullptr;
}

const Employee* Manager::getEmployeeById(const int id) const{
    for(const Employee* employee : employees_t){
        if(employee->getId() == id){
            return employee;
        }
    }
    return nullptr;
}

}