#ifndef ANNOYINGFLY_H
#define ANNOYINGFLY_H

#pragma once

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "AnnoyingFlyOwnedStates.h"
#include "fsm/StateMachine.h"

class AnnoyingFly : public BaseGameEntity {
private:
	StateMachine<AnnoyingFly>*  m_pStateMachine;

	location_type         m_Location;

	int m_iHp;

	int m_iMaxHp;

	bool m_bIsActive;

public:

	AnnoyingFly(int id) :m_Location(saloon),
		m_iMaxHp(3),
		m_iHp(3),
		m_bIsActive(true),
		BaseGameEntity(id)
	{
		//set up state machine
		m_pStateMachine = new StateMachine<AnnoyingFly>(this);

		m_pStateMachine->SetCurrentState(IdleInSaloon::Instance());

		/* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
	}

	~AnnoyingFly() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);


	StateMachine<AnnoyingFly>* GetFSM()const { return m_pStateMachine; }



	//-------------------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	void GetAttack() { if(--m_iHp <= 0) m_bIsActive = false; }
	bool IsDying() { return !m_bIsActive; }
	void Recover() { if (++m_iHp == m_iMaxHp) m_bIsActive = true; }

};


#endif