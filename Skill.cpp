#include "Skill.h"
#include "exceptions.h"

using namespace mtm;

Skill::Skill(int id, std::string name, int required_points) : id(id), required_points(required_points), name(name){
}
Skill::Skill(const Skill& skill) : id(skill.id), required_points(skill.required_points), name(skill.name){
}
Skill::~Skill(){
}


int Skill::getId() const{
    return id;
}
int Skill::getRequiredPoints() const{
    return required_points;
}
std::string Skill::getName() const{
    return name;
}


std::ostream& operator<<(std::ostream& os, const Skill& skill){
    return os << skill.getName();
}

bool Skill::operator>(const Skill& rvalue){
    return id > rvalue.getId();
}

bool Skill::operator<(const Skill& rvalue){
    return id < rvalue.getId();
}

bool Skill::operator>=(const Skill& rvalue){
    return id >= rvalue.getId();
}

bool Skill::operator<=(const Skill& rvalue){
    return id <= rvalue.getId();
}

bool Skill::operator==(const Skill& rvalue){
    return id == rvalue.getId();
}

bool Skill::operator!=(const Skill& rvalue){
    return id != rvalue.getId();
}

void Skill::operator++(int){
    id++;
}

void Skill::operator+=(int points){
    if(points < 0){
        throw mtm::NegativePoints();
    }
    id+=points;
}

int Skill::operator+(int points){
    if(points < 0){
        throw NegativePoints();
    }
    return this->getId() + points;
}
