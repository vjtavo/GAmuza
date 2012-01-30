#include <vector>

#define NUMBER_OF_INSTRUCTIONS 16
#define BITS_PER_INSTRUCTION 16 /// 4 operator index bits, three 8 bit memory addresses
#define MEMORY_SIZE 16

struct s_Machine {

    string code;    // all the bits
    ofFbo codeTex;
    ofPixels codePixels;

    bool memory[MEMORY_SIZE];

    float fitness;

    s_Machine(){

        codeTex.allocate(512,512,GL_LUMINANCE);

        code="";
        for(int i = 0; i < NUMBER_OF_INSTRUCTIONS*BITS_PER_INSTRUCTION; i++)
        {
            if(ofRandom(0,1)>0.5) { code+="1"; } else { code+="0"; }
        }

        fitness = 0;

    }

    void DrawBrain(){

        codeTex.begin();
            ofClear(0,0,0,1);
            int codeIndex=0;
            ofSetColor(255);
            float scale = 32;
            for(int i = 0; i < 16; i++)
            {
                for(int j = 0; j < 16; j++)
                {
                    if(code[codeIndex]=='1') { ofRect(i*32,j*32,32,32); }
                    codeIndex++;
                }
            }
        codeTex.end();
    }

    void ClearMemory(){

        // clear the memory
        for(int i = 0; i < MEMORY_SIZE; i++)
        {
            memory[i] = false;
        }

    }

    void MutateCode(float mutationRate){

        for(int i = 0; i < code.size(); i++)
        {
            if(ofRandom(0,1) < mutationRate)
            {
                if(code[i] == '1') { code[i] = '0'; }  else { code[i] = '1'; }
            }
        }

    }

    float EvaluateCode(float functionIndex){

        ClearMemory();

        // load terminalValue into memory
        if(functionIndex >= 128.0) { memory[0] = true; functionIndex-=128.0; } else { memory[0] = false; }
        if(functionIndex >=  64.0) { memory[1] = true; functionIndex-=64.0; } else { memory[1] = false; }
        if(functionIndex >=  32.0) { memory[2] = true; functionIndex-=32.0; } else { memory[2] = false; }
        if(functionIndex >=  16.0) { memory[3] = true; functionIndex-=16.0; } else { memory[3] = false; }
        if(functionIndex >=   8.0) { memory[4] = true; functionIndex-=8.0; } else { memory[4] = false; }
        if(functionIndex >=   4.0) { memory[5] = true; functionIndex-=4.0; } else { memory[5] = false; }
        if(functionIndex >=   2.0) { memory[6] = true; functionIndex-=2.0; } else { memory[6] = false; }
        if(functionIndex >=   1.0) { memory[7] = true; } else { memory[7] = false; }

        //cout << memory[0] << memory[1] << memory[2] << memory[3] << memory[4] << memory[5] << memory[6] << memory[7] << endl;

        for(int codeIndex = 0; codeIndex < code.size(); codeIndex+=BITS_PER_INSTRUCTION )
        {
            // find operator and memory addresses by reading the code
            int operatorIndex = 0; int A = 0; int B = 0; int C = 0;

            // find operator
            if(code[codeIndex+ 0] != '0'){ operatorIndex+=8; }
            if(code[codeIndex+ 1] != '0'){ operatorIndex+=4; }
            if(code[codeIndex+ 2] != '0'){ operatorIndex+=2; }
            if(code[codeIndex+ 3] != '0'){ operatorIndex+=1; }

            // find memory address
            if(code[codeIndex+ 4] != '0'){ A+=8; }
            if(code[codeIndex+ 5] != '0'){ A+=4; }
            if(code[codeIndex+ 6] != '0'){ A+=2; }
            if(code[codeIndex+ 7] != '0'){ A+=1; }

            if(code[codeIndex+ 8] != '0'){ B+=8; }
            if(code[codeIndex+ 9] != '0'){ B+=4; }
            if(code[codeIndex+10] != '0'){ B+=2; }
            if(code[codeIndex+11] != '0'){ B+=1; }

            if(code[codeIndex+12] != '0'){ C+=8; }
            if(code[codeIndex+13] != '0'){ C+=4; }
            if(code[codeIndex+14] != '0'){ C+=2; }
            if(code[codeIndex+15] != '0'){ C+=1; }

            switch(operatorIndex){
                /*
                    http://en.wikipedia.org/wiki/Logic_gates
                */

                case 0: /// FALSE, always false
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }
                break;

                case 1: /// A AND B, only true if both are true
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }
                break;

                case 2: /// A does not imply B, True if A but not B
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 3: /// A, true whenever A is true
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 4: /// A is not implied by B, true if not A and B
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 5: /// B, true whenever B is true
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 6: ///
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 7:
                    if(memory[A] == false && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 8:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 9:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 10:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 11:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 12:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;

                case 13:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = false; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

                case 14:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = false; }

                break;
                case 15:
                    if(memory[A] == false && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == false && memory[B] == true)  { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == false) { memory[C] = true; }
                    else if(memory[A] == true  && memory[B] == true)  { memory[C] = true; }

                break;

            }

        }

        /// All the operations are done, read the memory into a float.
        float returnVal = 0.0;

        if(memory[ 8]) { returnVal +=128.0; }
        if(memory[ 9]) { returnVal +=64.0; }
        if(memory[10]) { returnVal +=32.0; }
        if(memory[11]) { returnVal +=16.0; }
        if(memory[12]) { returnVal +=8.0; }
        if(memory[13]) { returnVal +=4.0; }
        if(memory[14]) { returnVal +=2.0; }
        if(memory[15]) { returnVal +=1.0; }

        returnVal *= 0.01; // normalize
        returnVal -= 1.275;

        return returnVal;

    }

};
