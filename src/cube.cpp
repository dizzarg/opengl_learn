#include <vector>
#include "Vertex.h"

const std::vector<Vertex> cube = {
  { glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f,  0.5f, -0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f,  0.5f, -0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3( -0.5f,  0.5f, -0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3( -0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},

  { glm::vec3( -0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3( -0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},
  { glm::vec3( -0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 0.1f, 0.7f)},

  { glm::vec3( -0.5f,  0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3( -0.5f,  0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3( -0.5f, -0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3( -0.5f, -0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3( -0.5f, -0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3( -0.5f,  0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},

  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3(  0.5f,  0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f, -0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},
  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 1.0f, 0.0f, 0.0f)},

  { glm::vec3( -0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3( -0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3( -0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},

  { glm::vec3( -0.5f,  0.5f, -0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f,  0.5f, -0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(  0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3( -0.5f,  0.5f,  0.5f), glm::vec3( 0.0f, 1.0f, 0.0f)},
  { glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3( 0.0f, 1.0f, 0.0f)}
};
