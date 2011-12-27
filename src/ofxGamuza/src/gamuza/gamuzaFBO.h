#ifndef _GAMUZAFBO
#define _GAMUZAFBO

// constants
#include "gamuzaConstants.h"
// extending ofxLuaWrapper for gamuza -> lua binding
#include "gamuzaWrapper.h"			

//////////////////////////////////////////////
// FBO texture with mapping structure vars
string					fboVideoFile;
bool					useVideoFile;
float					videoFileW;
float					videoFileH;

ofImage					calibImage;
ofImage					calibImageBW;
ofImage					capDevNO;
ofImage					kuro;

int						res;
int						realRes;

char					shaderName[64];
float					fbo_gammaCorrection;
float					fbo_brightness;
float					fbo_saturation;
float					fbo_contrast;
float					fbo_filmBleach;
float					fbo_techniColor;
float					fbo_whiteDiffusion;
float					fbo_exposure;
float					fbo_diffusion;

vector<string>          errorVector;
int                     returnS;

bool					useLiveCoding;
bool                    activateLiveEditor;
bool                    viewPreview;
bool					viewCode;
bool                    codeOnLive;
bool					liveCodingMode;
bool					printError;
bool					computeFBOTexture;
bool					saveMappingSettings;
bool					drawGrid;
bool					useSecondaryScreen;
bool					calibrationScreen;
int						calibScreenSel;
//////////////////////////////////////////////

//--------------------------------------------------------------
void gamuzaMain::setupFBO(){
	
	///////////////////////////
	// FBO setup
	drawingFbo.allocate(projectionScreenW,projectionScreenH);
	finalTexture.allocate(projectionScreenW,projectionScreenH);
    drawingTexture.allocate(projectionScreenW,projectionScreenH,GL_RGBA);
    outputPix.allocate(projectionScreenW,projectionScreenH,OF_IMAGE_COLOR_ALPHA);
	
	previewW = 512;
	previewH = (int)((projectionScreenH*512.0f)/projectionScreenW);
	previewY = (int)(85 + ((384-previewH)/2.0f));
	
	useSecondaryScreen = false;
	///////////////////////////
	
	///////////////////////////
	// Calibration images setup
	calibImage.loadImage("img/gamuza_calib.jpg");
	calibImage.resize(projectionScreenW,projectionScreenH);
	calibImageBW.loadImage("img/gamuza_calib_bw.jpg");
	calibImageBW.resize(projectionScreenW,projectionScreenH);
	capDevNO.loadImage("img/captureDev.jpg");
	capDevNO.resize(projectionScreenW,projectionScreenH);
	kuro.loadImage("img/kuro.jpg");
	///////////////////////////
	
	///////////////////////////
	// Grid Mapping setup
	saveMappingSettings = false;
	
	res = gridRes+1;
	realRes = res*res;
	finalTextureMapping.setup(mainScreenW+1,0,projectionScreenW,projectionScreenH,realRes);
	finalTextureMapping.loadSettings(GAMUZA_MAPPING_FILE);
	///////////////////////////
	
	///////////////////////////
	// SHADER setup
	
	// check graphic card shader support
	printf("\nOpenGL version: %s\n", glGetString (GL_VERSION));
	if(GL_ARB_shader_objects){
		useShader = 1;
		printf("GL_ARB_shader SUPPORTED by your Graphic Card: %s\n\n", glGetString (GL_RENDERER));
	}else{
		useShader = 0;
		printf("GL_ARB_shader NOT SUPPORTED by your Graphic Card: %s\n switching to SHADER OFF MODE\n\n", glGetString (GL_RENDERER));
	}
	
	if(useShader){
		shaderColorCorrection.load(GAMUZA_SHADER);
		
		shaderColorCorrection.begin();
			sprintf(shaderName,"tex_w");
			shaderColorCorrection.setUniform1f(shaderName,projectionScreenW);
			sprintf(shaderName,"tex_h");
			shaderColorCorrection.setUniform1f(shaderName,projectionScreenH);
		shaderColorCorrection.end();
	}
	///////////////////////////
	
	///////////////////////////
	// LIVE CODING CONSOLE	setup
	liveCoding.setup();
	
	// adding lua language to live coding
	ofAddListener(liveCoding.doCompileEvent, this, &gamuzaMain::renderScript);
	
	useLiveCoding	= false;	
	liveCodingMode	= false;
	printError		= false;
    returnS         = 0;
    
    for(int i=0;i<5;i++){
        errorVector.push_back(" ");
    }
	
	if(autoLoadScript){
		loadScript(autoScriptFile);
		liveCoding.glEditor[liveCoding.currentEditor]->ClearAllText();
		liveCoding.pasteFromLuaScript(readScript(autoScriptFile,false));
		viewCode            = false;
        codeOnLive          = false;
        viewPreview         = false;
        activateLiveEditor  = false;
	}else{
		loadScript("scripts/00_emptyExample.lua");
		liveCoding.glEditor[liveCoding.currentEditor]->ClearAllText();
		liveCoding.pasteFromLuaScript(readScript("scripts/00_emptyExample.lua",false));
		viewCode            = true;
        codeOnLive          = true;
        viewPreview         = true;
        activateLiveEditor  = true;
	}
	///////////////////////////
	
	///////////////////////////
	// simple video file output
	if(useVideoFile){
		outputVideo.loadMovie(fboVideoFile);
		outputVideo.play();
		videoFileW = (outputVideo.getWidth()*projectionScreenH)/outputVideo.getHeight();
		videoFileH = projectionScreenH;
	}
	///////////////////////////
	
}

