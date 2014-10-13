#ifndef __SDL2_CLASS_WAV_H__
#define __SDL2_CLASS_WAV_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Wav declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Wav);

class Object_Wav : public Object {
private:
	SDL_AudioSpec _spec;
	Uint8 *_buffer;
	Uint32 _length;
public:
	Gura_DeclareObjectAccessor(Wav)
public:
	inline Object_Wav(const SDL_AudioSpec &spec, Uint8 *buffer, Uint32 length) :
			Object(Gura_UserClass(Wav)), _spec(spec), _buffer(buffer), _length(length) {}
	virtual ~Object_Wav();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_AudioSpec *GetSpec() { return &_spec; }
	inline const SDL_AudioSpec *GetSpec() const { return &_spec; }
	inline Uint8 *GetBuffer() { return _buffer; }
	inline const Uint8 *GetBuffer() const { return _buffer; }
	inline Uint32 GetLength() const { return _length; }
};

Gura_EndModuleScope(sdl2)

#endif
