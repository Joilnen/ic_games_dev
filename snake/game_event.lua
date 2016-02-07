function treat_keyboard(k)
    if k == 'escape' then
        love.event.quit()
    end

	if k == "up" and baixo ~= 1 then
		cima = 1
		baixo = 0
		direita = 0
		esquerda = 0
	elseif k == "down" and cima ~= 1 then
		cima = 0
		baixo = 1
		direita = 0
		esquerda = 0
	elseif k == "left" and direita ~= 1 then
		cima = 0
		baixo = 0
		direita = 0
		esquerda = 1
	elseif k == "right" and esquerda ~= 1 then
		cima = 0
		baixo = 0
		direita = 1
		esquerda = 0
	end
end

