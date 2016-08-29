require 'enemy_list'
require 'bullet_list'

local anim = require 'anim8'

animator_list = {}

function loadAssets(cannon, barries)
    enemies = love.graphics.newImage(figs_dir .. 'enemies.png')
end

function setAnimator()
    local g = anim.newGrid(32, 32, enemies:getWidth(), enemies:getHeight())
    animator_list['en_1'] = anim.newAnimation(g('5-6', 1), 0.4)
    animator_list['en_2'] = anim.newAnimation(g('1-2', 1), 0.4)
    animator_list['en_3'] = anim.newAnimation(g('3-4', 1), 0.4)
    animator_list['cannon'] = anim.newAnimation(g('1-1', 2), 0.1)
    animator_list['bullet_1'] = anim.newAnimation(g('2-3', 2), 0.1)
    animator_list['bullet_2'] = anim.newAnimation(g('4-5', 2), 0.1)
    animator_list['bullet_cannon'] = anim.newAnimation(g('6-6', 2), 0.1)
end

function createEnemies()
    local count_x = 110
    local count_y = 120

    el = EnemyList:new{ count_list = 1 }

    for i = 1, 11 do
        local e = Enemy:new()
        e:setAnimator(animator_list['en_1'])
        e:setXY(count_x, count_y)
        el:addEnemy(e)
        count_x = count_x + 50
    end
    count_x = 110
    count_y = count_y + 40

    for a = 1, 2 do
        for i = 1, 11 do
            local e = Enemy:new()
            e:setAnimator(animator_list['en_2'])
            e:setXY(count_x, count_y)
            el:addEnemy(e)
            count_x = count_x + 50
        end
        count_x = 110
        count_y = count_y + 40
    end

    for a = 1, 2 do
        for i = 1, 11 do
            local e = Enemy:new()
            e:setAnimator(animator_list['en_3'])
            e:setXY(count_x, count_y)
            el:addEnemy(e)
            count_x = count_x + 50
        end
        count_x = 110
        count_y = count_y + 40
    end

    -- print("p_x * size_xy / 2", p_x * size_xy / 2)
    -- print("p_y * size_xy ", p_y * size_xy)
    animator_list['cannon']:draw(enemies, p_x * size_xy / 2, p_y * size_xy);
    animator_list['bullet_1']:draw(enemies, p_x * size_xy / 2, p_y * size_xy - 100);
    animator_list['bullet_2']:draw(enemies, p_x * size_xy / 2 + 100, p_y * size_xy - 100);
    animator_list['bullet_cannon']:draw(enemies, p_x * size_xy / 2 + 200, p_y * size_xy - 100);

    if orientation['shot'] then
        love.graphics.print('Shooting', 200, 0)
    end

    love.graphics.setFont(score_font)
    love.graphics.print(score, 10, 0)

    if orientation['shot'] then shoot() end
end

function game_load()
    -- debug.debug()
    -- t.console = true
    font1 = love.graphics.newFont('fonts/Marker Felt.ttf', 36)
    font2 = love.graphics.newFont('fonts/Marker Felt.ttf', 20)

    lost_flag = false
    paused_flag = false

    -- bullet_list = {}

    width = 800
    height = 600

    size_xy = 16
    sn_x = math.abs(width / size_xy)
    sn_y = math.abs(height / size_xy)

    p_x = 7
    p_y = 32

    orientation = {
        shot = nil,
        double_shot = nil,
        left = nil,
        right = nil
    }

    figs_dir = 'figs/'

    love.window.setTitle("Space Invaders v1.0")
    -- border = love.graphics.newImage(figs_dir .. 'border.png')
    cannon = love.graphics.newImage(figs_dir .. 'sn1.png')
    loadAssets()
    setAnimator()

    love.window.setMode(width, height)

    time_lapse = 0
    time_update_limit = .2

    music = love.audio.newSource(figs_dir .. "song.xm")
    music:setLooping(true)
    music:play()

    score_font = love.graphics.newFont(26)
    score = 0

    createEnemies()
end

function reset_game()
    enemy_pos_list = {}
    lost_flag = false

    sn_x = math.abs(width / 16)
    sn_y = math.abs(height / 16)

    enemy_pos_list[1] = {x = sn_x, y = sn_y}
    enemy_list_count = 1
    score = 0
end


