#ifndef __FREETYPE_CLASS_FACE_H__
#define __FREETYPE_CLASS_FACE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Face);

class Object_Face : public Object {
public:
	Gura_DeclareObjectAccessor(Face)
private:
	FT_Face _face;
	std::unique_ptr<Handler> _pHandler;
public:
	inline Object_Face(FT_Face face = nullptr) :
					Object(Gura_UserClass(Face)), _face(face) {}
	inline Object_Face(const Object_Face &obj) :
					Object(obj), _face(obj._face) {}
	~Object_Face();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Face &GetEntity() { return _face; }
	inline const FT_Face &GetEntity() const { return _face; }
	bool Initialize(Environment &env, Signal &sig, Stream *pSstream, int index);
};

Gura_EndModuleScope(freetype)

#endif
