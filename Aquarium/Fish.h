/**
 * \file Fish.h
 *
 * \author Funakoshi Silva
 *
 * 
 */


#pragma once
#include"Item.h"
#include"Aquarium.h"



/**
 * Will represent all fish behaviour
 */
class CFish : public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish&) = delete;

	virtual void Update(double elapsed);

	/**
	* Class for a fish of type Bubbles
	*\return mSpeedX
	*/
	double GetSpeedX() { return mSpeedX; }

	/**
	* Class for a fish of type Bubbles
	*\return mSpeedY
	*/
	double GetSpeedY() { return mSpeedY; }

	
	/**
	* Class for a fish of type Bubbles
	*\param speedY
	*/
	void SetSpeedY(double speedY) { mSpeedY = speedY; }

	/**
	* Class for a fish of type Bubbles
	*\param speedX
	*/
	void SetSpeedX(double speedX) { mSpeedX = speedX; }


protected:

	/**
	 * Constructor
	 *
	 */
	CFish(CAquarium* aquarium, const std::wstring& filename);

	/// Save fish
	/// \param node 
	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);


	/**
 *Load speeds
 *
 * \param node
 */
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);
	

private:
	/// Fish speed X direction
	double mSpeedX;

	/// Fish speed Y direction
	double mSpeedY;



};
