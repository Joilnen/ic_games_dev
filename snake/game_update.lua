function game_update() 
	if cima == 1 and sn_y > 0 then	
		sn_y = sn_y - 16
	elseif baixo == 1 and sn_y < height - 16 then
		sn_y = sn_y + 16
	elseif esquerda == 1 and sn_x > 0 then		
		sn_x = sn_x - 16
	elseif direita == 1 and sn_x < width - 16 then
		sn_x = sn_x + 16
	end
	sleep(0.2)
	--print("x0 " .. x[0] .. " y0" .. y[0])

	if(checkCollision(sn_x, sn_y, 16, 16, p_x, p_y, 16, 16)) then
		p_x = math.random(0, width -16)
		p_y = math.random(0, height - 16)
	end
end
