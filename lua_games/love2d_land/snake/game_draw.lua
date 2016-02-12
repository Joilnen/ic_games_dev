function game_draw()
    if lost_flag then
        show_lost()
    else
        for i = 1,sn_body_list_count do
            love.graphics.draw(snake_body, 
                 snake_body_pos_list[i]['x'], 
                 snake_body_pos_list[i]['y'])
        end
        love.graphics.draw(point, p_x, p_y)
    end

end
