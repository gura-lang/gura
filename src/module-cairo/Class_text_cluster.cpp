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
	return nullptr;
}

String Object_text_cluster::ToString(bool exprFlag)
{
	return String("<cairo.text_cluster>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_cluster
//-----------------------------------------------------------------------------
// cairo.text_cluster.allocate(num_clusters:number) {block?}
Gura_DeclareClassMethod(text_cluster, allocate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num_clusters", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(text_cluster, allocate)
{
	int num_clusters = arg.GetInt(0);
	cairo_text_cluster_t *clusters = ::cairo_text_cluster_allocate(num_clusters);
	Object_text_cluster *pObjCluster = new Object_text_cluster(clusters, num_clusters);
	return ReturnValue(env, arg, Value(pObjCluster));
}

// implementation of class text_cluster
Gura_ImplementUserClass(text_cluster)
{
	Gura_AssignMethod(text_cluster, allocate);
}

Gura_EndModuleScope(cairo)
