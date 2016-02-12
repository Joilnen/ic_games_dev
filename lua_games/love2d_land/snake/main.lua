--[[
    Snake 
    Autores Felipe, Joilnen e Lucas
--]]

require 'game_event'
require 'game_update'
require 'game_load'
require 'game_lost'
require 'game_draw'

function check_collision(x1, y1, w1, h1, x2, y2, w2, h2)
    return x1 < x2+w2 and
         x2 < x1 + w1 and
         y1 < y2 + h2 and
         y2 < y1 + h1
end

function love.load()
    game_load()
end

function love.draw()
    -- for i = 1,#snake_body do
    game_draw()
end

function love.keypressed(k)
    treat_keyboard(k)
end

function love.update(dt)
    if time_lapse > time_update_limit then 
        game_update()
        time_lapse =  dt
    end
    time_lapse = time_lapse + dt
end


