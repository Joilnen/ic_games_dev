require 'configs'
require 'resources'
playerPositionX = windowWidth * 0.5
playerPositionY = windowHeight * 0.92
playerCurrentMovement = ''
playerSpeed = 0.8

function handleKeyboard(key)
	if key == 'left' then
		playerCurrentMovement = 'left'
	elseif key == 'right' then
		playerCurrentMovement = 'right'
	end
end

function moveLeft()
	newPosition = playerPositionX - playerSpeed
	if (newPosition - playerSprite:getWidth()/2) > 0.0 then
		return newPosition
	else 
		return playerPositionX
	end
end

function moveRight()
	newPosition = playerPositionX + playerSpeed
	if (newPosition + playerSprite:getWidth()/2) < windowWidth then
		return newPosition
	else 
		return playerPositionX
	end
end

function playerUpdate() 
	if love.keyboard.isDown('left') then
		playerPositionX = moveLeft()
	elseif love.keyboard.isDown('right') then
		playerPositionX = moveRight()
		moveRight()
	end
end

function drawPlayer()
	love.graphics.print(tostring(playerPositionX),
	300,200)
	love.graphics.setColor(255,0,0)
	love.graphics.point(playerPositionX,playerPositionY)
	love.graphics.setColor(255,255,255)
	love.graphics.draw(playerSprite,
	playerPositionX - playerSprite:getWidth()/2,
	playerPositionY - playerSprite:getHeight()/2)
end
