#include "Workplace.h"
#include "exceptions.h"
#include <string>

namespace mtm{


Workplace::Workplace(int id, std::string name, double workers_salary, double managers_salary):
id_t(id), name_t(name), workers_salary_t(workers_salary), managers_salary_t(managers_salary), managers_set_t(std::set<Manager*>()){
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

int Workplace::getId() const{
    return id_t;
}


void Workplace::hireManager(Manager* manager){
    try{
        getManagerById(manager->getId());// getManagerById throws ManagerIsNotHired if manager isn't hired.
        throw ManagerAlreadyHired();
    }
    catch(ManagerIsNotHired&){
        if(manager->getIsHired()){
            throw CanNotHireManager();
        }
        manager->setSalary(managers_salary_t);
        managers_set_t.insert(manager);
        return;
    }
}

void Workplace::fireEmployee(int employee_id, int manager_id){
    Manager* manager = getManagerById(manager_id);
    manager->removeEmployee(employee_id);
}

void Workplace::fireManager(int manager_id){
    Manager* manager = getManagerById(manager_id);
    manager->setIsHired(false);
    manager->setSalary(-managers_salary_t);
}

ostream& operator<<(ostream& os, Workplace& workplace){
    os << std::string("Workplace name - ") + workplace.getName() + std::string(" Groups:\n") << std::endl;
    for(Manager* const manager : workplace.managers_set_t){
        manager->printLong(os);
    }
    return os;
}

bool Workplace::isEmployeeWorkingHere(int id) const{
    for(Manager* const manager : managers_set_t){
        if(manager->isEmployeeHere(id)){
            return true;
        }
    }
    return false;
}

bool Workplace::operator<(const Workplace& workplace) const{
    return getId() < workplace.getId();
}

Manager* Workplace::getManagerById(const int id) const{
    for(Manager* const manager : managers_set_t){
        if(manager->getId() == id){
            return manager;
        }
    }
    throw ManagerIsNotHired();
}

}