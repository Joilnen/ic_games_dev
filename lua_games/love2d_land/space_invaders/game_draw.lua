local function shoot()
    love.graphics.print('Shooting', 200, 0)
    cannon:shoot()
end

local function show_score()
    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)
end

local function draw_cannon_bullet()
    local a = el:getList()
    if cannon_bullet ~= nil then
        for i = 1, #a do
            if checkBulletCollision (a[i]:getBoundingBox(), cannon_bullet:ngetXY()) then
                --cannon_bullet = nil
                                                                                                        print ("Player bullet collided against alien")
            end
        end
    end

    if cannon_bullet ~= nil then
        cannon_bullet:setXY(c_x * size_xy / 2, c_y * size_xy - 100)
        cannon_bullet:draw()
        c_y = c_y - 1
        if c_y < 3 then cannon_bullet = nil end
    end
end

local function draw_enemy_bullet()
    if enemy_bullet ~= nil then
        local bulletposition = enemy_bullet:getXY()
        bulletposition[2] = bulletposition[2] + 10
        enemy_bullet:setXY(bulletposition[1], bulletposition[2])
        -- checkBulletCollision (cannon:getBoundingBox(), enemy_bullet:ngetXY())
        enemy_bullet:draw()
        if bulletposition[2] > 797 then enemy_bullet = nil end
    else
        love.graphics.print('No enemy_bullet ', 300, 20)
    end
end


local function update_cannon_position()
    if orientation['left'] then
        p_x = p_x - 1
    elseif orientation['right'] then
        p_x = p_x + 1
    end

    if p_x < 1 then
        p_x = 1
    elseif p_x > size_xy * 6 then
        p_x = size_xy * 6
    end
end

local function draw_enemy_list()
    local a = el:getList()
    for i = 1, #a do
        a[i]:draw()
    end
end

function game_draw()

    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    end

    cannon:setXY(p_x * size_xy / 2, p_y * size_xy)
    cannon:draw()
    draw_cannon_bullet()
    -- draw_enemy_bullet()
    update_cannon_position()
    draw_enemy_list()

    if orientation['shot'] then shoot() end
end


