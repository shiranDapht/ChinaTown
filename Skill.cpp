#include "Skill.h"
#include "exceptions.h"

using namespace mtm;

Skill::Skill(int id, std::string name, int required_points) : id_t(id), required_points_t(required_points), name_t(name){
}
Skill::Skill(const Skill& skill) : id_t(skill.id_t), required_points_t(skill.required_points_t), name_t(skill.name_t){
}
Skill::~Skill(){
}


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
    return os << skill.getName();
}

bool Skill::operator>(const Skill& rvalue){
    return id_t > rvalue.getId();
}

bool Skill::operator<(const Skill& rvalue){
    return id_t < rvalue.getId();
}

bool Skill::operator>=(const Skill& rvalue){
    return id_t >= rvalue.getId();
}

bool Skill::operator<=(const Skill& rvalue){
    return id_t <= rvalue.getId();
}

bool Skill::operator==(const Skill& rvalue){
    return id_t == rvalue.getId();
}

bool Skill::operator!=(const Skill& rvalue){
    return id_t != rvalue.getId();
}

void Skill::operator++(int){
    id_t++;
}

void Skill::operator+=(int points){
    if(points < 0){
        throw mtm::NegativePoints();
    }
    id_t+=points;
}

int Skill::operator+(int points){
    if(points < 0){
        throw NegativePoints();
    }
    return getId() + points;
}
