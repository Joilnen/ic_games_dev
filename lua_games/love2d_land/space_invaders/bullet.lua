
Bullet = {
    animator = nil,
    x, y,
    lineToShoot,
    on
}

function Bullet:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    self.x, self.y = o.x, o.y
    return o
end

function Bullet:setAnimator(a)
    self.animator = a
end

function Bullet:getAnimator()
    return self.animator
end

function Bullet:setXY(x, y)
    self.x, self.y = x, y
end

function Bullet:getXY()
    return {self.x, self.y}
end

function Bullet:setLineToShoot(a)
    self.lineToShoot = a
end

function Bullet:getLineToShoot()
    return self.lineToShoot
end

function Bullet:draw()
    if self.on then
        self.animator:draw(enemies, self.x, self.y)
    end
end

function Bullet:setState(a)
    if a == nil then
        self.on = true
    else
        self.on = a
    end
end

function Bullet:getState()
    return self.on
end


