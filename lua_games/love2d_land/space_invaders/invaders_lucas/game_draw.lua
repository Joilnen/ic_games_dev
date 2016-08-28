
function game_draw()
	if menu_start then
		show_menu()
		love.graphics.print('APERTE ESPAÇO PARA INICIAR', 320, 350)
		love.graphics.print('MAIOR PONTUAÇÃO', 350, 400)
    	love.graphics.print(high_score, 400, 420)
	elseif menu2_start then
		show_menu2()
		love.graphics.print('APERTE UP PARA UM JOGADOR E DOWN PARA 2', 270, 280)
	end

end


