/**
* \file PictureObserver.cpp
*
* \author Funakoshi Silva
*
* Functionality for
* observer.
*/

#include "pch.h"
#include "PictureObserver.h"
#include "Picture.h"

/** Constructor */
CPictureObserver::CPictureObserver()
{
}


/** Destructor */
CPictureObserver::~CPictureObserver()
{
	if (mPicture != nullptr)
	{
		mPicture->RemoveObserver(this);
	}
}

/** Set the picture 
* \param picture */
void CPictureObserver::SetPicture(std::shared_ptr<CPicture> picture)
{
	mPicture = picture;
	mPicture->AddObserver(this);
}