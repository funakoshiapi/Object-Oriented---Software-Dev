/**
 * \file RotatedBitmap.cpp
 *
 * \author Funakoshi Silva
 */

#include "pch.h"
#include "RotatedBitmap.h"
#include <string>

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CRotatedBitmap::CRotatedBitmap()
{
}

/**
 * Destructor
 */
CRotatedBitmap::~CRotatedBitmap()
{
}

/**
* Load image.
* \param filename
*/
void CRotatedBitmap::LoadImage(const std::wstring &filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
	else
	{
		mLoaded = true;
	}
}

/**
* Draw the bitmap
* \param graphics 
* \param position 
* \param angle 
*/
void CRotatedBitmap::DrawImage(Gdiplus::Graphics *graphics,
	Gdiplus::Point position, double angle)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)position.X, (float)position.Y);
	graphics->RotateTransform((float)(-angle * RtoD));
	graphics->DrawImage(mImage.get(), -mCenter.X, -mCenter.Y,
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}