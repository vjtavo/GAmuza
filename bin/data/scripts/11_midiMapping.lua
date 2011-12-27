







-- midi device mapping
-- select your midi device from SettingManager FIRST!!!

verdana = of.font()

function setup()
    verdana:loadFont("fonts/verdana.ttf",84, true, false)
end

function draw()
    ga.background(0.0,0.3)
    
    of.pushMatrix()
    of.translate(OUTPUT_W/2,OUTPUT_H/2 + 42,0)
    of.enableAlphaBlending()
    gl.color4f(1.0,0.0,0.0,1.0)
    -- midi channel (midi program)
    verdana:drawString(tostring(ga.getMidiChannel()),-240,0)
    -- midi byte one (midi index, a knob, or trigger, or pad, etc..)
    verdana:drawString(tostring(ga.getMidiByteOne()),-70,0)
    -- midi byte two (midi value, 0-127)
    verdana:drawString(tostring(ga.getMidiByteTwo()),150,0)
    of.disableAlphaBlending()
    of.popMatrix()
end
































