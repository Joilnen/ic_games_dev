local bcount = 1

local function grow_snake()
    table.insert(snake_body_pos_list, {x = sn_x, y = sn_y})
    sn_body_list_count = #snake_body_pos_list
end

local function check_collision_improved(x1, y1, w1, h1, x2, y2, w2, h2)
    return x1 == x2 and y1 == y2
end


function check_if_lost(list)
    if #list <= 2 then
    -- if sn_body_list_count < 5 then
        return false
    end

    for i = 3,#list do
        if check_collision_improved(list[1]['x'], list[1]['y'], size_xy, size_xy,
                       list[i]['x'], list[i]['y'], size_xy, size_xy) then
            print('A ' .. list[1]['x'] .. ' ' .. list[1]['y'])
            print('B '.. i .. '--' .. list[i]['x'] .. ' ' .. list[i]['y'])
            return true
        end
    end
    return false
end

function game_update() 

	if orientation['up'] then	
		sn_y = sn_y - 1
	elseif orientation['down'] then
		sn_y = sn_y + 1
	elseif orientation['left'] then		
		sn_x = sn_x - 1
	elseif orientation['right'] then
		sn_x = sn_x + 1
	end

    if sn_x < 1 then
        sn_x = 28
    elseif sn_x > 28 then
        sn_x = 1 
    end

    if sn_y < 1 then
        sn_y = 28
    elseif sn_y > 28 then
        sn_y = 1 
    end

    if bcount <= sn_body_list_count then
        snake_body_pos_list[bcount]['x'] = sn_x
        snake_body_pos_list[bcount]['y'] = sn_y
        bcount = bcount + 1
    end

    if bcount > sn_body_list_count then
        bcount = 1
    end

	if(check_collision_improved(sn_x, sn_y, size_xy, size_xy, p_x, p_y, size_xy, size_xy)) then
		p_x = math.random(1, math.abs(width / size_xy) - 2)
		p_y = math.random(1, math.abs(height / size_xy) - 2)
        grow_snake()
    elseif check_if_lost(snake_body_pos_list) then 
       lost_flag = true
    end

    print("Cobra\n")
    for i = 1,#snake_body_pos_list do
        print(i .. ": " .. snake_body_pos_list[i]['x'] .. "  " .. snake_body_pos_list[i]['y'])
    end
    print("---\n")

end


