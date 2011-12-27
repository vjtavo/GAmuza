





-- FORM+CODE - Embedded Iteration
-- from http://formandcode.com

option = 1

function setup()
    of.enableSmoothing()
end

function draw()
    ga.background(0.0,1.0)

    of.setColor(245,151,176)
    
    if option==1 then
        -- stitches
        for x=50, OUTPUT_W-50, 20 do
            for y=50, OUTPUT_H-50, 20 do
                of.line(x-5,y-5,x+5,y+5)
                of.line(x+5,y-5,x-5,y+5)
            end
        end
    elseif option==2 then
        -- perspective
        for x=50, OUTPUT_W-50, 20 do
            for y=50, OUTPUT_H-50, 20 do
                of.line(x,y,OUTPUT_W/2,OUTPUT_H/2)
            end
        end
    elseif option==3 then
        -- overlapping circles
        of.noFill()
        for x=50, OUTPUT_W-50, 20 do
            for y=50, OUTPUT_H-50, 20 do
                of.ellipse(x,y,40,40)                
            end
        end
    elseif option==4 then
        -- rotating arcs
        for x=50, OUTPUT_W-50, 20 do
            for y=50, OUTPUT_H-50, 20 do
                of.line(x-5,y-5,x+5,y+5)
            end
        end
    elseif option==5 then
        -- groups of five
        for x=50, OUTPUT_W-50, 20 do
            for y=50, OUTPUT_H-50, 20 do
                for i=1, 16, 4 do
                    of.line(x+i,y,x+i,y+12)
                end
                of.line(x,y,x+12,y+12)
            end
        end
    end
end

function mouseReleased()
    if option >= 5 then
        option = 1
    else
        option = option + 1
    end
end













