head_index = 1
function change_orientation(k)
    for ch, v in pairs(orientation) do orientation[ch] = false end
    orientation[k] = true
    head_index = bcount
end

function treat_keyboard(k)
    if lost_flag and k == 'space' then
        reset_game()
    elseif k == 'space' then
        paused_flag = not paused_flag
    end

    if k == 'escape' then
        love.event.quit()
    end

	if k == 'up' and  orientation['down'] or
	   k == 'down' and orientation['up'] or
	   k == 'left' and orientation['right'] or
	   k == 'right' and orientation['left'] or
       k ~= 'up' and k ~= 'down' and k ~= 'left' and k ~= 'right' then
           return
	end
    change_orientation(k)
end


