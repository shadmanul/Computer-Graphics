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

void Wheels(float x, float y,float z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glPushMatrix();
	glRotatef(_reverseAngle,1,0,0);
	glPushMatrix();
	glRotatef(90,0,1,0);
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glutSolidTorus(.015,.1,12,12);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Moon(){
	glPushMatrix();
	glTranslatef(-55,55,-200);
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glNormal3f(1,1,1);
	glutSolidTorus(15,0,50,50);
	glPopMatrix();
	glPopMatrix();
}
void CarObject(){
	//Wheel Lines
	glPushMatrix();
	glTranslatef(0,-.3,-2);
	glPushMatrix();
	glColor3f(0,0,0);
	glLineWidth(10);
	glBegin(GL_LINES);
		glVertex3f(-0.31,.06,0);
		glVertex3f(0.31,.06,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.85,.06,-5.0);
		glVertex3f(0.85,.06,-5.0);
	glEnd();
	
	//Wheels
	glPushMatrix();
	glColor3f(1,1,.5);
		Wheels(-.29,.06,0);	//Buttom Left
		Wheels(.29,.06,0);	//Buttom Right
		Wheels(-0.35,.2,-1);	//Top Left
		Wheels(0.35,.2,-1);		//Top Right
		
	glPopMatrix();
		
	//BoX
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0.06,0.1);
	glPushMatrix();
	glScalef(0.8,1,1);
	glPushMatrix();
	glRotatef(17,1,0,0);
	glColor3f(0.4, 0.0, 0.0);
	glPushMatrix();
	glBegin(GL_QUADS);
		
		//Front
		glNormal3f(-1,0,1);
		glVertex3f(-0.3, 0.0, 0.2);
		glNormal3f(-1,0,1);
		glVertex3f(-0.3, 0.08, 0.2);
		glNormal3f(1,0,1);
		glVertex3f(0.3, 0.08, 0.2);
		glNormal3f(1,0,1);
		glVertex3f(0.3, 0.0, 0.2);

		//Left
		glNormal3f(-1,0,1);
		glVertex3f(-0.3, 0.0, 0.2);
		glNormal3f(-1,0,1);
		glVertex3f(-0.3, 0.08, 0.2);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.3, 0.08, -0.6);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.3, 0.0, -0.6);

		//Back
		glNormal3f(-1,0,-1);
		glVertex3f(-0.3, 0.0, -0.6);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.3, 0.08, -0.6);
		glNormal3f(1,0,-1);
		glVertex3f(0.3, 0.08, -0.6);
		glNormal3f(1,0,-1);
		glVertex3f(0.3, 0.0, -0.6);

		//Right
		glNormal3f(1,0,1);
		glVertex3f(0.3, 0.0, 0.2);
		glNormal3f(1,0,1);
		glVertex3f(0.3, 0.08, 0.2);
		glNormal3f(1,0,-1);
		glVertex3f(0.3, 0.08, -0.6);
		glNormal3f(1,0,-1);
		glVertex3f(0.3, 0.0, -0.6);

		//Top
		glNormal3f(-1,1,0);
		glVertex3f(-0.3, 0.08, 0.2);
		glNormal3f(-1,1,-1);
		glVertex3f(-0.3, 0.08, -0.6);
		glNormal3f(1,1,-1);
		glVertex3f(0.3, 0.08, -0.6);
		glNormal3f(1,1,0);
		glVertex3f(0.3, 0.08, 0.2);

		//top
		//Front
		glNormal3f(-1,0,1);
		glVertex3f(-0.2, 0.0, 0.1);
		glNormal3f(-1,0,1);
		glVertex3f(-0.2, 0.2, 0.1);
		glNormal3f(1,0,1);
		glVertex3f(0.2, 0.2, 0.1);
		glNormal3f(-1,0,1);
		glVertex3f(0.2, 0.08, 0.1);

		//Left
		glNormal3f(-1,0,1);
		glVertex3f(-0.2, 0.08, 0.1);
		glNormal3f(-1,0,1);
		glVertex3f(-0.2, 0.2, 0.1);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.2, 0.2, -0.5);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.2, 0.08, -0.5);

		//Back
		glNormal3f(-1,0,-1);
		glVertex3f(-0.2, 0.08, -0.5);
		glNormal3f(-1,0,-1);
		glVertex3f(-0.2, 0.2, -0.5);
		glNormal3f(1,0,-1);
		glVertex3f(0.2, 0.2, -0.5);
		glNormal3f(1,0,-1);
		glVertex3f(0.2, 0.08, -0.5);

		//Right
		glNormal3f(1,0,1);
		glVertex3f(0.2, 0.08, 0.1);
		glNormal3f(1,0,1);
		glVertex3f(0.2, 0.2, 0.1);
		glNormal3f(1,0,-1);
		glVertex3f(0.2, 0.2, -0.5);
		glNormal3f(1,0,-1);
		glVertex3f(0.2, 0.08, -0.5);

		//Top
		glNormal3f(-1,1,0);
		glVertex3f(-0.2, 0.2, 0.1);
		glNormal3f(-1,1,-1);
		glVertex3f(-0.2, 0.2, -0.5);
		glNormal3f(1,1,-1);
		glVertex3f(0.2, 0.2, -0.5);
		glNormal3f(1,1,0);
		glVertex3f(0.2, 0.2, 0.1);
	
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
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
			glutSolidTorus(7,20, 75,75);
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
	GLfloat ambientColor[] = {0.07,0.07,0.07,1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientColor);

	GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
	GLfloat lightPos0[] = {1.0f, 1.3f, -22.0f, 1.0f}; 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
	GLfloat lightPos1[] = {-1.0f, 1.3f, -22.0f, 1.0f}; 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	
	
	//Platform Border
	DottedLine(5.3);
	DottedLine(-5.3);
	//Platform
	Platform();
	//Car Object
	CarObject();
	
	Moon();
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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	glEnable(GL_SMOOTH);
	glClearColor(0.09, 0.09, 0.09, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.00, 1.0, 1000.0);
}


int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 550);
    glutCreateWindow("MID TERM ASSIGNMENT"); 
    //glutFullScreen();
	Initialize();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Exit);
	update(0);
	glutMainLoop();
	return 0;
}