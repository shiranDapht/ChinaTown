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
<<<<<<< HEAD
        Citizen(id, first_name, last_name, year) ,employees_t(set<Employee*, Comparator>()){}

    void Manager::addEmployee(Employee* const employee){
        if(employees_t.find(employee) == employees_t.end()){
            employees_t.insert(employee);
=======
        Citizen(id, first_name, last_name, year), salary_t(-1) ,employees_t(set<shared_ptr<Employee>, Comparator>()){}

    void Manager::addEmployee(Employee* const employee){
        shared_ptr<Employee> employee_ptr = make_shared<Employee>(employee);
        if(employees_t.find(employee_ptr) == employees_t.end()){
            employees_t.insert(employee_ptr);
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
        }
        else{
            throw EmployeeAlreadyHired();
        }
    }

    void Manager::removeEmployee(const int employee_id){
<<<<<<< HEAD
        Employee* employee = getEmployeeByIdOrNullptr(employee_id);
        if(!employee){
            throw EmployeeIsNotHired();
        }
        employees_t.erase(employee);
=======
        for(shared_ptr<Employee> const employee : employees_t){
            if(employee->getId() == employee_id){
                employees_t.erase(employee);
                return;
            }
        }
        throw EmployeeIsNotHired();
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
    }


    ostream& Manager::printShort(ostream& os) const{
        os << getFirstName() + string(" ") + getLastName() + string("\nSalary: ") + to_string(getSalary()) << endl;
        return os;
    }

    ostream& Manager::printEmployees(ostream& os) const{
        if(!employees_t.empty()){
            os << string("Employees: ") << endl;
<<<<<<< HEAD
            for(Employee* const employee : employees_t){
=======
            for(shared_ptr<Employee> employee : employees_t){
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
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

<<<<<<< HEAD
    Manager* Manager::clone() const{
        return new Manager(*this);
=======
    shared_ptr<Citizen> Manager::clone() const{
        return shared_ptr<Manager>(new Manager(*this));
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
    }

    bool Manager::isEmployeeHere(const int id) const{
        return getEmployeeByIdOrNullptr(id) != nullptr;
<<<<<<< HEAD
    }

    Employee* Manager::getEmployeeByIdOrNullptr(const int id) const{
        for(Employee* const employee : employees_t){
            if(employee->getId() == id){
                return employee;
            }
        }
        return nullptr;
=======
    }

    shared_ptr<Employee> Manager::getEmployeeByIdOrNullptr(const int id) const{
        for(shared_ptr<Employee> const employee : employees_t){
            if(employee->getId() == id){
                return employee;
            }
        }
        return nullptr;
    }


    shared_ptr<Employee> Manager::getEmployeeById(const int id) const{
        shared_ptr<Employee> employee = getEmployeeByIdOrNullptr(id);
        if(employee == nullptr){
            throw EmployeeIsNotHired();
        }
        return employee;
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
    }

    void Manager::fireAllEmployees(const int salary){
        for(shared_ptr<Employee> const employee : employees_t){
            employee->setSalary(-salary);
        }
        employees_t.clear();
    }

<<<<<<< HEAD
    Employee* Manager::getEmployeeById(const int id) const{
        Employee* employee = getEmployeeByIdOrNullptr(id);
        if(employee == nullptr){
            throw EmployeeIsNotHired();
        }
        return employee;
    }

    void Manager::fireAllEmployees(const int salary){
        for(Employee* const employee : employees_t){
            employee->setSalary(-salary);
        }
=======
    int Manager::getSalary() const {
        return salary_t;
    }

    void Manager::setSalary(const int add_salary) {
        salary_t = getSalary() + add_salary <= 0 ? 0 : getSalary() + add_salary;
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
    }

}