/**
* \file AnimChannelPoint.h
*
* \author Funakoshi Silva
*
*/

#pragma once
#include "AnimChannel.h"

/**
* Animation channel for Points.
*/
class CAnimChannelPoint : public CAnimChannel
{
public:
	CAnimChannelPoint();
	virtual ~CAnimChannelPoint();

	/** \brief Copy constructor disabled */
	CAnimChannelPoint(const CAnimChannelPoint &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelPoint &) = delete;

	/** Get the Point
	* \returns mPoint Point
	*/
	Gdiplus::Point GetPoint() { return mPoint; }



	/**
	* Set a keyframe
	*
	* allocates a new keyframe
	*\param point
	*/
	void SetKeyframe(Gdiplus::Point point);


	/** Class that represents a keyframe for an Point */
	class KeyframePoint : public CAnimChannel::Keyframe
	{
	public:

		/** Constructor
		* \param channel
		* \param point  */
		KeyframePoint(CAnimChannelPoint *channel, Gdiplus::Point point) :
			Keyframe(channel), mChannel(channel), mPoint(point) {}

		/** Get the Point
		*\returns mPoint Point
		*/
		Gdiplus::Point GetPoint() { return mPoint; }

		/** 
		Use this keyframe as the Point
		*\returns
		*/
		virtual void angle() override { mChannel->mPoint = mPoint; }

		/** Use this keyframe as keyframe 1
		*\returns
		*/
		virtual void first() override { mChannel->mKeyframe1 = this; }

		/** Use this keyframe as keyfraem 2
		*\returns
		*/
		virtual void second() override { mChannel->mKeyframe2 = this; }

	

	private:
		/// private
		CAnimChannelPoint* mChannel;
		/// private
		Gdiplus::Point mPoint = Gdiplus::Point(0,0);

		
	};

protected:
	
	/** Get the Point
	*\param t
	*/
	void Tweening(double t);

private:

	/// member private
	Gdiplus::Point mPoint = Gdiplus::Point(0,0);

	/// member private
	KeyframePoint *mKeyframe1 = nullptr;

	/// member private
	KeyframePoint *mKeyframe2 = nullptr;
};

