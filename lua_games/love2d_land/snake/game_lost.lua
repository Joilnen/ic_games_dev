function show_lost()
    love.graphics.setFont(font1)
    love.graphics.print('Perdeu Playboy !', width / 2 - 100, height/2)
    love.graphics.setFont(font2)
    love.graphics.print('space pra continuar', width / 2 - 60, height/2 + 40)
end

function show_pause()
    love.graphics.setFont(font1)
    love.graphics.print('PAUSA, vai arregar ?!', width / 2 - 150, height/2)
end
