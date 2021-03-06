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
	AutoPtr<Trainer> _pTrainer;
	Trainer::Node *_pNode;
public:
	inline Object_trainernode(Environment &env, Trainer *pTrainer, Trainer::Node *pNode) :
		Object(env.LookupClass(VTYPE_trainernode)), _pTrainer(pTrainer), _pNode(pNode) {}
	inline Object_trainernode(Class *pClass, Trainer *pTrainer, Trainer::Node *pNode) :
		Object(pClass), _pTrainer(pTrainer), _pNode(pNode) {}
	Object_trainernode(const Object_trainernode &obj);
	virtual ~Object_trainernode();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Trainer::Node *GetTrainerNode() { return _pNode; }
	inline const Trainer::Node *GetTrainerNode() const { return _pNode; }
};

}

#endif
