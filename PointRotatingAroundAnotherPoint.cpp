#include <gl/glut.h>
float angle = 0;
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glPointSize(7);
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
		glBegin(GL_POINTS);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glEnd();
	glPopMatrix();
	
	
	glFlush();  
}
void update(int value){
	angle += 0.1;
	if (angle > 360){
		angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(1,update,0);
}
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1.0, 1.0, 1.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350, 350);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("AIUB");
	Initialize();
	glutDisplayFunc(Draw);
	glutTimerFunc(1000, update,0);
	glutMainLoop();

	return 0; 
}