require 'enemy'
require 'list'
require 'cannon'

local anim = require 'anim8'

animator_list = {}

function loadAssets(cannon, barries)
    enemies = love.graphics.newImage(figs_dir .. 'enemies.png')

    -- Isso foi muito fooooda por mim mesmo heh 
    enemies:getData():mapPixel(
        function (x, y, r, g, b, a) 
            if r == 0 and g == 0 and b == 0 then
                a = 0
            end
            return r, g, b, a
        end
     )
end

function setAnimator()
    local g = anim.newGrid(32, 32, enemies:getWidth(), enemies:getHeight())
    animator_list['en_1'] = anim.newAnimation(g('5-6', 1), 0.4)
    animator_list['en_2'] = anim.newAnimation(g('1-2', 1), 0.4)
    animator_list['en_3'] = anim.newAnimation(g('3-4', 1), 0.4)
    animator_list['cannon'] = anim.newAnimation(g('1-1', 2), 0.1)
    animator_list['bullet_1'] = anim.newAnimation(g('2-3', 2), 0.1)
    animator_list['bullet_2'] = anim.newAnimation(g('4-5', 2), 0.1)
    animator_list['cannon_bullet'] = anim.newAnimation(g('6-6', 2), 0.1)
end

function createEnemies()

    local count_x = 110
    local count_y = 120

    el = List:new { count_list = 1 }

    for i = 1, 11 do
        local e = Enemy:new()
        e:setAnimator(animator_list['en_1'])
        e:setInitXY(count_x, count_y)
        el:add(e)
        count_x = count_x + size_xy * 3
    end
    count_x = 110
    count_y = count_y + 2 * size_xy

    for a = 1, 2 do
        for i = 1, 11 do
            local e = Enemy:new()
            e:setAnimator(animator_list['en_2'])
            e:setInitXY(count_x, count_y)
            el:add(e)
            count_x = count_x + size_xy * 3
        end
        count_x = 110
        count_y = count_y + 2 * size_xy
    end

    for a = 1, 2 do
        for i = 1, 11 do
            local e = Enemy:new()
            e:setAnimator(animator_list['en_3'])
            e:setInitXY(count_x, count_y)
            el:add(e)
            count_x = count_x + size_xy * 3
        end
        count_x = 110
        count_y = count_y + 2 * size_xy
    end

    love.graphics.setFont(score_font)
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
        shoot = nil,
        double_shot = nil,
        left = nil,
        right = nil
    }

    figs_dir = 'figs/'

    love.window.setTitle("Space Invaders v1.0")
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

    cannon = Cannon:new()
    cannon:setAnimator(animator_list['cannon'])
    cannon:setXY(p_x * size_xy / 2, p_y * size_xy)
    cannon:setState(true)
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


