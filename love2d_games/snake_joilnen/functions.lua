function setHeadAndTailSprite(s)
    s[sprite_head] = love.graphics.newImage('head.png')
    s[sprite_tail] = love.graphics.newImage('tail.png') 
end

function setBodySprite(s)
    s[sprite] = love.graphics.newImage('head.png') 
end

function setBodySprite(s)
    s[sprite] = love.graphics.newImage('sn_1.png') 
end

function check_colision(c)
    if sn_x + side_piece / 2 > c:get_x() and sn_x + side_piece / 2 < c:get_x() + side_piece and
       sn_y + side_piece / 2 > c:get_y() and sn_y + side_piece / 2 < c:get_y() + side_piece and not colide then
       colide = true
       return false
    end
    if not colide then
        return true
    end
end


