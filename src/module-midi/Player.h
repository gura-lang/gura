#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <gura.h>
#include "Port.h"

Gura_BeginModuleScope(midi)

class Sequence;

//-----------------------------------------------------------------------------
// Player
//-----------------------------------------------------------------------------
class Player {
public:
	class Thread : public OAL::Thread {
	private:
		AutoPtr<Player> _pPlayer;
	public:
		inline Thread(Player *pPlayer) : _pPlayer(pPlayer) {}
		// virtual function of OAL::Thread
		virtual void Run();
	};
private:
	int _cntRef;
	Signal _sig;
	AutoPtr<Port> _pPort;
	UShort _division;
	ULong _mpqn;
	double _speed;
	int _iRepeat;
	int _cntRepeat;
	AutoPtr<EventOwner> _pEventOwner;
	EventOwner::iterator _ppEvent;
	size_t _cntEvents;
	size_t _idxEventCur;
public:
	Gura_DeclareReferenceAccessor(Player);
public:
	Player(Signal sig, Port *pPort);
protected:
	virtual ~Player();
public:
	inline Port *GetPort() { return _pPort.get(); }
	inline void SetMPQN(ULong mpqn) { _mpqn = mpqn; }
	bool SetupSequence(Signal sig, const Sequence *pSequence,
				UShort division, ULong mpqn, double speed, int cntRepeat);
	bool Play();
	void PlayBackground();
	inline void SetSpeed(double speed) { _speed = speed; }
	inline double GetSpeed() const { return _speed; }
	inline size_t CountEvents() const { return _cntEvents; }
	inline size_t GetProgress() const { return _idxEventCur; }
	inline int GetRepeat() const { return _iRepeat; }
};

Gura_EndModuleScope(midi)

#endif
