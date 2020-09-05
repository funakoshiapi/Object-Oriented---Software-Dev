/**
 * \file AnimChannelAngle.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once
#include "AnimChannel.h"

 /**
  * Class for drawable elements of our picture
  *
  * A drawable is one part of an actor. Drawable parts can be moved
  * independently.
  */
class CAnimChannelAngle : public CAnimChannel
{
public:
	CAnimChannelAngle();
	virtual ~CAnimChannelAngle();

	/** \brief Copy constructor disabled */
	CAnimChannelAngle(const CAnimChannelAngle &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAnimChannelAngle &) = delete;

	/** Get the angle
	* \returns mAngle angle
	*/
	double GetAngle() { return mAngle; }

	/**
	* Set a keyframe
	*
	* This function allocates a new keyframe and sends it to
	*\param angle
	*/
	void SetKeyframe(double angle);


	/** Class that represents a keyframe for an angle */
	class KeyframeAngle : public CAnimChannel::Keyframe
	{
	public:

		/** Constructor
		* \param channel 
		* \param angle */
		KeyframeAngle(CAnimChannelAngle *channel, double angle) :
			Keyframe(channel), mChannel(channel), mAngle(angle) {}

		/** Get the angle
		* \returns mAngle angle
		*/
		double GetAngle() { return mAngle; }

		/** Get the angle
		* \returns
		*/
		virtual void first() override { mChannel->mKeyframe1 = this; }

		/** Get the angle
		* \returns
		*/
		virtual void second() override { mChannel->mKeyframe2 = this; }

		/** Get the angle
		* \returns
		*/
		virtual void angle() override { mChannel->mAngle = mAngle; }

	private:

		/// angle for the keyframe
		double mAngle = 0;

		/// The channel this keyframe is associated with
		CAnimChannelAngle *mChannel;
	};

protected:
/**
 * Compute an angle that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframeAngle. This function does the
 * tweening.
 *\param t
 */
	void Tweening(double t);

private:

	/// angle for the channel
	double mAngle = 0;

	/// The first angle keyframe
	KeyframeAngle *mKeyframe1 = nullptr;

	/// The second angle keyframe
	KeyframeAngle *mKeyframe2 = nullptr;
};

