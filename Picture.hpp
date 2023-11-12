#ifndef PICTURE_HPP
#define PICTURE_HPP

#include<string>

#include "Person.hpp"

using namespace std;

class PictureManager;

class Picture
{
private:
	string link;
	int likes;
	int dislikes;
	Person owner;

	void setPictureLink(const string&);
	void setLikes(const int&);
	void setDisLikes(const int&);

	friend class PictureManager;
public:
	Picture(const string& link, Person owner): link(link), owner(owner), likes(0), dislikes(0) {}

	string getPictureLink();
	int getLikes();
	int getDislikes();
};

#endif //PICTURE_HPP