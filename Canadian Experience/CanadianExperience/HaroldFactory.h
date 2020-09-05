/**
 * \file HaroldFactory.h
 *
 * \author Funakoshi Silva
 * 
 */

#pragma once
#include "ActorFactory.h"
#include "Actor.h"

/**
*  builds Harold's character
*/
class CHaroldFactory : public CActorFactory
{
public:
	CHaroldFactory();
	virtual ~CHaroldFactory();
	std::shared_ptr<CActor> Create();
};

