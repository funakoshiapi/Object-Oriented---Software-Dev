/**
 * \file Drawable.cpp
 *
 * \author Funakoshi Silva
 */


#include "pch.h"
#include <cmath>
#include "Actor.h"
#include "Timeline.h"
#include "Drawable.h"


/** Constructor

*/
CDrawable::CDrawable(const std::wstring &name) : mName(name)
{

}

/** Destructor */
CDrawable::~CDrawable()
{
}


/**
* Set the actor using this drawable
* \param actor Actor using this drawable
*/
void CDrawable::SetActor(CActor *actor)
{
	mActor = actor;

	// Set the channel name
	mChannel.SetName(actor->GetName() + L":" + mName);
}


/**
*  drawable relative to parent

*/
void CDrawable::Place(Gdiplus::Point offset, double rotate)
{
	// Combine the transformation 

	mPlacedPosition = offset + RotatePoint(mPosition, rotate);
	mPlacedR = mRotation + rotate;

	// Update our children
	for (auto drawable : mChildren)
	{
		drawable->Place(mPlacedPosition, mPlacedR);
	}
}

/**
* Add child drawable

*/
void CDrawable::AddChild(std::shared_ptr<CDrawable> child)
{
	mChildren.push_back(child);
	child->SetParent(this);

}



/**
* Move drawable

*/
void CDrawable::Move(Gdiplus::Point delta)
{
	if (mParent != nullptr)
	{
		mPosition = mPosition + RotatePoint(delta, -mParent->mPlacedR);
	}
	else
	{
		mPosition = mPosition + delta;
	}
}

/** Rotate a point by a given angle.

*/
Gdiplus::Point CDrawable::RotatePoint(Gdiplus::Point point, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	return Gdiplus::Point(int(cosA * point.X + sinA * point.Y),
		int(-sinA * point.X + cosA * point.Y));
}

/** Add the channels for this drawable to a timeline

*/
void CDrawable::SetTimeline(CTimeline *timeline)
{
	timeline->AddChannel(&mChannel);
}

/** Set the keyframe 
*/
void CDrawable::SetKeyframe()
{
	mChannel.SetKeyframe(mRotation);
}

/** Get the current channel from the animation system.
*/
void CDrawable::GetKeyframe()
{
	if (mChannel.IsValid())
		mRotation = mChannel.GetAngle();
}
