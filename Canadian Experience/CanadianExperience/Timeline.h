/**
 * \file Timeline.h
 *
 * \author Funakoshi Silva
 *
 *
 * 
 */

#pragma once
#include <vector>
#include "Drawable.h"

class CAnimChannel;

/** This class implements a timeline that manages the animation
*
* A timeline consists of animation channels for different parts of our
* actors, each with keyframes that set the position, orientation, etc
* at that point in time. */

class CTimeline
{
public:
	CTimeline();


	virtual ~CTimeline();

	/** \brief Copy constructor disabled */
	CTimeline(const CTimeline &) = delete;


	/** \brief Assignment operator disabled */
	void operator=(const CTimeline &) = delete;

	/** Get the number of frames in the animation
	* \returns Number of frames in the animation
	*/
	int GetNumFrames() const { return mNumFrames; }

	/** Set the number of frames in the animation
	* \param numFrames Number of frames in the animation
	*/
	void SetNumFrames(int numFrames) { mNumFrames = numFrames; }

	/** Get the frame rate
	* \returns Animation frame rate in frames per second
	*/
	int GetFrameRate() const { return mFrameRate; }

	/** Set the frame rate
	* \param frameRate Animation frame rate in frames per second
	*/
	void SetFrameRate(int frameRate) { mFrameRate = frameRate; }

	/** Get the current time
	* \returns Current animation time in seconds
	*/
	double GetCurrentTime() const { return mCurrentTime; }




	/** Set the current time
	* \param t new current animation time in seconds
	*/
	void SetCurrentTime(double t);

   
	//void SetCurrentTime(double currentTime) { mCurrentTime = currentTime; }



	/** Get the current frame.
	*
	* This is the frame associated with the current time
	* \returns Current frame
	*/

	int GetCurrentFrame() const { return int( mCurrentTime * mFrameRate) ; }

	/** Get the animation duration
	* \returns Animation duration in seconds
	*/

	void AddChannel(CAnimChannel * channel);


	void DeleteKeyframe();



	/// Draw the object
	/// \return
	double GetDuration() const { return double(mNumFrames) / mFrameRate; }

private:

	/// animation channels
	std::vector<CAnimChannel*> mChannels;


	/// frame rate
	int mFrameRate = 30;

	/// current time
	double mCurrentTime = 0;

	/// number of frames
	int mNumFrames = 300;


};

