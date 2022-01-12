#include "Manager.h"
#include "exceptions.h"
#include <set>
#include <string>
#include <iostream>

namespace mtm{

Manager::Manager(int id, std::string first_name, std::string last_name, int year):
    CitizenPlus(id, first_name, last_name, year), employees_t(std::set<Employee*>()), is_hired_t(false) {}


bool Manager::getIsHired() const{
    return is_hired_t;
}

void Manager::setIsHired(const bool is_hired){
    is_hired_t = is_hired;
}

void Manager::addEmployee(Employee* const employee){
    if(employees_t.find(employee) == employees_t.end()){
        employees_t.insert(employee);
    }
    else{
        throw CitizenAlreadyExists();
    }
}

void Manager::removeEmployee(const int employee_id){
    for(Employee* const employee : employees_t){
        if(employee->getId() == employee_id){
            employees_t.erase(employee);
            return;
        }
    }
    throw EmployeeIsNotHired();
}


std::ostream& Manager::printShort(std::ostream& os) const{
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") + std::string("Salary: ") 
        + std::to_string(getSalary()) << std::endl;
    return os;
}

std::ostream& Manager::printEmployees(std::ostream& os) const{
    if(!employees_t.empty()){
        os << std::string("Employees: ") << std::endl;
        for(const Employee* employee : employees_t){
            employee->printShort(os);
        }
    }
    return os;
}

std::ostream& Manager::printLong(std::ostream& os) const{
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") +
        std::string("id - ") + std::to_string(getId()) + std::string(" birth_year - ") + std::to_string(getBirthYear()) 
        + std::string("\n") + std::string("Salary: ") + std::to_string(getSalary()) << std::endl;
    printEmployees(os);
    return os;
}

Manager* Manager::clone() const{
    return new Manager(*this);
}

bool Manager::isEmployeeHere(const int id) const{
    return getEmployeeByIdOrNullptr(id) != nullptr;
}

Employee* Manager::getEmployeeByIdOrNullptr(const int id) const{
    for(Employee* const employee : employees_t){
        if(employee->getId() == id){
            return employee;
        }
    }
    return nullptr;
}


Employee* Manager::getEmployeeById(const int id) const{
    Employee* employee = getEmployeeByIdOrNullptr(id);
    if(employee == nullptr){
        throw EmployeeIsNotHired();
    }
    return employee;
}

void Manager::fireAllEmployees(const double salary){
    for(Employee* const employee : employees_t){
        employee->setSalary(-salary);
    }
    employees_t.clear();
}

}