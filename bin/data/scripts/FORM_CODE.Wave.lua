









-- FORM+CODE - Wave
-- from http://formandcode.com

brickW = 40
brickH = 15
cols = 20
rows = 24
cOffset = 60
rOffset = 30
phaseInc = 0.15
r = 0.0

function setup()
    r = of.random(-math.pi/4, math.pi/4)
end

function update()
    
end

function draw()
    ga.background(0.0,0.05)
    of.noFill()
    of.setColor(245,151,176)
    of.translate(30,30,0)
    for i=0, cols do
        of.pushMatrix()
        of.translate(i*cOffset,0,0)
        
        dir = 1
        for j=0, rows do
            of.pushMatrix()
            of.translate(0,rOffset*j,0)
            of.rotateZ(of.radToDeg(r))
            of.rect(-brickW/2,-brickH/2,brickW,brickH)
            of.popMatrix()
            r = r + ((dir+0.0001)*phaseInc)
            if r >= math.pi/4 or r <= -math.pi/4 then
                dir = dir * -1
            end
        end
        of.popMatrix()
    end
end








































