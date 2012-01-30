#include "ofxLogicMachine.h"


//---------------------------------------------------------------
ofxLogicMachine::ofxLogicMachine(){
	

}

//---------------------------------------------------------------
ofxLogicMachine::~ofxLogicMachine(){
	
    
}

//---------------------------------------------------------------
void ofxLogicMachine::CreateTargetValues(){
    
    for(int i = 0; i < FITNESS_CASES; i++)
    {
        float sinOfWhat = i * 0.5 * (mouseX/ofGetWidth());  /// This is the function the simulation is trying to approximate.
        targetValues[i] = sinf(sinOfWhat) ;
    }
}

//---------------------------------------------------------------
void ofxLogicMachine::setupSimulation(){
    
    // fill the target value table
    CreateTargetValues();
    
    // initialize the new machines
    for(int i = 0; i < NUMBER_OF_MACHINES; i++)
    {
        machines[i] = s_Machine();
    }
    
}

//---------------------------------------------------------------
void ofxLogicMachine::PerformSimulation(){
    
    /// Evaluate the machine for each fitness case and store the values in a table.
    for(int i = 0; i < NUMBER_OF_MACHINES; i++)
    {
        for(int j = 0; j < FITNESS_CASES; j++)
        {
            machineIdeas[i][j] = machines[i].EvaluateCode(float(j));
        }
    }
    
}

//---------------------------------------------------------------
void ofxLogicMachine::EvaluateSimulation(){
    
    for(int i = 0; i < NUMBER_OF_MACHINES; i++)
    {
        machines[i].fitness = 0.0;
        for(int j = 0; j < FITNESS_CASES; j++)
        {
            float diff = fabsf(targetValues[j]-machineIdeas[i][j]);
            machines[i].fitness += diff;
        }
    }
    
    bestFitness = machines[0].fitness;
    bestCode = machines[0].code;
    
    for(int i = 0; i < NUMBER_OF_MACHINES; i++)
    {
        if(machines[i].fitness <= bestFitness) { bestCode = machines[i].code;  bestFitness = machines[i].fitness; }
    }
    
}


//---------------------------------------------------------------
void ofxLogicMachine::DrawSimulation(int x, int y, int w, int h){
    
    /// draw a border, and the brain of the best
    ofSetColor(32,255,255,255);
    ofNoFill();
    ofRect(383,103,513,513);
    ofFill();
    ofSetColor(255,255,255,255);
    machines[0].codeTex.draw(x+384,y+104,512,512);
    
    
    float xScale = w/(FITNESS_CASES+0.0f);
    float yScale = 250.0;
    ofPushMatrix();
    ofTranslate(x,y + h/2.0);
    
    ofPushMatrix(); /// the masses in red
    ofScale(xScale,yScale);
    ofSetLineWidth(1.0);
    ofSetColor(255,0,0,64);
    for(int i = 0; i < NUMBER_OF_MACHINES; i++)
    {
        for(int j = 0; j < FITNESS_CASES-1; j++)
        {
            ofLine(j,machineIdeas[i][j], j+1,machineIdeas[i][j+1]);
        }
    }
    ofPopMatrix();
    
    ofPushMatrix(); /// target values, the function we are trying to approximate
    ofSetLineWidth(10.0);
    for(int i = 0; i < FITNESS_CASES-1; i++)
    {
        ofSetColor(0,0,255,255);
        ofLine(i*xScale,targetValues[i]*yScale, (i+1)*xScale,targetValues[i+1]*yScale);
    }
    ofPopMatrix();
    
    ofPushMatrix(); /// best code, the elite member of the population
    ofSetLineWidth(5.0);
    ofScale(xScale,yScale);
    ofSetColor(0,255,0,255);
    for(int j = 0; j < FITNESS_CASES-1; j++)
    {
        ofLine(j,machineIdeas[0][j], j+1,machineIdeas[0][j+1]);
    }
    ofPopMatrix();
    ofPopMatrix();
}


//---------------------------------------------------------------
void ofxLogicMachine::EvolvePopulation(){
    
    machines[0].code = bestCode; machines[0].DrawBrain();   /// machine[0] is elite, always is the best code
    
    for(int i = 1; i < NUMBER_OF_MACHINES; i++)
    {
        machines[i].code = bestCode;
        machines[i].MutateCode(0.01);

    }
    
}