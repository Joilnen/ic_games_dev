function check_if_lost(x, y, list)

end

local x_step = 1
local x_d = 0

function game_update()
    if paused_flag then
        return
    end

    local l = el:getList()
::continue::
    for i = 1, #l do
        if l[1]:getXY()[2] > 580 then
            for f = 1, #l do l[f]:resetXY() end
            goto continue
        end

        l[1]:setXY(l[1]:getXY()[1] + x_step, l[1]:getXY()[2])
        if l[1]:getXY()[1] > 200 then
            x_step = -1
            l[i]:incY()
        elseif l[1]:getXY()[1] < 40 then
            x_step = 1
            l[i]:incY()
        end
    end
end


