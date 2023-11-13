#ifndef PICTURE_MANAGER_HPP
#define PICTURE_MANAGER_HPP

#include<map>
#include<vector>

#include "Picture.hpp"
#include "Person.hpp"
#include "ProfileManager.hpp"

using namespace std;

class PictureManager
{
private:
	static PictureManager* picManagerInstance;
	map<Person, vector<Picture>> userPictureDatabase;
	ProfileManager* profileManager;
	PictureManager() {}
public:
	
	static PictureManager* getPictureManagerInstance()
	{
		if(picManagerInstance == nullptr)
		{
			picManagerInstance = new PictureManager();
		}
		return picManagerInstance;
	}
	
	void uploadPicture(Person&, Picture&);
	void deletePicture(Person&, Picture&);
	void reactPicture(Picture&, bool);
};

#endif //PICTURE_MANAGER_HPP