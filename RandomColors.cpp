#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <GL/glut.h>
using namespace std;

float _angle = 30.0f;
int MaxColor = 255;
float RandomColor[12];

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}



//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units
	
	glPushMatrix(); //Save the transformations performed thus far
		glTranslatef(0.0f, -1.0f, 0.0f); //Move to the center of the trapezoid
		glRotatef(_angle, 0.0f, 0.0f, 1.0f); //Rotate about the z-axis
	
		glBegin(GL_QUADS);
	
		//Trapezoid
		glColor3f(RandomColor[0],RandomColor[6],RandomColor[5]);
		glVertex3f(-0.7f, -0.5f, 0.0f);
		glColor3f(RandomColor[7],RandomColor[1],RandomColor[10]);
		glVertex3f(0.7f, -0.5f, 0.0f);
		glColor3f(RandomColor[4],RandomColor[9],RandomColor[2]);
		glVertex3f(0.4f, 0.5f, 0.0f);
		glColor3f(RandomColor[8],RandomColor[3],RandomColor[11]);
		glVertex3f(-0.4f, 0.5f, 0.0f);
	
		glEnd();
	
	glPopMatrix(); //Undo the move to the center of the trapezoid
	glPushMatrix(); //Save the current state of transformations
		glTranslatef(1.0f, 1.0f, 0.0f); //Move to the center of the pentagon
		glRotatef(_angle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
		glScalef(0.7f, 0.7f, 0.7f); //Scale by 0.7 in the x, y, and z directions
	
		glBegin(GL_TRIANGLES);
	
		//Pentagon
		glColor3f(RandomColor[0],RandomColor[9],RandomColor[6]);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glColor3f(RandomColor[1],RandomColor[10],RandomColor[7]);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glColor3f(RandomColor[2],RandomColor[11],RandomColor[8]);
		glVertex3f(-0.5f, 0.0f, 0.0f);

		glColor3f(RandomColor[3],RandomColor[0],RandomColor[9]);
		glVertex3f(-0.5f, 0.0f, 0.0f);
		glColor3f(RandomColor[4],RandomColor[1],RandomColor[10]);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glColor3f(RandomColor[5],RandomColor[2],RandomColor[11]);
		glVertex3f(0.5f, 0.0f, 0.0f);
	
		glColor3f(RandomColor[6],RandomColor[3],RandomColor[0]);
		glVertex3f(-0.5f, 0.0f, 0.0f);
		glColor3f(RandomColor[7],RandomColor[4],RandomColor[1]);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glColor3f(RandomColor[8],RandomColor[5],RandomColor[2]);
		glVertex3f(0.0f, 0.5f, 0.0f);
	
		glEnd();
	
	glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
		glTranslatef(-1.0f, 1.0f, 0.0f); //Move to the center of the triangle
		glRotatef(_angle, 1.0f, 2.0f, 3.0f); //Rotate about the the vector (1, 2, 3)
	
		glBegin(GL_TRIANGLES);
	
		//Triangle
		glColor3f(RandomColor[0],RandomColor[1],RandomColor[6]);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glColor3f(RandomColor[2],RandomColor[4],RandomColor[11]);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glColor3f(RandomColor[3],RandomColor[5],RandomColor[9]);
		glVertex3f(-0.5f, -0.5f, 0.0f);
	
		glEnd();
	
	glPopMatrix(); //Undo the move to the center of the triangle
	
	glutSwapBuffers();
}

void update(int value) {
	for(int i = 0; i <12; i++){
		RandomColor[i] = ((double) rand() / (RAND_MAX));
	}
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	
	glutPostRedisplay();
	glutTimerFunc(75, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Transformations and Timers - videotutorialsrock.com");
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









