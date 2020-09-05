/**
 * \file ImageDrawable.cpp
 *
 * \author Funakoshi Silva
 *
 */

#include "pch.h"
#include "ImageDrawable.h"

using namespace std;
using namespace Gdiplus;




/** Constructor */
CImageDrawable::CImageDrawable(const std::wstring &name, const std::wstring &filename) :
	CDrawable(name)
{
	LoadImage(filename);
}


/**
 * Destructor
 */
CImageDrawable::~CImageDrawable()
{
}


/**
* Draw picture

*/
void CImageDrawable::Draw(Gdiplus::Graphics *graphics)
{
	DrawImage(graphics, mPlacedPosition, mPlacedR);
}

/**
* see if image was clicked.
*/

bool CImageDrawable::HitTest(Gdiplus::Point pos)
{
	Matrix mat;
	mat.Translate((float)mCenter.X, (float)mCenter.Y);
	mat.Rotate((float)(mPlacedR * RtoD));
	mat.Translate((float)-mPlacedPosition.X, (float)-mPlacedPosition.Y);

	Point points[] = { pos };
	mat.TransformPoints(points, 1);

	double wid = mImage->GetWidth();
	double hit = mImage->GetHeight();

	double testX = points[0].X;
	double testY = points[0].Y;

	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
	
		return false;
	}


	auto format = mImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		
		Color color;
		mImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else 
	{
		return true;
	}

}