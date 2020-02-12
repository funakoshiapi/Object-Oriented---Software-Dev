#include "pch.h"
#include <string>
#include "DecorCastle.h"


using namespace Gdiplus;
using namespace std;

/// Castle filename 
const wstring CastleImageName = L"images/castle.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
    CItem(aquarium, CastleImageName)
{
}

std::shared_ptr<xmlnode::CXmlNode> CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"type", L"castle");

    return itemNode;
}

/**
* Destructor
*/
CDecorCastle::~CDecorCastle()
{
}


