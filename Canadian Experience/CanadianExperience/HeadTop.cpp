/**
 * \file HeadTop.cpp
 *
 * \author Funakoshi Silva
 *
 */

#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace Gdiplus;


CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) :
	CImageDrawable(name, filename)
{
}

/**
 * Destructor
 */
CHeadTop::~CHeadTop()
{
}



/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
* Draw an eyebrow, automatically transforming the points
*
* Draw a line from (x1, y1) to (x2, y2) after transformation
* to the local coordinate system.
*/
void CHeadTop::DrawEyebrow(Gdiplus::Graphics *graphics,
	Gdiplus::Point p1, Gdiplus::Point p2)
{
	Point eb1 = TransformPoint(p1);
	Point eb2 = TransformPoint(p2);

	Pen eyebrowPen(Color::Black, 2);
	graphics->DrawLine(&eyebrowPen, eb1, eb2);
}

/** Draw an eye using an Ellipse
*/
void CHeadTop::DrawEye(Gdiplus::Graphics *graphics, Gdiplus::Point p1)
{
	SolidBrush brush(Color::Black);

	Point e1 = TransformPoint(p1);

	float wid = 15.0f;
	float hit = 20.0f;

	auto state = graphics->Save();
	graphics->TranslateTransform((float)e1.X, (float)e1.Y);
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}

/**
* Draw the head
* graphics Graphics context to draw on
*/
void CHeadTop::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);

	int d2 = mInterocularDistance / 2;

	
	int rightX = mEyesCenter.X - d2;
	int leftX = mEyesCenter.X + d2;


	int eyeY = mEyesCenter.Y;

	DrawEyebrow(graphics, Point(rightX - 10, eyeY - 16), Point(rightX + 4, eyeY - 18));
	DrawEyebrow(graphics, Point(leftX - 4, eyeY - 20), Point(leftX + 9, eyeY - 18));

	if (mLeftEye.IsLoaded() && mRightEye.IsLoaded())
	{
		// Determine the point on the screen were we will draw the left eye
		Point leye = TransformPoint(Point(leftX, eyeY));
		// And draw the bitmap there
		mLeftEye.DrawImage(graphics, leye, mPlacedR);

		// Repeat the process for the right eye.
		Point reye = TransformPoint(Point(rightX, eyeY));
		mRightEye.DrawImage(graphics, reye, mPlacedR);
	}
	else
	{
		DrawEye(graphics, Point(leftX, eyeY));
		DrawEye(graphics, Point(rightX, eyeY));
	}
}

/** Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
	CDrawable::SetKeyframe();

	mChannel.SetKeyframe(GetPosition());
}

/** Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
	CDrawable::GetKeyframe();

	if (mChannel.IsValid())
		SetPosition(mChannel.GetPoint());
}

/** Addchannel

*/
void CHeadTop::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);

	timeline->AddChannel(&mChannel);
}