#include "Employee.h"
#include <string>
#include <set>
#include <iostream>

namespace mtm{

Employee::Employee(const int id, const std::string first_name, const std::string last_name, const int year) :
            Citizen(id, first_name, last_name, year), salary_t(0), score_t(0) {
                skills_t = std::set<Skill>();
}



int Employee::getSalary() const{
    return salary_t;
}

int Employee::getScore() const{
    return score_t;
}

void Employee::learnSkill(const Skill skill){
    if(score_t < skill.getRequiredPoints()){
        throw CanNotLearnSkill();
    }
    if(skills_t.find(skill) == skills_t.end()){
        throw SkillAlreadyLearned();
    }
    skills_t.insert(skill);
}

void Employee::forgetSkill(const int skill_id){
    for(const Skill& skill : skills_t){
        if(skill.getId() == skill_id){
            skills_t.erase(skill);
            return;
        }
    }
    throw DidNotLearnSkill();
}

bool Employee::hasSkill(const int skill_id) const{
    for(const Skill& skill : skills_t){
        if(skill.getId() == skill_id){
            return true;
        }
    }
    return false;
}

void Employee::setSalary(const int add_salary){
    salary_t = getSalary() + add_salary;
}

void Employee::setScore(const int add_score){
    score_t = getScore() + add_score;
}

ostream& Employee::printShort(ostream& os){
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n") + std::string("Salary: ") 
        + std::to_string(getSalary()) + std::string("Score: ") + std::to_string(getScore()) <<std::endl;
    return os;
}

ostream& Employee::printLong(ostream& os){
    os << getFirstName() + std::string(" ") + getLastName() + std::string("\n")
        + std::string("id - ") + std::to_string(getId()) + std::string(" birth_year - ") + std::to_string(getBirthYear())
        + std::string("\n") + std::string("Salary: ") + std::to_string(getSalary()) + std::string(" Score: ") 
        + std::to_string(getScore()) + std::string(" Skills: ")  << std::endl;
    printSkills(os);
    return os;
}

ostream& Employee::printSkills(ostream& os){
    for(const Skill& skill : skills_t){
        os << skill.getName() << std::endl;
    }
    return os;
}

Employee* Employee::clone(){
    return new Employee(*this);
}



}