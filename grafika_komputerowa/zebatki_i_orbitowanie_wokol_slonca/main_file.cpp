/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "allmodels.h"

using namespace glm;

float aspect=1;
float speed=1; //prędkość kątowa obrotu w radianach na sekundę
Models::Torus myTorus(1.5,0.5,36,36);
Models::Sphere slonce(0.5,32,32);
Models::Sphere planeta(0.2,32,32);
Models::Sphere planeta2(0.25,32,32);
Models::Sphere ksiezyc(0.1,32,32);
Models::Sphere ksiezyc2(0.07,32,32);

//Framebuffer size change event processing
void windowResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height); //Generate images in this resolution
	aspect=(float)width/(float)height; //Compute aspect ratio of width to height of the window
}

//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************

	glfwSetFramebufferSizeCallback(window, windowResize);//Zarejestruj procedurę obsługi zmiany rozmiaru ekranu.

    glClearColor(0,0,0,1); //Ustaw kolor czyszczenia bufora kolorów na czarno
    glEnable(GL_LIGHTING); //Włącz cieniowanie
    glEnable(GL_LIGHT0); //Włącz świało numer 0
    glEnable(GL_DEPTH_TEST); //Włącz bufor głębokości
    glEnable(GL_COLOR_MATERIAL); //Włącz ustawianie koloru materiału przez polecenia glColor
}




//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window,float angle) {
	//************Tutaj umieszczaj kod rysujący obraz******************
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczyść bufor kolorów i bufor głębokości

	//Przygotuj macierze rzutowania i widoku dla renderowanego obrazu
	mat4 P=perspective(50.0f*PI/180.0f, aspect, 1.0f, 50.0f); //Wylicz macierz rzutowania

	mat4 V=lookAt( //Wylicz macierz widoku
	vec3(0.0f,0.0f,-5.0f),
	vec3(0.0f,0.0f,0.0f),
	vec3(0.0f,1.0f,0.0f));

	glMatrixMode(GL_PROJECTION); //Włącz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Skopiuj macierz rzutowania



	glMatrixMode(GL_MODELVIEW); //Włącz tryb modyfikacji macierzy model-widok. UWAGA! Macierz ta będzie ładowana przed narysowaniem każdego modelu
    mat4 M=mat4(1.0f);
    M=translate(M,glm::vec3(-2.1,0,0));
	M=rotate(M,angle,vec3(0.0f,0.0f,-1.0f));
	glLoadMatrixf(value_ptr(V*M));
	glColor3d(0.5,0.5,0.5);
	myTorus.drawWire();

	glMatrixMode(GL_MODELVIEW);
    mat4 M2=mat4(1.0f);
    M2=translate(M2,glm::vec3(2.1,0,0));
	M2=rotate(M2,angle,vec3(0.0f,0.0f,1.0f));
	glLoadMatrixf(value_ptr(V*M2));
	glColor3d(0.5,0.5,0.5);
	myTorus.drawWire();

    mat4 M3=M;
	for(int i=0;i<27;i++){
        glMatrixMode(GL_MODELVIEW);
        M3=M;
        M3=rotate(M3,i*6.28f/27,glm::vec3(0,0,1));
        M3=translate(M3,glm::vec3(2.1,0,0));
        M3=scale(M3,glm::vec3(0.1,0.1,0.1));
        glLoadMatrixf(value_ptr(V*M3));
        glColor3d(0.5,0.5,0.5);
        Models::cube.drawSolid();
	}

	for(int i=0;i<27;i++){
        glMatrixMode(GL_MODELVIEW);
        M3=M2;
        M3=rotate(M3,3.14f/27+i*6.28f/27,glm::vec3(0,0,-1));
        M3=translate(M3,glm::vec3(-2.1,0,0));
        M3=scale(M3,glm::vec3(0.1,0.1,0.1));
        glLoadMatrixf(value_ptr(V*M3));
        glColor3d(0.5,0.5,0.5);
        Models::cube.drawSolid();
	}

    //Rysowanie pojedynczego modelu
    //1. Oblicz i załaduj macierz modelu
	/*mat4 M=mat4(1.0f); //Wylicz macierz modelu
	//M=rotate(M,angle,vec3(0.0f,0.0f,1.0f));
	//M=scale()
	glLoadMatrixf(value_ptr(V*M)); //Załaduj macierz model-widok
	//2. Narysuj obiekt
	glColor3d(1,1,0);
	slonce.drawSolid();
    //Stop

	glMatrixMode(GL_MODELVIEW);
	mat4 M2=M;
	M2=rotate(M2,angle,vec3(0.0f,1.0f,0.0f));
	M2=translate(M2,glm::vec3(-1.5,0,0));
	glLoadMatrixf(value_ptr(V*M2));
	glColor3d(0,1,0);
	planeta.drawSolid();

	glMatrixMode(GL_MODELVIEW);
	mat4 M3=M2;
	M3=rotate(M3,4*angle,vec3(0.0f,1.0f,0.0f));
	M3=translate(M3,glm::vec3(-0.5,0,0));
	glLoadMatrixf(value_ptr(V*M3));
	glColor3d(0,0,1);
	ksiezyc.drawSolid();

	glMatrixMode(GL_MODELVIEW);
	mat4 M4=M;
	M4=rotate(M4,angle,vec3(0.0f,0.0f,1.0f));
	M4=translate(M4,glm::vec3(-2,0,0));
	glLoadMatrixf(value_ptr(V*M4));
	glColor3d(0,0,1);
	planeta2.drawSolid();

	glMatrixMode(GL_MODELVIEW);
	mat4 M5=M4;
	M5=rotate(M5,4*angle,vec3(1.0f,0.0f,0.0f));
	M5=translate(M5,glm::vec3(-0.3,0,0));
	glLoadMatrixf(value_ptr(V*M5));
	glColor3d(0.5,0.5,0.5);
	ksiezyc2.drawSolid();*/

	//Koniec
	glfwSwapBuffers(window);
}

int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.


	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	GLenum err;
	if ((err=glewInit()) != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

	float angle=0; //Aktualny kąt obrotu obiektu
	glfwSetTime(0); //Wyzeruj licznik czasu
	//Główna pętla
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
	    angle+=speed*glfwGetTime(); //Powiększ kąt obrotu o szybkość obrotu razy czas, który minął od poprzedniej klatki
	    glfwSetTime(0); //Wyzeruj licznik czasu
		drawScene(window,angle); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
