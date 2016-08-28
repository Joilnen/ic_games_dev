local anim = require 'anim8'

function load_assets(cannon, barries)
    enemies = love.graphics.newImage(figs_dir .. 'enemies.png')
end

function set_animnator()
    local g = anim.newGrid(32, 32, enemies:getWidth(), enemies:getHeight())
    animator_list['en_1'] = anim.newAnimation(g('3-4', 1), 0.4)
    animator_list['en_2'] = anim.newAnimation(g('1-2', 1), 0.4)
    animator_list['en_3'] = anim.newAnimation(g('1-2', 2), 0.4)
    animator_list['cannon'] = anim.newAnimation(g('1-1', 3), 0.1)
end

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
    sn_y = math.abs(height / size_xy)

    p_x = 7
    p_y = 32

    orientation = {
        shot = nil,
        double_shot = nil,
        left = nil,
        right = nil
    }

    figs_dir = 'figs/'

    love.window.setTitle("Space Invaders v1.0")
    -- border = love.graphics.newImage(figs_dir .. 'border.png')
    cannon = love.graphics.newImage(figs_dir .. 'sn1.png')
    animator_list = {}
    load_assets()
    set_animnator()

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


