
#ifndef _OFXLOGICMACHINE
#define _OFXLOGICMACHINE

#include "ofMain.h"
#include "machine.h"

#define NUMBER_OF_MACHINES 16
#define FITNESS_CASES 32

//---------------------------------------------------------------
class ofxLogicMachine{

	public:
	
		ofxLogicMachine();
        ~ofxLogicMachine();
        void CreateTargetValues();
        void setupSimulation();
        void PerformSimulation();
        void EvaluateSimulation();
        void DrawSimulation(int x, int y, int w, int h);
        void EvolvePopulation();
    
        s_Machine machines[NUMBER_OF_MACHINES];
    
        float mouseX, mouseY;
    
        string bestCode;
        float bestFitness;
    
        float targetValues[FITNESS_CASES];
        float machineIdeas[NUMBER_OF_MACHINES][FITNESS_CASES];
	
		
};
//---------------------------------------------------------------

#endif
