#include "pch.h"
#include <string>
#include "Carp.h"
#include "XmlNode.h"


/**
 * \file FishBeta.cpp
 *
 * \author Funakoshi Silva
 */





using namespace Gdiplus;

using namespace std;

/// Fish filename 
const wstring CarpImageName = L"images/carp.png";


/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CCarp::CCarp(CAquarium* aquarium) :
    CFish(aquarium,CarpImageName)
{
}

std::shared_ptr<xmlnode::CXmlNode>
CCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"type", L"carp");

    return itemNode;
}


