/* programa ex1_HelloWorld.c */
/* Para compreender estrutura inicial de um programa com OpenGL
   - Desenha um ponto em (100,100)
  */

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int linRobo=3, colRobo=2;
float limInf = -190;
float limEsq = -190;
float cel = 38;
BOOLEAN teste = true;

// Funções callback para desenhos
// Para exemplificar figuras
void DesenhaPontos(void);
void DesenhaLinhas(void);
void DesenhaTriangulos(void);
void DesenhaQuadrados(void);
void DesenhaPoligonos(void);

// Para exemplificar transfs.
void Translacao(void);
void Escala(void);
void Rotacao(void);

// Para vislumbrar cenário
void displayRobo(void);
void displaySala(void);


// Funções callback para outras funções
void Inicializa (void);
void Teclado (unsigned char key, int x, int y);

int main(int argc, char *argv[])
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Primeiro exemplo");
// Desenho das figuras
    // glutDisplayFunc(DesenhaPontos);
    // glutDisplayFunc(DesenhaLinhas);
//     glutDisplayFunc(DesenhaTriangulos);
  //   glutDisplayFunc(DesenhaQuadrados);
//     glutDisplayFunc(DesenhaPoligonos);

// Transformações
     //glutDisplayFunc(Translacao);
//     glutDisplayFunc(Escala);
//     glutDisplayFunc(Rotacao);

// Cenário de exemplo
     glutDisplayFunc(displaySala);
     glutKeyboardFunc (Teclado);

  //   gluLookAt(posX,posY,posZ)
     Inicializa();
     glutMainLoop();
}


void DesenhaPontos(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha
     //(funcionamento como máquina de estado para cor)
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha os pontos com novo tamanho
     glPointSize(10);
     glBegin(GL_POINTS);
               glVertex2i(100,100);
               glVertex2i(0,0);
               glVertex2i(0,100);
               glVertex2i(100,0);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}


void DesenhaLinhas(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha (funcionamento como máquina de estado para cor)
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha linhas com nova espessura
     glLineWidth(10);
     glBegin(GL_LINES);
               glVertex2i(-100,-100);
               glVertex2i(100,100);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}


void DesenhaTriangulos(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha (funcionamento como máquina de estado para cor)
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void DesenhaQuadrados(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha (funcionamento como máquina de estado para cor)
     glColor3f(0.0f, 1.0f, 0.0f);

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(-100,50);
               glVertex2i(-100,-50);
               // Especifica que a cor corrente é azul
               //glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(50,-50);
               glVertex2i(50,50);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void DesenhaPoligonos(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha
     //(funcionamento como máquina de estado para cor)
     glColor3f(1.0f, 0.0f, 0.0f);

     // Desenha os pontos com novo tamanho
     glPointSize(10);
     glBegin(GL_POLYGON);
               glVertex2i(100,120);
               glVertex2i(0,30);
               glVertex2i(0,100);
               glVertex2i(100,0);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}


void Translacao(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     DesenhaQuadrados();

     glTranslatef(+30.0f, -70.0f, 0.0f);

     // Cor corrente é azul
     glColor3f(0.0f, 0.0f, 1.0f);
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void Escala(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     // Cor corrente é vermelha (funcionamento como máquina de estado para cor)
     glColor3f(1.0f, 0.0f, 0.0f);
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     glScalef(+0.5f, 0.7f, 0.0f);

     glColor3f(0.0f, 0.0f, 1.0f);
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void Rotacao(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1.0f, 0.0f, 0.0f);
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     glRotatef(30, 0.0f, 0.0f, 1.0f);

     glColor3f(0.0f, 0.0f, 1.0f);
     glBegin(GL_TRIANGLES);
               glVertex2i(0,0);
               glVertex2i(100,0);
               glVertex2i(0,150);
     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

void Inicializa (void)
{
    // Cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D (-200.0f, 200.0f, -200.0f, 200);
}



void displayRobo(void){

  float xe = limEsq + (colRobo-1) * cel;
  float xd = limEsq + (colRobo) * cel;
  float yi = limInf + (linRobo-1) * cel;
  float ys = limInf + (linRobo) * cel;
  float ym = (yi+ys) / 2;

  glColor3f (0.7, 0.0, 0.0);
  glBegin(GL_TRIANGLES);
      glVertex2f(xe,yi);
      glVertex2f(xe,ys);
      glVertex2f(xd,ym);
  glEnd();
//  glFlush();
}

void displaySala(void){

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

          if(teste) printf("xe = %.1f \nyi = %.1f \nxd = %.1f \nys = %.1f \n\n", xe, yi, xd, ys);
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

    teste = false;
  }

  displayRobo();


  glFlush();
}

void Teclado (unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'a':	colRobo--;
					break;
		case 'w':	linRobo++;
					break;
		case 'x':	linRobo--;
					break;
		case 'd':	colRobo++;
					break;
        case 'q':   exit(0);
                    break;
	}
	glutPostRedisplay();
}

