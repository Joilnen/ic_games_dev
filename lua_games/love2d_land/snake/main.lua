--[[
    Snake
    Autor: Joilnen
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

function love.update(dt)

    if time_lapse > time_update_limit then 
        game_update()
        time_lapse =  dt
    end
    time_lapse = time_lapse + dt
end

