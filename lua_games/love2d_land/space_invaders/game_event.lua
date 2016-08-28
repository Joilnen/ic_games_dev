function change_orientation(k)
    if k == 'left' then orientation['right'] = nil end
    if k == 'right' then orientation['left'] = nil end

    orientation[k] = true

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

    change_orientation(k)
end


