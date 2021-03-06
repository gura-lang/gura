#ifndef __FREETYPE_CLASS_FTC_NODE_H__
#define __FREETYPE_CLASS_FTC_NODE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Node declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_Node);

class Object_FTC_Node : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_Node)
private:
	FTC_Node _node;
public:
	inline Object_FTC_Node(const FTC_Node &node) :
			Object(Gura_UserClass(FTC_Node)), _node(node) {}
	inline Object_FTC_Node(const Object_FTC_Node &obj) :
			Object(obj), _node(obj._node) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FTC_Node &GetEntity() { return _node; }
	inline const FTC_Node &GetEntity() const { return _node; }
};

Gura_EndModuleScope(freetype)

#endif
