#ifndef ANNOYINGFLYOWNEDSTATE_H
#define ANNOYINGFLYOWNEDSTATE_H

#pragma once

#include "fsm/State.h"

class AnnoyingFly;
struct Telegram;

class IdleInSaloon : public State<AnnoyingFly> 
{
private:
	IdleInSaloon() {}

public:
	//this is a singleton
	static IdleInSaloon* Instance();

	virtual void Enter(AnnoyingFly* miner) override;

	virtual void Execute(AnnoyingFly* miner) override;

	virtual void Exit(AnnoyingFly* miner) override;

	virtual bool OnMessage(AnnoyingFly* agent, const Telegram& msg) override;

	IdleInSaloon(const IdleInSaloon&) = delete;
	IdleInSaloon& operator=(const IdleInSaloon&) = delete;

};

class BattleModeWithMiner : public State<AnnoyingFly> 
{
private:
	BattleModeWithMiner() {}
public:
	//this is a singleton
	static BattleModeWithMiner* Instance();

	virtual void Enter(AnnoyingFly* miner) override;

	virtual void Execute(AnnoyingFly* miner) override;

	virtual void Exit(AnnoyingFly* miner) override;

	virtual bool OnMessage(AnnoyingFly* agent, const Telegram& msg) override;

	BattleModeWithMiner(const BattleModeWithMiner&) = delete;
	BattleModeWithMiner& operator=(const BattleModeWithMiner&) = delete;
};

class FleeAwayAndRecover : public State<AnnoyingFly>
{
private:
	FleeAwayAndRecover() {}
public:
	
	//this is a singleton
	static FleeAwayAndRecover* Instance();

	virtual void Enter(AnnoyingFly* miner) override;

	virtual void Execute(AnnoyingFly* miner) override;

	virtual void Exit(AnnoyingFly* miner) override;

	virtual bool OnMessage(AnnoyingFly* agent, const Telegram& msg) override;

	FleeAwayAndRecover(const FleeAwayAndRecover&) = delete;
	FleeAwayAndRecover& operator=(const FleeAwayAndRecover&) = delete;

};



#endif