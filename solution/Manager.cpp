#include "Manager.h"
#include "exceptions.h"

#include <set>
#include <string>
#include <iostream>
#include <memory>

using std::set;
using std::ostream;
using std::string;
using std::to_string;
using std::endl;
using std::shared_ptr;
using std::make_shared;
namespace mtm{

    Manager::Manager(int id, string first_name, string last_name, int year):
        Citizen(id, first_name, last_name, year) ,employees_t(set<Employee*, Comparator>()){}

    void Manager::addEmployee(Employee* const employee){
        if(getEmployeeByIdOrNullptr(employee->getId()) == nullptr){
            employees_t.insert(employee);
        }
        else{
            throw EmployeeAlreadyHired();
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


    ostream& Manager::printShort(ostream& os) const{
        os << getFirstName() + string(" ") + getLastName() + string("\nSalary: ") + to_string(getSalary()) << endl;
        return os;
    }

    ostream& Manager::printEmployees(ostream& os) const{
        if(!employees_t.empty()){
            os << string("Employees: ") << endl;
            for(Employee* employee : employees_t){
                employee->printShort(os);
            }
        }
        return os;
    }

    ostream& Manager::printLong(ostream& os) const{
        os << getFirstName() + string(" ") + getLastName() + string("\nid - ") + to_string(getId()) 
        + string(" birth_year - ") + to_string(getBirthYear()) + string("\nSalary: ") 
        + to_string(getSalary()) << endl;
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
    
    void Manager::setEmployeesSalary(const int salary){
        for(Employee* const employee : employees_t){
            employee->setSalary(salary);
        }
    }

    void Manager::fireAllEmployees(const int salary){
        setEmployeesSalary(-salary);
        employees_t.clear();
    }

}