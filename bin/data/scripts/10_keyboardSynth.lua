





-- keyboard Synth Example

function setup()
    ga.wave(SINE,1.6)
    ga.waveVolume(0,0.8)    
end

function update()
    
end

function draw()
    ga.background(0.0,1.0)
end

function keyReleased()
    ga.waveFrequency(0,ga.key()*10.0)
end





