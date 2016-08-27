currentMovement = 'nomov'

function getKeyboard (key)
	if key == 'left' then
		currentMovement = 'left'
	elseif key == 'right' then
		currentMovement = 'right'
	end
end

