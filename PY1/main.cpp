#include <windows.h>
#include <stdio.h>
#include<string.h>
#include <GL/glut.h>
#include <math.h>
#define PI=3.14159265358979323846;


void draw_circle(float x, float y, float radio);
float move_cloud=0;
float move_dust=0;

void Fondo(){
    ///=====================  cesped
    glBegin(GL_QUADS);
    glColor3ub(51, 128, 0);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glColor3ub(35, 87, 0);
    glVertex2i(1000, 300);
    glVertex2i(0, 300);
    glEnd();

    ///=====================  Pista
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50);
    glVertex2i(0, 50);
    glVertex2i(1000, 50);
    glColor3ub(0, 0, 0);
    glVertex2i(1000, 270);
    glVertex2i(0, 270);
    glEnd();
    //====================== Lineas amarillas
    int linea=0;
    for(int i=0;i<5;i++){
        glBegin(GL_QUADS);
        glColor3ub(255,254, 17);
        glVertex2i(10+linea, 180);
        glVertex2i(100+linea, 180);
        glVertex2i(100+linea, 200);
        glVertex2i(10+linea, 200);
        glEnd();
        linea=linea+210;
    }

    ///==================================== estrellas
    int Distance=0;
    //------------------------------------ 1ra linea de estrellas
    for(int i=0;i<5;i++){
        glColor3f(255, 251, 0); //Amarillo
        draw_circle(50+Distance,840,10);
        glColor3f(0.0,0.1,0.23); //Azul
        draw_circle(59+Distance,850,10);
        draw_circle(59+Distance,830,10);
        draw_circle(40+Distance,830,10);
        draw_circle(40+Distance,850,10);
        Distance=Distance+215;
    }

     Distance=0;
    //------------------------------------ 2da linea de estrellas
    for(int i=0;i<5;i++){
        glColor3f(255, 251, 0); //Amarillo
        draw_circle(120+Distance,690,10);
        glColor3f(0.0,0.1,0.23); //Azul
        draw_circle(129+Distance,700,10);
        draw_circle(129+Distance,680,10);
        draw_circle(110+Distance,680,10);
        draw_circle(110+Distance,700,10);
        Distance=Distance+215;
    }

    Distance=0;
    //------------------------------------ 3ra linea de estrellas
    for(int i=0;i<5;i++){
        glColor3f(255, 251, 0); //Amarillo
        draw_circle(120+Distance,990,10);
        glColor3f(0.0,0.1,0.23); //Azul
        draw_circle(129+Distance,1000,10);
        draw_circle(129+Distance,980,10);
        draw_circle(110+Distance,980,10);
        draw_circle(110+Distance,1000,10);
        Distance=Distance+215;
    }

    ///================================ Aeropuerto
    glBegin(GL_POLYGON);
	glColor3ub(204, 20, 255);
    glVertex2i(250,700);
    glVertex2i(750,700);
    glColor3ub(102, 51, 40);
    glVertex2i(750,295);
    glVertex2i(250,295);
    glEnd();
    int buildingY1=620,buildingY2=623;
	for(int i=0;i<10;i++){
        //================= Division de los pisos
        glBegin(GL_POLYGON);
        glColor3ub(153, 153, 102);
        glVertex2i(250,buildingY1);
        glVertex2i(750,buildingY1);
        glVertex2i(750,buildingY2);
        glVertex2i(250,buildingY2);
        glEnd();
        buildingY1=buildingY1-25;
        buildingY2=buildingY2-25;
	}
	//==================================antena
	glBegin(GL_POLYGON);
	glColor3ub(102, 51, 40);
    glVertex2i(495,800);
    glVertex2i(505,800);
    glVertex2i(505,700);
    glVertex2i(495,700);
    glEnd();
    glColor3ub(102, 51, 40);
    draw_circle(500,770,15);

    for(int i=0;i<15;i++){
        glBegin(GL_POLYGON);
        if(i%2==0){
            glColor3ub(10, 151, 40);
        }
        else{
            glColor3ub(120, 51, 140);
        }
        glVertex2i(275+(i*10),705+(i*5));
        glVertex2i(725-(i*10),705+(i*5));
        glVertex2i(725-(i*10),700+(i*5));
        glVertex2i(275+(i*10),700+(i*5));
        glEnd();
    }

}


void Moon()
{
    ///================================= Creacion de la luna

    glColor3f(1.0,0.99,0.81);   //color
    draw_circle(500, 900,70);
    glColor3f(0.0,0.1,0.23);   //azul color
    draw_circle(560, 900,70);

}

void myDisplay(void)
{
    glClearColor(0.0,0.1,0.23,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    Fondo();
    Moon();
    glEnd();
    glFlush ();
}

void Dibujar (void)
{
    glClearColor(0.0,0.7,1.5,0.0);  //color del cielo
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
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
    glutInitWindowSize (1000, 760);
    glutInitWindowPosition (100,0);
    glutCreateWindow ("Proyecto 1 - 1SF141" );
    glutDisplayFunc(myDisplay);
    Dibujar();
    glutMainLoop();
}
