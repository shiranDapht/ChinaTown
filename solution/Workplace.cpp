#include "Workplace.h"
#include "exceptions.h"
#include <string>
#include <set>
#include <iostream>

namespace mtm{


    Workplace::Workplace(int id, std::string name, double workers_salary, double managers_salary):
        id_t(id), name_t(name), workers_salary_t(workers_salary), managers_salary_t(managers_salary), 
        managers_set_t(std::set<Manager*>()){}

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
        if(getManagerByIdOrNullptr(manager->getId()) != nullptr){
            throw ManagerAlreadyHired();
        }
        if(manager->getIsHired()){
            throw CanNotHireManager();
        }
        manager->setIsHired(true);
        manager->setSalary(managers_salary_t);
        managers_set_t.insert(manager);
    }

    void Workplace::fireEmployee(int employee_id, int manager_id){
        Manager* manager = getManagerById(manager_id);
        manager->getEmployeeById(employee_id)->setSalary(-getWorkersSalary());
        manager->removeEmployee(employee_id);
    }

    void Workplace::fireManager(int manager_id){
        Manager* manager = getManagerById(manager_id);
        manager->fireAllEmployees(getWorkersSalary());
        manager->setIsHired(false);
        manager->setSalary(-getManagersSalary());
        managers_set_t.erase(manager);
    }

    std::ostream& operator<<(std::ostream& os, const Workplace& workplace){
        os << std::string("Workplace name - ") + workplace.getName();
        if(!workplace.managers_set_t.empty()){
            os << " Groups:\n";
            for(Manager* const manager : workplace.managers_set_t){
                os << "Manager ";
                manager->printLong(os);
            }
        }
        else{
            os << std::endl;
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


    Manager* Workplace::getManagerByIdOrNullptr(const int id) const{
        for(Manager* const manager : managers_set_t){
            if(manager->getId() == id){
                return manager;
            }
        }
        return nullptr;
    }

    Manager* Workplace::getManagerById(const int id) const{
        Manager* manager = getManagerByIdOrNullptr(id);
        if(manager == nullptr){
            throw ManagerIsNotHired();
        }
        return manager;
    }

}