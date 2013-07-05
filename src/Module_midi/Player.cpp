#include "Module_midi.h"
#include "Player.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
Player::Player(Signal sig, Port *pPort, unsigned short division, unsigned long mpqn) :
	_cntRef(1), _sig(sig), _pPort(pPort), _division(division), _mpqn(mpqn),
	_speed(1), _pEventOwner(new EventOwner())
{
	_ppEvent = GetEventOwner().end();
}

Player::~Player()
{
}

bool Player::SetSpeed(Signal sig, double speed)
{
	if (speed <= 0) {
		sig.SetError(ERR_ValueError, "speed must be a positive number");
		return false;
	}
	_speed = speed;
	return true;
}

bool Player::Play()
{
	Event *pEventPrev = NULL;
	_ppEvent = GetEventOwner().begin();
	for ( ; _ppEvent != GetEventOwner().end(); _ppEvent++) {
		Event *pEvent = *_ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			double delayTime = static_cast<double>(_mpqn) *
									deltaTime / _division / 1000000 / _speed;
			OAL::Sleep(delayTime);
		}
		if (!pEvent->Play(_sig, this)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

void Player::Run()
{
	Play();
}

}}
