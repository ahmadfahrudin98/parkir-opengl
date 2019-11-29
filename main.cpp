#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

static float angle=0.0,ratio;
static float x=0.0f,y=1.75f,z=5.0f;
static float lx=0.10f,ly=0.10f,lz=-1.0f;
static GLint carr_display_list,house_display_list, pohon_display_list, panzer_display_list,awan_display_list;
float theta=0.01,fxincr=0.1,fzincr=0,temp,theta1,fx=-10,fz=80;
int xxxx=0,yyyy=0,kk=0,housevisible=0, pohonvisible=0,panzervisible=0,awanvisible=0,movecarvar=0;
int a[36]={55,97,44,152,55,171,108,86,168,99,147,207,238,55,233,167,105,80,134,29,253,130,32,240,110,199,224,121,93,199,180,61,110,251,77,237};
int b[36]={102,194,110,152,153,184,137,113,55,138,104,43,240,255,203,8,100,53,88,64,127,64,87,5,2,144,211,128,10,89,27,11,175,185,157,241};
int c[36]={159,243,133,253,233,228,141,18,46,195,75,52,253,204,169,30,78,94,68,117,4,2,33,12,2,25,195,76,26,54,98,103,205,173,65,242};

void changeSize(int w, int h)
{
 // Prevent a divide by zero, when window is too short
 // (you cant make a window of zero width).
if(h == 0)
h = 1;
ratio = 1.0f * w / h;
 // Reset the coordinate system before modifying
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

 // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

 // Set the clipping volume
 gluPerspective(45,ratio,1,1000);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(x, y, z,
        x + lx,y + ly,z + lz,
     0.0f,1.0f,0.0f);


 }

void pohon()
{
    // Draw daun cone
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,2, 0.0f);
	glScaled(2.5,2.5,2.5);
	glRotated(-90,1,0,0);
	glutSolidCone(1,2,60,1);
	glPopMatrix();



	// Draw batang
	glPushMatrix();
	glColor3f(0.8f, 0.4f, 0.1f);     // coklat
    glTranslatef(0.0f, 1.5f, 0.0f);
    glScaled(1.1,6,1);
    glutSolidCube(0.5f);
    glPopMatrix();

}

void awan()
        {

         glPushMatrix();
         glColor3f(1, 1, 1);
          glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
         glutSolidSphere(10, 50, 50);
         glPopMatrix();
         glPushMatrix();
         glTranslatef(10,0,1);
         glutSolidSphere(5, 50, 50);
         glPopMatrix();
         glPushMatrix();
         glTranslatef(-2,6,-2);
         glutSolidSphere(7, 50, 50);
         glPopMatrix();
         glPushMatrix();
         glTranslatef(-10,-3,0);
         glutSolidSphere(7, 50, 50);
         glPopMatrix();
         glPushMatrix();
         glTranslatef(6,-2,2);
         glutSolidSphere(7, 50, 50);
         glPopMatrix();

        }


void drawcarr()
{

glTranslatef(.0,0.8,0.0);
glEnable(GL_BLEND);//TRANCPARENCY1
  glBlendFunc(GL_ONE, GL_ZERO);//TRANCPARENCY2
   //glColor3f(1.0,1.0,1.0);
  // glBegin(
   //glVertex3f(

glBegin(GL_LINE_LOOP);
 glVertex3f(-1.12,-.48,0.7);//a
 glVertex3f(-0.86,-.48,0.7);//b
 glVertex3f(-.74,-0.2,0.7);//c
 glVertex3f(-.42,-.2,0.7);//d
 glVertex3f(-0.3,-.48,0.7);//e
 glVertex3f(.81,-0.48,0.7);//f
 glVertex3f(.94,-0.2,0.7);//g
 glVertex3f(1.24,-.2,0.7);//h
 glVertex3f(1.38,-.48,0.7);//i
 glVertex3f(1.52,-.44,0.7);//j
 glVertex3f(1.52,.14,0.7);//k
 glVertex3f(1.14,0.22,0.7);//l
 glVertex3f(0.76,.22,0.7);//m
 glVertex3f(.52,0.56,0.7);//n
 glVertex3f(-0.1,0.6,0.7);//0
 glVertex3f(-1.02,0.6,0.7);//p
 glVertex3f(-1.2,0.22,0.7);//q
 glVertex3f(-1.2,-.28,0.7);//r
 glEnd();

glBegin(GL_LINE_LOOP);
 glVertex3f(-1.12,-.48,-0.7);//a'
 glVertex3f(-0.86,-.48,-0.7);//b'
 glVertex3f(-.74,-0.2,-0.7);//c'
 glVertex3f(-.42,-.2,-0.7);//d'
 glVertex3f(-0.3,-.48,-0.7);//e'
 glVertex3f(.81,-0.48,-0.7);//f'
 glVertex3f(.94,-0.2,-0.7);//g'
 glVertex3f(1.24,-.2,-0.7);//h'
 glVertex3f(1.38,-.48,-0.7);//i'
 glVertex3f(1.52,-.44,-0.7);//j'
 glVertex3f(1.52,.14,-0.7);//k'
 glVertex3f(1.14,0.22,-0.7);//l'
 glVertex3f(0.76,.22,-0.7);//m'
 glVertex3f(.52,0.56,-0.7);//n'
 glVertex3f(-0.1,0.6,-0.7);//o'
 glVertex3f(-1.02,0.6,-0.7);//p'
 glVertex3f(-1.2,0.22,-0.7);//q'
 glVertex3f(-1.2,-.28,-0.7);//r'
 glEnd();

glBegin(GL_LINES);
 glVertex3f(-1.12,-.48,0.7);//a
 glVertex3f(-1.12,-.48,-0.7);//a'
 glVertex3f(-0.86,-.48,0.7);//b
 glVertex3f(-0.86,-.48,-0.7);//b'
 glVertex3f(-.74,-0.2,0.7);//c
 glVertex3f(-.74,-0.2,-0.7);//c'
 glVertex3f(-.42,-.2,0.7);//d
 glVertex3f(-.42,-.2,-0.7);//d'
 glVertex3f(-0.3,-.48,0.7);//e
 glVertex3f(-0.3,-.48,-0.7);//e'
 glVertex3f(.81,-0.48,0.7);//f
 glVertex3f(.81,-0.48,-0.7);//f'
 glVertex3f(.94,-0.2,0.7);//g
 glVertex3f(.94,-0.2,-0.7);//g'
 glVertex3f(1.24,-.2,0.7);//h
 glVertex3f(1.24,-.2,-0.7);//h'
 glVertex3f(1.38,-.48,0.7);//i
 glVertex3f(1.38,-.48,-0.7);//i'
 glVertex3f(1.52,-.44,0.7);//j
 glVertex3f(1.52,-.44,-0.7);//j'
 glVertex3f(1.52,.14,0.7);//k
 glVertex3f(1.52,.14,-0.7);//k'
 glVertex3f(1.14,0.22,0.7);//l
 glVertex3f(1.14,0.22,-0.7);//l'
 glVertex3f(0.76,.22,0.7);//m
 glVertex3f(0.76,.22,-0.7);//m'
 glVertex3f(.52,0.56,0.7);//n
 glVertex3f(.52,0.56,-0.7);//n'
 glVertex3f(-0.1,0.6,0.7);//0
 glVertex3f(-0.1,0.6,-0.7);//o'
 glVertex3f(-1.02,0.6,0.7);//p
 glVertex3f(-1.02,0.6,-0.7);//p'
 glVertex3f(-1.2,0.22,0.7);//q
 glVertex3f(-1.2,0.22,-0.7);//q'
 glVertex3f(-1.2,-.28,0.7);//r
 glVertex3f(-1.2,-.28,-0.7);//r'
glEnd();

 // top filling
glBegin(GL_POLYGON);
 glVertex3f(-0.1,0.6,0.7);//o
 glVertex3f(-0.1,0.6,-0.7);//o'
 glVertex3f(-1.02,0.6,-0.7);//p'
 glVertex3f(-1.02,0.6,0.7);//p
glEnd();


glBegin(GL_POLYGON);
 glVertex3f(-0.1,0.6,0.7);//o
 glVertex3f(-0.1,0.6,-0.7);//o'
 glVertex3f(.52,0.56,-0.7);//n'
 glVertex3f(.52,0.56,0.7);//n
glEnd();

 //back filling
glBegin(GL_POLYGON);
 glVertex3f(-1.2,0.22,0.7);//q
 glVertex3f(-1.2,0.22,-0.7);//q'
 glVertex3f(-1.2,-.28,-0.7);//r'
 glVertex3f(-1.2,-.28,0.7);//r
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(1.52,.14,0.7);//k
 glVertex3f(1.14,0.22,0.7);//l
 glVertex3f(1.14,0.22,-0.7);//l'
 glVertex3f(1.52,.14,-0.7);//k'
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(0.76,.22,0.7);//m
 glVertex3f(0.76,.22,-0.7);//m'
 glVertex3f(1.14,0.22,-0.7);//l'
 glVertex3f(1.14,0.22,0.7);//l
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(-1.12,-.48,0.7);//a
 glVertex3f(-0.86,-.48,0.7);//b
 glVertex3f(-.74,-0.2,0.7);//c
 glVertex3f(-0.64,0.22,0.7);//cc
 glVertex3f(-1.08,0.22,0.7);//dd
 glVertex3f(-1.2,0.22,0.7);//q
 glVertex3f(-1.2,-.28,0.7);//r
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-.74,-0.2,0.7);//c
glVertex3f(-0.64,0.22,0.7);//cc
glVertex3f(-0.5,0.22,0.7);//hh
glVertex3f(-0.5,-0.2,0.7);//pp
glEnd();
glBegin(GL_POLYGON);
glVertex3f(0.0,0.22,0.7);//gg
glVertex3f(1.14,0.22,0.7);//l
glVertex3f(1.24,-.2,0.7);//h
glVertex3f(0.0,-0.2,0.7);//oo

