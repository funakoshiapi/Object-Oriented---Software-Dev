/**
 * \file Actor.cpp
 *
 * \author Funakoshi Silva
 */



#include "pch.h"
#include "Actor.h"
#include "Picture.h"

using namespace Gdiplus;


/** Constructor
* \param name The actor name */
CActor::CActor(const std::wstring &name) : mName(name)
{
	// Set the channel name
	mChannel.SetName(mName);
}


/** Destructor */
CActor::~CActor()
{
}


/** Set the root drawable for the actor
 */
void CActor::SetRoot(std::shared_ptr<CDrawable> root)
{
	mRoot = root;
}

/** Draw this actor
 */
void CActor::Draw(Gdiplus::Graphics *graphics)
{
	// Don't draw if not enabled
	if (!mEnabled)
		return;


	if (mRoot != nullptr)
		mRoot->Place(mPosition, 0);

	for (auto drawable : mDrawablesInOrder)
	{
		drawable->Draw(graphics);
	}
}


/**
Test mouse click.
*/
std::shared_ptr<CDrawable> CActor::HitTest(Gdiplus::Point pos)
{

	if (!mClickable || !mEnabled)
		return nullptr;

	
	for (auto d = mDrawablesInOrder.rbegin(); d != mDrawablesInOrder.rend(); d++)
	{
		auto drawable = *d;
		if (drawable->HitTest(pos))
			return drawable;
	}

	return nullptr;
}


/**
drawable to this actor
*/
void CActor::AddDrawable(std::shared_ptr<CDrawable> drawable)
{
	mDrawablesInOrder.push_back(drawable);
	drawable->SetActor(this);
}

void CActor::SetPicture(CPicture *picture)
{
	mPicture = picture;

	
	for (auto drawable : mDrawablesInOrder)
	{
		drawable->SetTimeline(mPicture->GetTimeline());
	}
	SetTimeline(mPicture->GetTimeline());
}
/** Set a keyframe on an actor.
*/
void CActor::SetKeyframe()
{
	for (auto drawable : mDrawablesInOrder)
	{
		drawable->SetKeyframe();
	}

	mChannel.SetKeyframe(mPosition);
}

/**  Get keyframe .
*/
void CActor::GetKeyframe()
{
	for (auto drawable : mDrawablesInOrder)
	{
		drawable->GetKeyframe();
	}

	if (mChannel.IsValid())

		mPosition = mChannel.GetPoint();
}

/** Add channels 
*/
void CActor::SetTimeline(CTimeline *timeline)
{
	timeline->AddChannel(&mChannel);
}
