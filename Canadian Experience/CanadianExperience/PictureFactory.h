/**
 * \file PictureFactory.h
 *
 * \author Funakoshi Silva
 *
 */

#pragma once

#include <memory>
#include "Picture.h"

 /**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
	virtual ~CPictureFactory();    
	CPictureFactory();

	std::shared_ptr<CPicture> Create();
};

