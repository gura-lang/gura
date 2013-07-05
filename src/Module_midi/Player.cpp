#include "Module_midi.h"
#include "Player.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
Player::Player(Signal sig, Port *pPort) :
	_cntRef(1), _sig(sig), _pPort(pPort), _division(1), _mpqn(0),
	_speed(1), _pEventOwner(new EventOwner())
{
	_ppEvent = _pEventOwner->end();
}

Player::~Player()
{
}

bool Player::SetupContent(Signal sig, const Content *pContent,
				unsigned short division, unsigned long mpqn, double speed)
{
	if (speed <= 0) {
		sig.SetError(ERR_ValueError, "speed must be a positive number");
		return false;
	}
	_division = division;
	_mpqn = mpqn;
	_speed = speed;
	foreach_const (TrackOwner, ppTrack, pContent->GetTrackOwner()) {
		const Track *pTrack = *ppTrack;
		_pEventOwner->AddEvents(pTrack->GetEventOwner());
	}
	_pEventOwner->Sort();
	_ppEvent = _pEventOwner->begin();
	return true;
}

bool Player::Play()
{
	Event *pEventPrev = NULL;
	for ( ; _ppEvent != _pEventOwner->end(); _ppEvent++) {
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

Value Player::PlayBackground(Environment &env)
{
	Value value(new Object_player(env, Player::Reference(this)));
	Start();
	return value;
}

void Player::Run()
{
	Play();
}

}}
