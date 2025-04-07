#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>

void menu(int item);
GLuint initshaders(GLenum type, const char *filename);
GLuint initprogram(GLuint, GLuint);
void display();

GLuint  shaderprogram;

// width and height of the window.
int Glut_w = 600, Glut_h = 400;

//Variables and their values for the camera setup.
myPoint3D camera_eye(0, 0, 2);
myVector3D camera_up(0, 1, 0);
myVector3D camera_forward(0, 0, -1);

float fovy = 45.0f;
float zNear = 0.1f;
float zFar = 6000;

int frame = 0, timebase = 0;
float fps = 0;

int button_pressed = 0; // 1 if a button is currently being pressed.
int GLUTmouse[2] = { 0, 0 };

#define NUM_BUFFERS 10
vector<GLuint> buffers(NUM_BUFFERS, 0);
vector<GLuint> vaos(NUM_BUFFERS, 0);
unsigned int num_triangles;

enum {
	BUFFER_VERTICES = 0, BUFFER_NORMALS_PERFACE, BUFFER_NORMALS_PERVERTEX, BUFFER_VERTICESFORNORMALDRAWING,
	BUFFER_INDICES_TRIANGLES, BUFFER_INDICES_EDGES, BUFFER_INDICES_VERTICES
};
enum { VAO_TRIANGLES_NORMSPERVERTEX = 0, VAO_TRIANGLES_NORMSPERFACE, VAO_EDGES, VAO_VERTICES, VAO_NORMALS };


