#include <iostream>

#include "Person.hpp"
#include "Picture.hpp"
#include "PictureManager.hpp"
#include "ProfileManager.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Person person1("Nikhil", "nikhil.sangwan95@gmail.com");
	Person person2("Mota", "mota.sangwan95@gmail.com");
	Person person3("Roy", "mota1.sangwan95@gmail.com");
	Person person4("teju", "mota2.sangwan95@gmail.com");
	ProfileManager* profileManager = ProfileManager::getProfileMagangerInstance();
	cout<<"profileManager : "<<profileManager<<endl;
	PictureManager* pictureManager = PictureManager::getPictureManagerInstance();

	profileManager->createProfile(person1);
	profileManager->createProfile(person2);
	profileManager->createProfile(person3);
	profileManager->createProfile(person4);

	unsigned int profile_id = person1.getProfileID();
	profileManager->followProfile(person1, person2);
	profileManager->followProfile(person1, person3);
	profileManager->followProfile(person1, person4);

	Picture picture1("Picture_link", person1);
	pictureManager->uploadPicture(person1, picture1);

	return 0;
}