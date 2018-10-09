#include "loadOBJ.h"

bool loadOBJ(
    const char * path,
    std::vector < glm::vec4 > & out_vertices,
    std::vector < glm::vec2 > & out_uvs,
    std::vector < glm::vec4 > & out_normals
)
{
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec4 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec4 > temp_normals;
    FILE * file = fopen(path, "r");
    if( file == NULL )
    {
        printf("Impossible to open the file !\n");
        return false;
    }
    while( 1 )
    {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if ( strcmp( lineHeader, "v" ) == 0 )
        {
            glm::vec4 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            vertex.w = 1.0f;
            temp_vertices.push_back(vertex);
        }
        else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            temp_uvs.push_back(uv);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
            glm::vec4 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            normal.w = 0.0f;
            temp_normals.push_back(normal);
            printf("%f %f %f %f",normal.x,normal.y,normal.z,normal.w);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 )
        {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9)
            {
                printf("File can't be read by our simple parser : ( Try exporting with other options\n %d",matches);
                return false;
            }
            /*else{
                printf("lel");
            }*/
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    // For each vertex of each triangle
    for( unsigned int i=0; i<vertexIndices.size(); i++ )
    {
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec4 vertex = temp_vertices[ vertexIndex-1 ];
        out_vertices.push_back(vertex);
    }
    for( unsigned int i=0; i<uvIndices.size(); i++ )
    {
        unsigned int uvIndex = uvIndices[i];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        out_uvs.push_back(uv);
    }
    for( unsigned int i=0; i<normalIndices.size(); i++ )
    {
        unsigned int normalIndex = normalIndices[i];
        glm::vec4 normal = temp_normals[ normalIndex-1 ];
        out_normals.push_back(normal);
    }
    return true;
}
