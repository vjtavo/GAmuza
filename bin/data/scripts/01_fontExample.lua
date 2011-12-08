



-- font example

verdana = of.font()

function setup()
    -- font name, size, anti-aliased, full character set
    verdana:loadFont("fonts/verdana.ttf",18, true, false)
    verdana:setLineHeight(18)
end

function update()

end

function draw()
    ga.background(0.0,0.3)
    
    of.pushMatrix()
    of.translate(20,OUTPUT_H/2,0)
    of.enableAlphaBlending()
    gl.color4f(1.0,1.0,1.0,1.0)
    verdana:drawString("If the television screen os goig to watch you, rewire it.", 0, 0)
    verdana:drawString("Philip K. Dick", 200, 20)
    of.disableAlphaBlending()
    of.popMatrix()
end
