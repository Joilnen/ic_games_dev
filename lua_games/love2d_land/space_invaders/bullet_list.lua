
Bullet = {
    animator = nil,
    x, y,
    lineToShoot
}

function Bullet:setAnimator(a)
    self.animator = a
end

function Bullet:getAnimator()
    return self.animator
end

function setXY(x, y)
    self.x, self.y = x, y
end

function setLineToShoot(a)
    self.lineToShoot = a
end

function getLineToShoot()
    return self.lineToShoot
end

BulletList = {
    l = {},
    count_list
}

function BulletList:addBullet(a)
    if self.count_list == 0 then
        self.count_list = 1
    else
        self.count_list = self.count_list + 1
    end
    self.l[count_list] = a
end

function BulletList:getBulletList()
    return self.l
end


