








-- timeline Example
-- press "alt t" to view the timeline
-- press "alt g" to play/stop the timeline

circleX = 0
circleY = 0
function setup()
    of.setCircleResolution(50)

    ga.addTimelineKeyframes("posX","posX.xml",0,OUTPUT_W)
    ga.addTimelineKeyframes("posY","posY.xml",0,OUTPUT_H)
    ga.setTimelineFrames(200)
    ga.setTimelineLoop(OF_LOOP_NORMAL)
    ga.playTimeline()
end

function update()
    circleX = ga.getTimelineValue("posX")
    circleY = ga.getTimelineValue("posY")    
end

function draw()
    ga.background(0.0,0.1)

    if ga.getTimelineTrigger() == "RED" then
        of.setColor(255,0,0)
    elseif ga.getTimelineTrigger() == "WHITE" then
        of.setColor(255)
    end
    of.circle(circleX,circleY,30)
end





































