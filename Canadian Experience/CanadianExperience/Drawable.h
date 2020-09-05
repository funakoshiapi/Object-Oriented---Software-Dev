/**
 * \file Drawable.h
 *
 * \author Funakoshi Silva
 *
 */



#pragma once

#include <memory>
#include <string>
#include <vector>
#include "AnimChannelAngle.h"

class CActor;
class CTimeline;

/**
* Abstract base class for drawable elements of our picture
*/
class CDrawable
{
public:
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;
	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;

	void SetActor(CActor *actor);
	
	/// Draw the object
	/// \param graphics The GDI+ graphics context to draw on
	/// \return
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;

	/// Draw the object
	/// \param offset The GDI+ graphics context to draw on
	/// \param rotate The GDI+ graphics context to draw on
	/// \return
	void Place(Gdiplus::Point offset, double rotate);

	/// Draw the object
	/// \param child The GDI+ graphics context to draw on
	/// \return
	void AddChild(std::shared_ptr<CDrawable> child);

	/// Check if we clicked on the object
	/// \param pos the Point clicked
	/// \return True if hit
	virtual bool HitTest(Gdiplus::Point pos) = 0;

	/// Check if the object is movable
	/// \return True if movable
	virtual bool IsMovable() { return false; }

	/// Draw the object
	/// \param delta offset The GDI+ graphics context to draw on
	/// \return
	void Move(Gdiplus::Point delta);

	/// Draw the object
	/// \param pos The GDI+ graphics context to draw on
	/// \return
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Set the drawable position
	* \param x The new drawable position x value
	* \param y The new drawable position y value
	*/
	void SetPosition(int x, int y) { SetPosition(Gdiplus::Point(x, y)); }

	/** Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }


	/** Set the parent
	* \param parent The parent drawable */
	void SetParent(CDrawable * parent) { mParent = parent; }

	/** Get the parent
	* \returns mParent pointer to the parent drawable */
	CDrawable * GetParent() const { return mParent; }

	/// Draw the object
	/// \param timeline offset The GDI+ graphics context to draw on
	/// \return
	virtual void SetTimeline(CTimeline * timeline);

	/// Draw the object
	/// \return
	virtual void SetKeyframe();

	/// Draw the object
	/// \return
	virtual void GetKeyframe();
	
	/** The angle animation channel
	* \returns Pointer to animation channel */
	CAnimChannelAngle *GetAngleChannel() { return &mChannel; }

protected:

	/// Draw the object
	/// \param name offset The GDI+ graphics context to draw on
	/// \return
	CDrawable(const std::wstring &name);


	/// Draw the object
	/// \param point offset The GDI+ graphics context to draw on
	/// \param angle
	/// \return
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;

	/// The actor using this drawable
	CActor *mActor = nullptr;

	/// Children drawables
	std::vector<std::shared_ptr<CDrawable> > mChildren;

	/// Parent drawable
	CDrawable * mParent = nullptr;

	/// The animation channel for animating the angle of this drawable
	CAnimChannelAngle mChannel;
};

