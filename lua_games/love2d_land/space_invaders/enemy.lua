
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

function Enemy:setInitXY(a, b)
    self.init_x, self.init_y = a, b
    self.x, self.y = self.init_x, self.init_y
end

function Enemy:setXY(x, y)
    self.x, self.y = x, y
end

function Enemy:getXY()
    return {self.x, self.y}
end

function Enemy:ngetXY()
    return {x = self.x,y = self.y}
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
    self.x = self.x + 1 * size_xy
end

function Enemy:incY()
    self.y = self.y + 1 * size_xy
end

function Enemy:resetXY()
    self.x, self.y = self.init_x, self.init_y
end

function Enemy:shoot()
    if enemy_bullet == nil then
        enemy_bullet = Bullet:new()
        math.randomseed(os.time())
        local choose_bullet = math.random(1, 2)
        if choose_bullet == 1 then
            enemy_bullet:setAnimator(animator_list['bullet_1'])
        else
            enemy_bullet:setAnimator(animator_list['bullet_2'])
        end
        enemy_bullet:setState(true)
        enemy_bullet:setXY(self.x, self.y)
--        ec_x, ec_y = self.x, p_y
    end
end

function Enemy:getBoundingBox()
    -- I am assuming that alien size is 32x32
    -- But we should get this information instead of trying to guess
    local dummyW = self.x + 32
    local dummyH = self.y + 32
    return {x = self.x, y = self.y, w = dummyW, h = dummyH}
end


