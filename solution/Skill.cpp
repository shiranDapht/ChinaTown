#include "Skill.h"
#include "exceptions.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::endl;

namespace mtm{

    Skill::Skill(int id, string name, int required_points) 
        : id_t(id), name_t(name), required_points_t(required_points){}

    Skill::Skill(const Skill& skill) 
        : id_t(skill.id_t), name_t(skill.name_t), required_points_t(skill.required_points_t){}


    int Skill::getId() const{
        return id_t;
    }

    int Skill::getRequiredPoints() const{
        return required_points_t;
    }

    string Skill::getName() const{
        return name_t;
    }


    ostream& operator<<(ostream& os, const Skill& skill){
        return os << skill.getName() << endl;
    }

    bool Skill::operator>(const Skill& rvalue) const{
        return id_t > rvalue.getId();
    }

    bool Skill::operator<(const Skill& rvalue) const{
        return id_t < rvalue.getId();
    }

    bool Skill::operator>=(const Skill& rvalue) const{
        return id_t >= rvalue.getId();
    }

    bool Skill::operator<=(const Skill& rvalue) const{
        return id_t <= rvalue.getId();
    }

    bool Skill::operator==(const Skill& rvalue) const{
        return id_t == rvalue.getId();
    }

    bool Skill::operator!=(const Skill& rvalue) const{
        return id_t != rvalue.getId();
    }

    Skill Skill::operator++(int){
        Skill skill = Skill(*this);
        ++required_points_t;
        return skill;
    }

    Skill& Skill::operator+=(int points){
        if(points < 0){
            throw mtm::NegativePoints();
        }
        required_points_t += points;
        return *this;
    }

    Skill operator+(const Skill& skill, int points){
        if(points < 0){
            throw mtm::NegativePoints();
        }
        Skill new_skill =  Skill(skill) += points;
        return new_skill;
    }

    Skill operator+(int points, const Skill& skill){
        if(points < 0){
            throw mtm::NegativePoints();
        }
        Skill new_skill =  Skill(skill) += points;
        return new_skill;
    }
}