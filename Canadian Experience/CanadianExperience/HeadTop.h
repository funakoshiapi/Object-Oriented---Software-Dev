/**
 * \file HeadTop.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once
#include "ImageDrawable.h"
#include "AnimChannelPoint.h"



/**
* Characters head functionality.
*/
class CHeadTop :
	public CImageDrawable
{
public:

	/** Set the location for the center of the eyes
	*
	*\param &name
	*
	*\param &filename
	*
	*/
	 CHeadTop(const std::wstring &name, const std::wstring &filename);

	/** Set the location for the center of the eyes
	*
	*\ return
	*
	*/
	virtual ~CHeadTop();

	/** Set the location for the center of the eyes
	*
	*\param graphics
	*
	*\param p1
	*
	*\param p2
	*
	*/
	void DrawEyebrow(Gdiplus::Graphics * graphics, Gdiplus::Point p1, Gdiplus::Point p2);


	/// Set the location for the center of the eyes
	/// \param graphics
	/// \param p1
	void DrawEye(Gdiplus::Graphics * graphics, Gdiplus::Point p1);

	/// Set the location for the center of the eyes
	/// \param graphics
	void Draw(Gdiplus::Graphics * graphics);

	/** Default constructor disabled */
	CHeadTop() = delete;
	/** Copy constructor disabled */
	CHeadTop(const CHeadTop &) = delete;
	/** Assignment operator disabled */
	void operator=(const CHeadTop &) = delete;

	/// Is this drawable moveable?
	/// \returns true
	virtual bool IsMovable() override { return true; }

	/** Get a pointer to the left eye bitmap
	* \returns Pointers to the left eye bitmap
	*/
	CRotatedBitmap *GetLeftEye() { return &mLeftEye; }

	/** Get a pointer to the left eye bitmap
	* \returns Pointers to the left eye bitmap
	*/
	CRotatedBitmap *GetRightEye() { return &mRightEye; }

	/** Set the location for the center of the eyes
	* \param center New eyes center location
	*/
	void SetEyesCenter(Gdiplus::Point center) { mEyesCenter = center; }

	/** Get the eyes center location
	* \returns Eyes center location
	*/
	Gdiplus::Point GetEyesCenter() const { return mEyesCenter; }

	/** Set the distance beTweening the eyes
	* \param d Distance beTweening the eyes in pixels
	*/
	void SetInterocularDistance(int d) { mInterocularDistance = d; }

	/** Get the distance beTweening the eyes
	* \returns Distance beTweening the eyes in pixels
	*/
	int GetInterocularDistance() const { return mInterocularDistance; }

	/** Get the distance beTweening the eyes
	* \returns
	*/
	virtual void SetKeyframe();
	/** Get the distance beTweening the eyes
	* \returns
	*/
	virtual void GetKeyframe();

	/** Get the distance beTweening the eyes
	*\param timeline
	*\returns
	*/
	virtual void SetTimeline(CTimeline * timeline);

private:

	/// private
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	/// private
	CRotatedBitmap mLeftEye;      
	/// private
	CRotatedBitmap mRightEye;

	/// private							
	Gdiplus::Point mEyesCenter = Gdiplus::Point(55, 79);

	/// private
	int mInterocularDistance = 27;
	/// private
	CAnimChannelPoint mChannel;
};

