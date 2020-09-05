/**
 * \file AnimChannelAngle.cpp
 *
 * \author Funakoshi Silva
 */

#include "pch.h"
#include "AnimChannelAngle.h"

using namespace std;

/**
 * Constructor
 */
CAnimChannelAngle::CAnimChannelAngle()
{
}


/**
 * Destructor
 */
CAnimChannelAngle::~CAnimChannelAngle()
{
}

/**
* Set a keyframe
*/
void CAnimChannelAngle::SetKeyframe(double angle)
{
	// Create a keyframe 
	
	shared_ptr<KeyframeAngle> keyframe =
		make_shared<KeyframeAngle>(this, angle);
	
	// Insert in collection
	InsertKeyframe(keyframe);
}

/**
 * Compute an angle that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframeAngle. This function does the
 * tweening.
 *\param t 
 */
void CAnimChannelAngle::Tweening(double t)
{
	mAngle = mKeyframe1->GetAngle() * (1 - t) + mKeyframe2->GetAngle() * t;
}