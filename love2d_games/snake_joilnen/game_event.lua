
left_flag = false
right_flag = false
up_flag = false
down_flag = false
local last_key = 'left'

function treat_key_event(k)
    if k == 'escape' then 
        love.event.quit()
    end
    if k == 'up' and last_key ~= 'down' then
       up_flag = true 
       down_flag = not up_flag 
       left_flag = not up_flag 
       right_flag = not up_flag 
       last_key = k
       -- snake_body[1] = head_fig['up']
    end
    if k == 'down' and last_key ~= 'up' then
       down_flag = true
       up_flag = not down_flag
       left_flag = not down_flag 
       right_flag = not down_flag 
       last_key = k
       -- snake_body[1] = head_fig['down']
    end
    if k == 'left' and last_key ~= 'right' then
       left_flag = true
       down_flag = not left_flag 
       up_flag = not left_flag
       right_flag = not left_flag 
       last_key = k
       -- snake_body[1] = head_fig['left']
    end
    if k == 'right' and last_key ~= 'left' then
       right_flag = true 
       down_flag = not right_flag 
       up_flag = not right_flag
       left_flag = not right_flag 
       last_key = k
       -- snake_body[1] = head_fig['right']
    end
end


