/**
 * \file FishBeta.h
 *
 * \author Funakoshi Silva
 *
 * Class the implements a Beta fish
 */

#pragma once
#include <memory>

#include "Item.h"
#include"Fish.h"

 /**
  * Class for a fish of type Bubbles
 */
class CCarp :

	public CFish
{
public:
	/**
	 * aquarium class
	 * \param aquarium
	 */
	CCarp(CAquarium* aquarium);

	/**
	* Class for a fish of type Bubbles
	*\param node
	*\return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	/// Default constructor (disabled)
	CCarp() = delete;

	/// Copy constructor (disabled)
	CCarp(const CCarp&) = delete;
	
	


};