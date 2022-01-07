#include "Faculty.h"
#include "exceptions.h"
#include <functional>
namespace mtm{
using namespace mtm;
/*
template<class T>
Faculty<T>::Faculty(int id, T* isAccepted, Skill skill, int added_pointes): id_t(id), isAccepted_t(isAccepted), skill_t(skill), added_pointes_t(added_pointes){
}

template<class T>
Faculty<T>::Faculty(const Faculty& faculty) : id_t(faculty.getId()), isAccepted_t(faculty.isAccepted_t), skill_t(faculty.getSkill()), added_pointes_t(faculty.getAddedPoints()){
}
template<class T>
Faculty<T>::~Faculty(){
}

template<class T>
int Faculty<T>::getAddedPoints() const{
    return added_pointes_t;
}

template<class T>
int Faculty<T>::getId() const{
    return id_t;
}

template<class T>
Skill Faculty<T>::getSkill() const{
    return skill_t;
}

template<class T>
void Faculty<T>::teach(Employee& employee) const{
    if((*isAccepted_t)(employee)){
        employee.learnSkill(getSkill());
        employee.setScore(getAddedPoints());
     return;   
    }
    throw EmployeeNotAccepted();
}
*/
}