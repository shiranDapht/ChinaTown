#include "Employee.h"
#include "Manager.h"
#include "Faculty.h"
#include "Workplace.h"
#include "City.h"
#include "exceptions.h"

#include <memory>
#include <string>

namespace mtm{

City::City(std::string city_name) : city_name_t(city_name), employees_t(std::set<Employee>()),
    managers_t(std::set<Manager>()), faculties_t(std::set<Faculty<Condition>, CompareFaculties>()), 
    workplaces_t(std::set<Workplace>()){};

void City::addEmployee(const int id, const std::string first_name, const std::string last_name, const int year){
    Employee new_employee = Employee(id, first_name, last_name, year);
    if(employees_t.find(new_employee) != employees_t.end()){
        throw EmployeeAlreadyExists();
    }
    employees_t.insert(new_employee);
}

void City::addManager(const int id, const std::string first_name, const std::string last_name, const int year){
    Manager new_manager = Manager(id, first_name, last_name, year);
    if(managers_t.find(new_manager) != managers_t.end()){
        throw ManagerAlreadyExists();
    }
    managers_t.insert(new_manager);
}
/*
template<class IsAccepted>
void City::addFaculty(const int id,const Skill& skill, const int added_pointes, const IsAccepted isAccepted){
    Faculty<IsAccepted> new_faculty = Faculty<IsAccepted>(id, *isAccepted, skill, added_pointes);
    if(faculties_t.find(new_faculty) != faculties_t.end()){
        throw FacultyAlreadyExists();
    }
    faculties_t.insert(new_faculty);
}
*/
void City::createWorkplace(int id, std::string name, double workers_salary, double managers_salary){
    Workplace new_workplace = Workplace(id,name,workers_salary,managers_salary);
    if(workplaces_t.find(new_workplace) != workplaces_t.end()){
        throw WorkplaceAlreadyExists();
    }
    workplaces_t.insert(new_workplace);
}


void City::teachAtFaculty(const int employee_id, const int faculty_id){
    for(const Employee& employee : employees_t){
        if(employee.getId() == employee_id){
            for(const Faculty<Condition>& faculty : faculties_t){
                if(faculty.getId() == faculty_id){
                    Employee new_employee = Employee(employee);
                    faculty.teach(new_employee);
                    employees_t.erase(employee);
                    employees_t.insert(new_employee);
                    return;
                }
            }
            throw FacultyDoesNotExist();
        }
    }
    throw EmployeeDoesNotExist();
}
/*
template<class Condition>
void City::hireEmployeeAtWorkplace(const Condition cond, const int employee_id,const int manager_id, const int workplace_id){
    for(const Employee& employee : employees_t){
        if(employee.getId() == employee_id){
            for(const Manager& manager : managers_t){
                if(manager.getId() == manager_id){
                    for(const Workplace& workplace : workplaces_t){
                        if(workplace.getId() == workplace_id){
                            workplace.hireEmployee(cond, employee, manager);
                        }
                    }
                    throw WorkplaceDoesNotExist();
                }
            }
            throw ManagerDoesNotExist();
        }
    }
    throw EmployeeDoesNotExist();
}
*/
void City::hireManagerAtWorkplace(const int manager_id, const int workplace_id){
    for(const Manager& manager : managers_t){
        if(manager.getId() == manager_id){
            for(const Workplace& workplace : workplaces_t){
                if(workplace.getId() == workplace_id){
                    Workplace new_workplace = Workplace(workplace);
                    new_workplace.hireManager(&manager);
                    workplaces_t.erase(workplace);
                    workplaces_t.insert(new_workplace);
                    return;
                }
            }
            throw WorkplaceDoesNotExist();
        }
    }
    throw ManagerDoesNotExist();
}

void City::fireEmployeeAtWorkplace(const int employee_id,const int manager_id, const int workplace_id){
        for(const Employee& employee : employees_t){
        if(employee.getId() == employee_id){
            for(const Manager& manager : managers_t){
                if(manager.getId() == manager_id){
                    for(const Workplace& workplace : workplaces_t){
                        if(workplace.getId() == workplace_id){
                            Workplace new_workplace = Workplace(workplace);
                            new_workplace.fireEmployee(employee_id, manager_id);
                            workplaces_t.erase(workplace);
                            workplaces_t.insert(new_workplace);
                            return;
                        }
                    }
                    throw WorkplaceDoesNotExist();
                }
            }
            throw ManagerDoesNotExist();
        }
    }
    throw EmployeeDoesNotExist();
}

void City::fireManagerAtWorkplace(const int manager_id, const int workplace_id){
    for(const Manager& manager : managers_t){
        if(manager.getId() == manager_id){
            for(const Workplace& workplace : workplaces_t){
                if(workplace.getId() == workplace_id){
                    Workplace new_workplace = Workplace(workplace);
                    new_workplace.fireManager(manager.getId());
                    workplaces_t.erase(workplace);
                    workplaces_t.insert(new_workplace);
                    return;
                }
            }
            throw WorkplaceDoesNotExist();
        }
    }
    throw ManagerDoesNotExist();
}

class Comparator{
    public:
    bool operator()(const std::unique_ptr<CitizenPlus>& ptr1, const std::unique_ptr<CitizenPlus>& ptr2){
    return *ptr1 < *ptr2;
    }
};


int City::getAllAboveSalary(ostream& os, const int salary_bar){
    int count = 0;
    std::set<std::unique_ptr<CitizenPlus>, Comparator> set_union = std::set<std::unique_ptr<CitizenPlus> , Comparator>();
    for(const Employee& employee : employees_t){
        set_union.insert(std::unique_ptr<CitizenPlus>(employee.clone()));
    }
    for(const Manager& manager : managers_t){
        set_union.insert(std::unique_ptr<CitizenPlus>(manager.clone()));
    }
    for(const std::unique_ptr<CitizenPlus>& citizen : set_union){
        if((*citizen).getSalary() >= salary_bar){
            (*citizen).printShort(os);
            count++;
        }
    }
    return count;
}

bool City::isWorkingInTheSameWorkplace(const int employee_id1, const int employee_id2){
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

}