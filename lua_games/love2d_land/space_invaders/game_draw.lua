function game_draw()
    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    else
        for i = 1,#snake_body_pos_list do
            love.graphics.draw(snake_body,
                 snake_body_pos_list[i]['x'] * size_xy,
                 snake_body_pos_list[i]['y'] * size_xy)
        end
        love.graphics.draw(point, p_x * size_xy, p_y * size_xy)
    end
    love.graphics.draw(snake_border, 0, 0)
    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)
end


