#ifndef __TRACK_H__
#define __TRACK_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Track
//-----------------------------------------------------------------------------
class Track {
private:
	int _cntRef;
	EventOwner _eventOwner;
public:
	Gura_DeclareReferenceAccessor(Track);
public:
	inline Track() : _cntRef(1) {}
	inline EventOwner &GetEventOwner() { return _eventOwner; }
	inline const EventOwner &GetEventOwner() const { return _eventOwner; }
};

//-----------------------------------------------------------------------------
// TrackList
//-----------------------------------------------------------------------------
class TrackList : public std::vector<Track *> {
};

//-----------------------------------------------------------------------------
// TrackOwner
//-----------------------------------------------------------------------------
class TrackOwner : public TrackList {
public:
	~TrackOwner();
	void Clear();
};

}}

#endif
