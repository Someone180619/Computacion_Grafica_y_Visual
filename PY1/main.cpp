#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#define PI = 3.14159265358979323846;

void draw_circle(float x, float y, float radio);
float move_cloud = 0;
float move_dust = 0;

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
	glColor3ub(93, 193, 198);
    glVertex2i(250,700);
    glVertex2i(750,700);
    glColor3ub(78, 81, 78);
    glVertex2i(750,295);
    glVertex2i(250,295);
    glEnd();
    int buildingY1=620,buildingY2=623;
	for(int i=0;i<10;i++){
        //================= Division de los pisos
        glBegin(GL_POLYGON);
        glColor3ub(26, 75, 52);
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
    //Puerta y ventana
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(400, 295);
    glVertex2i(480, 295);
    glColor3ub(20, 20, 58);
    glVertex2i(480, 370);
    glVertex2i(400, 370);
    //Linea
    glColor3ub(100, 100, 50);
    glVertex2i(440, 295);
    glVertex2i(441, 295);
    glColor3ub(100, 100, 0);
    glVertex2i(441, 370);
    glVertex2i(440, 370);
    //La otra
    glColor3ub(0, 0, 0);
    glVertex2i(520, 295);
    glVertex2i(600, 295);
    glColor3ub(20, 20, 58);
    glVertex2i(600, 370);
    glVertex2i(520, 370);
     //Linea
    glColor3ub(100, 100, 50);
    glVertex2i(560, 295);
    glVertex2i(561, 295);
    glColor3ub(100, 100, 0);
    glVertex2i(561, 370);
    glVertex2i(560, 370);
    glEnd();
    ///===================== Lamppost
    int post=0;
    for(int i=0;i<6;i++){
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50);
    glVertex2i(50+post, 280);
    glVertex2i(60+post, 280);
    glColor3ub(0, 0, 0);
    glVertex2i(60+post, 320);
    glVertex2i(50+post, 320);
    glEnd();

    glColor3f(1.0,0.99,0.81);   //foquito
    draw_circle(55+post, 320,5);
    post=post+200;


    }

}


void Moon()
{
    ///================================= Creacion de la luna

    glColor3f(1.0, 0.99, 0.81); // color
    draw_circle(500, 900, 70);
    glColor3f(0.0, 0.1, 0.23); // azul color
    draw_circle(560, 900, 70);
}
float a;
void paletas(void){
    glPushMatrix();
    glTranslatef(660, 515, 0);
    glRotatef(a,0,0,1);
    glTranslatef(-660, -515, 0);
    glBegin(GL_POLYGON);
    glColor3ub(51, 54, 55);
    glVertex2i(660, 500);glVertex2i(670, 500);
    glVertex2i(670, 625);glVertex2i(665, 630);
    glVertex2i(660, 625);glVertex2i(660, 550);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(660, 500);glVertex2i(670, 500);
    glVertex2i(670, 415);glVertex2i(665, 410);
    glVertex2i(660, 415);glVertex2i(660, 550);
    glEnd();
    glPopMatrix();
}

