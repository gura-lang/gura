//=============================================================================
// Gura class: trainernode
//=============================================================================
#ifndef __GURA_CLASS_TRAINERNODE_H__
#define __GURA_CLASS_TRAINERNODE_H__

#include "Class.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_trainernode
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_trainernode : public ClassFundamental {
public:
	Class_trainernode(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_trainernode
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_trainernode : public Object {
public:
	Gura_DeclareObjectAccessor(trainernode)
private:
	AutoPtr<Trainer::Node> _pNode;
public:
	inline Object_trainernode(Environment &env, Trainer::Node *pNode) :
			Object(env.LookupClass(VTYPE_trainernode)), _pNode(pNode) {}
	inline Object_trainernode(Class *pClass, Trainer::Node *pNode) :
			Object(pClass), _pNode(pNode) {}
	Object_trainernode(const Object_trainernode &obj);
	virtual ~Object_trainernode();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Trainer::Node *GetTrainerNode() { return _pNode.get(); }
	inline const Trainer::Node *GetTrainerNode() const { return _pNode.get(); }
};

}

#endif
