#include "myMesh.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <GL/glew.h>
#include "myVector3D.h"

using namespace std;

myMesh::myMesh(void)
{
    /**** TODO ****/
}

myMesh::~myMesh(void)
{
    /**** TODO ****/
}

void myMesh::clear()
{
    for (unsigned int i = 0; i < vertices.size(); i++)
        if (vertices[i])
            delete vertices[i];
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (halfedges[i])
            delete halfedges[i];
    for (unsigned int i = 0; i < faces.size(); i++)
        if (faces[i])
            delete faces[i];

    vector<myVertex *> empty_vertices;
    vertices.swap(empty_vertices);
    vector<myHalfedge *> empty_halfedges;
    halfedges.swap(empty_halfedges);
    vector<myFace *> empty_faces;
    faces.swap(empty_faces);
}

void myMesh::checkMesh()
{
    vector<myHalfedge *>::iterator it;
    for (it = halfedges.begin(); it != halfedges.end(); it++)
    {
        if ((*it)->twin == NULL)
            break;
    }
    if (it != halfedges.end())
        cout << "Error! Not all edges have their twins!\n";
    else
        cout << "Each edge has a twin!\n";
}
bool myMesh::readFile(std::string filename)
{
    string s, t, u;
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Unable to open file!\n";
        return false;
    }

    name = filename;

    map<pair<int, int>, myHalfedge *> twin_map;

    while (getline(fin, s)) {
        stringstream myline(s);
        myline >> t;

        if (t == "v") {
            float x, y, z;
            myline >> x >> y >> z;
            myPoint3D* p = new myPoint3D(x, y, z);
            myVertex* v = new myVertex;
            v->point = p;
            v->outgoing_halfedge = nullptr;
            vertices.push_back(v);
        } else if (t == "f") {
            vector<int> v_indices;
            while (myline >> u) {
                int idx = atoi((u.substr(0, u.find("/"))).c_str()) - 1;
                v_indices.push_back(idx);
            }

            int n = v_indices.size();
            if (n < 3) continue;

            myFace* face = new myFace;
            faces.push_back(face);

            vector<myHalfedge*> hedge_list(n);

            for (int i = 0; i < n; ++i) {
                myHalfedge* he = new myHalfedge;
                hedge_list[i] = he;
                halfedges.push_back(he);

                he->source = vertices[v_indices[i]];
                he->adjacent_face = face;

                if (!vertices[v_indices[i]]->outgoing_halfedge)
                    vertices[v_indices[i]]->outgoing_halfedge = he;

                int from = v_indices[i];
                int to = v_indices[(i + 1) % n];
                pair<int, int> edge = make_pair(from, to);
                pair<int, int> twin_edge = make_pair(to, from);

                if (twin_map.find(twin_edge) != twin_map.end()) {
                    myHalfedge* twin = twin_map[twin_edge];
                    he->twin = twin;
                    twin->twin = he;
                } else {
                    twin_map[edge] = he;
                }
            }

            for (int i = 0; i < n; ++i) {
                hedge_list[i]->next = hedge_list[(i + 1) % n];
                hedge_list[(i + 1) % n]->prev = hedge_list[i];
            }

            face->adjacent_halfedge = hedge_list[0];
        }
    }

    checkMesh();
    normalize();

    return true;
}

void myMesh::computeNormals()
{
    /**** TODO ****/
}
void myMesh::normalize()
{
	if (vertices.size() < 1) return;

	int tmpxmin = 0, tmpymin = 0, tmpzmin = 0, tmpxmax = 0, tmpymax = 0, tmpzmax = 0;

	for (unsigned int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->point->X < vertices[tmpxmin]->point->X) tmpxmin = i;
		if (vertices[i]->point->X > vertices[tmpxmax]->point->X) tmpxmax = i;

		if (vertices[i]->point->Y < vertices[tmpymin]->point->Y) tmpymin = i;
		if (vertices[i]->point->Y > vertices[tmpymax]->point->Y) tmpymax = i;

		if (vertices[i]->point->Z < vertices[tmpzmin]->point->Z) tmpzmin = i;
		if (vertices[i]->point->Z > vertices[tmpzmax]->point->Z) tmpzmax = i;
	}

	double xmin = vertices[tmpxmin]->point->X, xmax = vertices[tmpxmax]->point->X,
		ymin = vertices[tmpymin]->point->Y, ymax = vertices[tmpymax]->point->Y,
		zmin = vertices[tmpzmin]->point->Z, zmax = vertices[tmpzmax]->point->Z;

	double scale = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	scale = scale > (zmax - zmin) ? scale : (zmax - zmin);

	for (unsigned int i = 0; i < vertices.size(); i++) {
		vertices[i]->point->X -= (xmax + xmin) / 2;
		vertices[i]->point->Y -= (ymax + ymin) / 2;
		vertices[i]->point->Z -= (zmax + zmin) / 2;

		vertices[i]->point->X /= scale;
		vertices[i]->point->Y /= scale;
		vertices[i]->point->Z /= scale;
	}
}

void myMesh::splitFaceTRIS(myFace *f, myPoint3D *p)
{
    /**** TODO ****/
}

void myMesh::splitEdge(myHalfedge *e1, myPoint3D *p)
{

    /**** TODO ****/
}

void myMesh::splitFaceQUADS(myFace *f, myPoint3D *p)
{
    /**** TODO ****/
}

void myMesh::subdivisionCatmullClark()
{
    /**** TODO ****/
}

void myMesh::triangulate()
{
    /**** TODO ****/
}

// return false if already triangle, true othewise.
bool myMesh::triangulate(myFace *f)
{
    /**** TODO ****/
    return false;
}
