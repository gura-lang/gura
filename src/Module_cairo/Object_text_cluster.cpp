#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_text_cluster implementation
//-----------------------------------------------------------------------------
Object_text_cluster::~Object_text_cluster()
{
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
//#cairo_text_cluster_t *cairo_text_cluster_allocate(int num_clusters);
//#void cairo_text_cluster_free(cairo_text_cluster_t *clusters);

// implementation of class text_cluster
Gura_ImplementUserClass(text_cluster)
{
}

}}
