#include "Faculty.h"
#include "exceptions.h"
#include <functional>
namespace mtm{
using namespace mtm;

template<class IsAcceptedFunctor>
Faculty<IsAcceptedFunctor>::Faculty(int id, IsAcceptedFunctor isAccepted, Skill skill, int added_pointes): id_t(id), isAccepted_t(isAccepted), skill_t(skill), added_pointes_t(added_pointes){
    isAccepted_t = isAccepted;
}

template<class IsAcceptedFunctor>
Faculty<IsAcceptedFunctor>::Faculty(const Faculty& faculty) : id_t(faculty.getId()), isAccepted_t(faculty.isAccepted_t), skill_t(faculty.getSkill()), added_pointes_t(faculty.getAddedPoints()){
}
template<class IsAcceptedFunctor>
Faculty<IsAcceptedFunctor>::~Faculty(){
}

template<class IsAcceptedFunctor>
int Faculty<IsAcceptedFunctor>::getAddedPoints() const{
    return added_pointes_t;
}

template<class IsAcceptedFunctor>
int Faculty<IsAcceptedFunctor>::getId() const{
    return id_t;
}

template<class IsAcceptedFunctor>
Skill Faculty<IsAcceptedFunctor>::getSkill() const{
    return skill_t;
}

template<class IsAcceptedFunctor>
void Faculty<IsAcceptedFunctor>::teach(Employee& employee) const{
    if(isAccepted_t(employee)){
        employee.learnSkill(getSkill());
        employee.setScore(getAddedPoints());
     return;   
    }
    throw EmployeeNotAccepted();
}

}