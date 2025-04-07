#pragma once
#include "myPoint3D.h"

class myHalfedge;
class myVector3D;

class myVertex
{
public:
	myPoint3D *point;
	myHalfedge *originof;
	myHalfedge *outgoing_halfedge; //outgoing halfedge

	int index;  //use as you wish.

	myVector3D *normal;

	void computeNormal();
	myVertex(void);
	~myVertex(void);
};
