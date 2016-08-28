
function game_draw()
    if lost_flag then
        show_lost()
    elseif paused_flag then
        show_pause()
    end
    -- love.graphics.draw(border, 0, 0)
    local count_x = 110
    local count_y = 120

    for i = 1, 11 do
        animator_list['en_3']:draw(enemies, count_x, count_y)
        count_x = count_x + 50
    end
    count_x = 110
    count_y = count_y + 40

    for a = 1, 2 do
        for i = 1, 11 do
            animator_list['en_2']:draw(enemies, count_x, count_y)
            count_x = count_x + 50
        end
        count_x = 110
        count_y = count_y + 40
    end

    for a = 1, 2 do
        for i = 1, 11 do
            animator_list['en_1']:draw(enemies, count_x, count_y)
            count_x = count_x + 50
        end
        count_x = 110
        count_y = count_y + 40
    end

    animator_list['cannon']:draw(enemies, p_x, p_y);

    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)
end


