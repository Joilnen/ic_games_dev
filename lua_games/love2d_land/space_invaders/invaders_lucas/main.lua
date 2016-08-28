require 'game_event'
require 'game_load'
require 'game_draw'
require 'ui'

function love.load()
    game_load()
end

function love.draw()
    game_draw()
end

function love.keypressed(k)
    treat_keyboard(k)
end




