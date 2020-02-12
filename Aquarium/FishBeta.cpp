/**
 * \file FishBeta.cpp
 *
 * \author Funakoshi Silva
 */


#include "pch.h"
#include <string>
#include "FishBeta.h"
#include "XmlNode.h"

using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
    CFish(aquarium, FishBetaImageName)
{
}

/**
* Class for a fish of type Bubbles
*\param node
*\return itemNode
*/
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"beta");

    return itemNode;
}

