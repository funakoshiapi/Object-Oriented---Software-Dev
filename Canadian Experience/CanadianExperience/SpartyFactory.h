/**
* \file SpartyFactory.h
*
* \author Funakoshi Silva
*
*/

#pragma once
#include "ActorFactory.h"
#include "Actor.h"

/**
* Factory class for Sparty
*/
class CSpartyFactory : public CActorFactory
{
public:
	CSpartyFactory();
	virtual ~CSpartyFactory();
	std::shared_ptr<CActor> Create();
};