bool smooth = false; //smooth = true means smooth normals, default false means face-wise normals.
bool drawmesh = true;
bool drawwireframe = false;
bool drawmeshvertices = false;
bool drawsilhouette = false;
bool drawnormals = false;
void makeBuffers(myMesh *input_mesh)
{
    std::cout << "==> Generating OpenGL buffers..." << std::endl;

    std::vector<GLfloat> verts, norms_per_face, norms, verts_and_normals;
    std::vector<GLuint> indices_edges, indices_vertices;
    num_triangles = 0;
    unsigned int index = 0;

    for (myFace* f : input_mesh->faces)
    {
        if (!f || !f->adjacent_halfedge || !f->normal) continue;

        // Collect all vertices of the face
        std::vector<myVertex*> face_verts;
        myHalfedge* start = f->adjacent_halfedge;
        myHalfedge* e = start;

        do {
            face_verts.push_back(e->source);
            e = e->next;
        } while (e && e != start);

        // Triangulate (fan triangulation)
        if (face_verts.size() < 3) continue;

        for (size_t i = 1; i < face_verts.size() - 1; ++i)
        {
            myVertex* v0 = face_verts[0];
            myVertex* v1 = face_verts[i];
            myVertex* v2 = face_verts[i + 1];

            if (!v0 || !v1 || !v2 || !v0->point || !v1->point || !v2->point) continue;

            verts.insert(verts.end(), {
                (GLfloat)v0->point->X, (GLfloat)v0->point->Y, (GLfloat)v0->point->Z,
                (GLfloat)v1->point->X, (GLfloat)v1->point->Y, (GLfloat)v1->point->Z,
                (GLfloat)v2->point->X, (GLfloat)v2->point->Y, (GLfloat)v2->point->Z
            });

            // Give indices for edge drawing
            v0->index = index++;
            v1->index = index++;
            v2->index = index++;

            // Face normals (same for all 3 vertices of the triangle)
            for (int j = 0; j < 3; ++j) {
                norms_per_face.insert(norms_per_face.end(), {
                    (GLfloat)f->normal->dX,
                    (GLfloat)f->normal->dY,
                    (GLfloat)f->normal->dZ
                });
            }

            if (v0->normal && v1->normal && v2->normal)
            {
                norms.insert(norms.end(), {
                    (GLfloat)v0->normal->dX, (GLfloat)v0->normal->dY, (GLfloat)v0->normal->dZ,
                    (GLfloat)v1->normal->dX, (GLfloat)v1->normal->dY, (GLfloat)v1->normal->dZ,
                    (GLfloat)v2->normal->dX, (GLfloat)v2->normal->dY, (GLfloat)v2->normal->dZ
                });
            }

            num_triangles++;
        }
    }

    // Vertices for drawing normals
    for (myVertex* v : input_mesh->vertices)
    {
        if (!v || !v->point || !v->normal) continue;

        verts_and_normals.insert(verts_and_normals.end(), {
            (GLfloat)v->point->X, (GLfloat)v->point->Y, (GLfloat)v->point->Z,
            (GLfloat)(v->point->X + v->normal->dX / 20.0f),
            (GLfloat)(v->point->Y + v->normal->dY / 20.0f),
            (GLfloat)(v->point->Z + v->normal->dZ / 20.0f)
        });

        indices_vertices.push_back(v->index);
    }

    // Edges
    for (myHalfedge* he : input_mesh->halfedges)
    {
        if (!he || !he->next || !he->source || !he->next->source) continue;
        indices_edges.push_back(he->source->index);
        indices_edges.push_back(he->next->source->index);
    }

    // === OpenGL buffer setup ===
    glDeleteBuffers(NUM_BUFFERS, &buffers[0]);
    buffers.assign(NUM_BUFFERS, 0);
    glGenBuffers(NUM_BUFFERS, &buffers[0]);

    if (!verts.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICES]);
        glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(GLfloat), verts.data(), GL_STATIC_DRAW);
    }

    if (!norms.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERVERTEX]);
        glBufferData(GL_ARRAY_BUFFER, norms.size() * sizeof(GLfloat), norms.data(), GL_STATIC_DRAW);
    }

    if (!norms_per_face.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_NORMALS_PERFACE]);
        glBufferData(GL_ARRAY_BUFFER, norms_per_face.size() * sizeof(GLfloat), norms_per_face.data(), GL_STATIC_DRAW);
    }

    if (!verts_and_normals.empty()) {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTICESFORNORMALDRAWING]);
        glBufferData(GL_ARRAY_BUFFER, verts_and_normals.size() * sizeof(GLfloat), verts_and_normals.data(), GL_STATIC_DRAW);
    }

    if (!indices_edges.empty()) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_EDGES]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_edges.size() * sizeof(GLuint), indices_edges.data(), GL_STATIC_DRAW);
    }

    if (!indices_vertices.empty()) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[BUFFER_INDICES_VERTICES]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_vertices.size() * sizeof(GLuint), indices_vertices.data(), GL_STATIC_DRAW);
    }

    std::cout << "✅ Buffers generated. Triangles: " << num_triangles << std::endl;
}


void draw_text(GLfloat x, GLfloat y, GLfloat z, string text, vector<GLfloat> color)
{
	glUseProgram(0);

	GLfloat w = 1;
	GLfloat fx, fy;
	glColor3f(color[0], color[1], color[2]);

	glPushAttrib(GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDepthRange(z, z);
	glViewport((int)x - 1, (int)y - 1, 2, 2);

	fx = x - (int)x;
	fy = y - (int)y;
	glRasterPos4f(fx, fy, 0.0, w);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glPopAttrib();

	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)text.c_str());
	glUseProgram(shaderprogram);
}

