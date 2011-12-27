





-- 3D webcam

cam = of.texture()
pixels = of.pixels()

function setup()
    cam:allocate(CAPTURE_W,CAPTURE_H,GL_RGB)
end

function update()
    cam = ga.cameraTexture(0)
    cam:readToPixels(pixels)
end

function draw()
    ga.background(0.0,0.2)
    
    of.pushMatrix()
        of.translate(OUTPUT_W/2,OUTPUT_H/2,0.0)
        of.rotateY(of.degToRad(500-(OUTPUT_W/2)))
        of.rotateX(of.degToRad(-(200-(OUTPUT_H/2))))
        of.translate(-OUTPUT_W/2,-OUTPUT_H/2,0.0)

        of.scale(OUTPUT_W/CAPTURE_W,OUTPUT_H/CAPTURE_H,1.0)
        index = 0
        c = of.color()
        of.enableAlphaBlending()
        for y=0, cam:getHeight(), 5 do
            gl.beginShape(GL_LINES)
            for x=0, cam:getWidth(), 1 do
                c = pixels:getColor(x,y)
                of.setColor(15,c:getBrightness()/1.2,15,210)
                gl.vertex3f(x,y,c:getBrightness()/2.2 - 100)
                index = index + 1
            end
            gl.endShape()
        end
        of.disableAlphaBlending()
    of.popMatrix()
end














