







-- FORM+CODE - Diffusion-Limited Aggregation
-- from http://formandcode.com

field = {}
particleCount = 20000
particles = {}
pixels = of.pixels()
tex = of.texture()
color = of.color(245,151,176,255)

---------------------------------------------------------
function round(f)
    if f > 0.0 then
    	return 1
    elseif f < 0.0 then
    	return -1
    else
    	return 0
    end
end

---------------------------------------------------------
class 'Particle'

function Particle:__init()
	self.x = 0
	self.y = 0
	self.stuck = false
	self:reset()
end

function Particle:reset()
	while field[self.y * OUTPUT_W + self.x] do
	   self.x = math.floor(of.random(0,OUTPUT_W))
	   self.y = math.floor(of.random(0,OUTPUT_H))
	end
end

function Particle:update()
	if not self.stuck then
	    self.x = self.x + round(of.randomf())
	    self.y = self.y + round(of.randomf())
	    
	    if self.x<0 or self.y<0 or self.x>=OUTPUT_W or self.y>=OUTPUT_H then
	        self:reset()
	        return
	    end
	    
	    -- test if something is next to us
	    if not self:alone() then
	        self.stuck = true
	        field[self.y*OUTPUT_W + self.x] = true
	    end
	end
end

function Particle:alone()
    cx = self.x
    cy = self.y

    -- get positions
    lx = cx-1
    rx = c+1
    ty = cy-1
    by = cy+1

    if cx <= 0 or cx >= OUTPUT_W or
       lx <= 0 or lx >= OUTPUT_W or
       rx <= 0 or rx >= OUTPUT_W or
       cy <= 0 or cy >= OUTPUT_W or
       ty <= 0 or ty >= OUTPUT_W or
       by <= 0 or by >= OUTPUT_W then
       
        return true
    
    end

    -- pre multiply the ys
    cy = cy * OUTPUT_W
    ty = ty * OUTPUT_W
    by = by * OUTPUT_W
    
    -- N, W, E, S
    if field[cx+ty] or field[lx+cy] or field[rx+cy] or field[cx+by] then
        return false
    end

    -- NW, NE, SW, SE
    if field[lx+ty] or field[lx+by] or field[rx+ty] or field[rx+by] then
        return false
    end

    return true
    
end

--------------------------------------------------------

function setup()
    tex:allocate(OUTPUT_W,OUTPUT_H,GL_LUMINANCE)
    tex:clear()
    --pixels:allocate(OUTPUT_W,OUTPUT_H,OF_IMAGE_GRAYSCALE)
    for i=0, OUTPUT_W*OUTPUT_H do
        field[i] = false
    end
    
    fcenterX = OUTPUT_W/2
    fcenterY = OUTPUT_H/2
    field[fcenterX + fcenterY*OUTPUT_W] = true
    
    for i=0, particleCount do
        particles[i] = Particle()
    end
    
end

function update()
    for i=0, particleCount do
        particles[i]:update()
        if particles[i].stuck then
            pixels:setColor(particles[i].x,particles[i].y,color)
        end
    end
    tex:loadData(pixels)
end

function draw()
    ga.background(0.0,1.0)
    
    of.setColor(255)
    tex:draw(0,0)
end














