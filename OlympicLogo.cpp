#include <gl/glut.h>

float _angle = 0.0;


void Draw() {
	float x = 0;
	float y = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // just keep
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (float i = -4; i <= 4; i += 4){
		if (i == -4){
			glColor3f(1.6, 1.7, 0.3);
			x = 0;
			y = 1;
		}
		else if (i == 0){
			glColor3f(0.4, 0.0, 0.0);
			x = 1;
			y = 1;
		}
		else{
			glColor3f(0.0, 0.0, 1.0);
			x = 1;
			y = 0;
		}
		glPushMatrix();
			glTranslatef(i, 0.0, -30.0);
			glPushMatrix();
				glRotatef(_angle, x, y, 0.0);
				glPushMatrix();
					glutSolidTorus(0.3, 1.5, 15, 35);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	}
	for (float i = -2; i <= 2; i += 4){
		if (i == -2){
			glColor3f(0.6, 0.7, 1.3);
			x = 1;
			y = 0;
		}
		else {
			glColor3f(1.4, 0.0, 0.0);
			x = 0;
			y = 1;
		}
		glPushMatrix();
			glTranslatef(i, -2.0, -30.0);
			glPushMatrix();
				glRotatef(_angle, x, y, 0.0);
				glPushMatrix();
					glutSolidTorus(0.3, 1.5, 15, 35);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	}
	glFlush();
	glutSwapBuffers();
}


void update(int value)
{
	_angle += 0.5;
	if (_angle > 360)
	{
		_angle = 0.0;
	}

	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}


void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("AIUB");
	Initialize();
	glutDisplayFunc(Draw);
	update(0);
	glutMainLoop();
	return 0;
}