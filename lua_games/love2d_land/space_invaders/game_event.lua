function change_orientation(k)

    if k == 'left' then orientation['right'] = nil end
    if k == 'right' then orientation['left'] = nil end

    orientation[k] = true
end

function treat_keyboard(k)
    if lost_flag and k == 'space' then
        reset_game()
    end

    if k == 'escape' then love.event.quit() end
    if k == 'return' then goplay = true end

    change_orientation(k)
end

function cannon_shooted()
    love.graphics.print("Cannon shooted", 10, 10)
    cannon:setAnimator(animator_list['explosion'])
    lost_flag = true
end

function enemy_shooted()
    love.graphics.print("Enemy shooted", 10, 60)
end


