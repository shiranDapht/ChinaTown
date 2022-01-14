#include "Citizen.h"
#include "exceptions.h"

#include <string>
#include <iostream>

using std::string;
using std::ostream;

namespace mtm{

    Citizen::Citizen(const int id, const string first_name, const string last_name, const int year): id_t(id), 
<<<<<<< HEAD
                    first_name_t(first_name), last_name_t(last_name), year_of_birth_t(year), salary_t(0) {}
=======
                    first_name_t(first_name), last_name_t(last_name), year_of_birth_t(year) {}
>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1

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

<<<<<<< HEAD
    int Citizen::getSalary() const {
        return salary_t;
    }

    void Citizen::setSalary(const int add_salary) {
        salary_t = getSalary() + add_salary <= 0 ? 0 : getSalary() + add_salary;
    }


    bool Comparator::operator()(const Citizen& ptr1, const Citizen& ptr2){
                return ptr1 < ptr2;
    }

=======
    bool Comparator::operator()(const shared_ptr<Citizen> ptr1, const shared_ptr<Citizen> ptr2){
                return *ptr1 < *ptr2;
    }

>>>>>>> 50a9a1c6a05094a158b1e4f84cf9c3fd6bd6a6a1
}