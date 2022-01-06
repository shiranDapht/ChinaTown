#include "Citizen.h"
#include "exceptions.h"

namespace mtm{

    int Citizen::getId() const{
        return id_t;
    }

    string Citizen::getFirstName() const{
        return first_name_t;
    }

    string Citizen::getLastName() const{
        return last_name_t;
    }

    int Citizen::getBirthYear() const{
        return year_of_birth_t;
    }

    bool Citizen::operator<(const Citizen& citizen) const{
        return getId() < citizen.getId();
    }

    bool Citizen::operator>(const Citizen& citizen) const{
        return getId() > citizen.getId();
    }

    bool Citizen::operator==(const Citizen& citizen) const{
        return getId() == citizen.getId();
    }

    bool Citizen::operator<=(const Citizen& citizen) const{
        return getId() <= citizen.getId();
    }

    bool Citizen::operator>=(const Citizen& citizen) const{
        return getId() >= citizen.getId();
    }

    bool Citizen::operator!=(const Citizen& citizen) const{
        return getId() != citizen.getId();
    }

    int CitizenPlus::getSalary() const{
        return salary_t;
    }

    void CitizenPlus::setSalary(int salary){
        salary_t = salary + salary_t < 0 ? 0 : salary + salary_t;
    }
}