#include<iostream>
#include<string>

#include "PictureManager.hpp"

void PictureManager::uploadPicture(Person user, Picture pic)
{
	auto itr = userPictureDatabase.find(user);
	if(itr == userPictureDatabase.end());
	{
		cout<<"User does not exist!\n";
		return;
	}

	userPictureDatabase[user].push_back(pic);
}
void PictureManager::deletePicture(Person& user, Picture& pic)
{
	if(userPictureDatabase.find(user) == userPictureDatabase.end())
	{
		cout<<"User does not exist!\n";
		return;
	}

	vector<Picture> picturesToRemove;
	for(Picture picture: userPictureDatabase[user])
	{
		if(picture.getPictureLink() == pic.getPictureLink())
		{
			picturesToRemove.push_back(picture);
		}
	}
	// Then, remove the pictures
	// for (const Picture& picture : picturesToRemove) {
	//     auto& pictures = userPictureDatabase[user];
	//     auto newEnd = remove(pictures.begin(), pictures.end(), picture);
	//     pictures.erase(newEnd, pictures.end());
	// }
	
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