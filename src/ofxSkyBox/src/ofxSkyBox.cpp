//
// ofxSkyBox.cpp
//
// Created by kalwalt alias Walter Perdan on 27/12/11
// Copyright 2011 http://www.kalwaltart.it/ All rights reserved.
//



#include "ofxSkyBox.h"

ofxSkyBox::ofxSkyBox(){



}

void ofxSkyBox::load(){

    cubeshader.load("shaders/skybox/skybox");
	cubeMap.loadImages("shaders/skybox/positive_x.png","shaders/skybox/positive_y.png","shaders/skybox/positive_z.png","shaders/skybox/negative_x.png","shaders/skybox/negative_y.png","shaders/skybox/negative_z.png");

}

void ofxSkyBox::draw() {

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


		glEnable(GL_TEXTURE_CUBE_MAP_ARB);

		glDepthFunc(GL_LEQUAL);
		glEnable(GL_DEPTH_TEST);
		cubeshader.begin();
		//glDisable(GL_DEPTH_TEST);
		glActiveTexture(GL_TEXTURE0);
		cubeMap.bind();



		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	   	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);





        cubeshader.setUniform1i("EnvMap", 0);
    	glMatrixMode(GL_MODELVIEW);
    	glPushMatrix();


	 Draw_Skybox(0, 0, 0, 100, 100, 100);



	cubeshader.end();

	glDisable(GL_TEXTURE_CUBE_MAP_ARB);

	glDisable(GL_DEPTH_TEST);
   	glPopMatrix();










}

void ofxSkyBox::Draw_Skybox(float x, float y, float z, float width, float height, float length){

    // Center the Skybox around the given x,y,z position
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;


	// Draw Front side

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height, z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height, z+length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z+length);
	glEnd();

	// Draw Back side

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Left side

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Right side

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height,	z);
	glEnd();

	// Draw Up side

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height, z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
	glEnd();

	// Draw Down side

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z);
	glEnd();



}





