Cookie = {}

function Cookie:new(o)
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

    o.visible = true
    o:setSprite()

    return o
end

function Cookie:setSprite()
    self.sprite = love.graphics.newImage('figs/cookie.png') 
end

function Cookie:draw()
    if self.visible then
        love.graphics.draw(self.sprite, self.sn_x, self.sn_y)
    end
end

function Cookie:setVisible(t)
    self.visible = t
end

function Cookie:get_x()
    return self.sn_x
end

function Cookie:get_y()
    return self.sn_y
end


