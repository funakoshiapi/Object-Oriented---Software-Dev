#include "pch.h"
#include <string>
#include "Bubbles.h"
#include"Fish.h"
#include "XmlNode.h"

/**
 * \file FishBeta.cpp
 *
 * \author Funakoshi Silva
 */



using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring BubblesImageName = L"images/bubbles.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CBubbles::CBubbles(CAquarium* aquarium) :
    CFish(aquarium, BubblesImageName)
{
}
  /**
    * Class for a fish of type Bubbles
    *\param node
    *\return itemNode
    */
std::shared_ptr<xmlnode::CXmlNode>
CBubbles::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"type", L"bubbles");

    return itemNode;
}

	

