








-- FORM+CODE - Superformula
-- from http://formandcode.com

scaler = 300
m = 1
n1 = 18
n2 = 1
n3 = 2
pointNum = 180
holePoints = {}

function setup()
   of.enableSmoothing() 
end

function update()
    
end

function draw()
    ga.background(0.0,1.0)
    
    of.noFill()
    of.setLineWidth(1)
    of.setColor(245,151,176)
    of.pushMatrix()
    of.translate(OUTPUT_W/3,OUTPUT_H/2,0)
    of.rotateZ(of.getElapsedTimef())
    newscaler = scaler
    for s=0, 16 do
        of.beginShape()
        
        mm = m + s
        nn1 = n1 + s
        nn2 = n2 + s
        nn3 = n3 + s
        newscaler = newscaler * 0.98
        sscaler = newscaler
        
        holePoints = superFormula(mm, nn1, nn2, nn3)   
        of.curveVertex(holePoints[pointNum-1].x*sscaler,holePoints[pointNum-1].y*sscaler)
        for j=0, pointNum do
            of.curveVertex(holePoints[j].x*sscaler,holePoints[j].y*sscaler)
        end
        of.curveVertex(holePoints[0].x*sscaler,holePoints[0].y*sscaler)
        of.endShape(false)
    end
    of.popMatrix()
end


function sfPoint(m, n1, n2, n3, phi)
    
    point = {}
    point.x = 0
    point.y = 0

    a = 1
    b = 1
    
    t1 = math.cos(m * phi / 4) / a
    t1 = math.abs(t1)
    t1 = math.pow(t1,n2)

    t2 = math.sin(m * phi / 4) / b
    t2 = math.abs(t2)
    t2 = math.pow(t2,n3)

    r = math.pow(t1+t2,1/n1)

    if math.abs(r) == 0 then
        point.x = 0
        point.y = 0
    else
        r = 1 / r
        point.x = r * math.cos(phi)
        point.y = r * math.sin(phi)
    end

    return point
end

function superFormula(m, n1, n2, n3)

    points = {}
    numPoints = pointNum
    phi = (math.pi*2) / numPoints

    for i=0, numPoints do
        points[i] = sfPoint(m, n1, n2, n3, phi*i)
    end

    return points

end

























