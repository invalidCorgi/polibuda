#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class GraphicalObject
{
    public:
        GraphicalObject();

        GLuint vao;
        GLuint bufVertices; //Uchwyt na bufor VBO przechowujący tablicę współrzędnych wierzchołków
        GLuint bufNormals; //Uchwyt na bufor VBO przechowujący tablicę wektorów normalnych
        GLuint bufTexCoords; //Uchwyt na bufor VBO przechowujący tablicę współrzędnych teksturowania

        GLuint texture;

        std::vector< glm::vec4 > vertices;
        std::vector< glm::vec2 > uvs;
        std::vector< glm::vec4 > normals;

        virtual ~GraphicalObject();

    protected:

    private:
};

#endif // GRAPHICALOBJECT_H
