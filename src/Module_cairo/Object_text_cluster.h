#ifndef __CAIRO_OBJECT_TEXT_CLUSTER_H__
#define __CAIRO_OBJECT_TEXT_CLUSTER_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_text_cluster declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(text_cluster);

class Object_text_cluster : public Object {
private:
	cairo_text_cluster_t _text_cluster;
public:
	Gura_DeclareObjectAccessor(text_cluster)
public:
	inline Object_text_cluster(const cairo_text_cluster_t &text_cluster) :
						Object(Gura_UserClass(text_cluster)), _text_cluster(text_cluster) {}
	virtual ~Object_text_cluster();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_text_cluster_t &GetEntity() { return _text_cluster; }
	inline const cairo_text_cluster_t &GetEntity() const { return _text_cluster; }
};

}}

#endif
