#include "Faculty.h"
#include "exceptions.h"
#include <functional>
namespace mtm{
using namespace mtm;

Faculty::Faculty(int id, std::function<bool (Employee)> isAccepted, Skill skill, int added_pointes): id_t(id), isAccepted_t(isAccepted), skill(skill), added_pointes_t(added_pointes){
    isAccepted_t = isAccepted;
}
Faculty::Faculty(const Faculty& faculty) : id_t(faculty.getId()), isAccepted_t(faculty.isAccepted_t), skill(faculty.getSkill()), added_pointes_t(faculty.getAddedPoints()){
}
Faculty::~Faculty(){
}


int Faculty::getAddedPoints() const{
    return this->added_pointes_t;
}

int Faculty::getId() const{
    return this->id_t;
}

Skill Faculty::getSkill() const{
    return this->skill;
}

void Faculty::teach(Employee& emp) const{
    throw NotEmplemented();
    if(isAccepted_t(emp)){
     return;   
    }
    throw EmployeeNotAccepted();
}

}