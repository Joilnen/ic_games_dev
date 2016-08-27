require 'player'

function love.update(dt)
	playerUpdate()
end

function love.load()
	love.window.setMode(800,600,{vsync=false})
	loadResources()
end

function love.draw()
	drawPlayer()
end
