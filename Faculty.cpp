#include "Faculty.h"
#include "exceptions.h"
#include <functional>
namespace mtm{
using namespace mtm;

Faculty::Faculty(int id, std::function<bool (Employee)> isAccepted, Skill skill, int added_pointes): id_t(id), isAccepted_t(isAccepted), skill_t(skill), added_pointes_t(added_pointes){
    isAccepted_t = isAccepted;
}
Faculty::Faculty(const Faculty& faculty) : id_t(faculty.getId()), isAccepted_t(faculty.isAccepted_t), skill_t(faculty.getSkill()), added_pointes_t(faculty.getAddedPoints()){
}
Faculty::~Faculty(){
}

int Faculty::getAddedPoints() const{
    return added_pointes_t;
}

int Faculty::getId() const{
    return id_t;
}

Skill Faculty::getSkill() const{
    return skill_t;
}

void Faculty::teach(Employee& employee) const{
    if(isAccepted_t(employee)){
        employee.learnSkill(getSkill());
        employee.setScore(getAddedPoints());
     return;   
    }
    throw EmployeeNotAccepted();
}

}