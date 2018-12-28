#include "AnnoyingFlyOwnedStates.h"
#include "fsm/State.h"
#include "AnnoyingFly.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

IdleInSaloon* IdleInSaloon::Instance()
{
	static IdleInSaloon instance;

	return &instance;
}

void IdleInSaloon::Enter(AnnoyingFly* pAnnoyingFly) 
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "I Fly~~~~~~!!";
}

void IdleInSaloon::Execute(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "Fly in Saloon!!";
}


void IdleInSaloon::Exit(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": "
		<< "Quit Idle";
}


bool IdleInSaloon::OnMessage(AnnoyingFly* pAnnoyingFly, const Telegram& msg)
{
	//send msg to global message handler
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_FindFly:

		cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": "
			<< "Someone wants to find me.";

		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			pAnnoyingFly->ID(),
			msg.Sender,
			Msg_FlyExists,
			NO_ADDITIONAL_INFO);

		pAnnoyingFly->GetFSM()->ChangeState(BattleModeWithMiner::Instance());
	}

	return true;
}

//--------------------------------------------------------------------------------

BattleModeWithMiner* BattleModeWithMiner::Instance()
{
	static BattleModeWithMiner instance;

	return &instance;
}

void BattleModeWithMiner::Enter(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "The miner is annoyinggggggggg";	
}

void BattleModeWithMiner::Execute(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "Oh!!!!";
}


void BattleModeWithMiner::Exit(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": "
		<< "I'll come back again~~~~~~~";
}


bool BattleModeWithMiner::OnMessage(AnnoyingFly* pAnnoyingFly, const Telegram& msg)
{
	//send msg to global message handler
	//send msg to global message handler
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_HitFly:

		pAnnoyingFly->GetAttack();

		if (pAnnoyingFly->IsDying()) 
		{
			pAnnoyingFly->GetFSM()->ChangeState(FleeAwayAndRecover::Instance());
		}
	}
	return true;
}

//----------------------------------------------------------------------------------------------
FleeAwayAndRecover* FleeAwayAndRecover::Instance()
{
	static FleeAwayAndRecover instance;

	return &instance;
}

void FleeAwayAndRecover::Enter(AnnoyingFly* pAnnoyingFly)
{
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
		pAnnoyingFly->ID(),
		ent_Miner_Bob,
		Msg_FlyRunAway,
		NO_ADDITIONAL_INFO);
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "Rest start!!";
}

void FleeAwayAndRecover::Execute(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": " << "Recover Health ING";

	pAnnoyingFly->Recover();

	if (!pAnnoyingFly->IsDying()) 
	{
		pAnnoyingFly->GetFSM()->ChangeState(IdleInSaloon::Instance());
	}
}


void FleeAwayAndRecover::Exit(AnnoyingFly* pAnnoyingFly)
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pAnnoyingFly->ID()) << ": "
		<< "I come back again. XDDDDDDD";
}


bool FleeAwayAndRecover::OnMessage(AnnoyingFly* pAnnoyingFly, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}