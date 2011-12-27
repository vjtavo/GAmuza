










-- polyline Example

lazo = of.polyline()
test = of.rectangle()

function setup()
    for i=0,100 do
        lazo:curveTo(math.sin(of.degToRad(i))*OUTPUT_W,math.cos(i)*OUTPUT_H/4,1.0,50)
    end

    test = lazo:getBoundingBox()
end

function update()
    
end

function draw()
    ga.background(0.0,1.0)
    
    of.setPolyMode(OF_POLY_WINDING_ODD)
    of.setColor(255)
    of.pushMatrix()
    of.translate(0,OUTPUT_H/2,0)
    of.setLineWidth(3)
    lazo:draw()

    of.setColor(255,0,0)
    of.noFill()
    
    of.rect(test.x,test.y,test.width,test.height)

    of.popMatrix()
end




























