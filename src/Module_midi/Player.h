#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <gura.h>
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
class Player {
private:
	AutoPtr<Port> _pPort;
	unsigned short _division;
	unsigned long _mpqn;
	AutoPtr<EventOwner> _pEventOwner;
public:
	Player(Port *pPort, unsigned short division, unsigned long mpqn);
	bool Play(Signal sig, double speed);
	inline Port *GetPort() { return _pPort.get(); }
	inline void SetMPQN(unsigned long mpqn) { _mpqn = mpqn; }
	inline EventOwner &GetEventOwner() { return *_pEventOwner; }
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
};

}}

#endif
