









-- FORM+CODE - Slit-Scan
-- from http://formandcode.com

videoSliceX = CAPTURE_W/2
drawPositionX = 0
camPixels = of.pixels()
texPixels = of.pixels()
cam = of.texture()
tex = of.texture()
c = of.color()

function setup()
    tex:allocate(OUTPUT_W,OUTPUT_H,GL_RGB)
    texPixels:allocate(OUTPUT_W,OUTPUT_H,3)
end

function update()
    cam = ga.cameraTexture(0)
    cam:readToPixels(camPixels)
    
    temp = of.color()
    for y=0, CAPTURE_H do
        c = camPixels:getColor(videoSliceX,y)
        temp:set(c:getBrightness(),255)
        texPixels:setColor(drawPositionX,y,temp)
    end
    
    tex:loadData(texPixels)
    
    if drawPositionX > OUTPUT_W then
        drawPositionX = 0
    else
        drawPositionX = drawPositionX + 1
    end
end

function draw()
    ga.background(0.0,1.0)
    
    of.setColor(245,151,176)
    tex:draw(0,OUTPUT_H/2 - CAPTURE_H/2)
    
end
























