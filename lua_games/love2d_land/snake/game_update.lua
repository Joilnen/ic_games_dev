sn_body_list_count = 1
local bcount = 1

function grow_snake(o)

    if o['up'] then
        table.insert(snake_body_pos_list, {x = sn_x, y = sn_y + 16})
    elseif o['down'] then 
        table.insert(snake_body_pos_list, {x = sn_x, y = sn_y - 16})
    elseif o['left'] then
        table.insert(snake_body_pos_list, {x = sn_x + 16, y = sn_y})
    else
        table.insert(snake_body_pos_list, {x = sn_x - 16, y = sn_y})
    end

    -- table.insert(snake_body, love.graphics.newImage(figs_dir .. 'sn.png'))
    sn_body_list_count = sn_body_list_count + 1
end

function check_if_lost(list)
    -- if #list < 2 then
    if sn_body_list_count < 2 then
        return false
    end

    for i = 2,#list do
        if check_collision_improved(list[1]['x'], list[1]['y'], 16, 16,
                       list[i]['x'], list[i]['y'], 16, 16) then
            return true
        end
    end

    -- for i = 1, #list do
    --     print ('list[' .. i .. '][\'x\'] = ' .. list[i]['x'])
    --     print ('list[' .. i .. '][\'y\'] = ' .. list[i]['y'])
    -- end
    return false
end

function check_collision_improved(x1, y1, w1, h1, x2, y2, w2, h2)
    return x1 + w1 / 2 > x2 and x1 + w1 / 2 < x2 + w2 and
           y1 + h1 / 2 > y2 and y1 + h1 / 2 < y2 + h2
end

function game_update() 

	if orientation['up'] then	
		sn_y = sn_y - 16
	elseif orientation['down'] then
		sn_y = sn_y + 16
	elseif orientation['left'] then		
		sn_x = sn_x - 16
	elseif orientation['right'] then
		sn_x = sn_x + 16
	end

    if sn_x < 1 then
        sn_x = width - 16
    elseif sn_x > width - 31 then
        sn_x = 0 
    end

    if sn_y < 1 then
        sn_y = height - 31
    elseif sn_y > height - 17 then
        sn_y = 0 
    end

    if bcount <= sn_body_list_count then
        snake_body_pos_list[bcount]['x'] = sn_x
        snake_body_pos_list[bcount]['y'] = sn_y
        bcount = bcount + 1
    end

    if bcount > sn_body_list_count then
        bcount = 1
    end

    if check_if_lost(snake_body_pos_list) then 
        lost_flag = true
    end

	-- print("x0 " .. x[0] .. " y0" .. y[0])

	if(check_collision(sn_x, sn_y, 16, 16, p_x, p_y, 16, 16)) then
		p_x = math.random(0, width -16)
		p_y = math.random(0, height - 16)
        grow_snake(orientation)
	end
end