//--------------------------------------------------------------
void gamuzaMain::drawFBO(){
	
	char temp[128];
	
	if(computeFBOTexture){
		
		if(useShader){
			
			drawingFbo.begin();
			glPushAttrib(GL_ALL_ATTRIB_BITS);
			glEnable(GL_BLEND);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
			drawIntoFBO(projectionScreenW, projectionScreenH);
			glDisable(GL_BLEND);
			glPopAttrib();
			drawingFbo.end();
			
			drawingTexture = drawingFbo.getTextureReference();
			
			finalTexture.begin();
			// clear the FBO texture
			ofClear(0.0, 0.0, 0.0, 1.0);
			// compute matrix homografy
			cvHomographyFBO();
		
			shaderColorCorrection.begin();
			
			sprintf(shaderName,"gamma");
			shaderColorCorrection.setUniform1f(shaderName,fbo_gammaCorrection); // 1.0 - 4.0
			sprintf(shaderName,"brightness");
			shaderColorCorrection.setUniform1f(shaderName,fbo_brightness); // 0.0 - 4.0
			sprintf(shaderName,"saturation");
			shaderColorCorrection.setUniform1f(shaderName,fbo_saturation); // 0.0 - 4.0
			sprintf(shaderName,"contrast");
			shaderColorCorrection.setUniform1f(shaderName,fbo_contrast); // 0.0 - 1.0
			sprintf(shaderName,"filmBleach");
			shaderColorCorrection.setUniform1f(shaderName,fbo_filmBleach); // 0.0 - 2.0
			sprintf(shaderName,"technicolor");
			shaderColorCorrection.setUniform1f(shaderName,fbo_techniColor); // 0.0 - 2.0
			sprintf(shaderName,"whiteDiffusion");
			shaderColorCorrection.setUniform1f(shaderName,fbo_whiteDiffusion); // 0.0 - 1.0
			sprintf(shaderName,"exposure");
			shaderColorCorrection.setUniform1f(shaderName,fbo_exposure); // 0.0 - 10.0
			sprintf(shaderName,"diffusion");
			shaderColorCorrection.setUniform1f(shaderName,fbo_diffusion); // 0.0 - 4.0
			
			shaderColorCorrection.setUniformTexture("texBase", drawingTexture, 0);
		
			// apply mapping mesh
			glGridMeshFBO(0,0,projectionScreenW,projectionScreenH);
		
			shaderColorCorrection.end();
		
			finalTexture.end();
		}else{
			finalTexture.begin();
			// compute matrix homografy
			cvHomographyFBO();
			// draw inside fbo without shader
			glPushAttrib(GL_ALL_ATTRIB_BITS);
			glEnable(GL_BLEND);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
			drawIntoFBO(projectionScreenW, projectionScreenH);
			glDisable(GL_BLEND);
			glPopAttrib();
			finalTexture.end();
			
			drawingTexture = finalTexture.getTextureReference();
		}
		
        //////////////////////////////////////
		// preview
		glPushMatrix();
		glTranslatef(guiPosX, guiPosY, 0.0f);
		
		if(!gui.minimize && !autoPilot){
            if(liveCodingMode){
                if(viewPreview){
                    drawingTexture.draw(lcPrevX-guiPosX,lcPrevY-guiPosY,lcPrevW,lcPrevH);
                }
                if(viewCode && useLiveCoding){
                    ofPushView();
                    ofPushMatrix();
                    ofPushStyle();
                        liveCoding.reShape(lcPrevW,lcPrevH,lcPrevX,lcPrevY);
                        glColor4f(1.0,1.0,1.0,1.0);
                        liveCoding.draw();
                    ofPopStyle();
                    ofPopMatrix();
                    ofPopView();
                }
            }else{
                if(gui.getSelectedPanel() == 0){
                    if(viewPreview){
                        drawingTexture.draw(246.0, previewY,previewW,previewH);
                    }
                    if(viewCode && useLiveCoding){
                        ofPushView();
                        ofPushMatrix();
                        ofPushStyle();
                            liveCoding.reShape(previewW-90,previewH,246 + guiPosX,314 + guiPosY);
                            glColor4f(1.0,1.0,1.0,1.0);
                            liveCoding.draw();
                        ofPopStyle();
                        ofPopMatrix();
                        ofPopView();
                    }
                }
            }
		}
		
		glPopMatrix();
        //////////////////////////////////////
        
        //////////////////////////////////////
        // output texture
		if(useSecondaryScreen){
			if(useShader){
				finalTexture.draw(mainScreenW+1,0);
			}else{
				drawingTexture.bind();
				// apply mapping mesh
				glGridMeshFBO(mainScreenW+1,0,projectionScreenW,projectionScreenH);
				drawingTexture.unbind();
			}
            if(useLiveCoding && viewCode && codeOnLive){
                ofPushView();
                ofPushMatrix();
                ofPushStyle();
                liveCoding.reShape(projectionScreenW,projectionScreenH,mainScreenW+1,projectionScreenH/5.0);
                glColor4f(1.0,1.0,1.0,1.0);
                liveCoding.draw();
                ofPopStyle();
                ofPopMatrix();
                ofPopView();
            }
		}else{
            glColor4f(0.0,0.0,0.0,1.0);
            ofFill();
            ofRect(mainScreenW+1,0,projectionScreenW,projectionScreenH);
            glColor4f(1.0,1.0,1.0,1.0);
        }
        //////////////////////////////////////
        
		/////////////////////////////////////
		// texture mapping control points
		if(drawGrid && useSecondaryScreen){
			finalTextureMapping.drawMinimalGrid();
		}
		if(saveMappingSettings){
			finalTextureMapping.saveSettings(GAMUZA_MAPPING_FILE);
			saveMappingSettings = false;
		}
		/////////////////////////////////////
        
        /////////////////////////////////////
        // Output Texture exporting to video file
        if(isExporting){
            if(useSecondaryScreen && useShader){
                finalTexture.readToPixels(outputPix);
            }else{
                drawingTexture.readToPixels(outputPix);
            }
            movieExport.addFrame(outputPix);
            if(gamuzaMem > (ramMemory.getTotalMemory() - 500)){
                stopExportVideo();
            }
        }
        /////////////////////////////////////
		
		// simple video player
		if(useVideoFile){
			outputVideo.idleMovie();
		}
		
		// live coding
		if(useLiveCoding){
			lua.scriptUpdate();
		}
		
	}
	
}

