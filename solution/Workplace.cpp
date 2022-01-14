#include "Workplace.h"
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


    Workplace::Workplace(int id, string name, int workers_salary, int managers_salary):
        id_t(id), name_t(name), workers_salary_t(workers_salary), managers_salary_t(managers_salary), 
        managers_set_t(set<Manager*, Comparator>()){}

    int Workplace::getManagersSalary() const{
        return managers_salary_t;
    }

    int Workplace::getWorkersSalary() const{
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
        if(manager->getSalary() > 0){
            throw CanNotHireManager();
        }
        manager->setSalary(getManagersSalary());
        managers_set_t.insert(manager);
    }

    void Workplace::fireEmployee(int employee_id, int manager_id){
        Manager* manager_ptr = getManagerById(manager_id);
        manager_ptr->getEmployeeById(employee_id)->setSalary(-getWorkersSalary());
        manager_ptr->removeEmployee(employee_id);
    }

    void Workplace::fireManager(int manager_id){
        Manager* manager_ptr = getManagerById(manager_id);
        manager_ptr->fireAllEmployees(getWorkersSalary());
        manager_ptr->setSalary(-getManagersSalary());
        managers_set_t.erase(manager_ptr);
    }

    ostream& operator<<(ostream& os, const Workplace& workplace){
        os << string("Workplace name - ") + workplace.getName();
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