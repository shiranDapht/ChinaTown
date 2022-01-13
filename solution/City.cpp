#include "City.h"

#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

using std::string;
using std::vector;
using std::ostream;
using std::sort;
using std::find;
using std::shared_ptr;

namespace mtm{

    City::City(string city_name) : city_name_t(city_name), employees_t(vector<shared_ptr<Employee>>()),
        managers_t(vector<shared_ptr<Manager>>()), faculties_t(vector<shared_ptr<Faculty<Condition>>>()), 
        workplaces_t(std::vector<shared_ptr<Workplace>>()){}

    void City::addEmployee(const int id, const string first_name, const string last_name, const int year){
        if(getEmployeeByIdOrNullptr(id) == nullptr){
            
            employees_t.push_back(shared_ptr<Employee>(new Employee(id, first_name, last_name, year)));
        }
        else{
            throw CitizenAlreadyExists();
        }
    }

    void City::addManager(const int id, const string first_name, const string last_name, const int year){
        if(getManagerByIdOrNullptr(id) == nullptr){
            managers_t.push_back(shared_ptr<Manager>(new Manager(id, first_name, last_name, year)));
        }
        else{
            throw CitizenAlreadyExists();
        }
    }

    void City::createWorkplace(int id, string name, int workers_salary, int managers_salary){
        if(getWorkplaceByIdOrNullptr(id) == nullptr){
        workplaces_t.push_back(shared_ptr<Workplace>(new Workplace(id,name,workers_salary,managers_salary)));
        }
        else{
            throw WorkplaceAlreadyExists();
        }
    }


    void City::teachAtFaculty(const int employee_id, const int faculty_id){
        getFacultyById(faculty_id)->teach(getEmployeeById(employee_id).get());
    }

    void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->hireManager(getManagerById(manager_id).get());
    }

    void City::fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->fireEmployee(employee_id, manager_id);
    }

    void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->fireManager(manager_id);
    }

    


    int City::getAllAboveSalary(ostream& os, const int salary_bar) const{
        int count = 0;
        vector<shared_ptr<Citizen>> vector_union;
        for(const shared_ptr<Citizen> employee : employees_t){
            vector_union.push_back(employee);
        }
        for(const shared_ptr<Citizen> manager : managers_t){
            vector_union.push_back(manager);
        }
        sort(vector_union.begin(),vector_union.end(), Comparator());
        for(shared_ptr<Citizen> citizen : vector_union){
            if((*citizen).getSalary() >= salary_bar){
                (*citizen).printShort(os);
                count++;
            }
        }
        return count;
    }

    bool City::isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2) const{
        bool e1 = (find(employees_t.begin(), employees_t.end(), employee_id1) != employees_t.end());
        bool e2 = (find(employees_t.begin(), employees_t.end(), employee_id2) != employees_t.end());
        if(!e1 || !e2){
            throw EmployeeDoesNotExist();
        }
        for(const shared_ptr<Workplace> workplace : workplaces_t){
            if((*workplace).isEmployeeWorkingHere(employee_id1) && (*workplace).isEmployeeWorkingHere(employee_id2)){
                return true;
            }
        }
        return false;
    }

    void City::printAllEmployeesWithSkill(ostream& os, const int id) const{
        for(const shared_ptr<Employee> employee : employees_t){
            if((*employee).hasSkill(id)){
                (*employee).printShort(os);
            }
        }
    }


    shared_ptr<Employee> City::getEmployeeByIdOrNullptr(const int id){
        for(shared_ptr<Employee> employee : employees_t){
                if((*employee).getId() == id){
                    return employee;
                }
        }
        return nullptr;
    }

    shared_ptr<Manager> City::getManagerByIdOrNullptr(const int id){
        for(shared_ptr<Manager> manager : managers_t){
            if((*manager).getId() == id){
                return manager;
            }
        }
        return nullptr;

    }

    shared_ptr<Faculty<Condition>> City::getFacultyByIdOrNullptr(const int id){
        for(shared_ptr<Faculty<Condition>> faculty : faculties_t){
            if((*faculty).getId() == id){
                return faculty;
            }
        }
        return nullptr;
    }

    shared_ptr<Workplace> City::getWorkplaceByIdOrNullptr(const int id){
        for(shared_ptr<Workplace> workplace : workplaces_t){
            if((*workplace).getId() == id){
                return workplace;
            }
        }
        return nullptr;
    }



    shared_ptr<Employee> City::getEmployeeById(const int id){
        shared_ptr<Employee> employee = getEmployeeByIdOrNullptr(id);
        if(employee != nullptr){
            return employee;
        }
        throw EmployeeDoesNotExist();
    }

    shared_ptr<Manager> City::getManagerById(const int id){
        shared_ptr<Manager> manager = getManagerByIdOrNullptr(id);
        if(manager != nullptr){
            return manager;
        }
        throw ManagerDoesNotExist();
    }

    shared_ptr<Workplace> City::getWorkplaceById(const int id){
        shared_ptr<Workplace> workplace = getWorkplaceByIdOrNullptr(id);
        if(workplace != nullptr){
            return workplace;
        }
        throw WorkplaceDoesNotExist();
    }

    shared_ptr<Faculty<Condition>> City::getFacultyById(const int id){
        shared_ptr<Faculty<Condition>> faculty = getFacultyByIdOrNullptr(id);
        if(faculty != nullptr){
            return faculty;
        }
        throw FacultyDoesNotExist();
    }

}