#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <gura.h>
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
class Player : public OAL::Thread {
private:
	int _cntRef;
	Signal _sig;
	AutoPtr<Port> _pPort;
	unsigned short _division;
	unsigned long _mpqn;
	double _speed;
	AutoPtr<EventOwner> _pEventOwner;
	EventOwner::iterator _ppEvent;
public:
	Gura_DeclareReferenceAccessor(Player);
public:
	Player(Signal sig, Port *pPort, unsigned short division, unsigned long mpqn);
protected:
	virtual ~Player();
public:
	inline Port *GetPort() { return _pPort.get(); }
	inline void SetMPQN(unsigned long mpqn) { _mpqn = mpqn; }
	inline EventOwner &GetEventOwner() { return *_pEventOwner; }
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
	bool SetSpeed(Signal sig, double speed);
	bool Play();
public:
	// virtual function of OAL::Thread
	virtual void Run();
};

}}

#endif
