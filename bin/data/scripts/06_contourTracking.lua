





-- contour Tracking Example

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
    
    of.fill()
    of.setPolyMode(OF_POLY_WINDING_ODD)
    
    gl.pushMatrix()
    of.scale(OUTPUT_W/CAPTURE_W,OUTPUT_H/CAPTURE_H,1.0)
    
    for j=0, runningBlobs do
    
    of.setLineWidth(1)

    of.beginShape()
    for i=0, ga.camBlobContourSize(camID,j)-1 do
        gl.color4f(1.0,1.0,1.0,1.0)
        of.fill()
        of.vertex(ga.camBlobCPointX(camID,j,i),ga.camBlobCPointY(camID,j,i))
    end
    of.endShape(false)
    
    of.setLineWidth(3)

    for z=0, ga.camBlobGeometrySize(camID,j)-1 do
        gl.color4f(0.0,1.0,0.0,1.0)
        of.noFill()
        of.line(ga.camBlobGLineX1(camID,j,z),ga.camBlobGLineY1(camID,j,z),ga.camBlobGLineX2(camID,j,z),ga.camBlobGLineY2(camID,j,z))
        of.circle(ga.camBlobGLineX1(camID,j,z),ga.camBlobGLineY1(camID,j,z),4)
        of.circle(ga.camBlobGLineX2(camID,j,z),ga.camBlobGLineY2(camID,j,z),4)
    end

    end

    gl.popMatrix()

    of.disableAlphaBlending()

end






 








