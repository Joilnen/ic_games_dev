--[[
    Space Invaders
    Autor: Joilnen, Lukkas e Pedro
    Mar 2016
    This code is in MIT license
]]

require 'game_event'
require 'game_update'
require 'game_load'
require 'game_lost'
require 'game_draw'
require 'game_menu'

function love.load()
    game_load()
end

function love.draw()
    -- TODO 
    -- menu_draw()
    if goplay == false then
        menu_draw()
    else
        game_draw()
    end
end

function love.keypressed(k)
    treat_keyboard(k)
end

-- function love.touchmoved(id, x, y, dx, dy, p)
--     if math.abs(dx) > math.abs(dy) then
--         if dx > 0 then
--             love.keypressed('left')
--         else
--             love.keypressed('right')
--         end
--     elseif(math.abs(dx) < math.abs(dy)) then
--         if dy > 0 then
--             love.keypressed('down')
--         else
--             love.keypressed('up')
--         end
--     end
-- end

function love.update(dt)
    if time_lapse > time_update_limit then 
        if lost_flag ~= true then
            game_update()
        end
        time_lapse =  dt
    end

    for k, v in pairs(animator_list) do
        animator_list[k]:update(dt)
    end

    key_event()
    time_lapse = time_lapse + dt
end

function key_event()
    orientation['shoot'] = love.keyboard.isDown('lctrl')
    orientation['left'] = love.keyboard.isDown('left')
    orientation['right'] = love.keyboard.isDown('right')
end


