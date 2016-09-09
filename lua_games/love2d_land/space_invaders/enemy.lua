
Enemy = {
    animator = nil,
    x, y,
    lineToShoot
}

function Enemy:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function Enemy:setAnimator(a)
    self.animator = a
end

function Enemy:getAnimator()
    return self.animator
end

function Enemy:setXY(x, y)
    self.x, self.y = x, y
end

function Enemy:draw()
    self.animator:draw(enemies, self.x, self.y)
end

function Enemy:setLineToShoot(a)
    self.lineToShoot = a
end

function Enemy:getLineToShoot()
    return self.lineToShoot
end

function Enemy:incX()
    self.x = self.x + 1
end

function Enemy:incY() 
    self.y = self.y + 1
end

function Enemy:resetXY()
    self.x, self.y = 110, 120
end


