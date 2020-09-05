/**
 * \file Timeline.cpp
 *
 * \author Funakoshi Silva
 */

#include "pch.h"
#include "AnimChannel.h"
#include "Timeline.h"

/**
 * Constructor
 */
CTimeline::CTimeline()
{
}


/**
 * Destructor
 */
CTimeline::~CTimeline()
{
}


/**
 * Add a channel 
 * \param channel
 */
void CTimeline::AddChannel(CAnimChannel * channel)
{
	mChannels.push_back(channel);
	channel->SetTimeline(this);
}

/**
 * Delete the keyframe set at the current frame in this timeline
 */
void CTimeline::DeleteKeyframe()
{
	for (auto c : mChannels)
	{
		c->DeleteKeyframe();
	}
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
*/
void CTimeline::SetCurrentTime(double t)
{
	mCurrentTime = t;

	for (auto channel : mChannels)
	{
		channel->SetFrame(GetCurrentFrame());
	}
}