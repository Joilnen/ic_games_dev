
function game_draw()
    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    end
    -- love.graphics.draw(border, 0, 0)
    anima:draw(enemy_list['en1'], 200, 200)
    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)
end


