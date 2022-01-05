#include "Manager.h"
#include "Employee.h"
#include "exceptions.h"
#include <string>

namespace mtm{

Manager::Manager(int id, std::string first_name, std::string last_name, int year):
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

void Manager::addEmployee(const Employee* employee){
    if(employees_t.find(*employee) == employees_t.end()){
        employees_t.insert(*employee);
    }
    throw EmployeeAlreadyExists();
}

void Manager::removeEmployee(const int employee_id){
    for(const Employee& employee : employees_t){
        if(employee.getId() == employee_id){
            employees_t.erase(employee);
        }
    }
    throw EmployeeIsNotHired();
}

void Manager::setSalary(const int add_salary){
    salary_t = getSalary() + add_salary;
}

ostream& Manager::printShort(ostream& os) const{
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") + std::string("Salary: ") 
        + std::to_string(getSalary()) << std::endl;
    return os;
}

ostream& Manager::printEmployees(ostream& os) const{
    for(const Employee& employee : employees_t){
        employee.printShort(os);
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

Manager* Manager::clone(){
    return new Manager(*this);
}

}