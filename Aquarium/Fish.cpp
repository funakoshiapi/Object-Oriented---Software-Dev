/**
 * \file Fish.cpp
 *
 * \author Funakoshi Silva
 */





#include "pch.h"
#include "Fish.h"
#include <memory>
#include"Aquarium.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 75;
/// Maximum speed in the y direction in
/// in pixels per second
const double MaxSpeedY = 46;
///Distance
const int  MinDist = 10;

/// For sfish 
/// \param aquarium 
/// \param filename 
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
    CItem(aquarium, filename)
{
    mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
    mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}






/**
* Class for a fish of type Bubbles
*\param node
*\return itemNode
*/
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"speedx", mSpeedX);
    itemNode->SetAttribute(L"speedy", mSpeedY);

    return itemNode;
}

/**
 *Load speeds
 *
 * \param node 
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);

    mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
    mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);
    SetMirror(mSpeedX < 0);
}






/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
        GetY() + mSpeedY * elapsed);


    if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth())
    {
        mSpeedX = -mSpeedX;

        SetMirror(mSpeedX < 0);
    }

    double dRight = GetAquarium()->GetWidth() -
        GetX() - GetWidth() / 2;

    if (mSpeedX > 0 && dRight <= MinDist)
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }

    double dLeft = GetX() - GetWidth() / 2;
    if (mSpeedX < 0 && dLeft <= MinDist)
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }


    double dBottom = GetAquarium()->GetHeight() - GetY() - GetHeight() / 2;

    if (mSpeedY > 0 && dBottom <= MinDist)
    {
        mSpeedY = -mSpeedY;
    }


    double dTop = GetY() - GetHeight() / 2;

    if (mSpeedY < 0 && dTop <= MinDist)
    {
        mSpeedY = -mSpeedY;
    }
}



