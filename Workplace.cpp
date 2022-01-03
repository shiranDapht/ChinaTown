#include "Workplace.h"

using namespace mtm;

Workplace::Workplace(int id, std::string name, double workers_salary, double managers_salary):
id_t(id), name_t(name), workers_salary_t(workers_salary), managers_salary_t(managers_salary), managers_set_t(std::set<Manager>()){
}
Workplace::~Workplace(){
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
    for(Manager manager : managers_set_t){
        if(manager.getId() == manager_id){
            manager.addEmployee(*employee);
        }
    }
    throw ManagerIsNotHired();
}

void Workplace::hireManager(Manager* manager){
    
}

