#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define taxaMovimento 0.15

//futuro objeto que irá representar uma parte do cenário para teste de colisão
typedef struct{
    int x, y, altura, largura;
    float rgb[3];
    bool solido;
} Quadrado;

//posição da câmera
GLdouble posX= 0, posY = 0, posZ = 5;


//arraylist com todos os objetos do cenários para teste de colisão
std::vector<Quadrado> objetos;


//funções de movimentação da câmera quando alguma tecla for apertada
void moverCima()
{
     posY += taxaMovimento;
}

void moverBaixo()
{
     posY -= taxaMovimento;
}

void moverEsquerda()
{
     posX -= taxaMovimento;
}

void moverDireita()
{
    posX += taxaMovimento;
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
          default:
               exit(0);
               break;
	}
	glutPostRedisplay();
}

//desenha os eixos coloridos
void desenharEixos()
{
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

     // Limpar a visualização com a cor de fundo
     //glClear(GL_COLOR_BUFFER_BIT);

     // Desenha linhas com nova espessura
     glLineWidth(2);

     //eixo X vermelho
     glColor3f(1.0f, 0.0f, 0.0f);

     glBegin(GL_LINES);
          glVertex3i(-200,0,0);
          glVertex3i(200,0,0);
     glEnd();

     //eixo Y verde
     glColor3f(0.0f, 1.0f, 0.0f);

     glBegin(GL_LINES);
          glVertex3i(0,-200,0);
          glVertex3i(0,200,0);
     glEnd();

     //eixo Z azul
//     glColor3f(0.0f, 0.0f, 1.0f);
//
//     glBegin(GL_LINES);
//          glVertex3i(0,0,-200);
//          glVertex3i(0,0,200);
//     glEnd();
}

//desenha os objetos
void acao(void)
{

     glClear(GL_COLOR_BUFFER_BIT);

     //reposiciona a camera
     glLoadIdentity();
     gluLookAt(posX,posY,posZ, posX,posY,0, 0,1,0);

     //desenha objetos
     desenharEixos();
     cenario();


     glFlush();
}

void reshape(GLsizei w, GLsizei h)
{
     printf("w: %.1f h: %.1f posz: %.1f\n\n",(float) w, (float) h, (float) posZ);
     //posZ = w/h;
     //chamada quando redimensiona a tela
     glViewport (0, 0, w, h);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
     glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(640,640);
     glutInitWindowPosition(100,100);
     glutCreateWindow("Remote Robot");

     glutDisplayFunc(acao);
     glutReshapeFunc(reshape);
     glutKeyboardFunc (teclado);
     glutSpecialFunc(tecladoSpecial);

     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

     glutMainLoop();
}
