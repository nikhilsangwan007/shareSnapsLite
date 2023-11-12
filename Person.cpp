#include<bits/stdc++.h>
#include "Person.hpp"

void Person::setName(const string& name){
	this->name = name;
}

string Person::getName(){
	return name;
}

void Person::setEmail(const string& email){
	this->email = email;
}

unsigned int Person::getProfileID(){
	if(this->profileID == 0)
	{
		return 0;
	}
	return this->profileID;
}
