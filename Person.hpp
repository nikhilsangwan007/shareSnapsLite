#ifndef PERSON_HPP
#define PERSON_HPP

#include<iostream>
#include<string.h>

#include "Observer.hpp"

using namespace std;

class Person: public Observer {
private:
	string name;
	string email;
	unsigned int profileID;

public:
	Person(){}
	Person(string name, string email): name(name), email(email), profileID(0) {}

	void setName(const string&);
	string getName();
	void setEmail(const string&);
	unsigned int getProfileID();

	void update(const string& picLink, const unsigned int& profileID) override
	{
		cout<<"profileID : "<< profileID << "post a new picture : "<<picLink<<endl;
	}

    // Define the less-than operator
    bool operator<(const Person& other) const {
        return profileID < other.profileID;
    }

    // Define the equality operator
    bool operator==(const Person& other) const {
        return profileID == other.profileID;
    }
};

#endif //PERSON_HPP