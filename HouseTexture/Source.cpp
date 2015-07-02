#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "imageloader.h"
using namespace std;

float _angle = 0.0f;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId[7]; //The id of the texture

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);*/
	
	Image* grass = loadBMP("grass.bmp");
	_textureId[0] = loadTexture(grass);
	delete grass;

	Image* bricks = loadBMP("bricks.bmp");
	_textureId[1] = loadTexture(bricks);
	delete bricks;

	Image* bricksrotated = loadBMP("bricksrotated.bmp");
	_textureId[2] = loadTexture(bricksrotated);
	delete bricksrotated;

	Image* roof = loadBMP("roof.bmp");
	_textureId[3] = loadTexture(roof);
	delete roof;

	Image* door = loadBMP("door.bmp");
	_textureId[4] = loadTexture(door);
	delete door;

	Image* window = loadBMP("window.bmp");
	_textureId[5] = loadTexture(window);
	delete window;

	Image* sky = loadBMP("sky.bmp");
	_textureId[6] = loadTexture(sky);
	delete sky;
}

void handleResize(int w, int h) {
	glClearColor(1,1,1,1);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1, 1.0, 200.0);
}
void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	

	//Grass
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -50.0f);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-22.5, -22.5, 0);
	glTexCoord2f(0.0f, 10.0f);
	glVertex3f(-22.5, 0, 0);
	glTexCoord2f(10.0f, 10.0f);
	glVertex3f(22.5, 0, 0);
	glTexCoord2f(10.0f, 0.0f);
	glVertex3f(22.5, -22.5, 0);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, _textureId[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -50.0f);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-22.5, 0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-22.5, 22.5, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(22.5, 22.5, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(22.5, 0, 0);
	glEnd();
	glPopMatrix();

	
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//House Body
	glPushMatrix();
	glTranslatef(3.0f, 0.0f, -30.0f);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(35,0,1,0);
	glBegin(GL_QUADS);
	
	//front
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, -3, 0);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(-3, 3, 0);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(3, 3, 0);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(3, -3, 0);
	//left
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, -3, 0);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(-3, 3, 0);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(-3, 3, -10);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(-3, -3, -10);
	//back
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, -3, -10);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(-3, 3, -10);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(3, 3, -10);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(3, -3, -10);
	//right
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(3, -3, 0);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(3, 3, 0);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(3, 3, -10);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(3, -3, -10);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_TRIANGLES);
	//front top triangle
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, 3, 0);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(3, 3, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 7, 0);
	//back top triangle
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3, 3, -10);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(3, 3, -10);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0, 7, -10);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, _textureId[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	//left roof
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-4, 1.67, 1);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(0, 7, 1);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(0, 7, -11);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(-4, 1.67, -11);
	//right roof
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(4, 1.67, 1);
	glTexCoord2f(0.0f, 1.5f);
	glVertex3f(0, 7, 1);
	glTexCoord2f(1.5f, 1.5f);
	glVertex3f(0, 7, -11);
	glTexCoord2f(1.5f, 0.0f);
	glVertex3f(4, 1.67, -11);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, _textureId[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	//door
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1,-3,.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1,-3,.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1,2,.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1,2,.1);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, _textureId[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	//window
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.1,-1.5,-2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3.1,1,-2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-3.1,1,-4);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.1,-1.5,-4);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.1,-1.5,-6);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-3.1,1,-6);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-3.1,1,-8);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.1,-1.5,-8);

	glEnd();

	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glFlush();	
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 500);
	
	glutCreateWindow("Textures - videotutorialsrock.com");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	
	glutMainLoop();
	return 0;
}