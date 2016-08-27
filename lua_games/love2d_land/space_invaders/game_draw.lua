require 'anim8'

function game_draw()
    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    end
    -- love.graphics.draw(border, 0, 0)
    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)
end


