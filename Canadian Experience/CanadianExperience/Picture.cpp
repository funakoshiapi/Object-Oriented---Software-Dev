/**
 * \file Picture.cpp
 *
 * \author Funakoshi Silva
 *
 */

#include "pch.h"
#include "PictureObserver.h"
#include "Picture.h"


using namespace Gdiplus;

/**
* Constructor
*/
CPicture::CPicture()
{
}


/**
 * Destructor
 */
CPicture::~CPicture()
{
}

/** Add an observer to this picture.
* \param observer The observer to add
*/
void CPicture::AddObserver(CPictureObserver *observer)
{
	mObservers.push_back(observer);
}

/** Remove an observer from this picture
* \param observer The observer to remove
*/
void CPicture::RemoveObserver(CPictureObserver *observer)
{
	auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
	if (loc != std::end(mObservers))
	{
		mObservers.erase(loc);
	}
}

/** Update observers 
*/
void CPicture::UpdateObservers()
{
	for (auto observer : mObservers)
	{
		observer->UpdateObserver();
	}
}

/** Draw picture
* \param graphics
*/
void CPicture::Draw(Gdiplus::Graphics *graphics)
{
	for (auto actor : mActors)
	{
		actor->Draw(graphics);
	}
}


/**
 * Adds actor 
 * \param actor 
 */
void CPicture::AddActor(std::shared_ptr<CActor> actor)
{
	mActors.push_back(actor);
	actor->SetPicture(this);
}

/** Set animation time
*/
void CPicture::SetAnimationTime(double time)
{
	mTimeline.SetCurrentTime(time);

	for (auto actor : mActors)
	{
		actor->GetKeyframe();
	}

	UpdateObservers();

}