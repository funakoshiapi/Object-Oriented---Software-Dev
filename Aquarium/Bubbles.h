/**
 * \file FishBeta.h
 *
 * \author Funakoshi Silva
 *
 * 
 */

#pragma once
#include <memory>

#include "Item.h"
#include"Fish.h"

 /**
  * Class for a fish of type Bubbles
 */
class CBubbles :
	public CFish
{
public:

	/**
	* Class for a fish of type Bubbles
	*\param aquarium
	*/
	CBubbles(CAquarium* aquarium);

	/// Default constructor (disabled)
	CBubbles() = delete;

	/// Copy constructor (disabled)
	CBubbles(const CBubbles&) = delete;

	


	/**
	* Class for a fish of type Bubbles
	*\param node
	*\return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};