#ifndef PICTURE_MANAGER_HPP
#define PICTURE_MANAGER_HPP

#include<map>
#include<vector>

#include "Picture.hpp"
#include "ProfileManager.hpp"
#include "Person.hpp"

using namespace std;

class PictureManager
{
private:
	static PictureManager* picManagerInstance;
	map<Person, vector<Picture>> userPictureDatabase;

	PictureManager();
public:
	
	static PictureManager* getPictureManagerInstance()
	{
		if(picManagerInstance == nullptr)
		{
			return new PictureManager();
		}
		return picManagerInstance;
	}
	
	void uploadPicture(Person, Picture);
	void deletePicture(Person&, Picture&);
	void reactPicture(Picture&, bool);
};

PictureManager* PictureManager::picManagerInstance = nullptr;

#endif //PICTURE_MANAGER_HPP