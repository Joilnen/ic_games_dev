Snake = {}

local head_fig = {up = nil, down = nil, left = nil, right = nil}
local tail_fig = {up = nil, down = nil, left = nil, right = nil}

function Snake:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    math.randomseed(os.time())
    o.sn_x = math.random(1 + head_start_y, width - side_piece);
    o.sn_y = math.random(1 + head_start_y, height - side_piece);

    o.sn_x = math.abs(o.sn_x / 32)
    o.sn_x = o.sn_x * 32

    o.sn_y = math.abs(o.sn_y / 32)
    o.sn_y = o.sn_y * 32

    o.orientation = 'up'
    o.visible = true

    o:setSprite()

    return o
end

function Snake:setSprite(a)
    if a then
        self.sprite = a
    else
        self.sprite = love.graphics.newImage('figs/sn_1.png') 
    end
end

function Snake:draw()
    if self.visible then
        love.graphics.draw(self.sprite, self.sn_x, self.sn_y)
    end
end

function Snake:setVisible(t)
    self.visible = t
end

function Snake:get_x()
    return self.sn_x
end

function Snake:get_y()
    return self.sn_y
end


