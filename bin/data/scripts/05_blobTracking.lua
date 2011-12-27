




-- blob Tracking Example

camID = 0
runningBlobs = 0

function setup()
    
end

function update()
    runningBlobs = ga.camBlobs(0)
end

function draw()
    
    ga.background(0.0,0.8)
    of.enableAlphaBlending()
    
    gl.pushMatrix()
    of.scale(OUTPUT_W,OUTPUT_H,1.0)
    
    for j=0, runningBlobs do
    
    of.setLineWidth(3)
    of.noFill()
    gl.color4f(1.0,0.0,0.0,1.0)
    of.rect(ga.camBlobX(camID,j),ga.camBlobY(camID,j),ga.camBlobW(camID,j),ga.camBlobH(camID,j))

    end

    gl.popMatrix()

    of.disableAlphaBlending()

end






 
