#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_text_cluster implementation
//-----------------------------------------------------------------------------
Object_text_cluster::~Object_text_cluster()
{
	::cairo_text_cluster_free(_clusters);
}

Object *Object_text_cluster::Clone() const
{
	return NULL;
}

String Object_text_cluster::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.text_cluster>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_cluster
//-----------------------------------------------------------------------------
// cairo.text_cluster.allocate(num_clusters:number) {block?}
Gura_DeclareClassMethod(text_cluster, allocate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num_clusters", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(text_cluster, allocate)
{
	int num_clusters = args.GetInt(0);
	cairo_text_cluster_t *clusters = ::cairo_text_cluster_allocate(num_clusters);
	Object_text_cluster *pObjCluster = new Object_text_cluster(clusters, num_clusters);
	return ReturnValue(env, sig, args, Value(pObjCluster));
}

// implementation of class text_cluster
Gura_ImplementUserClass(text_cluster)
{
	Gura_AssignMethod(text_cluster, allocate);
}

Gura_EndModuleScope(cairo)
