/**
 * \file PolyDrawable.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once

#include "Drawable.h"
#include <vector>


 /**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class CPolyDrawable : public CDrawable
{
public:
	CPolyDrawable(const std::wstring & name);
	virtual ~CPolyDrawable();
	/** \brief Default constructor disabled */
	CPolyDrawable() = delete;
	/** \brief Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

	/// Draw the object
	/// \return
	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;
	void AddPoint(Gdiplus::Point point);
	
	/// Getter for the color
	/// \return mColor color of the drawable
	Gdiplus::Color GetColor() { return mColor; }

	/// Setter for the color
	/// \param color The color for the drawable
	void SetColor(Gdiplus::Color color) { mColor = color; }

private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
};