//--------------------------------------------------------------
void gamuzaMain::drawIntoFBO(int w, int h){
	
	ofEnableAlphaBlending();
	if(liveCoding.glEditor[liveCoding.currentEditor]->m_haveError){
		// clear the FBO texture
		ofClear(0.0, 0.0, 0.0, 1.0);
	}
	
	if(calibrationScreen){
		//////////////////////////////////
		// calibration screen
		ofClear(0.0, 0.0, 0.0, 1.0);
		switch(calibScreenSel){
			case 0:
				glColor4f(1.0, 1.0, 1.0, 0.8);
				ofNoFill();
				ofRect(1,1,w-2,h-2);
				break;
			case 1:
				glColor4f(1.0, 1.0, 1.0, 0.8);
				ofNoFill();
				ofBeginShape();
					ofVertex(0,0);
					ofVertex(w,h);
					ofVertex(w,0);
					ofVertex(0,h);
					ofVertex(w,h);
				ofEndShape(true);
				ofRect(1,1,w-2,h-2);
				break;
			case 2:
				//////////////////////////////////
				// fading background (changing alpha, ej. 0.05 = 5%)
				ofFill();
				glColor4f(1.0, 1.0, 1.0, 1.0); // white
				ofRect(0,0,w,h);
				//////////////////////////////////
				break;
			case 3:
				glColor4f(1.0, 1.0, 1.0, 1.0);
				ofFill();
				calibImage.draw(0,0);
				break;
			case 4:
				glColor4f(1.0, 1.0, 1.0, 1.0);
				ofFill();
				calibImageBW.draw(0,0);
				break;
			case 5:
				glColor4f(1.0, 1.0, 1.0, 1.0);
				ofFill();
				if(trackingActivated){
					if(inputCam[0].captureVideo && numCamInputs > 0){
						inputCam[0].colorImg.draw(0,0,w,h);
					}else{
						capDevNO.draw(0,0);
					}
				}else{
					capDevNO.draw(0,0);
				}
				break;

			default:
				break;
		}
		//////////////////////////////////
	}else{
		//////////////////////////////////
		///////////////////////////
		// LIVE CODING CONSOLE render
		if(useLiveCoding && !useVideoFile){
            ofPushView();
            ofPushMatrix();
            ofPushStyle();
            glEnable(GL_MULTISAMPLE_ARB);
                lua.scriptDraw();
            glDisable(GL_MULTISAMPLE_ARB);
            ofPopStyle();
            ofPopMatrix();
            ofPopView();
			if(printError){
				// print scripting errors into logger
				if(lua.lastError != "Script has no errors"){
                    ofStringReplace(lua.lastError,"[string \"...\"]","line");
                    ofStringReplace(lua.lastError,"custom ","");
                    ofStringReplace(lua.lastError,"\n",": ");
                    returnS = gaStringReplace(lua.lastError,": ",": ");
                    errorVector = ofSplitString(lua.lastError, ": ");
                    logger.log(99," ");
                    logger.log(99,"________________________________________");
                    while(returnS>=0){
                        logger.log(99," %s",errorVector[returnS--].c_str());
                    }
					// send error line to glEditor
					liveCoding.glEditor[liveCoding.currentEditor]->m_haveError = true;
					liveCoding.glEditor[liveCoding.currentEditor]->SetCurrentLine(lua.errorLine-2);
					liveCoding.glEditor[liveCoding.currentEditor]->m_errorLine = lua.errorLine-2;
				}else{
                    logger.log(99," ");
                    logger.log(99,"________________________________________");
                    logger.log(99," %s",lua.lastError.c_str());
                }
				printError = false;
			}
			
		// OR simple VIDEO PLAYER
		}else if(useVideoFile){
			outputVideo.draw((w-videoFileW)/2.0f,0.0f,videoFileW,videoFileH);
		}
		///////////////////////////
		//////////////////////////////////
	}
	
	ofDisableAlphaBlending();
	
}

