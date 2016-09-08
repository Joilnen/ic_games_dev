require 'bullet'

Cannon = {
    animator = nil,
    x, y,
    on
}

function Cannon:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function Cannon:setAnimator(a)
    self.animator = a
end

function Cannon:getAnimator()
    return self.animator
end

function Cannon:setXY(x, y)
    self.x, self.y = x, y
end

function Cannon:setLineToShoot(a)
    self.lineToShoot = a
end

function Cannon:getLineToShoot()
    return self.lineToShoot
end

function Cannon:draw()
    if self.on then
        self.animator:draw(enemies, self.x, self.y)
    end
end

function Cannon:setState(a)
    if a == nil then
        self.on = true
    else
        self.on = a
    end
end

function Cannon:getState()
    return self.on
end

function Cannon:shoot()
    if cannon_bullet == nil then
        cannon_bullet =  Bullet:new()
        cannon_bullet:setAnimator(animator_list['cannon_bullet'])
        cannon_bullet:setState(true)
        cannon_bullet:setXY(self.x * size_xy / 2, p_y * size_xy - 100)
        c_x, c_y = p_x, p_y
    end
end


