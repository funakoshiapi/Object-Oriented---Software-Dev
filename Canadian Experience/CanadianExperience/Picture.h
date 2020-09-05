/**
 * \file Picture.h
 *
 * \author Funakoshi Silva
 *
 *
 */

#pragma once


#include <vector>

#include "Actor.h"

#include "Timeline.h"



class CPictureObserver;

/**
* picture that will be drawn
*
*/
class CPicture
{
public:



	CPicture();
	virtual ~CPicture();
	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// Assignment Operator (Disabled)
	void operator=(const CPicture &) = delete;


	/** Get a pointer to the Timeline object
	* \returns Pointer to the Timeline object
	*/
	CTimeline* GetTimeline() { return &mTimeline; }


	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	/// Draw the object
	/// \return
	void UpdateObservers();


	void Draw(Gdiplus::Graphics* graphics);


	void AddObserver(CPictureObserver *observer);

	void RemoveObserver(CPictureObserver *observer);

	void AddActor(std::shared_ptr<CActor> actor);
	\
		
	/// Draw the object
	/// \param time observer offset The GDI+ graphics context to draw on
	/// \return
	void SetAnimationTime(double time);

	/**
	* picture that will be drawn
	*
	*/
	class Iter
	{
	public:
		/** Constructor
		* \param picture The picture we are iterating over 
		* \param pos Position in the collection
		*/
		Iter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

		/** Test for end of the iterator
		* \param other Iterator to compare to
		* \returns True if this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Test for end of the iterator
		* \param other Iterator to compare to
		* \returns True if this position equals to the other position */
		bool operator==(const Iter &other) const
		{
			return mPos == other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		/// private 
		CPicture *mPicture;  
		/// private
		int mPos;      
	};


	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */

	Iter begin() { return Iter(this, 0); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */

	Iter end() { return Iter(this, mActors.size()); }

private:

	/// animation timeline
	CTimeline mTimeline;

	/// picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);
	
	/// observers of  picture
	std::vector<CPictureObserver *> mObservers;
	/// private
	std::vector<std::shared_ptr<CActor> > mActors;

	
};

