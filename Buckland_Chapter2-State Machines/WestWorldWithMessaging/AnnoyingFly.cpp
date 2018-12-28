#include "AnnoyingFly.h"

bool AnnoyingFly::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

void AnnoyingFly::Update()
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}