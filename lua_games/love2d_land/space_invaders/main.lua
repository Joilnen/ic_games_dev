--[[
    Space Invaders
    Autor: Joilnen
    Mar 2016
    This code is in MIT license
--]]

require 'game_event'
require 'game_update'
require 'game_load'
require 'game_lost'
require 'game_draw'

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
        -- game_update()
        time_lapse =  dt
    end
    time_lapse = time_lapse + dt
    anima:update(dt)
end

