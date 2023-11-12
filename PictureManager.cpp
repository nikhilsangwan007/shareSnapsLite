#include<iostream>
#include<string>
#include<algorithm>

#include "PictureManager.hpp"

PictureManager* PictureManager::picManagerInstance = nullptr;

void PictureManager::uploadPicture(Person& user, Picture& pic)
{
	if(user.getProfileID() == 0)
	{
		cout<<"user not found!\n";
	}
	userPictureDatabase[user].push_back(pic);
	cout<<"Picture uploaded successfully\n";

	profileManager = ProfileManager::getProfileMagangerInstance();
	cout<<"upload profileManager : "<<profileManager<<endl;
	profileManager->notifyFollowers(user, pic.getPictureLink());
}

void PictureManager::deletePicture(Person& user, Picture& pic)
{
	if(userPictureDatabase.find(user) == userPictureDatabase.end())
	{
		cout<<"User does not exist!\n";
		return;
	}

	vector<Picture> pictureList = userPictureDatabase[user];
	int listSize = pictureList.size();
	int offset = -1;
	for(int i=0; i<listSize; ++i)
	{
		if(pic.getPictureLink() == pictureList[i].getPictureLink())
		{
			//picture found
			offset = i;
		}
	}

	if(offset == -1)
	{
		cout<<"Picture not found!\n";
		return;
	}
	//swap offset and last place
	swap(userPictureDatabase[user][offset], userPictureDatabase[user][listSize - 1]);

	//remove the last place
	userPictureDatabase[user].pop_back();

	cout<<"Picture successfully deleted!\n";

}
void PictureManager::reactPicture(Picture& pic, bool action)
{
	if(action == false)
	{
		pic.setDisLikes(pic.getDislikes()+1);
	}
	else
	{
		pic.setLikes(pic.getLikes()+1);
	}
}