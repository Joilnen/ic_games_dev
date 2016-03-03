bcount = 1
local last = {}

local function grow_snake()
    -- table.insert(snake_body_pos_list, {x = sn_x, y = sn_y})
    table.insert(snake_body_pos_list,
                   {x = snake_body_pos_list[#snake_body_pos_list]['x'],
                    y = snake_body_pos_list[#snake_body_pos_list]['y']})
    sn_body_list_count = #snake_body_pos_list
end

function shallowcopy(orig)

    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in pairs(orig) do
            copy[orig_key] = orig_value
        end
    else -- number, string, boolean, etc
        copy = orig
    end
    return copy
end

function check_if_lost(x, y, list)

    if #list < 2 then
        return false
    end

    print('--Checa cobra--')
    for i, v in ipairs(list) do
        print ('head_index [x] = ' .. list[head_index]['x'] .. ' [y] = ' .. list[head_index]['y'] ..' tile 2 [x] = ' .. v['x'] .. ' [y] = ' .. v['y'] .. " head # " .. head_index)
        if v ~= last and v['x'] == x and v['y'] == y then
            return true
        end
    end
    print('-- --')
    print()
    return false
end

function game_update()
    if paused_flag then
        return
    end

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
        last = snake_body_pos_list[bcount]
        bcount = bcount + 1
    end

    if bcount > sn_body_list_count then
        bcount = 1
    end

    if sn_x == p_x and sn_y == p_y then
        p_x = math.random(1, math.abs(width / size_xy) - 2)
        p_y = math.random(1, math.abs(height / size_xy) - 2)
        grow_snake()
    elseif #snake_body_pos_list < 3 then
        return
    elseif check_if_lost(sn_x, sn_y, snake_body_pos_list) then
        lost_flag = true
    end
end


