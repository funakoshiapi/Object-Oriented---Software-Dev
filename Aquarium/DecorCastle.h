/**
 * \file DecorCastle.h
 *
 * \author Funakoshi Silva
 *
 * 
 */

#pragma once
#include "Item.h"
#include <memory>

/**
 * For managment of DecorCASTLE
 */
class CDecorCastle :
	public CItem
{
public:
	/**
	* Class for Castle
	*\param aquarium
	*/
	CDecorCastle::CDecorCastle(CAquarium* aquarium);
	/**
* Class for a fish of type Bubbles
*\param node
*\return itemNode
*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
	/// Default constructor (disabled)

	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle&) = delete;

	virtual ~CDecorCastle();


};

