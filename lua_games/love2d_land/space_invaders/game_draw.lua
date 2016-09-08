function shoot()
    love.graphics.print('Shooting', 200, 0)
    cannon_o:shoot()
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

    -- print("p_x * size_xy / 2", p_x * size_xy / 2)
    -- print("p_y * size_xy ", p_y * size_xy)
    animator_list['cannon']:draw(enemies, p_x * size_xy / 2, p_y * size_xy);
    -- animator_list['bullet_1']:draw(enemies, p_x * size_xy / 2, p_y * size_xy - 100);
    -- animator_list['bullet_2']:draw(enemies, p_x * size_xy / 2 + 100, p_y * size_xy - 100);
    cannon_o:draw()
    if cannon_bullet then
        local a,l = cannon_bullet:getXY()
        if l ==  3 then
            cannon_bullet = nil
        else
            cannon_bullet:setXY(p_x * size_xy / 2, p_y * size_xy - 100)
            cannon_bullet:draw()
            p_y = p_y - 1
        end
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


