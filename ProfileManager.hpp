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

	unsigned int generateProfileID()
	{
		// Initialize random seed
	    srand(std::time(0));

	    // Generate random number between 1 and 1000
	    int randomNumber = rand() % 1000 + 1;

	    return randomNumber;
	}

public:

	static ProfileManager* getProfileMagangerInstance()
	{
		if(ProfileInstance == nullptr)
		{
			ProfileInstance = new ProfileManager();
		}

		return ProfileInstance;
	}

	void notifyFollowers(Person&, const string&);

	void followProfile(Person&, Person&);

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
				user.profileID = tempID;
			}
		}while(isIDFound);

		cout<<"User profile created successfully with profile id = "<<tempID<<endl;
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


#endif //PROFILE_MANAGER_HPP