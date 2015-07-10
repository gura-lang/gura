//----------------------------------------------------------------------------
// wxCoord
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COORD_H__
#define __CLASS_WX_COORD_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCoord
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Coord);

//----------------------------------------------------------------------------
// Object declaration for wxCoord
//----------------------------------------------------------------------------
class Object_wx_Coord : public Object {
protected:
	wxCoord *_pEntity;
public:
	Gura_DeclareObjectAccessor(wx_Coord)
public:
	inline Object_wx_Coord(wxCoord *pEntity) :
				Object(Gura_UserClass(wx_Coord)), _pEntity(pEntity) {}
	inline Object_wx_Coord(Class *pClass, wxCoord *pEntity) :
				Object(pClass), _pEntity(pEntity) {}
	inline bool IsInvalid(Signal &sig) const { return false; }
	virtual ~Object_wx_Coord();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCoord *GetEntity() { return _pEntity; }
};

Gura_EndModuleScope(wx)

#endif
