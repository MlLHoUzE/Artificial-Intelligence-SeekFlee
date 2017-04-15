#pragma once
#include "externals.h"
#include "cCamera.h"
#include "cEntity.h"
#include "cAreaInfo.h"

extern GLFWwindow* gWindow;

extern cCamera* gCamera;

extern cAreaInfo* gAreaInfo;


extern std::vector<cEntity*> gEntities;
extern cPlayer* gPlayer;
//extern cAreaInfo* gAreaInfo;


extern glm::mat4 gMonkeyMatrix;
extern glm::vec4 gMonkeyColor;

extern GLuint gVertexBufferID;
extern GLuint gTexCoordBufferID;
extern GLuint gNormalBufferID;
extern GLuint gIndexBufferID;

extern GLuint gProgramID;
extern GLuint gUniformId_ModelMatrix;
extern GLuint gUniformId_ViewMatrix;
extern GLuint gUniformId_PojectionMatrix;
extern GLuint gUniformId_ModelColor;
extern GLuint gUniformId_EyePosition;


float getRandFloat(float LO, float HIGH);

