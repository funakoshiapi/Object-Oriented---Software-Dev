/**
 * \file AnimChannel.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once

#include <string>
#include <memory>
#include <vector>
class CTimeline;

/**
 * Class for drawable elements of our picture
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class CAnimChannel
{
public:
	/// public
	CAnimChannel();
	/// public
	virtual ~CAnimChannel();

	/// public
	CAnimChannel(const CAnimChannel &) = delete;

	/// public
	void operator=(const CAnimChannel &) = delete;

	

	/** Get name 
	* \returns mName
	*/
	std::wstring GetName() const { return mName; }

	/** Timeline member variable
	* \param currFrame
	*/
	void SetFrame(int currFrame);

	/** Get name
	*\returns bool
	*/
	bool IsValid();

	/** Timeline member variable
	*/
	void DeleteKeyframe();



	/** Timeline member variable
	* \param timeline 
	*/

	void SetTimeline(CTimeline * timeline) { mTimeline = timeline; }


	/** Name member variable
	* \param name the name
	*/
	void SetName(const std::wstring& name) { mName = name; }

	/** Timeline member variable 
	* \returns mTimeline 
	*/
	CTimeline *GetTimeline() { return mTimeline; }

	/** represents thye keyframe */
	class Keyframe
	{
	public:

		/**
		Default constructor disabled 
		*/
		Keyframe() = delete;

		/** 
			Copy constructor disabled 
		* \returns mFrame
		*/
		Keyframe(const Keyframe &) = delete;

		/** 
		Assignment operator disabled
		*/
		void operator=(const Keyframe &) = delete;

	
		/** frame member variable
		* \returns mFrame
		*/
		int GetFrame() const { return mFrame; }

		/** frame member variable
	* \param frame
	*/
		void SetFrame(const int frame) { mFrame = frame; }


		/** 
		frame member variable
		* \return
		
		*/
		virtual void first() = 0;

		/** 
		frame member variable
		* \return
		*/
		virtual void second() = 0;

		/** 
		frame member variable
		* \return
		*/
		virtual void angle() = 0;

	protected:

		/// keyframes for this channel 
		int mFrame;

		/** Constructor
		* \param channel */

		Keyframe(CAnimChannel *channel) : mChannel(channel) {}

	private:
		/// keyframes for this channel 
		CAnimChannel *mChannel;
	};

protected:
	/** frame member variable
	*\param t
	*\return 
	*/
	virtual void Tweening(double t) = 0;

	/** frame member variable
	*\param keyframe
	*/
	void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);
private:


	/// keyframes for this channel 
	std::wstring mName;
	/// keyframes for this channel
	int mKeyframe1 = -1;
	/// keyframes for this channel
	int mKeyframe2 = -1;  
	

	/// keyframes for this channel
	std::vector<std::shared_ptr<Keyframe>> mKeyframes;
							
	/// The timeline object
	CTimeline *mTimeline = nullptr;

	
};
