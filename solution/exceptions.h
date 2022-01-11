#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
namespace mtm{

/**
 * @brief Parent Exception class.
 * 
 */
class Exception : std::exception{};
class CitizenAlreadyExists : Exception{};

class NegativePoints : Exception{};
class SkillAlreadyLearned : Exception{};
class CanNotLearnSkill : Exception{};
class DidNotLearnSkill : Exception{};
class EmployeeAlreadyHired : Exception{};
class EmployeeNotSelected : Exception{};
class ManagerIsNotHired : Exception{};
class ManagerAlreadyHired : Exception{};
class CanNotHireManager : Exception{};
class EmployeeIsNotHired : Exception{};
class EmployeeNotAccepted : Exception{};
class FacultyAlreadyExists : Exception{};
class WorkplaceAlreadyExists : Exception{};
class EmployeeDoesNotExist : Exception{};
class FacultyDoesNotExist : Exception{};
class WorkplaceDoesNotExist : Exception{};
class ManagerDoesNotExist : Exception{};


}

#endif