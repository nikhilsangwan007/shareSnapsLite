#ifndef PROFILE_MANAGER_HPP
#define PROFILE_MANAGER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Profile.hpp"
#include "Person.hpp"

class ProfileManager: public Profile
{
private:
	static ProfileManager* ProfileInstance;

	map<unsigned int, Person> customerDatabase;
	map<Person, vector<Person>> followerList;

	ProfileManager() {}

	unsigned int generateProfileID();

public:

	static ProfileManager* getProfileMagangerInstance()
	{
		if(ProfileInstance == nullptr)
		{
			return new ProfileManager();
		}

		return ProfileInstance;
	}

	void actionProfile(const unsigned int&, const int&);

	void notifyFollowers(Person&, const string&);

	void followProfile(unsigned int&, Person&);

	unsigned int createProfile(Person& user) override
	{
		unsigned int userProfileID = user.getProfileID();
		if(userProfileID != 0)
		{
			cout<<"User already exist!\n";
			return userProfileID;
		}

		bool isIDFound;
		unsigned int tempID;
		do
		{
			tempID = generateProfileID();
			isIDFound = false;
			if(customerDatabase.find(tempID) != customerDatabase.end())
			{
				isIDFound = true;
			}
			else
			{
				customerDatabase[tempID] = user;
			}
		}while(isIDFound);

		return tempID;
		
	}
	void deleteProfile(const unsigned int& profileID) override
	{
		if(profileID == 0)
		{
			cout<<"Invalid profileID\n";
		}

		customerDatabase.erase(profileID);
		cout<<"Profile deleted successfully\n";
	}
};

ProfileManager* ProfileManager::ProfileInstance = nullptr;

#endif //PROFILE_MANAGER_HPP