#include <gl/glut.h>
#include <math.h>

float _angle = 0.0;
float _reverseAngle = 360;
const float DEG2RAD = 3.14159/180;
float radius = 27;

void DottedLine(float x){
	glPushMatrix();
	glTranslatef(x,-22.5,-30.0);
	glPushMatrix();
	glRotatef(_angle,1,0,0);
	glPushMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glColor3f(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
 
	   for (int i=0; i <= 360; i+=5)
	   {
		  float degInRad = i*DEG2RAD;
		  glVertex3f(cos(degInRad)*radius,sin(degInRad)*radius,0);
	   }
 
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Wheels(float x, float y){
	glPushMatrix();
		glTranslatef(x,y,0);
		glPushMatrix();
		glRotatef(_reverseAngle,1,0,0);
		glPushMatrix();
		glRotatef(90,0,1,0);
		glPushMatrix();
		glutSolidTorus(.004,.035,8,8);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
}
void CarObject(){
	//Wheel Lines
	glPushMatrix();
	glTranslatef(0,-.3,-2);
	glPushMatrix();
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex3f(-.40,.06,0);
		glVertex3f(.40,.06,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-.32,.2,0);
		glVertex3f(.32,.2,0);
	glEnd();

	//Wheels
	glPushMatrix();
	glColor3f(1,1,.5);
		Wheels(-.37,.06);	//Buttom Left
		Wheels(.37,.06);	//Buttom Right
		Wheels(-.31,.2);	//Top Left
		Wheels(.31,.2);		//Top Right
	glPopMatrix();
		
	//BoX
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
		glVertex3f(-0.35, 0.0, 0.0);
		glColor3f(0, 0, 0);
		glVertex3f(0.35, 0.0, 0.0);
		glColor3f(0.5, 0.2, 0.3);
		glVertex3f(0.27, 0.25, 0.0);
		glColor3f(0.1, 0.6, 0.4);
		glVertex3f(-0.27, 0.25, 0.0);
		glEnd();
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUADS);
		glColor3f(0.1, 0.5, 0.12);
		glVertex3f(-0.27, 0.06, 0.0);
		glColor3f(0.2, 0.6, 0.11);
		glVertex3f(0.27, 0.06, 0.0);
		glColor3f(0.3, 0.7, 0.1);
		glVertex3f(0.24, 0.22, 0.0);
		glColor3f(0.4, 0.8, 0.9);
		glVertex3f(-0.24, 0.22, 0.0);
		glEnd();
	glPopMatrix();
	glPopMatrix();
}
void Platform(){
	glColor3f(0.8, 0.4, 0.2);
	glPushMatrix();
	glTranslatef(0.0,-25,-30.0); 
	glPushMatrix();
		glRotatef(_angle,1,0,0);
		glPushMatrix();
		glRotatef(90, 0.0, 1.0, 0.0);
		glPushMatrix();        
			glutSolidTorus(7,20, 25,25);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void Exit(unsigned char key, int x, int y){
	switch (key) {
		case 27:
			exit(0);
	}
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // just keep
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//Platform Border
	DottedLine(5.3);
	DottedLine(-5.3);
	//Platform
	Platform();
	//Car Object
	CarObject();
	
	
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
	_reverseAngle -= 10;
	if(_reverseAngle < 0){
		_reverseAngle = 360;
	}

	glutPostRedisplay();
	glutTimerFunc(20,update,0);
}


void Initialize() {
	glClearColor(0.53, 0.81, 0.98, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 200.0);
}


int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
    glutCreateWindow("MID TERM ASSIGNMENT"); 
    glutFullScreen();
	Initialize();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Exit);
	update(0);
	glutMainLoop();
	return 0;
}