void avionAlto(void){
    //Ala tracera
    glBegin(GL_POLYGON);
    glColor3ub(97, 64, 24);
    glVertex2i(430, 560);glVertex2i(455, 560);
    glVertex2i(460, 620);glVertex2i(455, 625);
    glVertex2i(440, 620);glVertex2i(430, 560);
    glEnd();
    //Ala tracera f
    glBegin(GL_POLYGON);
    glVertex2i(530, 500);glVertex2i(600, 500);
    glVertex2i(560, 600);glVertex2i(540, 620);
    glVertex2i(500, 620);glVertex2i(530, 500);
    glEnd();
    //Cuerpo
    glBegin(GL_POLYGON);
    glColor3ub(100, 104, 28);
    glVertex2i(445, 480);glVertex2i(630, 480);
    glVertex2i(630, 560);glVertex2i(460, 560);
    glVertex2i(455, 590);glVertex2i(440, 600);
    glVertex2i(430, 590);glVertex2i(425, 580);
    glVertex2i(425, 510);glVertex2i(430, 500);
    glVertex2i(435, 490);glVertex2i(445, 480);
    glEnd();
    //Ala frontal
    glBegin(GL_POLYGON);
    glColor3ub(97, 64, 24);
    glVertex2i(430, 560);glVertex2i(455, 560);
    glVertex2i(445, 500);glVertex2i(440, 495);
    glVertex2i(435, 500);glVertex2i(430, 560);
    glEnd();
    //Ala frontal f
    glBegin(GL_POLYGON);
    glVertex2i(530, 500);glVertex2i(600, 500);
    glVertex2i(560, 400);glVertex2i(540, 380);
    glVertex2i(500, 380);glVertex2i(530, 500);
    glEnd();
    
    //ventana
    glBegin(GL_POLYGON);
    glColor3ub(216, 215, 208);
    glVertex2i(500, 560);glVertex2i(630, 560);
    glVertex2i(615, 585);glVertex2i(520, 585);
    glEnd();
     //paletas
    paletas();

    

    glBegin(GL_QUADS);  
    glColor3ub(45, 76, 35);
    glVertex2i(480, 540);glVertex2i(520, 540);
    glVertex2i(520, 510);glVertex2i(480, 510);
    glEnd();
}

void specialkey(int key, int x, int y)
{
    if(key==GLUT_KEY_UP|GLUT_KEY_DOWN|GLUT_KEY_RIGHT|GLUT_KEY_LEFT)
        a+=100;
        glutPostRedisplay();
}

// Avión con movimiento
void avionMovil()
{
    // Ala derecha
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(250, 190);
    glVertex2f(270, 190);
    glVertex2f(350, 240);
    glVertex2f(300, 240);
    glEnd();

    // Ala izquierda
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(250, 340);
    glVertex2f(270, 340);
    glVertex2f(350, 290);
    glVertex2f(300, 290);
    glEnd();

    // Body del avión
    glBegin(GL_QUADS); 
    glColor3ub(255, 249, 98);
    glVertex2i(230, 240);
    glColor3ub(255, 255, 255);
    glVertex2i(400, 240);
    glVertex2i(400, 290);
    glVertex2i(230, 290);
    glEnd();

    //Cola del avión
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(250, 265);
    glVertex2i(225, 315);
    glVertex2i(220, 315);
    glVertex2i(220, 265);
    glEnd();
    
     //fin inferior a la cola
    glBegin(GL_QUADS);
    glColor3ub(255, 249, 98);
    glVertex2i(230, 265);
    glVertex2i(220, 265);
    glVertex2i(230, 240);
    glVertex2i(230, 265);
    glEnd();
 
    //Cabina
    glColor3ub(255, 255, 255);
    draw_circle(400, 260, 20);
    glColor3ub(234, 217, 233);
    draw_circle(396, 275, 15);
    

    //Ventanas
    int x = 265, y = 270;
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i<5 ; i++){
        draw_circle(x, y, 7);
        x+=25;
    }
}

void myDisplay(void)
{
    glClearColor(0.0, 0.1, 0.23, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    Fondo();
    Moon();
    avionMovil();

    avionAlto();
    //Helice Rtador
    glBegin(GL_POLYGON);
    glColor3ub(97, 28, 24);
    glVertex2i(630, 480);glVertex2i(650, 480);
    glVertex2i(660, 490);glVertex2i(670, 490);
    glVertex2i(680, 520);glVertex2i(630, 480);

    glVertex2i(680, 520);glVertex2i(670, 550);
    glVertex2i(660, 550);glVertex2i(650, 560);
    glVertex2i(630, 560);glVertex2i(630, 480);
    glEnd();
  
    glFlush();
}

void Dibujar(void)
{
    glClearColor(0.0, 0.7, 1.5, 0.0); // color del cielo
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void draw_circle(float x, float y, float radio)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angulo = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angulo1 = 0.0;
    glVertex2d(radio * cos(0.0), radio * sin(0.0));
    for (int i = 0; i < circle_points; i++)
    {
        glVertex2d(radio * cos(angulo1), radio * sin(angulo1));
        angulo1 += angulo;
    }
    glEnd();
    glPopMatrix();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 760);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Proyecto 1 - 1SF141");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialkey);
    Dibujar();
    glutMainLoop();
}