//--------------------------------------------------------------
void gamuzaMain::cvHomographyFBO(){
	
	//lets make a matrix for openGL
	//this will be the matrix that peforms the transformation
	GLfloat myMatrix[16];
	
	//we set it to the default - 0 translation
	//and 1.0 scale for x y z and w
	for(int i = 0; i < 16; i++){
		if(i % 5 != 0) myMatrix[i] = 0.0;
		else myMatrix[i] = 1.0;
	}
	
	//we need our points as opencv points
	CvPoint2D32f cvsrc[realRes];
	CvPoint2D32f cvdst[realRes];
	
	//we set the warp coordinates
	//source coordinates as the dimensions of our FBO texture
	for(int i=0;i<realRes;i++){
		float x = (i % res) / (float)(res-1);
		float y = (i / res) / (float)(res-1);
		cvsrc[i].x = x*projectionScreenW;
		cvsrc[i].y = y*projectionScreenH;
	}
	
	for(int i=0; i<realRes;i++){
		cvdst[i].x = finalTextureMapping.points[i].x;
		cvdst[i].y = finalTextureMapping.points[i].y;
	}
	
	//we create a matrix that will store the results
	//from openCV - this is a 3x3 2D matrix that is
	//row ordered
	CvMat * translate = cvCreateMat(3,3,CV_32FC1);
	
	//for the more accurate method we need to create
	//a couple of matrixes that just act as containers
	//to store our points  - the nice thing with this 
	//method is you can give it more than four points!
	
	CvMat* src_mat = cvCreateMat( realRes, 2, CV_32FC1 );
	CvMat* dst_mat = cvCreateMat( realRes, 2, CV_32FC1 );
	
	//copy our points into the matrixes
	cvSetData( src_mat, cvsrc, sizeof(CvPoint2D32f));
	cvSetData( dst_mat, cvdst, sizeof(CvPoint2D32f));
	
	//figure out the warping!
	cvFindHomography(src_mat, dst_mat, translate);
	
	//get the matrix as a list of floats
	float *matrix = translate->data.fl;
	
	//we need to copy these values
	//from the 3x3 2D openCV matrix which is row ordered
	//
	// ie:   [0][1][2] x
	//       [3][4][5] y
	//       [6][7][8] w
	
	//to openGL's 4x4 3D column ordered matrix
	//        x   y   z   w   
	// ie:   [0] [4] [8][12]
	//       [1] [5] [9][13]
	//       [2] [6][10][14]
	//		 [3] [7][11][15]
	//       
	
	myMatrix[0]		= matrix[0];
	myMatrix[4]		= matrix[1];
	myMatrix[12]	= matrix[2];
	
	myMatrix[1]		= matrix[3];
	myMatrix[5]		= matrix[4];
	myMatrix[13]	= matrix[5];	
	
	myMatrix[3]		= matrix[6];
	myMatrix[7]		= matrix[7];
	myMatrix[15]	= matrix[8];
	
	//finally lets multiply our matrix
	glMultMatrixf(myMatrix);

}

