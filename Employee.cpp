#include "Employee.h"
#include "exceptions.h"

namespace mtm{
    int Employee::getSalary() const{
        return this->salary_t;
    };

    int Employee::getScore() const{
        return this->score_t;
    };

    void Employee::learnSkill(const Skill skill){

    };

    void Employee::forgetSkill(const int skill_id){
        if(!hasSkill(skill_id)){
            throw DidNotLearnSkill();
        }
        Skill* up = nullptr;
        up = this->skills_t.get();
    };

    bool Employee::hasSkill(const int skill_id) const;
    void Employee::setSalary(const int add_salary);
    void Employee::setScore(const int add_score);

    virtual ostream& Employee::printShort(const ostream& os);
    virtual ostream& Employee::printLong(const ostream& os);

    virtual Citizen& Employee::clone();
}