/**
 * \file ImageDrawable.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once
#include "Drawable.h"
#include "RotatedBitmap.h"

/**
 * Class for drawable elements of our picture
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class CImageDrawable : public CDrawable, public CRotatedBitmap
{
public:
	/// Draw the object
	/// \param name offset The GDI+ graphics context to draw on
	/// \param filename offset The GDI+ graphics context to draw on
	/// \return
	CImageDrawable(const std::wstring & name, const std::wstring & filename);

	/// Draw the object
	/// \return
	virtual ~CImageDrawable();

	/// Draw the object
	/// \param graphics offset The GDI+ graphics context to draw on
	/// \return
	virtual void Draw(Gdiplus::Graphics * graphics) override;

	/// Draw the object
	/// \param pos offset The GDI+ graphics context to draw on
	/// \return
	virtual bool HitTest(Gdiplus::Point pos) override;

	/** \brief Default constructor disabled */
	CImageDrawable() = delete;

	/** \brief Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;

	/** \brief Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;
};