bool PickedPoint(int x, int y)
{
	// Check position
	if ((x < 0) || (Glut_w <= x) || (y < 0) || (Glut_h <= y)) {
		printf("Pick (%d,%d) outside viewport: (0,%d) (0,%d)\n", x, y, Glut_w, Glut_h);
		return false;
	}

	// Allocate select buffer
	const int SELECT_BUFFER_SIZE = 1024;
	GLuint select_buffer[SELECT_BUFFER_SIZE];
	GLint select_buffer_hits;

	// Initialize select buffer
	glSelectBuffer(SELECT_BUFFER_SIZE, select_buffer);
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);

	// Initialize view transformation
	GLint viewport[4];
	glViewport(0, 0, Glut_w, Glut_h);
	glGetIntegerv(GL_VIEWPORT, viewport);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPickMatrix((GLdouble)x, (GLdouble)y, 1, 1, viewport);
	// Set projection transformation
	// NOTE: THIS MUST MATCH CODE IN GLUTRedraw
	gluPerspective(fovy, Glut_w / (float)Glut_h, zNear, zFar);

	// Set camera transformation
	// NOTE: THIS MUST MATCH CODE IN GLUTRedraw
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera_eye.X, camera_eye.Y, camera_eye.Z, camera_eye.X + camera_forward.dX, camera_eye.Y + camera_forward.dY, camera_eye.Z + camera_forward.dZ, camera_up.dX, camera_up.dY, camera_up.dZ);

	// Draw mesh with pick names into selection buffer
	glLoadName(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int i = 0;
	for (vector<myFace *>::iterator it = m->faces.begin(); it != m->faces.end(); it++)
	{
		glLoadName(++i);
		glBegin(GL_POLYGON);
		myHalfedge *e = (*it)->adjacent_halfedge;
		myVertex *v;

		v = e->source;
		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);

		e = e->next; v = e->source;
		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);

		e = e->next; v = e->source;
		glVertex3f((float)v->point->X, (float)v->point->Y, (float)v->point->Z);
		glEnd();

	}

	glFlush();
	select_buffer_hits = glRenderMode(GL_RENDER);

	// Process select buffer to find front-most hit
	int hit = 0;
	GLuint hit_z = 0xFFFFFFFF;
	GLuint *bufp = select_buffer;
	GLuint numnames, z1, z2;
	for (int i = 0; i < select_buffer_hits; i++) {
		numnames = *bufp++;
		z1 = *bufp++;
		z2 = *bufp++;
		while (numnames--) {
			if (z1 < hit_z) {
				hit = (int)*bufp;
				hit_z = z1 / 2 + z2 / 2;
			}
			bufp++;
		}
	}

	// Return closest face
	if ((hit > 0)) {
		// Find face
		//if (pick_face) {
		// Subtract one because added one in glLoadName
		closest_face = m->faces[hit - 1];

		// }

		// Find hit position
		if (pickedpoint) {
			GLdouble p[3];
			GLdouble modelview_matrix[16];
			GLdouble projection_matrix[16];
			GLint viewport[16];
			glGetDoublev(GL_MODELVIEW_MATRIX, modelview_matrix);
			glGetDoublev(GL_PROJECTION_MATRIX, projection_matrix);
			glGetIntegerv(GL_VIEWPORT, viewport);
			GLdouble z = (GLdouble)hit_z / (GLdouble)0xFFFFFFFF;
			gluUnProject(x, y, z, modelview_matrix, projection_matrix, viewport, &(p[0]), &(p[1]), &(p[2]));
			pickedpoint->X = p[0];
			pickedpoint->Y = p[1];
			pickedpoint->Z = p[2];
		}

		// Return hit
		//cout << "true\n";
		return true;
	}
	else {
		// Return no hit
		//cout << "false\n";
		return false;
	}
}


//This function is called when a mouse button is pressed.
void mouse(int button, int state, int x, int y)
{
	// Remember button state 
	button_pressed = (state == GLUT_DOWN) ? 1 : 0;

	// Remember mouse position 
	GLUTmouse[0] = x;
	GLUTmouse[1] = Glut_h - y;

	int mode = glutGetModifiers();
	// Process mouse button event
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON) {
			if (mode == GLUT_ACTIVE_CTRL)
			{
				glUseProgram(0);
				pickedpoint = new myPoint3D();
				if (!PickedPoint(x, Glut_h - y)) delete pickedpoint;
				glUseProgram(shaderprogram);
				menu(MENU_SELECTVERTEX);
			}
			if (mode == GLUT_ACTIVE_SHIFT) {
			}
		}
		else if (button == GLUT_MIDDLE_BUTTON) {}
		else if (button == GLUT_RIGHT_BUTTON) {}
	}

	if (state == GLUT_UP)
	{
	}

	glutPostRedisplay();
}

