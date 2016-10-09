function treat_keyboard(k)
    if k == 'space' and menu_start then 
        menu_start = false
    elseif k == 'up' and menu2_start then 
        menu2_start = false
        number_player = 1
    elseif k == 'down' and menu2_start then 
        menu2_start = false
        number_player = 2
    elseif not menu2_start then
      menu_start = true
      menu2_start = true
      score = 20
      record_score()
    end
  
end


