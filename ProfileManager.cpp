#include<bits/stdc++.h>

#include <iostream>
#include "ProfileManager.hpp"

ProfileManager* ProfileManager::ProfileInstance = nullptr;

void ProfileManager::followProfile(Person& user, Person& follower)
{
	if(customerDatabase.find(user.getProfileID()) == customerDatabase.end())
	{
		cout<<"User not Found!\n";
	}
	
	if(this->followerList.find(user) != this->followerList.end())
	{
		for(Person& subscriber: this->followerList[user])
		{
			if(subscriber.getProfileID() == follower.getProfileID())
			{
				cout<<"Already a follower!\n";
				return;
			}
		}
	}

	this->followerList[user].push_back(follower);
	cout<<"follower list size = "<<this->followerList.size()<<endl;
	cout<<"Follower added successfully\n Follower list of user : "<<user.getProfileID()<<endl;

	for(auto follow: this->followerList[user])
	{
		cout<<"Follower : "<<follow.getProfileID()<<endl;
	}
	return;
}

void ProfileManager::notifyFollowers(Person& user, const string& pictureLink)
{
	cout<<"notifying followers of user :"<<user.getProfileID()<<endl;
	cout<<"follower list size = "<<this->followerList.size()<<endl;
	if(this->followerList.find(user) != this->followerList.end())
	{
		for(Person& follower: this->followerList[user])
		{
			cout<<"sending notification to follower: "<<follower.getProfileID()<<endl;
			follower.update(pictureLink, user.getProfileID());
		}
	}
}