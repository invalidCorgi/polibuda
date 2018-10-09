#ifndef LOADOBJ_H_INCLUDED
#define LOADOBJ_H_INCLUDED

#include <vector>
#include <glm/glm.hpp>
#include <stdio.h>
#include <string>

bool loadOBJ(
    const char * path,
    std::vector < glm::vec4 > & out_vertices,
    std::vector < glm::vec2 > & out_uvs,
    std::vector < glm::vec4 > & out_normals
);

#endif // LOADOBJ_H_INCLUDED
