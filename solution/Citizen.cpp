#include "Citizen.h"
#include "exceptions.h"

#include <string>
#include <iostream>
namespace mtm{

    Citizen::Citizen(const int id, const std::string first_name, const std::string last_name, const int year): id_t(id), 
                    first_name_t(first_name), last_name_t(last_name), year_of_birth_t(year) {}

    int Citizen::getId() const{
        return id_t;
    }

    std::string Citizen::getFirstName() const{
        return first_name_t;
    }

    std::string Citizen::getLastName() const{
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

    bool Citizen::operator==(const int id) const{
        return getId() == id;
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

    void CitizenPlus::setSalary(const double add_salary){
        salary_t = add_salary + salary_t < 0 ? 0 : add_salary + salary_t;
    }

    CitizenPlus::CitizenPlus(const int id, const std::string first_name, const std::string last_name, const int year):
        Citizen(id, first_name, last_name, year), salary_t(0){}

}