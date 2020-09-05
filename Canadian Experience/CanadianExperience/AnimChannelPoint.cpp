/**
 * \file AnimChannelPoint.cpp
 *
 * \author Funakoshi Silva
 */

#include "pch.h"
#include "AnimChannelPoint.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CAnimChannelPoint::CAnimChannelPoint()
{
}


/**
 * Destructor
 */
CAnimChannelPoint::~CAnimChannelPoint()
{
}

/**
* Set a keyframe
*
* allocates a new keyframe
*\param point
*/
void CAnimChannelPoint::SetKeyframe(Gdiplus::Point point)
{
	// Create a keyframe 
	
	shared_ptr<KeyframePoint> keyframe =
		make_shared<KeyframePoint>(this, point);

	// Insert in collection
	InsertKeyframe(keyframe);
}
 

void CAnimChannelPoint::Tweening(double t)
{

	Point a = mKeyframe1->GetPoint();
	Point b = mKeyframe2->GetPoint();

	Point c(int(a.X + t * (b.X - a.X)), int(a.Y + t * (b.Y - a.Y)));

	mPoint = c;
}