#ifndef __ML_LINEAR_CLASS_PROBLEM_H__
#define __ML_LINEAR_CLASS_PROBLEM_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

class Object_ifd;

//-----------------------------------------------------------------------------
// Entry
//-----------------------------------------------------------------------------
struct Entry {
	double y;
	struct feature_node featureNodes[1];
public:
	static Entry *Create(Signal &sig, const Value &valueY, const ValueList &valListX);
};

//-----------------------------------------------------------------------------
// EntryList
//-----------------------------------------------------------------------------
typedef std::vector<Entry *> EntryList;

//-----------------------------------------------------------------------------
// EntryOwner
//-----------------------------------------------------------------------------
class EntryOwner : public EntryList {
public:
	~EntryOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Object_problem declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(problem);

class Object_problem : public Object {
private:
	struct problem _prob;
	EntryOwner _entryOwner;
public:
	Gura_DeclareObjectAccessor(problem)
public:
	Object_problem();
	virtual ~Object_problem();
	virtual String ToString(bool exprFlag);
	struct problem &UpdateEntity();
};

Gura_EndModuleScope(ml_linear)

#endif
