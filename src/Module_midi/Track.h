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
	std::auto_ptr<MML> _pMML; // maybe NULL
public:
	Gura_DeclareReferenceAccessor(Track);
public:
	Track(Property *pProperty);
	inline EventOwner &GetEventOwner() { return *_pEventOwner; }
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
	bool Write(Signal sig, Stream &stream) const;
	bool ParseMML(Signal sig, const char *str);
	Property *GetProperty() { return _pProperty.get(); }
	const MML *GetMML() const { return _pMML.get(); }
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
