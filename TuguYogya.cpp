#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "shader.h"
#include <SOIL.h>
#include <iostream>

using namespace glm;
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Halo OpenGL", nullptr,
		nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrievingfunction pointers and extensions 
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("Object3D.vs", "Object3D.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		/*0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,

		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
		0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
		0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
		0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,

		0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
		-0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,*/
		//0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
//=============================>>> KUBUS 1 <<<===============================
		/*-0.5f, -1.2f, 0.5f, 0.5f, 0.5f, 0.1f, //index 0 //AlasDasar
		0.5f, -1.2f, 0.5f, 0.5f, 0.5f, 0.1f, //index 1
		0.5f, -1.2f, -0.5f, 0.5f, 0.5f, 0.1f, //index 2
		-0.5f, -1.2f, -0.5f, 0.5f, 0.5f, 0.1f, //index 3

		-0.5f, -1.15f, 0.5f, 0.5f, 0.5f, 0.1f, //index 4 //AlasDasar
		0.5f, -1.15f, 0.5f, 0.5f, 0.5f, 0.1f, //index 5
		0.5f, -1.15f, -0.5f, 0.5f, 0.5f, 0.1f, //index 6
		-0.5f, -1.15f, -0.5f, 0.5f, 0.5f, 0.1f, //index 7

		-0.5f, -1.2f, 0.5f, 0.5f, 0.0f, 0.8f, //index 8 //Depan
		0.5f, -1.2f, 0.5f, 0.5f, 0.0f, 0.8f, //index 9
		0.5f, -1.15f, 0.5f, 0.5f, 0.0f, 0.8f, //index 10
		-0.5f, -1.15f, 0.5f, 0.5f, 0.0f, 0.8f, //index 11

		0.5f, -1.2f, -0.5f, 0.5f, 0.5f, 0.8f, //index 12 //Kanan
		0.5f, -1.2f, 0.5f, 0.5f, 0.5f, 0.8f, //index 13
		0.5f, -1.15f, 0.5f, 0.5f, 0.5f, 0.8f, //index 14
		0.5f, -1.15f, -0.5f, 0.5f, 0.5f, 0.8f, //index 15

		-0.5f, -1.2f, -0.5f, 0.1f, 0.5f, 0.8f, //index 16 //Kiri
		-0.5f, -1.2f, 0.5f, 0.1f, 0.5f, 0.8f, //index 17
		-0.5f, -1.15f, 0.5f, 0.1f, 0.5f, 0.8f, //index 18
		-0.5f, -1.15f, -0.5f, 0.1f, 0.5f, 0.8f, //index 19

		-0.5f, -1.2f, -0.5f, 0.5f, 0.5f, 0.8f, //index 20 //Belakang
		0.5f, -1.2f, -0.5f, 0.5f, 0.5f, 0.8f, //index 21
		0.5f, -1.15f, -0.5f, 0.5f, 0.5f, 0.8f, //index 22
		-0.5f, -1.15f, -0.5f, 0.5f, 0.5f, 0.8f, //index 23

//=============================>>> KUBUS 2 <<<===============================
		-0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.1f, //index 24 //AlasDasar
		0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.1f, //index 25
		0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.1f, //index 26
		-0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.1f, //index 27

		-0.45f, -1.15f, 0.45f, 0.5f, 0.0f, 0.8f, //index 28 //Depan
		0.45f, -1.15f, 0.45f, 0.5f, 0.0f, 0.8f, //index 29
		0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.8f, //index 30
		-0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.8f, //index 31

		0.45f, -1.15f, -0.45f, 0.5f, 0.0f, 0.8f, //index 32 //Kanan
		0.45f, -1.15f, 0.45f, 0.5f, 0.0f, 0.8f, //index 33
		0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.8f, //index 34
		0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.8f, //index 35

		-0.45f, -1.15f, -0.45f, 0.5f, 0.0f, 0.8f, //index 36 //Belakanng
		0.45f, -1.15f, -0.45f, 0.5f, 0.0f, 0.8f, //index 37
		0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.8f, //index 38
		-0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.8f, //index 39

		-0.45f, -1.15f, -0.45f, 0.5f, 0.0f, 0.8f, //index 40 //Kiri
		-0.45f, -1.15f, 0.45f, 0.5f, 0.0f, 0.8f, //index 41
		-0.45f, -1.1f, 0.45f, 0.5f, 0.0f, 0.8f, //index 42
		-0.45f, -1.1f, -0.45f, 0.5f, 0.0f, 0.8f, //index 43

//=============================>>> KUBUS 3 <<<===============================
		-0.4f, -1.05f, 0.4f, 0.0f, 0.0f, 1.0f, //index 44 //AlasDasar
		0.4f, -1.05f, 0.4f, 0.0f, 0.0f, 1.0f, //index 45
		0.4f, -1.05f, -0.4f, 0.0f, 0.0f, 1.0f, //index 46
		-0.4f, -1.05f, -0.4f, 0.0f, 0.0f, 1.0f, //index 47

		-0.4f, -1.1f, 0.4f, 0.5f, 0.0f, 0.8f, //index 48 //Depan
		0.4f, -1.1f, 0.4f, 0.5f, 0.0f, 0.8f, //index 49
		0.4f, -1.05f, 0.4f, 0.5f, 0.0f, 0.8f, //index 50
		-0.4f, -1.05f, 0.4f, 0.5f, 0.0f, 0.8f, //index 51

		0.4f, -1.1f, -0.4f, 0.5f, 0.0f, 0.8f, //index 52 //Kanan
		0.4f, -1.1f, 0.4f, 0.5f, 0.0f, 0.8f, //index 53
		0.4f, -1.05f, 0.4f, 0.5f, 0.0f, 0.8f, //index 54
		0.4f, -1.05f, -0.4f, 0.5f, 0.0f, 0.8f, //index 55

		-0.4f, -1.1f, -0.4f, 0.5f, 0.0f, 0.8f, //index 56 //Belakanng
		0.4f, -1.1f, -0.4f, 0.5f, 0.0f, 0.8f, //index 57
		0.4f, -1.05f, -0.4f, 0.5f, 0.0f, 0.8f, //index 58
		-0.4f, -1.05f, -0.4f, 0.5f, 0.0f, 0.8f, //index 59

		-0.4f, -1.1f, -0.4f, 0.5f, 0.0f, 0.8f, //index 60 //Kiri
		-0.4f, -1.1f, 0.4f, 0.5f, 0.0f, 0.8f, //index 61
		-0.4f, -1.05f, 0.4f, 0.5f, 0.0f, 0.8f, //index 62
		-0.4f, -1.05f, -0.4f, 0.5f, 0.0f, 0.8f, //index 63

//=============================>>> KUBUS 4 <<<===============================
		-0.35f, -0.95f, 0.35f, 1.0f, 0.0f, 1.0f, //index 64 //AlasDasar
		0.35f, -0.95f, 0.35f, 1.0f, 0.0f, 1.0f, //index 65
		0.35f, -0.95f, -0.35f, 1.0f, 0.0f, 1.0f, //index 66
		-0.35f, -0.95f, -0.35f, 1.0f, 0.0f, 1.0f, //index 67

		-0.35f, -1.05f, 0.35f, 0.5f, 0.0f, 0.8f, //index 68 //Depan
		0.35f, -1.05f, 0.35f, 0.5f, 0.0f, 0.8f, //index 69
		0.35f, -0.95f, 0.35f, 0.5f, 0.0f, 0.8f, //index 70
		-0.35f, -0.95f, 0.35f, 0.5f, 0.0f, 0.8f, //index 71

		0.35f, -1.05f, -0.35f, 0.5f, 0.0f, 0.8f, //index 72 //Kanan
		0.35f, -1.05f, 0.35f, 0.5f, 0.0f, 0.8f, //index 73
		0.35f, -0.95f, 0.35f, 0.5f, 0.0f, 0.8f, //index 74
		0.35f, -0.95f, -0.35f, 0.5f, 0.0f, 0.8f, //index 75

		-0.35f, -1.05f, -0.35f, 0.5f, 0.0f, 0.8f, //index 76 //Belakanng
		0.35f, -1.05f, -0.35f, 0.5f, 0.0f, 0.8f, //index 77
		0.35f, -0.95f, -0.35f, 0.5f, 0.0f, 0.8f, //index 78
		-0.35f, -0.95f, -0.35f, 0.5f, 0.0f, 0.8f, //index 79

		-0.35f, -1.05f, -0.35f, 0.5f, 0.0f, 0.8f, //index 80 //Kiri
		-0.35f, -1.05f, 0.35f, 0.5f, 0.0f, 0.8f, //index 81
		-0.35f, -0.95f, 0.35f, 0.5f, 0.0f, 0.8f, //index 82
		-0.35f, -0.95f, -0.35f, 0.5f, 0.0f, 0.8f, //index 83
//======================>>>BALOK<<<============================
		-0.25f, -0.5f, 0.3f, 1.0f, 1.0f, 1.0f, //index 84 //BalokAtas
		0.25f, -0.5f, 0.3f, 1.0f, 1.0f, 1.0f, //index 85
		0.25f, -0.5f, -0.3f, 1.0f, 1.0f, 1.0f, //index 86
		-0.25f, -0.5f, -0.3f, 1.0f, 1.0f, 1.0f, //index 87

		-0.35f, -0.95f, 0.35f, 0.0f, 0.0f, 0.8f, //index 88 //Depan
		0.35f, -0.95f, 0.35f, 0.0f, 0.0f, 0.8f, //index 89
		0.25f, -0.5f, 0.3f, 0.0f, 0.0f, 0.8f, //index 90
		-0.25f, -0.5f, 0.3f, 0.0f, 0.0f, 0.8f, //index 91

		0.35f, -0.95f, -0.35f, 0.0f, 0.0f, 0.8f, //index 92 //Kanan
		0.35f, -0.95f, 0.35f, 0.0f, 0.0f, 0.8f, //index 93
		0.25f, -0.5f, 0.3f, 0.0f, 0.0f, 0.8f, //index 94
		0.25f, -0.5f, -0.3f, 0.0f, 0.0f, 0.8f, //index 95

		-0.35f, -0.95f, -0.35f, 0.0f, 0.0f, 0.8f, //index 96 //Belakanng
		0.35f, -0.95f, -0.35f, 0.0f, 0.0f, 0.8f, //index 97
		0.25f, -0.5f, -0.3f, 0.0f, 0.0f, 0.8f, //index 98
		-0.25f, -0.5f, -0.3f, 0.0f, 0.0f, 0.8f, //index 99

		-0.35f, -0.95f, -0.35f, 0.0f, 0.0f, 0.8f, //index 100 //Kiri
		-0.35f, -0.95f, 0.35f, 0.0f, 0.0f, 0.8f, //index 101
		-0.25f, -0.5f, 0.3f, 0.0f, 0.0f, 0.8f, //index 102
		-0.25f, -0.5f, -0.3f, 0.0f, 0.0f, 0.8f, //index 103

//=============================>>> KUBUS 4 <<<===============================
		-0.3f, -0.45f, 0.35f, 1.0f, 1.0f, 0.0f, //index 104 //AlasDasar1
		0.3f, -0.45f, 0.35f, 1.0f, 1.0f, 0.0f, //index 105
		0.3f, -0.45f, -0.35f, 1.0f, 1.0f, 0.0f, //index 106
		-0.3f, -0.45f, -0.35f, 1.0f, 1.0f, 0.0f, //index 107

		-0.3f, -0.5f, 0.35f, 1.0f, 1.0f, 0.0f, //index 108 //AlasDasar2
		0.3f, -0.5f, 0.35f, 1.0f, 1.0f, 0.0f, //index 109
		0.3f, -0.5f, -0.35f, 1.0f, 1.0f, 0.0f, //index 110
		-0.3f, -0.5f, -0.35f, 1.0f, 1.0f, 0.0f, //index 111

		-0.3f, -0.5f, 0.35f, 0.5f, 0.0f, 0.8f, //index 112 //Depan
		0.3f, -0.5f, 0.35f, 0.5f, 0.0f, 0.8f, //index 113
		0.3f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 114
		-0.3f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 115

		0.3f, -0.5f, -0.35f, 0.5f, 0.0f, 0.8f, //index 116 //Kanan
		0.3f, -0.5f, 0.35f, 0.5f, 0.0f, 0.8f, //index 117
		0.3f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 118
		0.3f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 119

		-0.3f, -0.5f, -0.35f, 0.5f, 0.0f, 0.8f, //index 120 //Belakanng
		0.3f, -0.5f, -0.35f, 0.5f, 0.0f, 0.8f, //index 121
		0.3f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 122
		-0.3f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 123

		-0.3f, -0.5f, -0.35f, 0.5f, 0.0f, 0.8f, //index 124 //Kiri
		-0.3f, -0.5f, 0.35f, 0.5f, 0.0f, 0.8f, //index 125
		-0.3f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 126
		-0.3f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 127
		
//>>>>>>>>>>>>>>>>>>>>>>>>>>>Balok Tengahk<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		-0.35f, -0.45f, 0.35f, 1.0f, 1.0f, 0.0f, //index 128 //AlasDasar1
		0.35f, -0.45f, 0.35f, 1.0f, 1.0f, 0.0f, //index 129
		0.35f, -0.45f, -0.35f, 1.0f, 1.0f, 0.0f, //index 130
		-0.35f, -0.45f, -0.35f, 1.0f, 1.0f, 0.0f, //index 131

		-0.35f, -0.25f, 0.35f, 1.0f, 1.0f, 0.0f, //index 132 //AlasDasar2
		0.35f, -0.25f, 0.35f, 1.0f, 1.0f, 0.0f, //index 133
		0.35f, -0.25f, -0.35f, 1.0f, 1.0f, 0.0f, //index 134
		-0.35f, -0.25f, -0.35f, 1.0f, 1.0f, 0.0f, //index 135

		-0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 136 //Depan
		0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 137
		0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 138
		-0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 139

		0.35f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 140 //Kanan
		0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 141
		0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 142
		0.35f, -0.25f, -0.35f, 0.5f, 0.0f, 0.8f, //index 143

		-0.35f, -0.45f, -0.35f, 0.5f, 0.0f, 0.8f, //index 144 //Kiri
		-0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 145
		-0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 146
		-0.35f, -0.25f, -0.35f, 0.5f, 0.0f, 0.8f, //index 147

		-0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 148 //Belakang
		0.35f, -0.45f, 0.35f, 0.5f, 0.0f, 0.8f, //index 149
		0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 150
		-0.35f, -0.25f, 0.35f, 0.5f, 0.0f, 0.8f, //index 151

//>>>>>>>>> Trapesium Tengah <<<<<<<<<<<
		-0.2f, 0.55f, 0.2f, 1.0f, 1.0f, 1.0f, //index 152 //BalokAtas
		0.2f, 0.55f, 0.2f, 1.0f, 1.0f, 1.0f, //index 153
		0.2f, 0.55f, -0.2f, 1.0f, 1.0f, 1.0f, //index 154
		-0.2f, 0.55f, -0.2f, 1.0f, 1.0f, 1.0f, //index 155

		-0.25f, -0.25f, 0.3f, 0.0f, 0.0f, 0.8f, //index 156 //Depan
		0.25f, -0.25f, 0.3f, 0.0f, 0.0f, 0.8f, //index 157
		0.2f, 0.55f, 0.2f, 0.0f, 0.0f, 0.8f, //index 158
		-0.2f, 0.55f, 0.2f, 0.0f, 0.0f, 0.8f, //index 159

		0.25f, -0.25f, -0.3f, 0.0f, 0.0f, 0.8f, //index 160 //Kanan
		0.25f, -0.25f, 0.3f, 0.0f, 0.0f, 0.8f, //index 161
		0.2f, 0.55f, 0.2f, 0.0f, 0.0f, 0.8f, //index 162
		0.2f, 0.55f, -0.2f, -0.0f, 0.0f, 0.8f, //index 163

		-0.25f, -0.25f, -0.3f, 0.0f, 0.0f, 0.8f, //index 164 //Belakang
		0.25f, -0.25f, -0.3f, 0.0f, 0.0f, 0.8f, //index 165
		0.2f, 0.55f, -0.2f, 0.0f, 0.0f, 0.8f, //index 166
		-0.2f, 0.55f, -0.2f, 0.0f, 0.0f, 0.8f, //index 167

		-0.25f, -0.25f, -0.3f, 0.0f, 0.0f, 0.8f, //index 168 //Kiri
		-0.25f, -0.25f, 0.3f, 0.0f, 0.0f, 0.8f, //index 169
		-0.2f, 0.55f, 0.2f, 0.0f, 0.0f, 0.8f, //index 170
		-0.2f, 0.55f, -0.2f, -0.0f, 0.0f, 0.8f, //index 171

//Balok Puncak
		-0.25f, 0.55f, 0.25f, 1.0f, 0.0f, 0.0f, //index 172 //BalokAtas
		0.25f, 0.55f, 0.25f, 1.0f, 0.0f, 0.0f, //index 173
		0.25f, 0.55f, -0.25f, 1.0f, 0.0f, 0.0f, //index 174
		-0.25f, 0.55f, -0.25f, 1.0f, 0.0f, 0.0f, //index 175

		-0.25f, 0.65f, 0.25f, 1.0f, 0.0f, 0.0f, //index 176 //BalokAtas2
		0.25f, 0.65f, 0.25f, 1.0f, 0.0f, 0.0f, //index 177
		0.25f, 0.65f, -0.25f, 1.0f, 0.0f, 0.0f, //index 178
		-0.25f, 0.65f, -0.25f, 1.0f, 0.0f, 0.0f, //index 179

		-0.25f, 0.55f, 0.25f, 0.0f, 1.0f, 0.0f, //index 180 //Depan
		0.25f, 0.55f, 0.25f, 0.0f, 1.0f, 0.0f, //index 181
		0.25f, 0.65f, 0.25f, 0.0f, 1.0f, 0.0f, //index 182
		-0.25f, 0.65f, 0.25f, 0.0f, 1.0f, 0.0f, //index 183

		0.25f, 0.55f, -0.25f, 0.0f, 1.0f, 0.0f, //index 184 //Depan
		0.25f, 0.55f, 0.25f, 0.0f, 1.0f, 0.0f, //index 185
		0.25f, 0.65f, 0.25f, 0.0f, 1.0f, 0.0f, //index 186
		0.25f, 0.65f, -0.25f, 0.0f, 1.0f, 0.0f, //index 187

		-0.25f, 0.55f, -0.25f, 0.0f, 1.0f, 0.0f, //index 188 //Depan
		-0.25f, 0.55f, 0.25f, 0.0f, 1.0f, 0.0f, //index 189
		-0.25f, 0.65f, 0.25f, 0.0f, 1.0f, 0.0f, //index 190
		-0.25f, 0.65f, -0.25f, 0.0f, 1.0f, 0.0f, //index 191

		-0.25f, 0.55f, -0.25f, 0.0f, 1.0f, 0.0f, //index 192 //Depan
		0.25f, 0.55f, -0.25f, 0.0f, 1.0f, 0.0f, //index 193
		0.25f, 0.65f, -0.25f, 0.0f, 1.0f, 0.0f, //index 194
		-0.25f, 0.65f, -0.25f, 0.0f, 1.0f, 0.0f, //index 195

//Segi empat
		0.0f, 0.75f, 0.25f, 0.0f, 1.0f, 0.8f, //index 196 //Depan
		0.25f, 0.75f, 0.0f, 0.0f, 1.0f, 0.8f, //index 197
		0.0f, 0.75f, -0.25f, 0.0f, 1.0f, 0.8f, //index 198
		-0.25f, 0.75f, 0.0f, 0.0f, 1.0f, 0.8f, //index 199

		0.0f, 0.75f, 0.25f, 1.0f, 1.0f, 0.8f, //index 196 //Depan
		0.25f, 0.75f, 0.0f, 1.0f, 1.0f, 0.8f, //index 197
		0.25f, 0.65f, 0.0f, 1.0f, 1.0f, 0.8f, //index 198
		0.0f, 0.65f, 0.25f, 1.0f, 1.0f, 0.8f, //index 199

		0.0f, 0.75f, 0.25f, 1.0f, 0.0f, 0.8f, //index 196 //Depan
		-0.25f, 0.75f, 0.0f, 1.0f, 0.0f, 0.8f, //index 197
		-0.25f, 0.65f, 0.0f, 1.0f, 0.0f, 0.8f, //index 198
		0.0f, 0.65f, 0.25f, 1.0f, 0.0f, 0.8f, //index 199

		0.0f, 0.75f, -0.25f, 1.0f, 0.0f, 1.8f, //index 196 //Depan
		-0.25f, 0.75f, 0.0f, 1.0f, 0.0f, 1.8f, //index 197
		-0.25f, 0.65f, 0.0f, 1.0f, 0.0f, 1.8f, //index 198
		0.0f, 0.65f, -0.25f, 1.0f, 0.0f, 1.8f, //index 199

		0.0f, 0.75f, -0.25f, 0.0f, 0.0f, 1.8f, //index 196 //Depan
		0.25f, 0.75f, 0.0f, 0.0f, 0.0f, 1.8f, //index 197
		0.25f, 0.65f, 0.0f, 0.0f, 0.0f, 1.8f, //index 198
		0.0f, 0.65f, -0.25f, 0.0f, 0.0f, 1.8f, //index 199

		0.0f, 0.75f, 0.1f, 1.0f, 0.0f, 0.0f, //index  //kanan
		0.1f, 0.75f, 0.0f, 1.0f, 0.0f, 0.0f,// index 
		0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,//index 

		0.1f, 0.75f, 0.0f, 0.0f, 1.0f, 0.0f, //index  //kanan Atas
		0.0f, 0.75f, -0.1f, 0.0f, 1.0f, 0.0f,// index 
		0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,//index 

		-0.1f, 0.75f, 0.0f, 0.0f, 0.0f, 1.0f, //index  //kiri Atas
		0.0f, 0.75f, -0.1f, 0.0f, 0.0f, 1.0f,// index 
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,//index 

		0.0f, 0.75f, 0.1f, 1.0f, 1.0f, 0.0f, //index 
		-0.1f, 0.75f, 0.0f, 1.0f, 1.0f, 0.0f,// index 
		0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,*/

		-0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //0
		0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //2
		0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //3
		-0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //4
		-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //5
		//Atas
		-0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //0
		0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		0.0f, 1.0f, 0.0f, 0.2f, 1.0f, 0.0f, //9
		//Bawah
		-0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //0
		0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		0.0f, -1.0f, 0.0f, 0.2f, 1.0f, 0.0f, //9
		//KananAtas
		0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, //2
		0.90f, 0.70f, 0.0f, 0.2f, 1.0f, 0.0f, //1
		//KiriAtas
		-0.25f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		-0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, //2
		-0.90f, 0.70f, 0.0f, 0.2f, 1.0f, 0.0f, //1
		//KananBawah
		0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, //2
		0.90f, -0.70f, 0.0f, 0.2f, 1.0f, 0.0f, //1
		//KiriBawah
		-0.25f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //1
		-0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, //2
		-0.90f, -0.70f, 0.0f, 0.2f, 1.0f, 0.0f, //1
	};

	/*GLuint sixpath[] = {

	};*/

	GLuint indices[] = {
		0, 1, 2, 
		2, 3, 0,
		3, 4, 5, 
		5, 0, 3,
		
		6, 7, 8,
		9, 10, 11,
		12, 13, 14,
		15, 16, 17,
		18,19,20,
		21, 22, 23
		/*0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9, 10, 10, 11, 8,
		12, 13, 14, 14, 15, 12,
		16, 17, 18, 18, 19, 16,
		20, 21, 22, 22, 23, 20,
		24, 25, 26, 26, 27, 24,
		28, 29, 30, 30, 31, 28,
		32, 33, 34, 34, 35, 32,
		36, 37, 38, 38, 39, 36,
		40, 41, 42, 42, 43, 40,
		44, 45, 46, 46, 47, 44,
		48, 49, 50, 50, 51, 48,
		52, 53, 54, 54, 55, 52,
		56, 57, 58, 58, 59, 56,
		60, 61, 62, 62, 63, 60,
		64, 65, 66, 66, 67, 64,
		68, 69, 70, 70, 71, 68,
		72, 73, 74, 74, 75, 72,
		76, 77, 78, 78, 79, 76,
		80, 81, 82, 82, 83, 80,
		84, 85, 86, 86, 87, 84,
		88, 89, 90, 90, 91, 88,
		92, 93, 94, 94, 95, 92,
		96, 97, 98, 98, 99, 96,
		100, 101, 102, 102, 103, 100,
		104, 105, 106, 106, 107, 104,
		108, 109, 110, 110, 111, 108,
		112, 113, 114, 114, 115, 112,
		116, 117, 118, 118, 119, 116,
		120, 121, 122, 122, 123, 120,
		124, 125, 126, 126, 127, 124,
		128, 129, 130, 130, 131, 128,
		132, 133, 134, 134, 135, 132,
		136, 137, 138, 138, 139, 136,
		140, 141, 142, 142, 143, 140,
		144, 145, 146, 146, 147, 144,
		148, 149, 150, 150, 151, 148,
		152, 153, 154, 154, 155, 152,
		156, 157, 158, 158, 159, 156,
		160, 161, 162, 162, 163, 160,
		164, 165, 166, 166, 167, 164,
		168, 169, 170, 170, 171, 168,
		172, 173, 174, 174, 175, 172,
		176, 177, 178, 178, 179, 176,
		180, 181, 182, 182, 183, 180,
		184, 185, 186, 186, 187, 184,
		188, 189, 190, 190, 191, 188,
		192, 193, 194, 194, 195, 192,
		//Segi empat dan limas
		196, 197, 198, 198, 199, 196,
		200, 201, 202, 202, 203, 200,
		204, 205, 206, 206, 207, 204,
		208, 209, 210, 210, 211, 208,
		212, 213, 214, 214, 215, 212,
		216, 217, 218,
		219, 220, 221,
		222, 223, 224,
		225, 226, 227*/

	};

	glEnable(GL_DEPTH_TEST);

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(sixpath), sixpath, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	float i = 0;
	float time = 100;
	while (!glfwWindowShouldClose(window))
	{
		i++;
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);

		ourShader.Use();
		mat4 model, modelX, modelY, modelZ;
		mat4 view;
		mat4 projection;

		model = rotate(model, i/time, vec3(0.0f, 1.0f, 0.0f));
		view = translate(view, vec3(0.0f, 0.2f, -3.0f));
		projection = perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();

	return 0;
}