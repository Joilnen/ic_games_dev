local anim = require 'anim8'

function game_load()
    -- debug.debug()
    -- t.console = true
    font1 = love.graphics.newFont('fonts/Marker Felt.ttf', 36)
    font2 = love.graphics.newFont('fonts/Marker Felt.ttf', 20)

    enemy_pos_list = {}
    enemy_list_count = 1

    lost_flag = false
    paused_flag = false

    width = 800
    height = 600

    size_xy = 16
    sn_x = math.abs(width / size_xy)
    sn_y = math.abs(height / size_xy) + 2

    p_x = 1
    p_y = 5

    orientation = {
        up = nil,
        down = nil,
        left = nil,
        right = nil
    }

    figs_dir = 'figs/'

    love.window.setTitle("Snake v1.0")
    -- border = love.graphics.newImage(figs_dir .. 'border.png')
    cannon = love.graphics.newImage(figs_dir .. 'sn1.png')
    enemy_list = {}
    enemy_pos_list[1] = {x = sn_x, y = sn_y}
    enemy_list['en1'] = love.graphics.newImage(figs_dir .. 'en1.png')

    g = anim.newGrid(80, 58, enemy_list['en1']:getWidth(), enemy_list['en1']:getHeight())
    anima = anim.newAnimation(g('1-2', 1), 0.4)

    point = love.graphics.newImage(figs_dir .. 'point.png')
    love.window.setMode(width, height)

    time_lapse = 0
    time_update_limit = .2

    score_font = love.graphics.newFont(26)
    score = 0
end

function reset_game()
    enemy_pos_list = {}
    lost_flag = false

    sn_x = math.abs(width / 16)
    sn_y = math.abs(height / 16)

    enemy_pos_list[1] = {x = sn_x, y = sn_y}
    enemy_list_count = 1
    score = 0
end


