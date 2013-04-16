//
//  gunessistemi.cpp
//  İlyas Tunç
//  040070220
//	Proje II dersi Proje I Ödevi
//
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/SOIL.h>

GLdouble angle = 0;
GLint texture[6];
GLboolean isKeyDownZ = false;
GLboolean isKeyDownX = false;
GLfloat material_shininess[] = { 20 };
GLdouble M_PI= 3.14;

int LoadGLTextures()									// Load Bitmaps And Convert To Textures
{
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
		"Data/Crate.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	texture[1] = SOIL_load_OGL_texture
		(
		"Data/earth.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	texture[2] = SOIL_load_OGL_texture
		(
		"Data/moon.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	texture[3] = SOIL_load_OGL_texture
		(
		"Data/mars.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	texture[4] = SOIL_load_OGL_texture
		(
		"Data/marsSat1.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	texture[5] = SOIL_load_OGL_texture
		(
		"Data/marsSat2.bmp",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	

	// Typical Texture Generation Using Data From The Bitmap
	/*
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
*/
	return true;										// Return Success
}

static void Key( unsigned char key, int x, int y){
    switch(key){
        case 'q':
            exit(0);
            break;
        case 'z':
            isKeyDownZ = true;
            break;
        case 'x':
            isKeyDownX = true;
            break;
        case 'c':
            material_shininess[0]+=5;
            break;
        case 'v':
            material_shininess[0]-=5;
            break;
    }
}
static void KeyUp( unsigned char key, int x, int y){
    isKeyDownZ = false;
    isKeyDownX = false;
    
}


static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    
    //GLUquadric* quadric = gluNewQuadric();
    
     
	
    glTranslatef(0.f, 0.f, -20.f);
	//gluLookAt(0,5,0,0,0,0,0,0,1);  //üssten bakmak için
    
	//gunes
	//glPushMatrix();
	//glEnable(GL_LIGHTING);
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	GLUquadric* quadric = gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluQuadricTexture(quadric, GL_TRUE);
	glRotated(90,1,0,0);
    glRotated(angle, 0, 1, 0);
    //glColor3ub(255, 0, 0);
    //glColor3f(1, 0, 0);
   
    gluSphere( quadric , 1 , 32 , 16 );
    //glPopMatrix();
    //glDisable(GL_LIGHTING);
    
	//dunya
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	gluQuadricTexture(quadric, GL_TRUE);
    glPushMatrix();
    //glColor3ub(0, 0, 1);
	//glColor3f(1, 0, 0);
    glTranslatef(5.f, 0.f, 0.f);
    //glRotated(90, 1, 0, 0);
	glRotatef(angle+0.3, 0,1,0);
    gluSphere( quadric , 0.7 , 32, 16);

	//ay
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	//glColor3ub(0, 1, 0);
	//glTranslatef(0.0f,1.0f,0.0f);
	//glRotated(90, 1, 0, 0);
	glRotatef(angle, 0,1,0);
	glTranslatef(1.5f,0.f,0.0f);
	glRotatef(angle, 0,1,0);
    gluSphere( quadric , 0.5 , 64 , 32 );
    glPopMatrix();

	//mars
	glBindTexture(GL_TEXTURE_2D, texture[3]);
    //glColor3ub(0, 0, 1);
    //glColor3f(0.5,1,0.0);
	glRotatef(angle,0,1,0);
    glTranslatef(8.f, 0.f, 0.f);
    //glRotated(90, 1, 0, 0);
	glRotatef(angle, 0,1,0);
    gluSphere( quadric , 0.4 , 32, 16);

	//mars uydu
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	//glColor3ub(0, 1, 0);
	//glColor3f(1,1,0);
	//glTranslatef(0.0f,0.0f,-1.0f);
	//glRotated(90, 1, 0, 0);
	glRotatef(angle, 0,1,0);
	glTranslatef(1.0f,0.f,0.0f);
	glRotatef(angle*2, 0,1,0);
    gluSphere( quadric , 0.2 , 64 , 32 );

	//mars uydu2
	glRotatef(angle, 0,1,0);
	glTranslatef(2.0f,0.f,0.0f);
	glRotatef(angle/3, 0,1,0);
    gluSphere( quadric , 0.1 , 64 , 32 );
        
    glutSwapBuffers();
    
}

static void timerCallback (int value)
{
 
    angle +=0.2;

	if( isKeyDownX ){
        angle-=5;
    }
    if( isKeyDownZ)
    {
        angle+=5;
    }
    
    /*GLfloat light_position[] = { cosf(angle*(M_PI/180) ), 1.0, sinf(angle*(M_PI/180) ), 0.0 };
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);
    
    */
    glutTimerFunc(10, timerCallback, 0);
    glutPostRedisplay();
}

//void setupLight(){
//    glEnable(GL_LIGHTING);
//    
//    GLfloat light_position[] = { 0.0, 0.0, .0, 1.0 };
//    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat light_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    
//    
//    glEnable(GL_LIGHT0);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    
//    GLfloat global_ambient[] = { 0.2,  0.2, 0.2, 1.0 };
//    
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
//    
//    glEnable(GL_COLOR_MATERIAL);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    
//    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
//    
//    
//    glMaterialfv(GL_FRONT,GL_SPECULAR, material_specular);
//    glMaterialfv(GL_FRONT,GL_AMBIENT, material_ambient);
//    glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);
//    
//    glShadeModel(GL_SMOOTH);
//}

int main (int argc, char ** argv)
{

    GLenum type;
    
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	type = GLUT_RGB;
	type |= GLUT_DOUBLE;
	type |= GLUT_DEPTH;
    type |= GLUT_MULTISAMPLE;
	glutInitDisplayMode(type);
	glutCreateWindow("Odev_1");
    
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective(55, 800/600, 0.1, 100);
    
	//setupLight();

    glMatrixMode(GL_MODELVIEW);
    
    timerCallback(0);
	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);
    glutDisplayFunc(Draw);
	glutKeyboardFunc(Key);
	glutKeyboardUpFunc(KeyUp);    
	glutMainLoop();
	
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

