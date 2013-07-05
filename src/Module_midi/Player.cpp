#include "Module_midi.h"
#include "Player.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
Player::Player(Port *pPort, unsigned short division, unsigned long mpqn) :
	_pPort(pPort), _division(division), _mpqn(mpqn), _pEventOwner(new EventOwner())
{
}

bool Player::Play(Signal sig, double speed)
{
	if (speed <= 0) {
		sig.SetError(ERR_ValueError, "speed must be a positive number");
		return false;
	}
	Event *pEventPrev = NULL;
	foreach_const (EventOwner, ppEvent, GetEventOwner()) {
		Event *pEvent = *ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			double delayTime = static_cast<double>(_mpqn) *
									deltaTime / _division / 1000000 / speed;
			OAL::Sleep(delayTime);
		}
		if (!pEvent->Play(sig, this)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

}}
