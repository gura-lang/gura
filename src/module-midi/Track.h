#ifndef __TRACK_H__
#define __TRACK_H__
#include <gura.h>
#include "Event.h"
#include "MML.h"

Gura_BeginModuleScope(midi)

//-----------------------------------------------------------------------------
// Property
//-----------------------------------------------------------------------------
class Property {
private:
	int _cntRef;
	UShort _division;
	ULong _mpqn;
	UChar _channelNext;
public:
	Gura_DeclareReferenceAccessor(Property);
public:
	inline Property() : _cntRef(1), _division(120),
							_mpqn(60000000 / 120), _channelNext(0) {}
private:
	inline ~Property() {}
public:
	inline void SetDivision(UShort division) { _division = division; }
	inline UShort GetDivision() const { return _division; }
	inline void SetMPQN(ULong mpqn) { _mpqn = mpqn; }
	inline ULong GetMPQN() const { return _mpqn; }
	inline UChar GetChannelNext() {
		UChar rtn = _channelNext;
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
	int _channel;
	AutoPtr<Property> _pProperty;
	AutoPtr<EventOwner> _pEventOwner;
	EventOwner::iterator _ppEventAt;
	bool _requestEndOfTrackFlag;
public:
	Gura_DeclareReferenceAccessor(Track);
public:
	Track(Property *pProperty);
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
	inline Property *GetProperty() { return _pProperty.get(); }
	inline const Property *GetProperty() const { return _pProperty.get(); }
	inline void RequestEndOfTrack() { _requestEndOfTrackFlag = true; }
	inline bool IsEndOfTrackRequested() const { return _requestEndOfTrackFlag; }
	inline void SetChannel(int channel) { _channel = channel; }
	UChar GetChannel();
	ULong GetPrevTimeStamp() const;
	void AdjustFollowingTimeStamp(long deltaTime);
	void AddEvent(Event *pEvent);
	void AddEvent(Event *pEvent, ULong deltaTime);
	bool SeekSet(Signal &sig, long offset);
	bool SeekCur(Signal &sig, long offset);
	long Tell() const;
	bool Erase(Signal &sig, size_t cnt);
};

//-----------------------------------------------------------------------------
// TrackList
//-----------------------------------------------------------------------------
class TrackList : public std::vector<Track *> {
public:
	bool Write(Signal &sig, Stream &stream) const;
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
	UChar GetChannelNext();
};

Gura_EndModuleScope(midi)

#endif
