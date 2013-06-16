#ifndef __TRACK_H__
#define __TRACK_H__
#include <gura.h>
#include "Event.h"
#include "MML.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Property
//-----------------------------------------------------------------------------
class Property {
private:
	int _cntRef;
	unsigned short _division;
	unsigned long _mpqn;
	unsigned char _channelNext;
public:
	Gura_DeclareReferenceAccessor(Property);
public:
	inline Property() : _cntRef(1), _division(120),
							_mpqn(60000000 / 120), _channelNext(0) {}
private:
	inline ~Property() {}
public:
	inline void SetDivision(unsigned short division) { _division = division; }
	inline unsigned short GetDivision() const { return _division; }
	inline void SetMPQN(unsigned long mpqn) { _mpqn = mpqn; }
	inline unsigned long GetMPQN() const { return _mpqn; }
	inline unsigned char GetChannelNext() {
		unsigned char rtn = _channelNext;
		if (_channelNext < 15) _channelNext++;
		return rtn;
	}
};

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
class Track {
private:
	int _cntRef;
	AutoPtr<Property> _pProperty;
	AutoPtr<EventOwner> _pEventOwner;
	EventOwner::iterator _ppEventAt;
	std::auto_ptr<MML> _pMML; // maybe NULL
public:
	Gura_DeclareReferenceAccessor(Track);
public:
	Track(Property *pProperty);
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
	inline Property *GetProperty() { return _pProperty.get(); }
	inline const MML *GetMML() const { return _pMML.get(); }
	bool Write(Signal sig, Stream &stream) const;
	bool ParseMML(Signal sig, const char *str);
	void AddEvent(Event *pEvent);
	bool Seek(Signal sig, long offset);
};

//-----------------------------------------------------------------------------
// TrackList
//-----------------------------------------------------------------------------
class TrackList : public std::vector<Track *> {
public:
	bool Write(Signal sig, Stream &stream) const;
};

//-----------------------------------------------------------------------------
// TrackOwner
//-----------------------------------------------------------------------------
class TrackOwner : public TrackList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(TrackOwner);
public:
	inline TrackOwner() : _cntRef(1) {}
protected:
	~TrackOwner();
public:
	void Clear();
	unsigned char GetChannelNext();
};

}}

#endif
