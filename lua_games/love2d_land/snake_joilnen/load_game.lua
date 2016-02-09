local dir = 'figs/'

function load_game()
    love.window.setTitle("Snake")

    head_fig['up'] = love.graphics.newImage(dir .. '/head_up.png')
    head_fig['down'] = love.graphics.newImage(dir .. '/head_down.png')
    head_fig['left'] = love.graphics.newImage(dir .. '/head_left.png')
    head_fig['right'] = love.graphics.newImage(dir .. '/head_right.png')

    tail_fig['up'] = love.graphics.newImage(dir .. '/tail_up.png')
    tail_fig['down'] = love.graphics.newImage(dir .. '/tail_down.png')
    tail_fig['left'] = love.graphics.newImage(dir .. '/tail_left.png')
    tail_fig['right'] = love.graphics.newImage(dir .. '/tail_right.png')

    snake_body[1] = head_fig['left']
    snake_body[2] = love.graphics.newImage(dir .. '/sn_1.png')
    snake_body[3] = tail_fig['right']

    cookie[1] = Cookie:new()
    -- cookie[1]:setSprite()
    colide = false
end


