
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
    self.animator:draw(self.x, self.y)
end

function Enemy:setLineToShoot(a)
    self.lineToShoot = a
end

function Enemy:getLineToShoot()
    return self.lineToShoot
end

EnemyList = {
    l = {},
    count_list
}

function EnemyList:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function EnemyList:addEnemy(a)
    if self.count_list == 0 then
        self.count_list = 1
    else
        self.count_list = self.count_list + 1
    end
    self.l[self.count_list] = a
end

function EnemyList:getEnemyList()
    return self.l
end


