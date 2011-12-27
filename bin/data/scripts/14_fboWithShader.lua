








-- FBO with Shader

test = of.fbo()
sh = of.shader()

function setup()
    of.setCircleResolution(50)
    test:allocate(OUTPUT_W,OUTPUT_H,GL_RGB,0)    
    sh:load("shaders/noise")
end

function update()
    
end

function draw()
    ga.background(0.0,1.0)
    
    of.pushMatrix()
    test:beginFbo()
    sh:beginShader()
        of.clear(0.0, 0.0, 0.0, 1.0)
        of.setColor(255,0,0)
        of.fill()
        of.circle(of.randomuf()*1000,of.randomuf()*300,200)
        of.noFill()
        of.setColor(55)
        of.setLineWidth(3)
        of.rect(0,0,test:getWidth(),test:getHeight())
    sh:endShader()
    test:endFbo()

    of.setColor(255)
    test:draw(0,0,OUTPUT_W,OUTPUT_H)
    of.popMatrix()
    
    of.setColor(255)
    of.noFill()
    of.rect(0,0,OUTPUT_W,OUTPUT_H)
end





































