#include "Picture.hpp"

string Picture::getPictureLink()
{
	return this->link;
}

int Picture::getLikes()
{
	return this->likes;
} 

int Picture::getDislikes()
{
	return this->dislikes;
}

void Picture::setPictureLink(const string& link)
{
	this->link = link;
}

void Picture::setLikes(const int& numLikes)
{
	this->likes = numLikes;
}

void Picture::setDisLikes(const int& numDislikes)
{
	this->dislikes = numDislikes;
}
