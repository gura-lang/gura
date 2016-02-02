//=============================================================================
// Vertex
//=============================================================================
#ifndef __GURA_VERTEX_H__
#define __GURA_VERTEX_H__

namespace Gura {

//-----------------------------------------------------------------------------
// Vertex2
//-----------------------------------------------------------------------------
struct GURA_DLLDECLARE Vertex2 {
public:
	double x, y;
public:
	static const Vertex2 Zero;
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Vertex2");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	inline Vertex2() : x(0), y(0) {}
	inline Vertex2(double _x, double _y) : x(_x), y(_y) {}
	inline Vertex2(const Vertex2 &vertex) : x(vertex.x), y(vertex.y) {}
	String ToString() const;
};

//-----------------------------------------------------------------------------
// Vertex3
//-----------------------------------------------------------------------------
struct GURA_DLLDECLARE Vertex3 {
public:
	double x, y, z;
public:
	static const Vertex3 Zero;
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Vertex3");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	inline Vertex3() : x(0), y(0), z(0) {}
	inline Vertex3(double _x, double _y) : x(_x), y(_y), z(0) {}
	inline Vertex3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	inline Vertex3(const Vertex2 &vertex) : x(vertex.x), y(vertex.y), z(0.) {}
	inline Vertex3(const Vertex3 &vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {}
	String ToString() const;
};

//-----------------------------------------------------------------------------
// Vertex
//-----------------------------------------------------------------------------
struct GURA_DLLDECLARE Vertex {
public:
	double x, y, z, w;
public:
	static const Vertex Zero;
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Vertex");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	inline Vertex() : x(0), y(0), z(0), w(1.) {}
	inline Vertex(double _x, double _y) : x(_x), y(_y), z(0), w(1.) {}
	inline Vertex(double _x, double _y, double _z) : x(_x), y(_y), z(_z), w(1.) {}
	inline Vertex(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {}
	inline Vertex(const Vertex2 &vertex) : x(vertex.x), y(vertex.y), z(0.), w(1.) {}
	inline Vertex(const Vertex3 &vertex) : x(vertex.x), y(vertex.y), z(vertex.z), w(1.) {}
	inline Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z), w(vertex.w) {}
	Vertex Translate(double tx, double ty, double tz) const;
	Vertex RotateX(double rad) const;
	Vertex RotateY(double rad) const;
	Vertex RotateZ(double rad) const;
	static Vertex CalcNormal(const Vertex &v1, const Vertex &v2, const Vertex &v3, bool unitFlag);
	String ToString() const;
	static Vertex CreateFromValues(Environment &env, const ValueList &valList);
};

}

#endif
