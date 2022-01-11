#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "City.h"
#include "exceptions.h"

#include <vector>   
#include <memory>
#include <string>
#include <algorithm>

namespace mtm{

City::City(std::string city_name) : city_name_t(city_name), employees_t(std::vector<Employee>()),
    managers_t(std::vector<Manager>()), faculties_t(std::vector<Faculty<Condition>>()), 
    workplaces_t(std::vector<Workplace>()){};

void City::addEmployee(const int id, const std::string first_name, const std::string last_name, const int year){
    try{
        getEmployeeById(id);
        throw CitizenAlreadyExists();
    }
    catch(EmployeeDoesNotExist&){
        employees_t.push_back(Employee(id, first_name, last_name, year));
    }
}

void City::addManager(const int id, const std::string first_name, const std::string last_name, const int year){
    try{
        getManagerById(id);
        throw CitizenAlreadyExists();
    }
    catch(ManagerDoesNotExist&){
        managers_t.push_back(Manager(id, first_name, last_name, year));
    }
}

void City::createWorkplace(int id, std::string name, double workers_salary, double managers_salary){
    try{
        getWorkplaceById(id);
        throw WorkplaceAlreadyExists();
    }
    catch(WorkplaceDoesNotExist&){
        workplaces_t.push_back(Workplace(id,name,workers_salary,managers_salary));
    }
}


void City::teachAtFaculty(const int employee_id, const int faculty_id){
    getFacultyById(faculty_id)->teach(getEmployeeById(employee_id));
}
void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id){
    getWorkplaceById(workplace_id)->hireManager(getManagerById(manager_id));
}

void City::fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id){
    getEmployeeById(employee_id);
    getManagerById(manager_id);
    getWorkplaceById(workplace_id)->fireEmployee(employee_id, manager_id);
}

void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id){
    getManagerById(manager_id);
    getWorkplaceById(workplace_id)->fireManager(manager_id);
}

class Comparator{
    public:
    bool operator()(const CitizenPlus* ptr1, const CitizenPlus* ptr2){
    return *ptr1 < *ptr2;
    }
};


int City::getAllAboveSalary(ostream& os, const int salary_bar){
    int count = 0;
    std::vector<CitizenPlus*> vector_union;
    for(const Employee& employee : employees_t){
        vector_union.push_back((CitizenPlus*)&employee);
    }
    for(const Manager& manager : managers_t){
        vector_union.push_back((CitizenPlus*)&manager);
    }
    std::sort(vector_union.begin(),vector_union.end(), Comparator());
    for(CitizenPlus* const citizen : vector_union){
        if((*citizen).getSalary() >= salary_bar){
            (*citizen).printShort(os);
            count++;
        }
    }
    return count;
}

bool City::isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2){
    getEmployeeById(employee_id1);
    getEmployeeById(employee_id2);
    for(const Workplace& workplace : workplaces_t){
        if(workplace.isEmployeeWorkingHere(employee_id1) && workplace.isEmployeeWorkingHere(employee_id2)){
            return true;
        }
    }
    return false;
}

void City::printAllEmployeesWithSkill(ostream& os, const int id){
    for(const Employee& employee : employees_t){
        if(employee.hasSkill(id)){
            employee.printShort(os);
        }
    }
}

Employee* City::getEmployeeById(const int id){
    for(Employee& employee : employees_t){
        if(employee.getId() == id){
            return &employee;
        }
    }
    throw EmployeeDoesNotExist();
}

Manager* City::getManagerById(const int id){
    for(Manager& manager : managers_t){
        if(manager.getId() == id){
            return &manager;
        }
    }
    throw ManagerDoesNotExist();
}

Workplace* City::getWorkplaceById(const int id){
    for(Workplace& workplace : workplaces_t){
        if(workplace.getId() == id){
            return &workplace;
        }
    }
    throw WorkplaceDoesNotExist();
}

Faculty<Condition>* City::getFacultyById(const int id){
    for(Faculty<Condition>& faculty : faculties_t){
        if(faculty.getId() == id){
            return &faculty;
        }
    }
    throw FacultyDoesNotExist();
}
}