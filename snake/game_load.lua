function game_load()

    snake_body = {}

    width = 480
    height = 480

    sn_x = math.abs(width / 16) * 8
    sn_y = math.abs(height / 16) * 8 
    -- size = 0

    p_x = 300
    p_y = 400

    orientation = {
        up = nil,
        down = nil,
        left = nil,
        right = nil
    }
    
    figs_dir = 'figs/'

    clock = os.clock
	love.window.setTitle("Snake v1.0")
	snake_body[1] = love.graphics.newImage(figs_dir .. 'sn.png')
    snake_body_pos_list = {}
    table.insert(snake_body_pos_list,{sn_x, sn_y})

	point = love.graphics.newImage(figs_dir .. 'point.png')
	love.window.setMode(width, height )
end

