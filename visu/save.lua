-- MAIN

function is_digit(c)
	if (c >= 48 and c <= 57) then return 1
	end
	return 0
end

function get_size_map(file) --Retourne la taille de la map grace a "Plateau x y:"
	local size = {}
	local index = 1
	while (string.find(file, "Plateau") == nil) do
		file = io.read("*line")
		if (file == nil) then love.event.quit() end
	end
	local str = string.sub(file, 9)
	while (is_digit(string.byte(string.sub(str, index, index))) == 1) do index = index + 1 end
	size[1] = tonumber(string.sub(str, 0, index - 1))
	size[2] = tonumber(string.sub(str, index + 1, string.len(str) - 1))
	return size
end

function	init_canvas(size)
	local canvas = {}
	io.write(size[1] * size[2])
	io.write('\n')
	for index=0, size[1] * size[2] do
		canvas[index] = love.graphics.newCanvas(10, 10)
		love.graphics.setCanvas(canvas[index])
		love.graphics.setColor(200, 0, 200)
		love.graphics.rectangle('fill', 0, 0, 10, 10)
		love.graphics.setCanvas()
	end
	return canvas
end

function	get_middle(size)
	local middle = {}
	middle[1] = (love.graphics.getWidth() / 2 - 150)
	middle[2] = (love.graphics.getHeight() / 2 - 150)
	return middle
end

function	get_color(player)
	--love.timer.sleep(0.001)
	if (player == 'X' or player == 'x') then return 255, 0, 0 end
	if (player == 'O' or player == 'o') then return 0, 0, 255
	else return 255, 255, 255 end
end

function	edit_canvas(canvas, index_c, line, size)
	local red
	local green
	local blue
	for index = 1, size[2] do
		if (string.sub(line, index, index) ~= '.') then
			love.graphics.setCanvas(canvas[index_c + index])
			red, green, blue = get_color(string.sub(line, index, index))
			love.graphics.setColor(red, green, blue)	
			love.graphics.rectangle('fill', 0, 0, 10, 10)
			love.graphics.setCanvas()
		end
	end 
end

--**************************************************************--

function	love.load()
	size_map = {}
	canvas = {}
	middle = {}
	file = io.read("*line")
	size_map = get_size_map(file)
	middle = get_middle(size_map)
	canvas = init_canvas(size_map)
end

function	love.update()
	file = io.read("*line")
	while (string.find(file, "Plateau") == nil) do
		file = io.read("*line")
		if (file == nil) then
			love.timer.sleep(5) 
			os.exit()
		end
	end
	file = io.read("*line")
	file = io.read("*line")
end


function	love.draw()
	local index_c = 1
	io.write('\n')
	for index=1,size_map[1] do
		edit_canvas(canvas, index_c, string.sub(file, 4), size_map)
		for index_str=0, size_map[2] - 1 do
			love.graphics.draw(canvas[index_c],middle[1]  + index_str * 20, middle[2] + (index - 1) * 20)
			index_c = index_c + 1 
		end
		if (file ~= nil) then
		--	love.graphics.print(file, 0,index * 12)
			io.write(file)
			io.write('\n')
		end
		-- ICI JE VOSI LES LIGNES UNE APR UNE
		
		file = io.read("*line")
	end
end
