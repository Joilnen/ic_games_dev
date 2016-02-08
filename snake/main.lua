--[[
    Snake 
    Autores Felipe, Joilnen e Lucas
--]]

require 'game_event'
require 'game_update'
require 'game_load'

function sleep(n)  -- seconds
    local t0 = clock()
    while clock() - t0 <= n do end
end

function checkCollision(x1,y1,w1,h1, x2,y2,w2,h2)
    return x1 < x2+w2 and
         x2 < x1+w1 and
         y1 < y2+h2 and
         y2 < y1+h1
end

function love.load()
    game_load()
end

function love.draw()
    -- for i = 1,#snake_body do
    for i = 1, sn_body_list_count do
	    love.graphics.draw(snake_body[1], 
             snake_body_pos_list[i]['x'], 
             snake_body_pos_list[i]['y'])
    end
	love.graphics.draw(point, p_x, p_y)
end

function love.keypressed(k)
    treat_keyboard(k)
end

function love.update(dt)
    game_update()	
end


