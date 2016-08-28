Bullet = {
    animator = nil,
    x, y
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

BulletList = {
    bulletList = {},
    count_list
}

function BulletList:addButtet(a)
    if self.count_list == 0 then
        self.count_list = 1
    else
        self.count_list = self.count_list + 1
    end
    self.bulletList[count_list] = a
end

function BulletList:getBulletList()
    return self.bulletList
end


