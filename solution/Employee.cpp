#include "Employee.h"
#include "exceptions.h"

#include <string>
#include <set>
#include <iostream>
#include <memory>

using std::string;
using std::set;
using std::ostream;
using std::to_string;
using std::endl;
using std::shared_ptr;
using std::make_shared;

namespace mtm{

    Employee::Employee(const int id, const string first_name, const string last_name, const int year) :
                Citizen(id, first_name, last_name, year), score_t(0), salary_t(0), skills_t(set<Skill>()) {}

    int Employee::getScore() const{
        return score_t;
    }

    void Employee::learnSkill(const Skill skill){
        if(score_t < skill.getRequiredPoints()){
            throw CanNotLearnSkill();
        }
        if(skills_t.find(skill) != skills_t.end()){
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

    int Employee::getSalary() const{
        return salary_t;
    }

    void Employee::setSalary(const int add_salary){
        salary_t = getSalary() + add_salary <= 0 ? 0 : getSalary() + add_salary;
    }

    void Employee::setScore(const int add_score){
        score_t = getScore() + add_score <= 0 ? 0 : getScore() + add_score;
    }

    ostream& Employee::printShort(ostream& os) const{
        os << getFirstName() + string(" ") + getLastName() + string("\nSalary: ") 
            + to_string(getSalary()) + string(" Score: ") + to_string(getScore()) <<endl;
        return os;
    }

    ostream& Employee::printLong(ostream& os) const{
        os << getFirstName() + string(" ") + getLastName() + string("\nid - ") + to_string(getId()) 
        + string(" birth_year - ") + to_string(getBirthYear()) + string("\nSalary: ") + to_string(getSalary()) 
        + string(" Score: ") + to_string(getScore());
        printSkills(os);
        return os;
    }

    ostream& Employee::printSkills(ostream& os) const{
        if(!skills_t.empty()){
            os << string(" Skills: ") << endl;
            for(const Skill& skill : skills_t){
                os << skill.getName() << endl;
            }
        }
        else{
            os << endl;
        }
        return os;
    }

    Employee* Employee::clone() const{
        return new Employee(*this);
    }

}