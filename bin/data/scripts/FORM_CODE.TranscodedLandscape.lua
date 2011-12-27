












-- FORM+CODE - Transcoded Landscape
-- from http://formandcode.com

img = of.image()
tex = of.texture()
c = of.color()
pixels = of.pixels()
angle = 0

function setup()
    img:loadImage("images/moon.jpg")
    img:reloadTexture()
    pixels:allocate(img:getWidth(),img:getHeight(),3)
    tex:allocate(img:getWidth(),img:getHeight(),GL_RGB)

    tex:readToPixels(pixels)
end

function update()
    angle = angle + 0.005

    
end

function draw()
    ga.background(0.0,0.3)
    

    of.pushMatrix()
        of.translate(OUTPUT_W/2,OUTPUT_H/2,0.0)
        of.scale(10.0,10.0,1.0)
        of.rotateY(angle)
        
        ww = img:getWidth()
        hh = img:getHeight()
        
        of.setPolyMode(OF_POLY_WINDING_ODD);
        gl.beginShape(GL_LINES)
        for i=0, hh do
            for j=0, ww do
                c = pixels:getColor(j,i)
                of.setColor(245,151,176,c:getBrightness()) 
            
                x1 = j - ww/2
                y1 = i - hh/2
                z1 = -c:getBrightness()/2
                x2 = j - ww/2
                y2 = i - hh/2
                z2 = -c:getBrightness()/2 - 7

                gl.vertex3f(x1,y1,z1)
                gl.vertex3f(x2,y2,z2)
                
            end
        end
        gl.endShape()

    of.popMatrix()

end





































































