#include "Faculty.h"
#include "exceptions.h"

namespace mtm{
using namespace mtm;

Faculty::Faculty(int id, bool (*isAccepted)(Employee), Skill skill, int added_pointes): id(id), isAccepted(isAccepted), skill(skill), added_pointes(added_pointes){
}
Faculty::Faculty(const Faculty& fac) : id(fac.id), isAccepted(fac.isAccepted), skill(fac.skill), added_pointes(fac.added_pointes){
}
Faculty::~Faculty(){
}


int Faculty::getAddedPoints(){
    return this->added_pointes;
}

int Faculty::getId(){
    return this->id;
}

Skill Faculty::getSkill(){
    return this->skill;
}

void Faculty::teach(Employee emp){
    throw NotEmplemented();
    if(this->isAccepted(emp)){
     return;   
    }
    throw EmployeeNotAccepted();
}

}