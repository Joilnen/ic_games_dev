function game_load()
    -- debug.debug()
    -- t.console = true
    font1 = love.graphics.newFont('fonts/Marker Felt.ttf', 36)
    font2 = love.graphics.newFont('fonts/Marker Felt.ttf', 20)

    snake_body_pos_list = {}
    sn_body_list_count = 1

    lost_flag = false
    paused_flag = false

    width = 480
    height = 480

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
    snake_border = love.graphics.newImage(figs_dir .. 'snake_border_1.png')
    snake_body = love.graphics.newImage(figs_dir .. 'sn1.png')
    snake_body_pos_list[1] = {x = sn_x, y = sn_y}

    point = love.graphics.newImage(figs_dir .. 'point.png')
    love.window.setMode(width, height)

    time_lapse = 0
    time_update_limit = .2

    score_font = love.graphics.newFont(26)
    score = 0
    -- hiscore = score
end

function reset_game()
    snake_body_pos_list = {}
    lost_flag = false

    sn_x = math.abs(width / 16)
    sn_y = math.abs(height / 16)

    snake_body_pos_list[1] = {x = sn_x, y = sn_y}
    sn_body_list_count = 1
    score = 0
end


