--[[                      
     Autor: Joilnen Leite 
                          ]]
require 'load_game'
require 'game_event'
require 'update_game'
require 'Cookie'
require 'Snake'
require 'functions'

-- debug.debug()

width, height = love.window.getMode()
step = 32
head_start_y = 80
side_piece = 32
sn_x = width / 2 - side_piece
sn_y = height / 2  + head_start_y - side_piece 

sn_x = math.abs(sn_x / 32)
sn_x = sn_x * 32

sn_y = math.abs(sn_y / 32)
sn_y = sn_y * 32

time_lapse = 0
time_update_limit = .3
colide = false

snake = {}
cookie = {}
head_fig = {up = nil, down = nil, left = nil, right = nil}
tail_fig = {up = nil, down = nil, left = nil, right = nil}

snake_body = {}

function love.load()
    load_game()
end

function love.draw() 
    for i = 1,#cookie do
        cookie[i]:draw()
    end
    love.graphics.draw(snake_body[1], sn_x, sn_y)
    love.graphics.draw(snake_body[2], sn_x + side_piece, sn_y)
    love.graphics.draw(snake_body[3], sn_x + 2*side_piece, sn_y)
end

function love.update(dt) 
    if not check_colision(cookie[1]) then 
        cookie[1] = nil
        cookie[1] = Cookie:new()
        colide = false
    end
    if time_lapse > time_update_limit then 
        update_game()
        time_lapse =  dt
    end
    time_lapse = time_lapse + dt
end

function love.keypressed(k)
    treat_key_event(k)
end


