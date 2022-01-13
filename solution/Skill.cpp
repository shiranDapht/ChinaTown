#include "Skill.h"
#include "exceptions.h"
#include <string>
#include <iostream>

namespace mtm{

Skill::Skill(int id, std::string name, int required_points) 
    : id_t(id), required_points_t(required_points), name_t(name){}

Skill::Skill(const Skill& skill) 
    : id_t(skill.id_t), required_points_t(skill.required_points_t), name_t(skill.name_t){}


int Skill::getId() const{
    return id_t;
}

int Skill::getRequiredPoints() const{
    return required_points_t;
}

std::string Skill::getName() const{
    return name_t;
}


std::ostream& operator<<(std::ostream& os, const Skill& skill){
    return os << skill.getName() << std::endl;
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
    return Skill(skill.getId(), skill.getName(), skill.getRequiredPoints()+points);
}

Skill operator+(int points, const Skill& skill){
    if(points < 0){
        throw mtm::NegativePoints();
    }
    return Skill(skill.getId(), skill.getName(), skill.getRequiredPoints()+points);
}
}