//--------------------------------------------------------------
void gamuzaMain::glGridMeshFBO(int xCalib, int yCalib, int w, int h){
	
	float xStep = w/gridRes;
	float yStep = h/gridRes;
	
	glBegin(GL_QUADS);
	for(int x=0; x < gridRes; x++) {
		for(int y=0; y < gridRes; y++) {
			int revY =  y;
			ofPoint mp;
			
			mp = finalTextureMapping.points[(x)+(y+1)*res];
			glTexCoord2f(x*xStep, (revY+1)*yStep);
			glVertex3f(xCalib+mp.x,yCalib+mp.y,0);
			
			mp = finalTextureMapping.points[(x+1)+(y+1)*res];
			glTexCoord2f((x+1)*xStep, (revY+1)*yStep);
			glVertex3f(xCalib+mp.x,yCalib+mp.y,0);
			
			mp = finalTextureMapping.points[(x+1)+(y)*res];
			glTexCoord2f((x+1)*xStep, (revY)*yStep);
			glVertex3f(xCalib+mp.x,yCalib+mp.y,0);
			
			mp = finalTextureMapping.points[(x)+(y)*res];
			glTexCoord2f(x*xStep, (revY)*yStep);
			glVertex3f(xCalib+mp.x,yCalib+mp.y,0);
			
		}
	}
	glEnd();
	
}

//--------------------------------------------------------------
//-- LIVE CODING exec script from ofxGlEditor to ofxLua --------
//--------------------------------------------------------------
void gamuzaMain::loadScript(string _script){
	
	// reset the audio output stream
	resetAudioOutput();
    
    // reset live coding timeline
    actualTriggerName = "";
    initTimeline();
	
	// init the lua state
	lua.scriptExit();
	lua.init(true,true);
	// bind OF007, GAmuza & openGL2.1 api to lua
	lua.bind<ofGamuzaWrapper>();
	// exec the script from editor
	lua.doScript(_script);
	lua.scriptSetup();
    
    // timeline triggers
    timeline.addTriggers("triggers", "settings/timeline/triggers.xml");
	
	printError = true;
	
}

//--------------------------------------------------------------
void gamuzaMain::renderScript(string & _script){
	
	// reset the audio output stream
	resetAudioOutput();
    
    // reset live coding timeline
    actualTriggerName = "";
    initTimeline();
	
	// init the lua state
	lua.scriptExit();
	lua.init(true,true);
	// bind OF007, GAmuza & openGL2.1 api to lua
	lua.bind<ofGamuzaWrapper>();
	// exec the script from editor
	lua.doString(_script);
	lua.scriptSetup();
    
    // timeline triggers
    timeline.addTriggers("triggers", "settings/timeline/triggers.xml");
	
	printError = true;
    
}

//--------------------------------------------------------------
string gamuzaMain::readScript(string _scriptFile,bool dialog){
	
	string		content;
	ifstream	scriptFile;
	char		_c;
	
	if(dialog){
		scriptFile.open(_scriptFile.c_str(), ifstream::in);
	}else{
		scriptFile.open(ofToDataPath(_scriptFile).c_str(), ifstream::in);
	}
	
	if(scriptFile.is_open()){
		while(scriptFile.good()){
			_c = (char)scriptFile.get();
			if(scriptFile.good()){
				content += _c;
			}
		}
		scriptFile.close(); 
	}
	
	return content;
	
}

//--------------------------------------------------------------
//--------------------------------------------------------------


#endif
