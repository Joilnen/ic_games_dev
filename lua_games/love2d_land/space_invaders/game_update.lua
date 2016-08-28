function check_if_lost(x, y, list)

end

function game_update()
    if paused_flag then
        return
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
end


