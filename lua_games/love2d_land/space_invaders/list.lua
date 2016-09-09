List = {
    l = {},
    count_list
}

function List:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function List:add(a)
    self.l[self.count_list] = a
    self.count_list = self.count_list + 1
end

function List:getList()
    return self.l
end

function List:resetXY()
    for f = 1, #self.l do
        self.l[f]:resetXY()
    end
end

