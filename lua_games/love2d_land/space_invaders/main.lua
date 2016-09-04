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
require 'bullet'

function love.load()
    game_load()
end

function love.draw()
    game_draw()
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
        game_update()
        time_lapse =  dt
    end

    for k, v in pairs(animator_list) do
        animator_list[k]:update(dt)
    end

    key_event()
    time_lapse = time_lapse + dt
end

function key_event()
    orientation['shot'] = love.keyboard.isDown('lctrl')
    orientation['left'] = love.keyboard.isDown('left')
    orientation['right'] = love.keyboard.isDown('right')
end

