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

-- BEGIN
    cannon:setXY(p_x * size_xy / 2, p_y * size_xy)
    cannon:draw()

    if cannon_bullet ~= nil then
        cannon_bullet:setXY(c_x * size_xy / 2, c_y * size_xy - 100)
								for i = 1, #a do
											if	checkBulletCollision (a[i]:getBoundingBox(),
																																  cannon_bullet:ngetXY())
																										then
																										c_y = -10 -- will force bullet to be erased
																								  cannon_bullet:setXY(99999999999,9999999999)
																										print ("Player bullet collided against alien")
																		end
								end
        cannon_bullet:draw()
        c_y = c_y - 1
        if c_y < 3 then cannon_bullet = nil end
    end

				if enemy_bullet ~= nil then
								local bulletposition = enemy_bullet:getXY()
								bulletposition[2] = bulletposition[2] + 10
        enemy_bullet:setXY(bulletposition[1],
																								   bulletposition[2])
								checkBulletCollision (cannon:getBoundingBox(),
																								      enemy_bullet:ngetXY())
        enemy_bullet:draw()
        if bulletposition[2] > 797 then enemy_bullet = nil end
    else
								love.graphics.print('No enemy_bullet ', 300, 20)
    end
-- END : Everything from BEGIN to END except for drawing calls should be moved
-- to game_update because game logic should be separed from rendering.

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