glEnd();
//
glBegin(GL_POLYGON);

 glVertex3f(-1.12,-.48,-0.7);//a'
 glVertex3f(-0.86,-.48,-0.7);//b'
 glVertex3f(-.74,-0.2,-0.7);//c'
 glVertex3f(-0.64,0.22,-0.7);//cc'
 glVertex3f(-1.08,0.22,-0.7);//dd'
 glVertex3f(-1.2,0.22,-0.7);//q'
 glVertex3f(-1.2,-.28,-0.7);//r'
glEnd();

glBegin(GL_POLYGON);

glVertex3f(-.74,-0.2,-0.7);//c'
glVertex3f(-0.64,0.22,-0.7);//cc'
glVertex3f(-0.5,0.22,-0.7);//hh'
glVertex3f(-0.5,-0.2,-0.7);//pp'

glEnd();
glBegin(GL_POLYGON);
glVertex3f(0.0,0.22,-0.7);//gg'
glVertex3f(1.14,0.22,-0.7);//l'
glVertex3f(1.24,-.2,-0.7);//h'
glVertex3f(0.0,-0.2,-0.7);//oo'

glEnd();


glBegin(GL_POLYGON);
glVertex3f(-1.2,0.22,0.7);//q
glVertex3f(-1.08,0.22,0.7);//dd
glVertex3f(-0.98,0.5,0.7);//aa
glVertex3f(-1.02,0.6,0.7);//p
glEnd();


glBegin(GL_POLYGON);
glVertex3f(-1.02,0.6,0.7);//p
glVertex3f(-0.98,0.5,0.7);//aa
glVertex3f(0.44,0.5,0.7);//jj
glVertex3f(.52,0.56,0.7);//n
glVertex3f(-0.1,0.6,0.7);//0
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-0.64,0.5,0.7);//bb
glVertex3f(-0.64,0.22,0.7);//cc
glVertex3f(-0.5,0.22,0.7);//hh
glVertex3f(-0.5,0.5,0.7);//ee
glEnd();

glBegin(GL_POLYGON);
glVertex3f(0.0,0.5,0.7);//ff
glVertex3f(0.0,0.22,0.7);//gg
glVertex3f(0.12,0.22,0.7);//ll
glVertex3f(0.12,0.5,0.7);//ii
glEnd();

glBegin(GL_POLYGON);
glVertex3f(.52,0.56,0.7);//n
glVertex3f(0.44,0.5,0.7);//jj
glVertex3f(0.62,0.22,0.7);//kk
glVertex3f(0.76,.22,0.7);//m
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-.42,-.2,0.7);//d
glVertex3f(.94,-0.2,0.7);//g
glVertex3f(.81,-0.48,0.7);//f
glVertex3f(-0.3,-.48,0.7);//e
glEnd();

glBegin(GL_POLYGON);
glVertex3f(1.14,0.22,0.7);//l
glVertex3f(1.52,.14,0.7);//k
glVertex3f(1.52,-.44,0.7);//j
glVertex3f(1.38,-.48,0.7);//i
glVertex3f(1.24,-.2,0.7);//h
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-1.2,0.22,-0.7);//q'
glVertex3f(-1.08,0.22,-0.7);//dd'
glVertex3f(-0.98,0.5,-0.7);//aa'
glVertex3f(-1.02,0.6,-0.7);//p'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-1.02,0.6,-0.7);//p'
glVertex3f(-0.98,0.5,-0.7);//aa'
glVertex3f(0.44,0.5,-0.7);//jj'
glVertex3f(.52,0.56,-0.7);//n'
glVertex3f(-0.1,0.6,-0.7);//0'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-0.64,0.5,-0.7);//bb'
glVertex3f(-0.64,0.22,-0.7);//cc'
glVertex3f(-0.5,0.22,-0.7);//hh'
glVertex3f(-0.5,0.5,-0.7);//ee'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(0.0,0.5,-0.7);//ff'
glVertex3f(0.0,0.22,-0.7);//gg'
glVertex3f(0.12,0.22,-0.7);//ll'
glVertex3f(0.12,0.5,-0.7);//ii'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(.52,0.56,-0.7);//n'
glVertex3f(0.44,0.5,-0.7);//jj'
glVertex3f(0.62,0.22,-0.7);//kk'
glVertex3f(0.76,.22,-0.7);//m'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(-.42,-.2,-0.7);//d'
glVertex3f(.94,-0.2,-0.7);//g'
glVertex3f(.81,-0.48,-0.7);//f'
glVertex3f(-0.3,-.48,-0.7);//e'
glEnd();

glBegin(GL_POLYGON);
glVertex3f(1.14,0.22,-0.7);//l'
glVertex3f(1.52,.14,-0.7);//k'
glVertex3f(1.52,-.44,-0.7);//j'
glVertex3f(1.38,-.48,-0.7);//i'
glVertex3f(1.24,-.2,-0.7);//h'
glEnd();

 // door1 body- rear, near
