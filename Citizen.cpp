#include "Citizen.h"
#include "exceptions.h"

namespace mtm{

    int Citizen::getId() const{
        return this->id_t;
    };

    string Citizen::getFirstName() const{
        return this->first_name_t;
    };

    string Citizen::getLastName() const{
        return this->last_name_t;
    };

    int Citizen::getBirthYear() const{
        return this->year_of_birth_t;
    };

    bool Citizen::operator<(const Citizen& citizen){
        return (this)
    };
    bool Citizen::operator>(const Citizen& citizen){};
    bool Citizen::operator==(const Citizen& citizen){};
    bool Citizen::operator<=(const Citizen& citizen){};
    bool Citizen::operator>=(const Citizen& citizen){};
    bool Citizen::operator!=(const Citizen& citizen){};
}