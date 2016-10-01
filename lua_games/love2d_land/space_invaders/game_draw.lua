function shoot()
    love.graphics.print('Shooting', 200, 0)
    cannon:shoot()
end

function game_draw()

    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    end

    local a = el:getList()
    for i = 1, #a do
        a[i]:draw()
    end

    cannon:setXY(p_x * size_xy / 2, p_y * size_xy)
    cannon:draw()
    if cannon_bullet ~= nil then
        cannon_bullet:setXY(c_x * size_xy / 2, c_y * size_xy - 100)
        cannon_bullet:draw()
        c_y = c_y - 1
        if c_y < 3 then cannon_bullet = nil end
    end

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

    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)

    if orientation['shot'] then shoot() end
end