glBegin(GL_POLYGON);
glVertex3f(-0.5,0.22,0.7);//hh
glVertex3f(0.0,0.22,0.7);//gg
glVertex3f(0.0,-0.2,0.7);//oo
glVertex3f(-0.5,-0.2,0.7);//pp
glEnd();

// door body- rear, far
glBegin(GL_POLYGON);
glVertex3f(-0.5,0.22,-0.7);//hh'
glVertex3f(0.0,0.22,-0.7);//gg'
glVertex3f(0.0,-0.2,-0.7);//oo'
glVertex3f(-0.5,-0.2,-0.7);//pp'
glEnd();

// door2  body- near, driver

glBegin(GL_POLYGON);
glVertex3f(0.12,0.22,0.7);//ll
glVertex3f(0.62,0.22,0.7);//kk
glVertex3f(0.62,-0.2,0.7);//mm
glVertex3f(0.12,-0.2,0.7);//nn
glEnd();

// door2  body- far, driver

glBegin(GL_POLYGON);
 glVertex3f(0.12,0.22,-0.7);//ll'
glVertex3f(0.62,0.22,-0.7);//kk'
glVertex3f(0.62,-0.2,-0.7);//mm'
glVertex3f(0.12,-0.2,-0.7);//nn'
glEnd();

glBegin(GL_POLYGON);//front**
 glVertex3f(1.52,.14,0.7);//k
 glVertex3f(1.52,.14,-0.7);//k'
 glVertex3f(1.52,-.44,-0.7);//j'
 glVertex3f(1.52,-.44,0.7);//j
glEnd();

glTranslatef(-.58,-.52,0.7);//translate to 1st tyre
glColor3f(0.09,0.09,0.09);// warna bagian ban
glutSolidTorus(0.12f, .14f, 10, 25);
glTranslatef(1.68,0.0,0.0);//translate to 2nd tyre
glutSolidTorus(0.12f, .14f, 10, 25);

glTranslatef(0.0,0.0,-1.4);//translate to 3rd tyre
glutSolidTorus(0.12f, .14f, 10, 25);
glTranslatef(-1.68,0.0,0.0);//translate to 4th tyre which is behind 1st tyre i.e rear .back
glutSolidTorus(0.12f, .14f, 10, 25);
glTranslatef(.58,.52,0.7);//translate to origin
glRotatef(90.0,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-1.40);

glutSolidTorus(0.2f, .2f, 10, 25);

glTranslatef(0.0,0.0,1.40);
glRotatef(270.0,0.0,1.0,0.0);

 //bottom filling
glBegin(GL_POLYGON);
glColor3f(0.50,0.75,0.50); //warna bagian bawah
 glVertex3f(-0.3,-.48,0.7);//e
 glVertex3f(-0.3,-.48,-0.7);//e'
 glVertex3f(.81,-0.48,-0.7);//f'
 glVertex3f(.81,-0.48,0.7);//f
glEnd();




glBegin(GL_POLYGON);
 glVertex3f(-.42,-.2,0.7);//d
 glVertex3f(-.42,-.2,-0.7);//d'
 glVertex3f(-0.3,-.48,-0.7);//e'
 glVertex3f(-0.3,-.48,0.7);//e
glEnd();

glBegin(GL_POLYGON);

glVertex3f(-1.2,-.28,0.7);//r
glVertex3f(-1.2,-.28,-0.7);//r'
glVertex3f(-1.12,-.48,-0.7);//a'
glVertex3f(-1.12,-.48,0.7);//a

glEnd();

glBegin(GL_POLYGON);
 glVertex3f(-1.12,-.48,0.7);//a
 glVertex3f(-1.12,-.48,-0.7);//a'
 glVertex3f(-0.86,-.48,-0.7);//b'
 glVertex3f(-0.86,-.48,0.7);//b
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(-0.86,-.48,0.7);//b
 glVertex3f(-0.86,-.48,-0.7);//b'
 glVertex3f(-.74,-0.2,-0.7);//c'
 glVertex3f(-.74,-0.2,0.7);//c
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(-.74,-0.2,0.7);//c
 glVertex3f(-.74,-0.2,-0.7);//c'
 glVertex3f(-.42,-.2,-0.7);//d'
 glVertex3f(-.42,-.2,0.7);//d
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(.81,-0.48,0.7);//f
 glVertex3f(.81,-0.48,-0.7);//f'
 glVertex3f(.94,-0.2,-0.7);//g'
 glVertex3f(.94,-0.2,0.7);//g
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(.94,-0.2,0.7);//g
 glVertex3f(.94,-0.2,-0.7);//g'
 glVertex3f(1.24,-.2,-0.7);//h'
 glVertex3f(1.24,-.2,0.7);//h
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(1.24,-.2,0.7);//h
 glVertex3f(1.24,-.2,-0.7);//h'
 glVertex3f(1.38,-.48,-0.7);//i'
 glVertex3f(1.38,-.48,0.7);//i
glEnd();

glBegin(GL_POLYGON);
 glVertex3f(1.38,-.48,0.7);//i
 glVertex3f(1.38,-.48,-0.7);//i'
 glVertex3f(1.52,-.44,-0.7);//j'
 glVertex3f(1.52,-.44,0.7);//j
glEnd();

//********************************************************************************************8


// door outline- rear, front
glBegin(GL_LINE_LOOP);
glColor3f(1.0,1.0,1.0);//warna bagian pintu depan
glVertex3f(-0.5,0.22,0.7);//hh
glVertex3f(0.0,0.22,0.7);//gg
glVertex3f(0.0,-0.2,0.7);//oo
glVertex3f(-0.5,-0.2,0.7);//pp


glEnd();



// door2 outline- near, driver

glBegin(GL_LINE_LOOP);

glVertex3f(0.12,0.22,0.7);//ll
glVertex3f(0.62,0.22,0.7);//kk
glVertex3f(0.62,-0.2,0.7);//mm
glVertex3f(0.12,-0.2,0.7);//nn
glEnd();


glColor3f(1.0,1.0,1.0);//warna jendela ke 2
// door2  outline- far, driver

glBegin(GL_LINE_LOOP);

glVertex3f(0.12,0.22,-0.7);//ll'
glVertex3f(0.62,0.22,-0.7);//kk'
glVertex3f(0.62,-0.2,-0.7);//mm'
glVertex3f(0.12,-0.2,-0.7);//nn'
glEnd();

// door outline- rear, far
glBegin(GL_LINE_LOOP);

glVertex3f(-0.5,0.22,-0.7);//hh'
glVertex3f(0.0,0.22,-0.7);//gg'
glVertex3f(0.0,-0.2,-0.7);//oo'
glVertex3f(-0.5,-0.2,-0.7);//pp'


glEnd();
glBegin(GL_POLYGON);//front**
glVertex3f(1.52,.14,0.7);//k
glVertex3f(1.52,.14,-0.7);//k'
glVertex3f(1.52,-.44,-0.7);//j'
glVertex3f(1.52,-.44,0.7);//j

glEnd();

glColor3f(0.0,0.0,0.0);

 // transparent objects are placed next ..

 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//TRANCPARENCY3

//windscreen
 glBegin(GL_POLYGON);
glColor4f(0.1,0.0,0.0,0.7);   //COLOR =WHITE TRANSPARENT
 glVertex3f(0.562,.5,.6);//AAA
 glVertex3f(.562,.5,-.6);//AAA'
 glVertex3f(.76,.22,-.6);//MMM'
 glVertex3f(.76,.22,.6);//MMM

