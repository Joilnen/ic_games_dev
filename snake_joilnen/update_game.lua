function update_game()

    if up_flag then 
        sn_y = sn_y - step
    end
    if down_flag then 
        sn_y = sn_y + step
    end
    if left_flag then 
        sn_x = sn_x - step
    end
    if right_flag then 
        sn_x = sn_x + step
    end

    if sn_x > width - side_piece - step then
        sn_x = side_piece - step
    elseif sn_x < step then
        sn_x = width - side_piece - step
    end

    if sn_y > height - side_piece - step then
        sn_y = head_start_y
    elseif sn_y < head_start_y then
        sn_y = height - side_piece - step
    end
end


