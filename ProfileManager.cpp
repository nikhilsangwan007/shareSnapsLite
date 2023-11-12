#include<bits/stdc++.h>

#include <iostream>
#include "ProfileManager.hpp"

void ProfileManager::actionProfile(const unsigned int& profileID, const int& action)
{

}

unsigned int generateProfileID()
{
	// Initialize random seed
    srand(std::time(0));

    // Generate random number between 1 and 1000
    int randomNumber = rand() % 1000 + 1;

    return randomNumber;
}

void ProfileManager::followProfile(unsigned int& profileID, Person& user)
{
	if(customerDatabase.find(profileID) == customerDatabase.end())
	{
		cout<<"User not Found!\n";
	}

	Person person = customerDatabase[profileID];
	
	if(followerList.find(person) != followerList.end())
	{
		for(Person follower: followerList[person])
		{
			if(user.getProfileID() == follower.getProfileID())
			{
				cout<<"Already a follower!\n";
				return;
			}
		}
	}

	followerList[person].push_back(user);
	return;
}

void ProfileManager::notifyFollowers(Person& user, const string& pictureLink)
{
	if(followerList.find(user) != followerList.end())
	{
		for(Person follower: followerList[user])
		{
			follower.update(pictureLink, user.getProfileID());
		}
	}
}