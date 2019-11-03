#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

static float angle=0.0,ratio;
static float x=0.0f,y=1.75f,z=5.0f;
static float lx=0.10f,ly=0.10f,lz=-1.0f;
static GLint carr_display_list,house_display_list;
float theta=0.01,fxincr=0.1,fzincr=0,temp,theta1,fx=-10,fz=80;
int xxxx=0,yyyy=0,kk=0,housevisible=0,movecarvar=0;
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
 
 / top filling
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
glColor3f(0.09,0.09,0.09);// tyre color********
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
