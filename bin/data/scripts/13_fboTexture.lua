






-- empty Example

test = of.fbo()

function setup()
    of.setCircleResolution(50)
    test:allocate(OUTPUT_W,OUTPUT_H,GL_RGB,0)    
end

function update()
    
end

function draw()
    ga.background(0.0,1.0)
    
    
    test:beginFbo()
        of.clear(0.0, 0.0, 0.0, 1.0)
        of.setColor(255,0,0)
        of.fill()
        of.circle(300,300,200)
        of.noFill()
        of.setColor(255)
        of.setLineWidth(3)
        of.rect(0,0,test:getWidth(),test:getHeight())
    test:endFbo()

    of.setColor(255)
    test:draw(0,0)
end





















