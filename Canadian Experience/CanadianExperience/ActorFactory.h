/**
 * \file ActorFactory.h
 *
 * \author Funakoshi Silva 
 */

#pragma once
#include <memory>
#include "Actor.h"

/**
*  Actor factories base class
*/
class CActorFactory
{
public:
	CActorFactory();
	virtual ~CActorFactory();

	/// Create actors
	/// \return pointer
	virtual std::shared_ptr<CActor> Create() = 0;
};

