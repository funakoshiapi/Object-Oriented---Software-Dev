/**
 * \file Actor.h
 *
 * \author Funakoshi Silva
 *
 */
 

#pragma once

#include "Drawable.h"
#include "AnimChannelPoint.h"
#include <string>
#include <memory>
#include <vector>

class CPicture;


 /**
 * Class for actors in our drawings.l
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class CActor
{
public:
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;

	/// ste picture
	/// \return
	virtual ~CActor();

	/// ste picture
	/// \param root
	void SetRoot(std::shared_ptr<CDrawable> root);

	/// ste picture
	/// \param graphics
	void Draw(Gdiplus::Graphics *graphics);

	/// ste picture
	/// \param pos
	/// \return
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);

	/// ste picture
	/// \param drawable
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }

	/// ste picture
	/// \param picture
	void SetPicture(CPicture * picture);

	/// ste picture
	/// \return
	void SetKeyframe();
	/// ste picture
	/// \return
	void GetKeyframe();

	/// ste picture
	/// \param timeline
	void SetTimeline(CTimeline * timeline);

	/** The actor picture
	* \returns mPicture actor's picture */
	CPicture * GetPicture() { return mPicture; }

	/** The position animation channel
	* \returns Pointer to animation channel */
	CAnimChannelPoint *GetPositionChannel() { return &mChannel; }

private:
	/// Name of the actor
	std::wstring mName;

	/// actor enabled
	bool mEnabled = true;

	/// Position of the actor
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// actor clickable
	bool mClickable = true;

	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;

	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

	/// The picture for this actor
	CPicture *mPicture = nullptr;

	/// The animation channel for animating the point of this actor
	CAnimChannelPoint mChannel;
};

