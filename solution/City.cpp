#include "City.h"

#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>

namespace mtm{

    City::City(std::string city_name) : city_name_t(city_name), employees_t(std::vector<Employee>()),
        managers_t(std::vector<Manager>()), faculties_t(std::vector<Faculty<Condition>>()), 
        workplaces_t(std::vector<Workplace>()){}

    void City::addEmployee(const int id, const std::string first_name, const std::string last_name, const int year){
        if(getEmployeeByIdOrNullptr(id) == nullptr){
            employees_t.push_back(Employee(id, first_name, last_name, year));
        }
        else{
            throw CitizenAlreadyExists();
        }
    }

    void City::addManager(const int id, const std::string first_name, const std::string last_name, const int year){
        if(getManagerByIdOrNullptr(id) == nullptr){
            managers_t.push_back(Manager(id, first_name, last_name, year));
        }
        else{
            throw CitizenAlreadyExists();
        }
    }

    void City::createWorkplace(int id, std::string name, double workers_salary, double managers_salary){
        if(getWorkplaceByIdOrNullptr(id) == nullptr){
        workplaces_t.push_back(Workplace(id,name,workers_salary,managers_salary));
        }
        else{
            throw WorkplaceAlreadyExists();
        }
    }


    void City::teachAtFaculty(const int employee_id, const int faculty_id){
        getFacultyById(faculty_id)->teach(getEmployeeById(employee_id));
    }

    void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->hireManager(getManagerById(manager_id));
    }

    void City::fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->fireEmployee(employee_id, manager_id);
    }

    void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id){
        getWorkplaceById(workplace_id)->fireManager(manager_id);
    }

    /**
     * @brief Comperator for CitizenPlus* collection sorting
     * 
     */
    class Comparator{
        public:
        Comparator() = default;
        ~Comparator() = default;
        Comparator(const Comparator&) = default;
        
        bool operator()(const CitizenPlus* ptr1, const CitizenPlus* ptr2){
        return *ptr1 < *ptr2;
        }
    };


    int City::getAllAboveSalary(std::ostream& os, const int salary_bar) const{
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

    bool City::isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2) const{
        bool e1 = (std::find(employees_t.begin(), employees_t.end(), employee_id1) != employees_t.end());
        bool e2 = (std::find(employees_t.begin(), employees_t.end(), employee_id2) != employees_t.end());
        if(!e1 || !e2){
            throw EmployeeDoesNotExist();
        }
        for(const Workplace& workplace : workplaces_t){
            if(workplace.isEmployeeWorkingHere(employee_id1) && workplace.isEmployeeWorkingHere(employee_id2)){
                return true;
            }
        }
        return false;
    }

    void City::printAllEmployeesWithSkill(std::ostream& os, const int id) const{
        for(const Employee& employee : employees_t){
            if(employee.hasSkill(id)){
                employee.printShort(os);
            }
        }
    }


    Employee* City::getEmployeeByIdOrNullptr(const int id){
        for(Employee& employee : employees_t){
                if(employee.getId() == id){
                    return &employee;
                }
        }
        return nullptr;
    }

    Manager* City::getManagerByIdOrNullptr(const int id){
        for(Manager& manager : managers_t){
            if(manager.getId() == id){
                return &manager;
            }
        }
        return nullptr;

    }

    Faculty<Condition>* City::getFacultyByIdOrNullptr(const int id){
        for(Faculty<Condition>& faculty : faculties_t){
            if(faculty.getId() == id){
                return &faculty;
            }
        }
        return nullptr;
    }

    Workplace* City::getWorkplaceByIdOrNullptr(const int id){
        for(Workplace& workplace : workplaces_t){
            if(workplace.getId() == id){
                return &workplace;
            }
        }
        return nullptr;
    }



    Employee* City::getEmployeeById(const int id){
        Employee* employee = getEmployeeByIdOrNullptr(id);
        if(employee != nullptr){
            return employee;
        }
        throw EmployeeDoesNotExist();
    }

    Manager* City::getManagerById(const int id){
        Manager* manager = getManagerByIdOrNullptr(id);
        if(manager != nullptr){
            return manager;
        }
        throw ManagerDoesNotExist();
    }

    Workplace* City::getWorkplaceById(const int id){
        Workplace* workplace = getWorkplaceByIdOrNullptr(id);
        if(workplace != nullptr){
            return workplace;
        }
        throw WorkplaceDoesNotExist();
    }

    Faculty<Condition>* City::getFacultyById(const int id){
        Faculty<Condition>* faculty = getFacultyByIdOrNullptr(id);
        if(faculty != nullptr){
            return faculty;
        }
        throw FacultyDoesNotExist();
    }

}