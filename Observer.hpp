#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class Observer
{
public:
	virtual void update(const std::string&, const unsigned int&) = 0;
};

#endif //OBSERVER_HPP