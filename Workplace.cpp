#include "Workplace.h"
#include "exceptions.h"
#include <string>

namespace mtm{


Workplace::Workplace(int id, std::string name, double workers_salary, double managers_salary):
id_t(id), name_t(name), workers_salary_t(workers_salary), managers_salary_t(managers_salary), managers_set_t(std::set<Manager>()){
}

double Workplace::getManagersSalary() const{
    return managers_salary_t;
}

double Workplace::getWorkersSalary() const{
    return workers_salary_t;
}

std::string Workplace::getName() const{
    return name_t;
}

int Workplace::getID() const{
    return id_t;
}

template<class IsAcceptedToWorkFunctor>
void Workplace::hireEmployee(IsAcceptedToWorkFunctor isAccepted, Employee* employee, int manager_id){
    if(isAccepted(*employee)){
        throw EmployeeNotSelected();
    }
    for(const Manager& manager : managers_set_t){
        if(manager.getId() == manager_id){
            Manager new_manager = Manager(manager);
            new_manager.addEmployee(employee);
            managers_set_t.erase(manager);
            managers_set_t.insert(new_manager);
            return;
        }
    }
    throw ManagerIsNotHired();
}

void Workplace::hireManager(Manager* manager){
    if(managers_set_t.find(*manager) != managers_set_t.end()){
        throw ManagerAlreadyHired();
    }
    if(manager->getIsHired()){
        throw CanNotHireManager();
    }
    managers_set_t.insert(*manager);
}

void Workplace::fireEmployee(int employee_id, int manager_id){
    for(const Manager& manager : managers_set_t){
        if(manager.getId() == manager_id){
            Manager new_manager = Manager(manager);
            new_manager.removeEmployee(employee_id);
            managers_set_t.erase(manager);
            managers_set_t.insert(new_manager);
            return;
        }
    }
    throw ManagerIsNotHired();
}

void Workplace::fireManager(int manager_id){
    for(const Manager& manager : managers_set_t){
        if(manager.getId() == manager_id){
            managers_set_t.erase(manager);
        }
    }
    throw ManagerIsNotHired();
}

ostream& operator<<(ostream& os, Workplace& workplace){
    os << std::string("Workplace name - ") + workplace.getName() + std::string(" Groups:\n") << std::endl;
    for(const Manager& manager : workplace.managers_set_t){
        manager.printLong(os);
    }
    return os;
}
}