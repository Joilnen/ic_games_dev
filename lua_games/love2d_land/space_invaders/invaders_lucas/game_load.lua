local anim = require 'anim8'

function game_load()


    --Lucas
    menu_start = true
    menu2_start = true
    --Lucas

    width = 800
    height = 600
    figs_dir = 'figs/'
    love.window.setTitle("Space Invaders V 0.1")
    menu = love.graphics.newImage(figs_dir .. 'menu1.png')
    menu2 = love.graphics.newImage(figs_dir .. 'menu2.png')
    score = 0
    score_font = love.graphics.newFont(26)
    num_player = 0
    high_score=0
    
end