//This function is called when the mouse is dragged.
void mousedrag(int x, int y)
{
	// Invert y coordinate
	y = Glut_h - y;

	//change in the mouse position since last time
	int dx = x - GLUTmouse[0];
	int dy = y - GLUTmouse[1];

	GLUTmouse[0] = x;
	GLUTmouse[1] = y;

	if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) return;
	if ((dx == 0 && dy == 0) || !button_pressed) return;

	double vx = (double)dx / (double)Glut_w;
	double vy = (double)dy / (double)Glut_h;
	double theta = 4.0 * (fabs(vx) + fabs(vy));

	myVector3D camera_right = camera_forward.crossproduct(camera_up);
	camera_right.normalize();

	myVector3D tomovein_direction = -camera_right*vx + -camera_up*vy;

	myVector3D rotation_axis = tomovein_direction.crossproduct(camera_forward);
	rotation_axis.normalize();

	camera_forward.rotate(rotation_axis, theta);
	camera_up.rotate(rotation_axis, theta);
	camera_eye.rotate(rotation_axis, theta);

	camera_up.normalize();
	camera_forward.normalize();

	glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
		camera_eye += camera_forward * 0.02;
	else
		camera_eye += -camera_forward * 0.02;
	glutPostRedisplay();
}


//This function is called when an arrow key is pressed.
void keyboard2(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		camera_eye += camera_forward * 0.01;
		break;
	case GLUT_KEY_DOWN:
		camera_eye += -camera_forward * 0.01;
		break;
	case GLUT_KEY_LEFT:
		camera_up.normalize();
		camera_forward.rotate(camera_up, 0.01);
		camera_forward.normalize();
		break;
	case GLUT_KEY_RIGHT:
		camera_up.normalize();
		camera_forward.rotate(camera_up, -0.01);
		camera_forward.normalize();
		break;
	}
	glutPostRedisplay();
}


void timerFunc(int lastTime)
{
	frame++;
	int time = glutGet(GLUT_ELAPSED_TIME);

	int diffTime = time - timebase;
	if (diffTime > 200) {
		fps = frame * 1000.0f / diffTime;
		timebase = time;
		frame = 0;
	}
	glutPostRedisplay();
	glutTimerFunc((1000 + lastTime - time)/60, timerFunc, time);  
}


void reshape(int width, int height) {
	Glut_w = width;
	Glut_h = height;

	glutPostRedisplay();
}


//This function is called when a key is pressed.
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:  // Escape to quit
		m->clear();
		glDeleteBuffers(10, &buffers[0]);
		glDeleteVertexArrays(10, &vaos[0]);
		exit(0);
		break;
	case 'm':
		break;
	case 'h':
		cout << "The keys for various algorithms are:\n";
		break;
	}
	glutPostRedisplay();
}


