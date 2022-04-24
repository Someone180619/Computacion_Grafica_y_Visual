#include <windows.h>
#include <stdio.h>
#include<string.h>
#include <GL/glut.h>
#include <math.h>
#define PI=3.14159265358979323846;

void update(int);
void draw_circle(float x, float y, float radio);
float move_cloud=0;
float move_dust=0;

void DrawGrassField(){
    ///============== el cesped
    glBegin(GL_POLYGON);
	glColor3f(0,0.60,0);     //green color
    glVertex2i(0,0);
    glVertex2i(800, 0);
    glVertex2i(800,180);
    glVertex2i(0, 180);
    glEnd();
    ///==================== primera linea de arboles
    int treeDistance=0;
    for(int i=0;i<4;i++){
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);  //tronco del arbol
        glVertex2i(60+treeDistance,30);
        glVertex2i(70+treeDistance,30);
        glVertex2i(65+treeDistance,150);
        glEnd();
        glColor3f(0, 153, 0);   //Hojas del arbol
        draw_circle(50+treeDistance,100,20);     //primera copa del arbol
        draw_circle(80+treeDistance,100,20);     //segunda copa del arbol
        draw_circle(58+treeDistance,130,18);     //1ra copa central del arbol
        draw_circle(72+treeDistance,130,18);     //2da copa central del arbol
        draw_circle(65+treeDistance,150,14);     //copa superior del arbol
        treeDistance=treeDistance+200;
    }
    ///================================ segunda linea de arboles
    treeDistance=100;
    for(int i=0;i<4;i++){
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);  //tronco del arbol
        glVertex2i(60+treeDistance,100);
        glVertex2i(70+treeDistance,100);
        glVertex2i(65+treeDistance,220);
        glEnd();
        glColor3f(0, 153, 0);   //Hojas del arbol
        draw_circle(50+treeDistance,170,20);     //primera copa del arbol
        draw_circle(80+treeDistance,170,20);     //segunda copa del arbol
        draw_circle(58+treeDistance,200,18);     //1ra copa central del arbol
        draw_circle(72+treeDistance,200,18);     //2da copa central del arbol
        draw_circle(65+treeDistance,220,14);     //copa superior del arbol
        treeDistance=treeDistance+200;
    }
}
void DrawCloud(){
    ///==================================== Creacion de nubes
    glColor3f(255, 255, 255);
                        //left cloud
    draw_circle(100+move_cloud,730,33);
    draw_circle(55+move_cloud,730,23);
    draw_circle(145+move_cloud,730,23);

    draw_circle(200+move_cloud,630,43);
    draw_circle(150+move_cloud,630,33);
    draw_circle(245+move_cloud,630,33);
                        //right cloud
    draw_circle(700+move_cloud,630,33);
    draw_circle(655+move_cloud,630,23);
    draw_circle(745+move_cloud,630,23);

    draw_circle(600+move_cloud,730,43);
    draw_circle(555+move_cloud,730,33);
    draw_circle(645+move_cloud,730,33);
}
void DrawIndustry(){
     ///============================== edificio del lado derecho

    glBegin(GL_POLYGON);
	glColor3ub(120, 100, 100);
    glVertex2i(570,100);
    glVertex2i(720,100);
    glVertex2i(720,390);
    glVertex2i(600,390);
    glVertex2i(600,430);
    glVertex2i(570,430);
    glEnd();
    glBegin(GL_POLYGON);
	glColor3f(0.0,0.7,1.5);
    glVertex2i(570,730);
    glVertex2i(600,730);
    glVertex2i(600,830);
    glVertex2i(570,830);
    glEnd();
            //primera fila de ventanas
    int b4y1=375,b4y2=372;
	for(int i=0;i<7;i++){
        glBegin(GL_POLYGON);
        glColor3ub(153, 153, 102);
        glVertex2i(570,b4y1);
        glVertex2i(720,b4y1);
        glVertex2i(720,b4y2);
        glVertex2i(570,b4y2);
        glEnd();
        b4y1=b4y1-25;
        b4y2=b4y2-25;
	}
	int b4y01=228,b4y02=240;
    int b4x01=575,b4x02=590;
                    //creacion de columnas por fila de ventanas
    for(int j=1;j<37;j++){
        glBegin(GL_POLYGON);
        glColor3ub(242, 242, 242);
        glVertex2i(b4x01,b4y01);
        glVertex2i(b4x02,b4y01);
        glVertex2i(b4x02,b4y02);
        glVertex2i(b4x01,b4y02);
        glEnd();
        b4x01=b4x01+25;
        b4x02=b4x02+25;
        if(j%6==0){
            b4x01=575;
            b4x02=590;
            b4y01=b4y01+25;
            b4y02=b4y02+25;
        }
}
}
void DrawCity()
{
    ///================================= Creacion del Sol
    glColor3f(1.0,1.0,0.94);   //color
    draw_circle(380,705,60);   //(X, Y, radio)
    glColor3f(1.0,0.99,0.81);   //color
    draw_circle(380,705,50);
    glColor3f(1.72,1.45,0.5);   //color
    draw_circle(380,705,40);

    DrawIndustry();
    DrawCloud();

   ///================================ Edificio del lado izquierdo
    glBegin(GL_POLYGON);
	glColor3ub(25,71,128);
    glVertex2i(50,450);
    glVertex2i(150,450);
    glVertex2i(150,100);
    glVertex2i(50,100);
    glEnd();
    int buildingY1=420,buildingY2=423;
	for(int i=0;i<8;i++){
        //================= Division de los pisos del edificio
        glBegin(GL_POLYGON);
        glColor3ub(153, 153, 102);
        glVertex2i(50,buildingY1);
        glVertex2i(150,buildingY1);
        glVertex2i(150,buildingY2);
        glVertex2i(50,buildingY2);
        glEnd();
        buildingY1=buildingY1-25;
        buildingY2=buildingY2-25;
	}

}

void myDisplay(void)
{
    glClearColor(0.0,0.7,1.5,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    DrawCity();
    DrawCloud();
    DrawGrassField();
    glEnd();
    glFlush ();
}

void Dibujar (void)
{
    glClearColor(0.0,0.7,1.5,0.0);  //sky color
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}


void draw_circle(float x, float y, float radio) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angulo = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angulo1=0.0;
    glVertex2d(radio * cos(0.0) , radio * sin(0.0));
    for (int i=0; i<circle_points; i++)
    {
        glVertex2d(radio * cos(angulo1), radio *sin(angulo1));
        angulo1 += angulo;
    }
    glEnd();
    glPopMatrix();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (500,50);
    glutCreateWindow ("Taller2 - Paisaje Libre" );
    glutDisplayFunc(myDisplay);
    Dibujar();
    glutMainLoop();
}
