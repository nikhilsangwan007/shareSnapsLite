#ifndef PROFILE_HPP
#define PROFILE_HPP

#include "Person.hpp"

class Profile
{
public:
	virtual unsigned int createProfile(Person&) = 0;
	virtual void deleteProfile(const unsigned int&) = 0;
};

#endif //PROFILE_HPP