#ifndef __TRACK_H__
#define __TRACK_H__
#include <gura.h>
#include "Event.h"
#include "MML.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
class Track {
private:
	int _cntRef;
	AutoPtr<EventOwner> _pEventOwner;
	std::auto_ptr<MML> _pMML; // maybe NULL
public:
	Gura_DeclareReferenceAccessor(Track);
public:
	Track();
	inline EventOwner &GetEventOwner() { return *_pEventOwner; }
	inline const EventOwner &GetEventOwner() const { return *_pEventOwner; }
	bool Write(Signal sig, Stream &stream) const;
	bool ParseMML(Signal sig, const char *str);
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
};

}}

#endif
