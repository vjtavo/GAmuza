












-- audioSample Example

function setup()
    ga.sample("loops/hypno00.wav")
    ga.sampleVolume(0,1.0)
    ga.sampleLooping(0,true)
    ga.samplePlay(0)    
end

function update()
   ga.sampleSpeed(0,1.0) 
end

function draw()
    ga.background(0.0,1.0)

    ga.drawSample(0,0,OUTPUT_H/2 - 100,OUTPUT_W,100)
end

function mousePressed()
    ga.samplePaused(0,true)
end

function mouseReleased()
    ga.samplePaused(0,false)
end




































































