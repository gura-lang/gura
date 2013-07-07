#include "Module_midi.h"
#include "Player.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
Player::Player(Signal sig, Port *pPort) :
	_cntRef(1), _sig(sig), _pPort(pPort), _division(1), _mpqn(0),
	_speed(1), _pEventOwner(new EventOwner()), _cntEvents(0), _idxEventCur(0)
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
	_pEventOwner->Clear();
	foreach_const (TrackOwner, ppTrack, pContent->GetTrackOwner()) {
		const Track *pTrack = *ppTrack;
		_pEventOwner->AddEvents(pTrack->GetEventOwner());
	}
	_pEventOwner->Sort();
	_ppEvent = _pEventOwner->begin();
	_cntEvents = _pEventOwner->size();
	_idxEventCur = 0;
	return true;
}

bool Player::Play()
{
	Event *pEventPrev = NULL;
	for ( ; _ppEvent != _pEventOwner->end(); _ppEvent++, _idxEventCur++) {
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

void Player::PlayBackground()
{
	Thread *pThread = new Thread(Reference(this));
	pThread->Start();	// pThread will be delete when thread is done
}

//-----------------------------------------------------------------------------
// Player::Thread
//-----------------------------------------------------------------------------
void Player::Thread::Run()
{
	_pPlayer->Play();
}


}}
