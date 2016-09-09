function check_if_lost(x, y, list)

end

function game_update()
    if paused_flag then
        return
    end

    local l = el:getList()
    for i = 1, #l do
        l[i]:incY()
        if l[1]:getXY()[2] > 580 then
            for f = 1, #l do l[f]:resetXY() end
        end
    end
end