glEnd();
//rear window
glBegin(GL_POLYGON);
   //COLOR =WHITE TRANSPARENT

 glVertex3f(-1.068,0.5,0.6);//pp
 glVertex3f(-1.068,0.5,-0.6);//pp'
 glVertex3f(-1.2,0.22,-0.6);//qq'
 glVertex3f(-1.2,0.22,0.6);//qq

glEnd();
//leftmost window front
glBegin(GL_POLYGON);
 glVertex3f(-0.98,0.5,0.7);//aa
 glVertex3f(-0.64,0.5,0.7);//bb
 glVertex3f(-0.64,0.22,0.7);//cc
 glVertex3f(-1.08,0.22,0.7);//dd
glEnd();

//leftmost window back
glBegin(GL_POLYGON);

 glVertex3f(-0.98,0.5,-0.7);//aa
 glVertex3f(-0.64,0.5,-0.7);//bb
 glVertex3f(-0.64,0.22,-0.7);//cc
 glVertex3f(-1.08,0.22,-0.7);//dd
glEnd();

//middle window front

glBegin(GL_POLYGON);

glVertex3f(-0.5,0.5,0.7);
glVertex3f(0.0,0.5,0.7);
glVertex3f(0.0,0.22,0.7);
glVertex3f(-0.5,0.22,0.7);

glEnd();

//middle window back

glBegin(GL_POLYGON);

glVertex3f(-0.5,0.5,-0.7);
glVertex3f(0.0,0.5,-0.7);
glVertex3f(0.0,0.22,-0.7);
glVertex3f(-0.5,0.22,-0.7);

glEnd();
//rightmost window front

glBegin(GL_POLYGON);

glVertex3f(0.12,0.5,0.7);//ii
glVertex3f(0.44,0.5,0.7);//jj
glVertex3f(0.62,0.22,0.7);//kk
glVertex3f(0.12,0.22,0.7);//ll


glEnd();


//rightmost window back

glBegin(GL_POLYGON);

glVertex3f(0.12,0.5,-0.7);//ii'
glVertex3f(0.44,0.5,-0.7);//jj'
glVertex3f(0.62,0.22,-0.7);//kk'
glVertex3f(0.12,0.22,-0.7);//ll'


glEnd();


////car code ends here
glColor3f(0.0,0.0,0.0);

}

void drawhouse()
{
 glBegin(GL_LINE_LOOP);

    glVertex3f(-2.6,-.84,2.5);//m
    glVertex3f(-2.6,0.84,2.5);//n
    glVertex3f(-3.04,0.84,2.8);//o
    glVertex3f(0,1.95,2.8);//p
    glVertex3f(3.04,0.84,2.8);//w
    glVertex3f(2.6,0.84,2.5);//q
    glVertex3f(2.6,-0.84,2.5);//r
       glVertex3f(1.59,-0.84,2.5);//s
    glVertex3f(1.59,0.16,2.5);//t
    glVertex3f(-1.59,0.16,2.5);//u
    glVertex3f(-1.59,-0.84,2.5);//v
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(1.59,-0.84,2.5);//s
       glVertex3f(-1.59,-0.84,2.5);//v
    glEnd();

    glBegin(GL_LINE_LOOP);
       glVertex3f(-2.6,-.84,-2.5);//m'
    glVertex3f(-2.6,0.84,-2.5);//n'
    glVertex3f(-3.04,0.84,-2.8);//o'
    glVertex3f(0,1.95,-2.8);//p'
    glVertex3f(3.04,0.84,-2.8);//w'
    glVertex3f(2.6,0.84,-2.5);//q'
    glVertex3f(2.6,-0.84,-2.5);//r'
       glVertex3f(1.59,-0.84,-2.5);//s'
    glVertex3f(1.59,0.16,-2.5);//t'
    glVertex3f(-1.59,0.16,-2.5);//u'
    glVertex3f(-1.59,-0.84,-2.5);//v'
       glEnd();

       glBegin(GL_LINES);
       glVertex3f(-2.6,-.84,2.5);//m
     glVertex3f(-2.6,-.84,-2.5);//m'
        glVertex3f(-2.6,0.84,2.5);//n
  glVertex3f(-2.6,0.84,-2.5);//n'
         glVertex3f(-3.04,0.84,2.8);//o
   glVertex3f(-3.04,0.84,-2.8);//o'
   glVertex3f(0,1.95,2.8);//p
    glVertex3f(0,1.95,-2.8);//p'

    glVertex3f(3.04,0.84,2.8);//w
       glVertex3f(3.04,0.84,-2.8);//w'
    glVertex3f(2.6,0.84,2.5);//q
    glVertex3f(2.6,0.84,-2.5);//q'
    glVertex3f(2.6,-0.84,2.5);//r
    glVertex3f(2.6,-0.84,-2.5);//r'
       glVertex3f(1.59,-0.84,2.5);//s
       glVertex3f(1.59,-0.84,-2.5);//s'

    glVertex3f(-1.59,-0.84,2.5);//v
       glVertex3f(-1.59,-0.84,-2.5);//v'


    glEnd();
    glColor3ub(75,83,32);//warna rumah bgian body

    glBegin(GL_QUADS);
        glVertex3f(-2.6,-.84,2.5);//m
  glVertex3f(-2.6,0.16,2.5);//uu
  glVertex3f(-1.59,0.16,2.5);//u
  glVertex3f(-1.59,-0.84,2.5);//v

       glVertex3f(-2.6,0.16,2.5);//uu
       glVertex3f(-2.6,0.84,2.5);//n
     glVertex3f(2.6,0.84,2.5);//q
  glVertex3f(2.6,0.16,2.5);//tt


     glVertex3f(1.59,-0.84,2.5);//s
    glVertex3f(1.59,0.16,2.5);//t
        glVertex3f(2.6,0.16,2.5);//tt
   glVertex3f(2.6,-0.84,2.5);//r


        glVertex3f(-2.6,-.84,-2.5);//m'
  glVertex3f(-2.6,0.16,-2.5);//uu'
  glVertex3f(-1.59,0.16,-2.5);//u'
  glVertex3f(-1.59,-0.84,-2.5);//v'

       glVertex3f(-2.6,0.16,-2.5);//uu'
       glVertex3f(-2.6,0.84,-2.5);//n'
     glVertex3f(2.6,0.84,-2.5);//q'
  glVertex3f(2.6,0.16,-2.5);//tt'


     glVertex3f(1.59,-0.84,-2.5);//s'
    glVertex3f(1.59,0.16,-2.5);//t'
        glVertex3f(2.6,0.16,-2.5);//tt'
   glVertex3f(2.6,-0.84,-2.5);//r'

   glVertex3f(-2.6,-.84,2.5);//m
     glVertex3f(-2.6,-.84,-2.5);//m'
        glVertex3f(-2.6,0.84,-2.5);//n'
  glVertex3f(-2.6,0.84,2.5);//n

  glVertex3f(2.6,0.84,2.5);//q
    glVertex3f(2.6,0.84,-2.5);//q'
    glVertex3f(2.6,-0.84,-2.5);//r'
    glVertex3f(2.6,-0.84,2.5);//r

    glEnd();


   glBegin(GL_TRIANGLES);
glVertex3f(0,1.95,2.5);//p
      glVertex3f(3.04,0.84,2.5);//w
         glVertex3f(-3.04,0.84,2.5);//o
   glVertex3f(0,1.95,-2.5);//p'
      glVertex3f(3.04,0.84,-2.5);//w'
         glVertex3f(-3.04,0.84,-2.5);//o'

glEnd();
  glColor3ub(0,0,0);//warna rumah atap

    glBegin(GL_QUADS);

     glVertex3f(0,1.95,2.8);//p
    glVertex3f(0,1.95,-2.8);//p'
       glVertex3f(3.04,0.84,-2.8);//w'
       glVertex3f(3.04,0.84,2.8);//w

     glVertex3f(-3.04,0.84,2.8);//o
   glVertex3f(-3.04,0.84,-2.8);//o'
   glVertex3f(0,1.95,-2.8);//p'
    glVertex3f(0,1.95,2.8);//p

          glEnd();

     glColor3ub(0,0,0);//*******base color

    glBegin(GL_QUADS);
    glVertex3f(-2.6,-.84,2.5);//m
          glVertex3f(2.6,-0.84,2.5);//r
    glVertex3f(2.6,-0.84,-2.5);//r'
    glVertex3f(-2.6,-.84,-2.5);//m'
    glEnd();
}

