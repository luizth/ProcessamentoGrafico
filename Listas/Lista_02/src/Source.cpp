#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>

using namespace std;

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int setupGeometry();
int generateCircle(float radius, int nPoints);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Variable const
const float Pi = 3.1419;


// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

    // Init and config GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL - LuizThomasini", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }


    int success;
    char infolog[512];

	Shader shader("./shaders/hello.vs", "./shaders/hello.fs");

    int nPoints = 20;
	GLuint VAO = setupGeometry(); // generateCircle(0.5, nPoints);  // setupGeometry();

	GLint colorLoc = glGetUniformLocation(shader.ID, "inputColor");
	// assert(colorLoc > -1);

	glUseProgram(shader.ID);

	//Criando a matriz de proje??o usando a GLM
	glm::mat4 projection = glm::mat4(1); //matriz identidade
	projection = glm::ortho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint projLoc = glGetUniformLocation(shader.ID, "projection");
	glUniformMatrix4fv(projLoc, 1, false, glm::value_ptr(projection));


	// Loop da aplica??o - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as fun??es de callback correspondentes
		glfwPollEvents();

		// Definindo as dimens?es da viewport com as mesmas dimens?es da janela da aplica??o
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		

		// Limpa o buffer de cor
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// --- VIEWPORT
		glViewport(width / 2, height / 2, width / 2, height / 2);

		// Chamada de desenho - drawcall
		// Poligono Preenchido - GL_TRIANGLES
		glUniform4f(colorLoc, 1.0f, 0.2f, 0.0f, 1.0f); //enviando cor para vari?vel uniform inputColor
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, nPoints + 2);

		glBindVertexArray(0);

		// --- VIEWPORT
		glViewport(0, 0, width/2, height/2);

		// Chamada de desenho - drawcall
		// Poligono Preenchido - GL_TRIANGLES
		glUniform4f(colorLoc, 1.0f, 1.0f, 0.0f, 1.0f); //enviando cor para vari?vel uniform inputColor
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, nPoints + 2);

		glBindVertexArray(0);

		// --- VIEWPORT
		glViewport(0, height / 2, width / 2, height / 2);

		// Chamada de desenho - drawcall
		// Poligono Preenchido - GL_TRIANGLES
		glUniform4f(colorLoc, 1.0f, 1.0f, 0.0f, 1.0f); //enviando cor para vari?vel uniform inputColor
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, nPoints + 2);

		glBindVertexArray(0);

		// --- VIEWPORT
		glViewport(width / 2, 0, width / 2, height / 2);

		// Chamada de desenho - drawcall
		// Poligono Preenchido - GL_TRIANGLES
		glUniform4f(colorLoc, 1.0f, 1.0f, 0.0f, 1.0f); //enviando cor para vari?vel uniform inputColor
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, nPoints + 2);

		glBindVertexArray(0);

		glfwSwapBuffers(window);

	}
	glDeleteVertexArrays(1, &VAO);
	
	glfwTerminate();
	return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


int setupGeometry()
{
	GLfloat vertices[] = {
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.0, 0.5, 0.0,
	};

	GLuint VBO, VAO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return VAO;
}

int generateCircle(float radius, int nPoints)
{
	int totalSize = (nPoints + 2) * 3;
	GLfloat* vertices = new GLfloat[totalSize];

	vertices[0] = 0.0; // x
	vertices[1] = 0.0; // y
	vertices[2] = 0.0; // z

	float angle = 0.0;
	float slice = 2 * Pi / (GLfloat)nPoints;
	for (int i = 3; i < totalSize; i += 3)
	{
		float x = radius * cos(angle) * 100;
		float y = radius * sin(angle) * 100;
		float z = 0.0;

		vertices[i] = x;
		vertices[i + 1] = y;
		vertices[i + 2] = z;

		angle += slice;
	}

	GLuint VBO, VAO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, totalSize * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	return VAO;
}