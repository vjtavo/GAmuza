





-- pixels Example

cam = of.texture()
camCrop = of.texture()
camMirror = of.texture()
pixels = of.pixels()

function setup()
    cam:allocate(CAPTURE_W,CAPTURE_H,GL_RGB)
    camCrop:allocate(CAPTURE_W,CAPTURE_H,GL_RGB)
    camMirror:allocate(CAPTURE_W,CAPTURE_H,GL_RGB)
end

function update()
    cam = ga.cameraTexture(0)

    cam:readToPixels(pixels)

    pixels:crop(0,0,200,200)
    camCrop:loadData(pixels)

    pixels:mirror(true,false)
    camMirror:loadData(pixels)
end

function draw()
    ga.background(0.0,0.2)
    of.setColor(255)
    cam:draw(0,OUTPUT_H/2 - CAPTURE_H/2)
    camCrop:draw(CAPTURE_W + 20,OUTPUT_H/2 - CAPTURE_H/2)
    camMirror:draw(CAPTURE_W*2 + 40,OUTPUT_H/2 - CAPTURE_H/2)
end














