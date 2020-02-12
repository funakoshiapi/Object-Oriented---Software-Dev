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
#include "XmlNode.h"
#include "Fish.h"

 /**
  * Class for a fish of type Beta
 */
class CFishBeta :
    public CFish
{
public:
    /**
    * Class for a fish of type Beta
    *\param aquarium
    */
    CFishBeta::CFishBeta(CAquarium* aquarium);
    /**
* Class for a fish of type Bubbles
*\param node
*\return itemNode
*/
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta&) = delete;


};