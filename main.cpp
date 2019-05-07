/*
     como instalar a biblioteca: qhttps://paulocweger.wordpress.com/2016/05/28/configurando-opengl-no-codeblocks/
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define taxaMovimento 0.15
#define distanciaCamera 0.5
#define limMinEixo -1000
#define limMaxEixo 1000
#define maxZoom 200
#define minZoom 10

//futuro objeto que irá representar uma parte do cenário para teste de colisão
typedef struct{
    int x, y, altura, largura;
    float rgb[3];
    bool solido;
} Quadrado;


GLdouble posX= 0, posY = 0, posZ = 0, //posição do personagem
         posCamX= 0, posCamY = 0, posCamZ = 20; //posição da câmera

int linRobo=3, colRobo=2;
float limInf = -190;
float limEsq = -190;
float cel = 38;

//arraylist com todos os objetos do cenários para teste de colisão
std::vector<Quadrado> objetos;

//funções de movimentação da câmera quando alguma tecla for apertada
void moverCima()
{
     posY += taxaMovimento;
     posCamY = posY - distanciaCamera;
}

void moverBaixo()
{
     posY -= taxaMovimento;
     posCamY = posY + distanciaCamera;
}

void moverEsquerda()
{
     posX -= taxaMovimento;
     posCamX = posX + distanciaCamera;
}

void moverDireita()
{
     posX += taxaMovimento;
     posCamX = posX - distanciaCamera;
}

void resetarPosCamera()
{
     posCamY = posY;
     posCamX = posX;
}

void zoomOut()
{
     if(posCamZ < maxZoom)
          posCamZ += taxaMovimento;
}

void zoomIn()
{
     if(posCamZ > minZoom)
          posCamZ -= taxaMovimento;
}

//captura eventos das setas
void tecladoSpecial(int key, int x, int y)
{
	switch (key)
	{
          case GLUT_KEY_LEFT :
               moverEsquerda();
               break;

          case GLUT_KEY_RIGHT :
               moverDireita();
               break;

		case GLUT_KEY_UP :
               moverCima();
               break;

		case GLUT_KEY_DOWN :
               moverBaixo();
               break;
	}

     glutPostRedisplay();
}

//captura os eventos do teclado
void teclado (unsigned char key, int x, int y)
{
     printf("especial: %c\n",key);
	switch(key)
	{
		case 'w':
		     moverCima();
               break;
		case 'a':
		     moverEsquerda();
		     break;
		case 's':
		     moverBaixo();
		     break;
		case 'd':
		     moverDireita();
               break;
          case 'r':
               zoomIn();
               break;
          case 'f':
               zoomOut();
               break;

          case ' ':
               resetarPosCamera();
               break;

          default:
               exit(0);
               break;
	}
	glutPostRedisplay();
}

//nessa função será a que realmente desenha o cenário em si. Cada parede, corredor e tudo mais relacionado ao ambiente
void cenario()
{
     //por enquanto estou testando a movimentação, então só mostra um objeto qualquer
     glColor3f (0,0,0);
     glBegin(GL_QUADS);
          glVertex3i(0,0,0);   // v0
          glVertex3i(0,5,0);   // v1
          glVertex3i(5,0,0);   // v2
          glVertex3i(5,5,0);   // v3
     glEnd();
}

//desenha os eixos coloridos
void desenharEixos()
{
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     //glClear(GL_COLOR_BUFFER_BIT);

     // Desenha linhas com nova espessura
     glLineWidth(1);

     //eixo X vermelho
     glColor3f(1.0f, 0.0f, 0.0f);

     glBegin(GL_LINES);
          glVertex3i(limMinEixo,0,0);
          glVertex3i(limMaxEixo,0,0);
     glEnd();

     //eixo Y verde
     glColor3f(0.0f, 1.0f, 0.0f);

     glBegin(GL_LINES);
          glVertex3i(0,limMinEixo,0);
          glVertex3i(0,limMaxEixo,0);
     glEnd();

     //eixo Z azul
     glColor3f(0.0f, 0.0f, 1.0f);

     glBegin(GL_LINES);
          glVertex3i(0,0,0);
          glVertex3i(0,0,limMaxEixo);
     glEnd();

     //eixo Z azul completo
//     glColor3f(0.0f, 0.0f, 1.0f);
//
//     glBegin(GL_LINES);
//          glVertex3i(0,0,limMinEixo);
//          glVertex3i(0,0,limMaxEixo);
//     glEnd();
}

void desenharPersonagem()
{
     glColor3f (0.5,0.5,0);

     glBegin(GL_POLYGON);
          glVertex3f(posX-2,posY-2,posZ);   // v0
          glVertex3f(posX+2,posY-2,posZ);   // v1
          glVertex3f(posX+2,posY+2,posZ);   // v2
          glVertex3f(posX-2,posY+2,posZ);   // v3
     glEnd();
}

void cenarioX()
{

  glClear(GL_COLOR_BUFFER_BIT);
  float cor1 = 0.7;
  float cor2 = 0.9;
  int corAtual = 1;
  float cor, xe, xd, yi, ys;
  int col, lin;

  for(lin=1; lin<=10; lin++)
  {
      for(col=1; col<=10; col++)
      {
           xe = limEsq + (lin-1) * cel;
           xd = limEsq + (lin) * cel;

           yi = limInf + (col-1) * cel;
           ys = limInf + (col) * cel;

          if (corAtual == 1)
          {
             cor = cor2;
             corAtual = 2;
          }
          else
          {
             cor = cor1;
             corAtual = 1;
          }

          glColor3f (cor, cor, cor);
          glBegin(GL_QUADS);
          glVertex2f(xe,yi);   // v0
          glVertex2f(xd,yi);   // v1
          glVertex2f(xd,ys);   // v2
          glVertex2f(xe,ys);   // v3
          glEnd();

      }

          if (corAtual == 1)
          {
             cor = cor2;
             corAtual = 2;
          }
          else
          {
             cor = cor1;
             corAtual = 1;
          }

  }

  glFlush();
}

//desenha os objetos
void acao(void)
{
     //log das posições
     printf("X: %.2f Y: %.2f Z: %.2f\n",(float) posX, (float) posY, (float) posZ);
     printf("Xc: %.2f Yc: %.2f Zc: %.2f\n",(float) posCamX, (float) posCamY, (float) posCamZ);

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

     //reposiciona a camera
     glLoadIdentity();
     gluLookAt(posCamX,posCamY,posCamZ, posCamX,posCamY,0, 0,1,0);

     //desenha parte de trás do eixo z para ficar por trás do personagem
     glColor3f(0.0f, 0.0f, 1.0f);
     glBegin(GL_LINES);
          glVertex3i(0,0,limMinEixo);
          glVertex3i(0,0,0);
     glEnd();

     desenharPersonagem();

     //desenha os eixos XY e a frente do Z
     desenharEixos();

     glFlush();
}


void reshape(GLsizei w, GLsizei h)
{
     //posZ = w/h;
     //chamada quando redimensiona a tela
     glViewport (0, 0, w, h);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, maxZoom);
     glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(640,640);
     glutInitWindowPosition(100,100);
     glEnable(GL_DEPTH_TEST);
     glutCreateWindow("Remote Robot");

     glutDisplayFunc(acao);
     glutReshapeFunc(reshape);
     glutKeyboardFunc (teclado);
     glutSpecialFunc(tecladoSpecial);

     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

     glutMainLoop();
}
