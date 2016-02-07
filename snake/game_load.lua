function game_load()
    snake_body = {}

    sn_x = 32
    sn_y = 32
    size = 0
    x = {}
    y = {}

    width = 480
    height = 480

    p_x = 300
    p_y = 400

    cima = 0
    baixo = 0
    direita = 0
    esquerda = 0

    figs_dir = 'figs/'

    clock = os.clock
	love.window.setTitle("Snake v1.0")
	snake_body[0] = love.graphics.newImage(figs_dir .. 'sn.png')
	 
	
	point = love.graphics.newImage(figs_dir .. 'point.png')
	love.window.setMode( width, height )
end