void panzer()
{
    glPushMatrix();
//============== BEGIN BODY PANZER=====================//
    glTranslatef(2.0,0.0,0.0);
    //bagian bawah
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(1.0,0.0,0.0);
        glVertex3f(1.0,0.0,-2.5);
        glVertex3f(0.0,0.0,-2.5);
    glEnd();

    //awal  depan bagian setengah ke atas
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord2f(1.0,0.0);glVertex3f(-0.3,0.5,0.0);
        glTexCoord2f(1.0,1.0);glVertex3f(-0.3,0.5,-1.0);
        glTexCoord2f(0.0,1.0);glVertex3f(-0.15,0.8,-1.0);
        glTexCoord2f(0.0,0.0);glVertex3f(-0.15,0.8,-0.105);
        glVertex3f(-0.2,0.6,0.01);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
        glTexCoord2f(1.0,0.0);glVertex3f(1.3,0.5,0.0);
        glTexCoord2f(1.0,1.0);glVertex3f(1.3,0.5,-1.0);
        glTexCoord2f(0.0,1.0);glVertex3f(1.15,0.8,-1.0);
        glTexCoord2f(0.0,0.0);glVertex3f(1.15,0.8,-0.105);
        glVertex3f(1.2,0.6,0.01);
    glEnd();

    //atap
    glBegin(GL_QUADS);
        glTexCoord2f(1.0,0.0);glVertex3f(1.15,0.8,-0.105);
        glTexCoord2f(1.0,1.0);glVertex3f(1.15,0.8,-1.0);
        glTexCoord2f(0.0,1.0);glVertex3f(-0.15,0.8,-1.0);
        glTexCoord2f(0.0,0.0);glVertex3f(-0.15,0.8,-0.105);
        glVertex3f(0.5,0.8,0.0);
    glEnd();

    //link tengah
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(1.3,0.5,-1.0);glVertex3f(1.3,0.5,-1.0);
        glTexCoord3f(1.2,0.9,-1.1);glVertex3f(1.2,0.9,-1.1);
        glTexCoord3f(1.15,0.8,-1.0);glVertex3f(1.15,0.8,-1.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(-0.3,0.5,-1.0);glVertex3f(-0.3,0.5,-1.0);
        glTexCoord3f(-0.2,0.9,-1.1);glVertex3f(-0.2,0.9,-1.1);
        glTexCoord3f(-0.15,0.8,-1.0);glVertex3f(-0.15,0.8,-1.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(1.15,0.8,-1.0);glVertex3f(1.15,0.8,-1.0);
        glTexCoord3f(1.2,0.9,-1.1);glVertex3f(1.2,0.9,-1.1);
        glTexCoord3f(-0.2,0.9,-1.1);glVertex3f(-0.2,0.9,-1.1);
        glTexCoord3f(-0.15,0.8,-1.0);glVertex3f(-0.15,0.8,-1.0);
    glEnd();

    //atas setengah kebelakang
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(1.2,0.9,-2.6);glVertex3f(1.2,0.9,-2.6);
        glTexCoord3f(1.3,0.5,-2.5);glVertex3f(1.3,0.5,-2.5);
        glTexCoord3f(1.0,0.5,-2.5);glVertex3f(1.0,0.5,-2.5);
        glTexCoord3f(1.0,0.0,-2.5);glVertex3f(1.0,0.0,-2.5);
        glTexCoord3f(0.0,0.0,-2.5);glVertex3f(0.0,0.0,-2.5);
        glTexCoord3f(-0.1,0.5,-2.5);glVertex3f(-0.1,0.5,-2.5);
        glTexCoord3f(-0.3,0.5,-2.5);glVertex3f(-0.3,0.5,-2.5);
        glTexCoord3f(-0.2,0.9,-2.6);glVertex3f(-0.2,0.9,-2.6);
    glEnd();

    //frame pintu belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(0.9,0.85,-2.61);
        glVertex3f(0.1,0.85,-2.61);
        glVertex3f(0.1,0.05,-2.61);
        glVertex3f(0.9,0.05,-2.61);
    glEnd();

    //pintu belakang
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.1);
        glVertex3f(0.7,0.82,-2.615);
        glVertex3f(0.15,0.82,-2.615);
        glVertex3f(0.15,0.07,-2.615);
        glVertex3f(0.7,0.07,-2.615);
    glEnd();
    //badan naik
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord2f(0.0,0.0);glVertex3f(1.2,0.9,-1.1);
        glTexCoord2f(1.0,0.0);glVertex3f(-0.2,0.9,-1.1);
        glTexCoord2f(1.0,1.0);glVertex3f(-0.2,0.9,-2.6);
        glTexCoord2f(0.0,1.0);glVertex3f(1.2,0.9,-2.6);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);glVertex3f(1.3,0.5,-2.5);
        glTexCoord2f(1.0,0.0);glVertex3f(1.2,0.9,-2.6);
        glTexCoord2f(1.0,1.0);glVertex3f(1.2,0.9,-1.1);
        glTexCoord2f(0.0,1.0);glVertex3f(1.3,0.5,-1.0);
    glEnd();

    //samping kanan
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);glVertex3f(-0.3,0.5,-2.5);
        glTexCoord2f(1.0,0.0);glVertex3f(-0.2,0.9,-2.6);
        glTexCoord2f(1.0,1.0);glVertex3f(-0.2,0.9,-1.1);
        glTexCoord2f(0.0,1.0);glVertex3f(-0.3,0.5,-1.0);
    glEnd();

    //awal bemper depan atas
    //kanan atas I
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(-0.3,0.5,0.0);glVertex3f(-0.3,0.5,0.0);
        glTexCoord3f(-0.2,0.6,0.01);glVertex3f(-0.2,0.6,0.01);
        glTexCoord3f(-0.105,0.55,0.3);glVertex3f(-0.105,0.55,0.3);
        glTexCoord3f(-0.15,0.5,0.3);glVertex3f(-0.15,0.5,0.3);
    glEnd();

    //kanan atas II
    glBegin(GL_QUADS);
        glTexCoord3f(-0.15,0.5,0.3);glVertex3f(-0.15,0.5,0.3);
        glTexCoord3f(0.1,0.5,0.5);glVertex3f(0.1,0.5,0.5);
        glTexCoord3f(0.15,0.52,0.48);glVertex3f(0.15,0.52,0.48);
        glTexCoord3f(-0.105,0.55,0.3);glVertex3f(-0.105,0.55,0.3);
    glEnd();

    //kiri atas I
    glBegin(GL_QUADS);
        glTexCoord3f(1.3,0.5,0.0);glVertex3f(1.3,0.5,0.0);
        glTexCoord3f(1.15,0.5,0.3);glVertex3f(1.15,0.5,0.3);
        glTexCoord3f(1.1,0.55,0.3);glVertex3f(1.1,0.55,0.3);
        glTexCoord3f(1.2,0.6,0.01);glVertex3f(1.2,0.6,0.01);
    glEnd();

    //kiri atas II
    glBegin(GL_QUADS);
        glTexCoord3f(1.15,0.5,0.3);glVertex3f(1.15,0.5,0.3);
        glTexCoord3f(0.9,0.5,0.5);glVertex3f(0.9,0.5,0.5);
        glTexCoord3f(0.85,0.52,0.48);glVertex3f(0.85,0.52,0.48);
        glTexCoord3f(1.1,0.55,0.3);glVertex3f(1.1,0.55,0.3);
    glEnd();

    //moncong
    glBegin(GL_QUADS);
        glTexCoord3f(0.9,0.5,0.5);glVertex3f(0.9,0.5,0.5);
        glTexCoord3f(0.85,0.52,0.48);glVertex3f(0.85,0.52,0.48);
        glTexCoord3f(0.15,0.52,0.48);glVertex3f(0.15,0.52,0.48);
        glTexCoord3f(0.1,0.5,0.5);glVertex3f(0.1,0.5,0.5);
        glTexCoord3f(0.2,0.45,0.5);glVertex3f(0.2,0.45,0.5);
        glTexCoord3f(0.8,0.45,0.5);glVertex3f(0.8,0.45,0.5);
    glEnd();

    //atap moncong
    glBegin(GL_QUADS);
        glTexCoord3f(0.85,0.52,0.48);glVertex3f(0.85,0.52,0.48);
        glTexCoord3f(0.15,0.52,0.48);glVertex3f(0.15,0.52,0.48);
        glTexCoord3f(-0.1,0.55,0.3);glVertex3f(-0.1,0.55,0.3);
        glTexCoord3f(-0.2,0.6,0.0);glVertex3f(-0.2,0.6,0.0);
        glTexCoord3f(0.5,0.6,0.1);glVertex3f(0.5,0.6,0.1);
        glTexCoord3f(1.2,0.6,0.0);glVertex3f(1.2,0.6,0.0);
        glTexCoord3f(1.1,0.55,0.3);glVertex3f(1.1,0.55,0.3);
    glEnd();

    //kaca depan full
    // frame kiri
    glBegin(GL_QUADS);
        glTexCoord3f(1.2,0.6,0.0);glVertex3f(1.2,0.6,0.0);
        glTexCoord3f(0.5,0.6,0.1);glVertex3f(0.5,0.6,0.1);
        glTexCoord3f(0.5,0.8,0.0);glVertex3f(0.5,0.8,0.0);
        glTexCoord3f(1.15,0.8,-0.1);glVertex3f(1.15,0.8,-0.1);
    glEnd();

    //kaca depan I
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-0.15,0.65,-0.01);
        glVertex3f(0.3,0.63,0.06);
        glVertex3f(0.3,0.75,0.0);
        glVertex3f(-0.1,0.75,-0.06);
    glEnd();

    // frame kanan
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(-0.2,0.6,0.0);glVertex3f(-0.2,0.6,0.0);
        glTexCoord3f(0.5,0.6,0.1);glVertex3f(0.5,0.6,0.1);
        glTexCoord3f(0.5,0.8,0.0);glVertex3f(0.5,0.8,0.0);
        glTexCoord3f(-0.15,0.8,-0.1);glVertex3f(-0.15,0.8,-0.1);
    glEnd();

    //kaca depan II
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1.15,0.65,-0.01);
        glVertex3f(0.7,0.63,0.06);
        glVertex3f(0.7,0.75,0.0);
        glVertex3f(1.1,0.75,-0.06);
    glEnd();

    //awal bemper depan bawah
    //bagian depan
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(1.1,0.0,0.0);glVertex3f(1.1,0.0,0.0);
        glTexCoord3f(1.05,0.0,0.1);glVertex3f(1.05,0.0,0.1);
        glTexCoord3f(-0.05,0.0,0.1);glVertex3f(-0.05,0.0,0.1);
        glTexCoord3f(-0.1,0.0,0.0);glVertex3f(-0.1,0.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(1.05,0.0,0.1);glVertex3f(1.05,0.0,0.1);
        glTexCoord3f(0.8,0.45,0.5);glVertex3f(0.8,0.45,0.5);
        glTexCoord3f(0.2,0.45,0.5);glVertex3f(0.2,0.45,0.5);
        glTexCoord3f(-0.05,0.0,0.1);glVertex3f(-0.05,0.0,0.1);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(1.0,0.0,0.0);glVertex3f(1.0,0.0,0.0);
        glTexCoord3f(1.1,0.0,0.0);glVertex3f(1.1,0.0,0.0);
        glTexCoord3f(1.3,0.5,0.0);glVertex3f(1.3,0.5,0.0);
        glTexCoord3f(1.0,0.5,0.0);glVertex3f(1.0,0.5,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(1.1,0.0,0.0);glVertex3f(1.1,0.0,0.0);
        glTexCoord3f(1.05,0.0,0.1);glVertex3f(1.05,0.0,0.1);
        glTexCoord3f(1.15,0.5,0.3);glVertex3f(1.15,0.5,0.3);
        glTexCoord3f(1.3,0.5,0.0);glVertex3f(1.3,0.5,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(1.05,0.0,0.1);glVertex3f(1.05,0.0,0.1);
        glTexCoord3f(0.8,0.45,0.5);glVertex3f(0.8,0.45,0.5);
        glTexCoord3f(0.9,0.5,0.5);glVertex3f(0.9,0.5,0.5);
        glTexCoord3f(1.15,0.5,0.3);glVertex3f(1.15,0.5,0.3);
    glEnd();

    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(0.4,0.5,0.6);
        glTexCoord3f(0.0,0.0,0.0);glVertex3f(0.0,0.0,0.0);
        glTexCoord3f(-0.1,0.0,0.0);glVertex3f(-0.1,0.0,0.0);
        glTexCoord3f(-0.3,0.5,0.0);glVertex3f(-0.3,0.5,0.0);
        glTexCoord3f(0.0,0.5,0.0);glVertex3f(0.0,0.5,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(-0.1,0.0,0.0);glVertex3f(-0.1,0.0,0.0);
        glTexCoord3f(-0.05,0.0,0.1);glVertex3f(-0.05,0.0,0.1);
        glTexCoord3f(-0.15,0.5,0.3);glVertex3f(-0.15,0.5,0.3);
        glTexCoord3f(-0.3,0.5,0.0);glVertex3f(-0.3,0.5,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord3f(-0.05,0.0,0.1);glVertex3f(-0.05,0.0,0.1);
        glTexCoord3f(0.2,0.45,0.5);glVertex3f(0.2,0.45,0.5);
        glTexCoord3f(0.1,0.5,0.5);glVertex3f(0.1,0.5,0.5);
        glTexCoord3f(-0.15,0.5,0.3);glVertex3f(-0.15,0.5,0.3);
    glEnd();


    //bagian sayap
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);glVertex3f(-0.3,0.5,0.0);
        glTexCoord2f(1.0,0.0);glVertex3f(1.3,0.5,0.0);
        glTexCoord2f(1.0,1.0);glVertex3f(1.3,0.5,-2.5);
        glTexCoord2f(0.0,1.0);glVertex3f(-0.3,0.5,-2.5);
    glEnd();

    //akhir bemper depan


    //bagian belakang
    /*glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
        glVertex3f(0.0,0.0,-2.5);
        glVertex3f(1.0,0.0,-2.5);
        glVertex3f(1.0,0.5,-2.5);
        glVertex3f(0.0,0.5,-2.5);
    glEnd();*/

    //bagian body bawah kanan
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(1.0,0.0);glVertex3f(0.0,0.5,0.0);
        glTexCoord2f(1.0,1.0);glVertex3f(0.0,0.5,-2.5);
        glTexCoord2f(0.0,1.0);glVertex3f(0.0,0.0,-2.5);
    glEnd();

    //bagian body bawah kiri
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);glVertex3f(1.0,0.0,0.0);
        glTexCoord2f(1.0,0.0);glVertex3f(1.0,0.5,0.0);
        glTexCoord2f(1.0,1.0);glVertex3f(1.0,0.5,-2.5);
        glTexCoord2f(0.0,1.0);glVertex3f(1.0,0.0,-2.5);
    glEnd();
//============== END BODY PANZER=====================//
//============== BEGIN RODA PANZER=====================//
    //RODA Kiri FULL
        //ban kiri_1
        glPushMatrix();
        glTranslatef(1.0,0.0,-0.4);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban kiri_2
        glPushMatrix();
        glTranslatef(1.0,0.0,-1.28);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban kiri_3
        glPushMatrix();
        glTranslatef(1.0,0.0,-2.1);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

    //ban dalam kiri_1
        glPushMatrix();
        glTranslatef(1.0,0.0,-0.4);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban dalam kiri_2
        glPushMatrix();
        glTranslatef(1.0,0.0,-1.28);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban dalam kiri_3
        glPushMatrix();
        glTranslatef(1.0,0.0,-2.1);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

    //END BAN KIRI FULL
    //BEGIN BAN KANAN FULL
        //ban kiri_1
        glPushMatrix();
        glTranslatef(0.0,0.0,-0.4);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban kiri_2
        glPushMatrix();
        glTranslatef(0.0,0.0,-1.28);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban kiri_3
        glPushMatrix();
        glTranslatef(0.0,0.0,-2.1);
        glScalef(0.3,0.5,0.5);
        glRotatef(270,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

    //ban dalam kiri_1
        glPushMatrix();
        glTranslatef(0.0,0.0,-0.4);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban dalam kiri_2
        glPushMatrix();
        glTranslatef(0.0,0.0,-1.28);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

        //ban dalam kanan_3
        glPushMatrix();
        glTranslatef(0.0,0.0,-2.1);
        glScalef(0.3,0.5,0.5);
        glRotatef(90,0.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);
            glutSolidTorus(0.5,0.3,20,20);

           //pelk
            glPushMatrix();
                glTranslatef(0.0,0.0,0.5);
                glScalef(0.5,0.5,0.5);
                glColor3f(0.1f,0.1f,0.1f);
                glutSolidCone(1.0,0.1,20,15);
            glPopMatrix();

        glPopMatrix();

    //END BAN KIRI FULL
//============== END RODA PANZER=====================//
    glPopMatrix();
}





GLuint createDL() {
 GLuint carrDL;

 // Create the id for the list
 carrDL = glGenLists(1);

 // start list
 glNewList(carrDL,GL_COMPILE);

 // call the function that contains the rendering commands
  drawcarr();

 // endList
 glEndList();

 return(carrDL);
}
GLuint createDL2()//******************
{
 GLuint houseDL;

 // Create the id for the list
 houseDL = glGenLists(1);

 // start list
 glNewList(houseDL,GL_COMPILE);

 // call the function that contains the rendering commands
  drawhouse();

 // endList
 glEndList();

 return(houseDL);
}//**************

GLuint createDL3() {
 GLuint pohonDL;

 // Create the id for the list
 pohonDL = glGenLists(1);

 // start list
 glNewList(pohonDL,GL_COMPILE);

 // call the function that contains the rendering commands
  pohon();

 // endList
 glEndList();

 return(pohonDL);
}

GLuint createDL4() {
 GLuint panzerDL;

 // Create the id for the list
 panzerDL = glGenLists(1);

 // start list
 glNewList(panzerDL,GL_COMPILE);

 // call the function that contains the rendering commands
  panzer();

 // endList
 glEndList();

 return(panzerDL);
}

GLuint createDL5() {
 GLuint awanDL;

 // Create the id for the list
 awanDL = glGenLists(1);

 // start list
 glNewList(awanDL,GL_COMPILE);

 // call the function that contains the rendering commands
  awan();

 // endList
 glEndList();

 return(awanDL);
}

void initScene()
{

 glEnable(GL_DEPTH_TEST);
 carr_display_list = createDL();
 house_display_list= createDL2();//***********
 pohon_display_list=createDL3();
 panzer_display_list=createDL4();
 awan_display_list=createDL5();
}


void renderScene(void)
{
 int i,j;
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glClearColor(.7,0.85,1.0,1.0);

// Draw ground

 glColor3f(0.25f, 0.25f, 0.25f);
 glBegin(GL_QUADS);
  glVertex3f(-100.0f, 0.0f, -100.0f);
  glVertex3f(-100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f, -100.0f);
 glEnd();

// Draw 36 car

 for( i = -2; i < 3; i++)//kolom
  for( j=-2; j < 4; j++) //baris
  {
   glPushMatrix();
   glTranslatef((i)*10.0,0,(j) * 10.0);
   glColor3ub(a[i],b[j],c[i]);
   glCallList(carr_display_list);
   glPopMatrix();
  }
 if(housevisible)
 {

glPushMatrix();
   glScalef(2.0,2.0,2.0);
   glTranslatef(0.0,.85,-20.0);
   glCallList(house_display_list);
           glTranslatef(10.0,0.0,0.0);
     glCallList(house_display_list);
          glTranslatef(-20.0,0.0,0.0);
     glCallList(house_display_list);

   glRotatef(90,0.0,1.0,0.0);
         glTranslatef(-10.0,0.0,-10.0);
   glCallList(house_display_list);

   glTranslatef(-10.0,0.0,0.0);
   glCallList(house_display_list);
   glTranslatef(-10.0,0.0,0.0);
   glCallList(house_display_list);
   glPopMatrix();

  glPushMatrix();
         glTranslatef(10.0,3.4,-80.0);
         glScalef(4.0,4.0,4.0);
   glCallList(house_display_list);
   glTranslatef(-10.0,0.0,0.0);
   glCallList(house_display_list);
  glPopMatrix();

         glPushMatrix();
            glRotatef(90,0.0,1.0,0.0);
    glScalef(2.0,2.0,2.0);
    glTranslatef(0.0,0.85,15.0);
             glCallList(house_display_list);
    glTranslatef(10.0,0.,0.0);
             glCallList(house_display_list);
                  glTranslatef(-20.0,0.,0.0);
             glCallList(house_display_list);
         glPopMatrix();
 }

 if(pohonvisible)
 {
 glPushMatrix();
   glScalef(2.7,2.7,2.7);
   glTranslatef(-3,0.0,-20.0); //angle rumah kiri depan yg ke 2 atau tengah
   glCallList(pohon_display_list);
           glTranslatef(10.0,0.0,0.0); //angle rumah kiri depan yg ke kanan
     glCallList(pohon_display_list);
          glTranslatef(-20.0,0.0,0.0); //angle rumah hadap  depan yg ke kiri
     glCallList(pohon_display_list);
         glPopMatrix();

 }

 if(panzervisible)
 {
 glPushMatrix();
   glScalef(2,2,2);
   glTranslatef(0.0,0.36,20.0); //angle rumah kiri depan yg ke 2 atau tengah
   glCallList(panzer_display_list);
           glTranslatef(10.0,0.0,0.0); //angle rumah kiri depan yg ke kanan
     glCallList(panzer_display_list);
          glTranslatef(-20.0,0.0,0.0); //angle rumah hadap  depan yg ke kiri
     glCallList(panzer_display_list);
         glPopMatrix();
 }

 if(awanvisible)
 {
 glPushMatrix();
   glScalef(2,2,5);
   glTranslatef(0.0,30,0.0); //angle rumah kiri depan yg ke 2 atau tengah
   glCallList(awan_display_list);
           glTranslatef(10.0,0.0,0.0); //angle rumah kiri depan yg ke kanan
     glCallList(awan_display_list);
          glTranslatef(-20.0,0.0,0.0); //angle rumah hadap  depan yg ke kiri
     glCallList(awan_display_list);
         glPopMatrix();
 }


 if(fxincr!=0)
 theta1=(atan(fzincr/fxincr)*180)/3.141;
 else if(fzincr>0)
  theta1=-90.0;
 else theta1=90.0;

 if(fxincr>0&&fzincr<0)
 {
  theta1=-theta1;
 }
 else if(fxincr<0&&fzincr<0)
 {
  theta1=180-theta1;
 }
 else if(fxincr<0&&fzincr>0)
 {
  theta1=-180-theta1;
 }else if(fxincr>0&&fzincr>0)
 {
 theta1=-theta1;
 }
 //else theta1=90;
 //glLoadIdentity();
    glPushMatrix();
    glTranslatef(fx,0,fz);
    glRotatef(theta1,0,1,0);
    glColor3f(1.0,0.0,0.0); //bagian warna mobil yg bisa jalan
    glCallList(carr_display_list);
    glPopMatrix();

    glutSwapBuffers();

}

void orientMe(float ang)
{
    lx = sin(ang);
 lz = -cos(ang);
 glLoadIdentity();
 gluLookAt(x, y, z,
        x + lx,y + ly,z + lz,
     0.0f,1.0f,0.0f);

}


void moveMeFlat(int i)
{
if(xxxx==1)
  y=y+i*(lz)*0.1;//*********

if(yyyy==1)
{
 x=x+i*(lz)*.1;
}
else
{
 z = z + i*(lz)*0.5;
           x = x + i*(lx)*0.5;}
glLoadIdentity();
 gluLookAt(x, y, z,
        x + lx,y + ly,z + lz,
     0.0f,1.0f,0.0f);

}

void processNormalKeys(unsigned char key, int x, int y)
{
glLoadIdentity();


 if (key == 'q')
  exit(0);
         if(key=='t')
          gluLookAt(1,190,50,0,0 ,-10,0.0,1.0,.0);
  if(key=='a') moveMeFlat(4);xxxx=1,yyyy=0;
     if(key=='s') moveMeFlat(-4);xxxx=1,yyyy=0;
       if(key=='w') moveMeFlat(4);yyyy=1;xxxx=0;
       if(key=='d') moveMeFlat(-4);yyyy=1;xxxx=0;
}


void inputKey(int key, int x, int y)
{
 switch (key)
 {
  case GLUT_KEY_LEFT : angle -= 0.05f;orientMe(angle);break;
  case GLUT_KEY_RIGHT : angle +=0.05f;orientMe(angle);break;
  case GLUT_KEY_UP : moveMeFlat(2);xxxx=0,yyyy=0;break;
  case GLUT_KEY_DOWN : moveMeFlat(-2);xxxx=0,yyyy=0;break;
 }
}
void movecar(int key, int x, int y)
{

 switch (key)
 {
  case GLUT_KEY_LEFT :temp=fxincr;
       fxincr=fxincr*cos(theta)+fzincr*sin(theta);
       fzincr=-temp*sin(theta)+fzincr*cos(theta);
       fx+=fxincr;
       fz+=fzincr;

       break;
  case GLUT_KEY_RIGHT :temp=fxincr;
       fxincr=fxincr*cos(-theta)+fzincr*sin(-theta);
       fzincr=-temp*sin(-theta)+fzincr*cos(-theta);
       fx+=fxincr;
       fz+=fzincr;

       break;
  case GLUT_KEY_UP :fx+=fxincr;
        fz+=fzincr;break;
  case GLUT_KEY_DOWN :fx-=fxincr;
                  fz-=fzincr; break;

 }
 glutPostRedisplay();
}

// Reset flags as appropriate in response to menu selections
void ProcessMenu(int value)
{
    glutPostRedisplay();
}

void ProcessMenu1(int value)
{
 switch(value)
 {
 case 1:if(housevisible==0)
          housevisible=1;
   else
    housevisible=0;
      glutPostRedisplay();
   break;
   case 3:if(pohonvisible==0)
          pohonvisible=1;
   else
   pohonvisible=0;
      glutPostRedisplay();
   break;
   case 4:if(panzervisible==0)
          panzervisible=1;
   else
   panzervisible=0;
      glutPostRedisplay();
   break;

   case 5:if(awanvisible==0)
          awanvisible=1;
   else
   awanvisible=0;
      glutPostRedisplay();
   break;

 case 2:if(movecarvar==0)
  {
  glutSpecialFunc(movecar);
        movecarvar=1;
     }
 else{
  glutSpecialFunc(inputKey);
  movecarvar=0;
     }
  break;
 }
}
void menu()
{
 int control;
    int control1;

 control= glutCreateMenu(ProcessMenu);
 glutAddMenuEntry("**KONTROL**",1);
 glutAddMenuEntry("1)  UP KEY:untuk arah maju.",1);
 glutAddMenuEntry("2)  DOWN KEY: untuk arah mundur.",1);
 glutAddMenuEntry("3)  LEFT KEY: untuk belok kiri.",1);
 glutAddMenuEntry("4)  RIGHT KEY:untuk belok kanan.",1);
 glutAddMenuEntry("5)  d: pindah ke kanan. ",1);
 glutAddMenuEntry("6)  a: pindah ke kiri.",1);
 glutAddMenuEntry("7)  s: untuk arah menjauh.",1);
 glutAddMenuEntry("8)  w: untuk arah mendekat.",1);
 glutAddMenuEntry("9)  t: untuk arah dari atas.",1);
 glutAddMenuEntry("10) q: keluar.",1);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
    control1=glutCreateMenu(ProcessMenu1);

 glutAddMenuEntry("Pake rumah dong...",1);
 glutAddMenuEntry("Maen mobil kuy...",2);
 glutAddMenuEntry ("Pake pohon dong...",3);
 glutAddMenuEntry ("Pake tank panzer dong...",4);
 glutAddMenuEntry ("Tambah awan...",5);
 glutAttachMenu(GLUT_LEFT_BUTTON);

}


int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(1010,710);
 glutCreateWindow("parkir mobil");

 initScene();

 glutKeyboardFunc(processNormalKeys);
 glutSpecialFunc(inputKey);
    menu();
 glutDisplayFunc(renderScene);
 glutIdleFunc(renderScene);

 glutReshapeFunc(changeSize);

 glutMainLoop();

 return(0);
}