void initInterface(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("My 4I-IG3 Application!");

	glewInit();
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	glutReshapeWindow(Glut_w, Glut_h);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard2);
	glutMotionFunc(mousedrag);
	glutMouseFunc(mouse);
	glutMouseWheelFunc(mouseWheel);
	glutTimerFunc(1000.0/60, timerFunc, 0);
	

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(1, 1, 1, 0);

	glEnable(GL_MULTISAMPLE);

	GLuint vertexshader = initshaders(GL_VERTEX_SHADER, "shaders/light.vert.glsl");
	GLuint fragmentshader = initshaders(GL_FRAGMENT_SHADER, "shaders/light.frag.glsl");
	shaderprogram = initprogram(vertexshader, fragmentshader);


	int sm1 = glutCreateMenu(menu);
	glutAddMenuEntry("Vertex-shading/face-shading", MENU_SHADINGTYPE);
	glutAddMenuEntry("Mesh", MENU_DRAWMESH);
	glutAddMenuEntry("Wireframe", MENU_DRAWWIREFRAME);
	glutAddMenuEntry("Vertices", MENU_DRAWMESHVERTICES);
	glutAddMenuEntry("Normals", MENU_DRAWNORMALS);
	glutAddMenuEntry("Silhouette", MENU_DRAWSILHOUETTE);
	glutAddMenuEntry("Crease", MENU_DRAWCREASE);

	int sm2 = glutCreateMenu(menu);
	glutAddMenuEntry("Catmull-Clark subdivision", MENU_CATMULLCLARK);
	glutAddMenuEntry("Loop subdivision", MENU_LOOP);
	glutAddMenuEntry("Inflate", MENU_INFLATE);
	glutAddMenuEntry("Smoothen", MENU_SMOOTHEN);
	glutAddMenuEntry("Simplification", MENU_SIMPLIFY);

	int sm3 = glutCreateMenu(menu);
	glutAddMenuEntry("Closest Edge", MENU_SELECTEDGE);
	glutAddMenuEntry("Closest Face", MENU_SELECTFACE);
	glutAddMenuEntry("Closest Vertex", MENU_SELECTVERTEX);
	glutAddMenuEntry("Clear", MENU_SELECTCLEAR);

	int sm4 = glutCreateMenu(menu);
	glutAddMenuEntry("Split edge", MENU_SPLITEDGE);
	glutAddMenuEntry("Split face", MENU_SPLITFACE);
	glutAddMenuEntry("Contract edge", MENU_CONTRACTEDGE);
	glutAddMenuEntry("Contract face", MENU_CONTRACTFACE);

	int m = glutCreateMenu(menu);
	glutAddSubMenu("Draw", sm1);
	glutAddSubMenu("Mesh Operations", sm2);
	glutAddSubMenu("Select", sm3);
	glutAddSubMenu("Face Operations", sm4);
	glutAddMenuEntry("Open File", MENU_OPENFILE);
	glutAddMenuEntry("Triangulate", MENU_TRIANGULATE);
	glutAddMenuEntry("Write to File", MENU_WRITE);
	glutAddMenuEntry("Undo", MENU_UNDO);
	glutAddMenuEntry("Generate Mesh", MENU_GENERATE);
	glutAddMenuEntry("Cut Mesh", MENU_CUT);
	glutAddMenuEntry("Exit", MENU_EXIT);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

}










// This is a basic program to initiate a shader
// The textFileRead function reads in a filename into a string
// programerrors and shadererrors output compilation errors
// initshaders initiates a vertex or fragment shader
// initprogram initiates a program with vertex and fragment shaders

string textFileRead(const char * filename) {
	string str, ret = "";
	ifstream in;
	in.open(filename);
	if (in.is_open()) {
		getline(in, str);
		while (in) {
			ret += str + "\n";
			getline(in, str);
		}
		//    cout << "Shader below\n" << ret << "\n" ; 
		return ret;
	}
	else {
		cerr << "Unable to Open File " << filename << "\n";
		throw 2;
	}
}

void programerrors(const GLint program) {
	GLint length;
	GLchar * log;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
	log = new GLchar[length + 1];
	glGetProgramInfoLog(program, length, &length, log);
	cout << "Compile Error, Log Below\n" << log << "\n";
	delete[] log;
}
void shadererrors(const GLint shader) {
	GLint length;
	GLchar * log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
	log = new GLchar[length + 1];
	glGetShaderInfoLog(shader, length, &length, log);
	cout << "Compile Error, Log Below\n" << log << "\n";
	delete[] log;
}

GLuint initshaders(GLenum type, const char *filename)
{
	// Using GLSL shaders, OpenGL book, page 679 

	GLuint shader = glCreateShader(type);
	GLint compiled;
	string str = textFileRead(filename);
	GLchar * cstr = new GLchar[str.size() + 1];
	const GLchar * cstr2 = cstr; // Weirdness to get a const char
	strncpy(cstr, str.c_str(), str.size() + 1);
	glShaderSource(shader, 1, &cstr2, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		shadererrors(shader);
		throw 3;
	}
	return shader;
}

GLuint initprogram(GLuint vertexshader, GLuint fragmentshader)
{
	GLuint program = glCreateProgram();
	GLint linked;
	glAttachShader(program, vertexshader);
	glAttachShader(program, fragmentshader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (linked) glUseProgram(program);
	else {
		programerrors(program);
		throw 4;
	}
	return program;
}
