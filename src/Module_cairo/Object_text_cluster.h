#ifndef __CAIRO_OBJECT_TEXT_CLUSTER_H__
#define __CAIRO_OBJECT_TEXT_CLUSTER_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_text_cluster declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(text_cluster);

class Object_text_cluster : public Object {
private:
	cairo_text_cluster_t *_clusters;
	int _num_clusters;
public:
	Gura_DeclareObjectAccessor(text_cluster)
public:
	inline Object_text_cluster(cairo_text_cluster_t *clusters, int num_clusters) :
		Object(Gura_UserClass(text_cluster)), _clusters(clusters), _num_clusters(num_clusters) {}
	virtual ~Object_text_cluster();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_text_cluster_t *GetClusters() { return _clusters; }
	inline int GetNumClusters() const { return _num_clusters; }
};

}}

#endif
