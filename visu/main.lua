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

function	get_middle(size)
	local middle = {}
	middle[1] = (love.graphics.getWidth() / 2 - 150)
	middle[2] = (love.graphics.getHeight() / 2 - 150)
	return middle
end

function	size_cubes(size_map)
	local size = {}
	size[1] = 650 / size_map[1]
	size[2] = 650 / size_map[2]
	return size
end

function	get_player(file)
	local	tab = {}
	for i=1, 2 do
		while (string.find(file, "$$$ exec p") == nil) do
			file = io.read("*line")
		end
	tab[i] = string.sub(file, 24, string.len(file) - 8)
	--io.write(tab[i], '\n')
	file = io.read("*line")
	end
	tab[3] = "Egalite"
	return tab
end

function	get_color(player)
	--love.timer.sleep(0.001)
	if (player == 'X') then return 255, 0, 0 end
	if (player == 'x') then return 255, 100, 0 end
	if (player == 'O') then return 0, 0, 255 end
	if (player == 'o') then return 0, 100, 255
	else return 50, 75, 50 end
end

function	get_winner(line)
	local r1 = line
	local score = {}
	score[1] = tonumber(string.sub(r1, 10))
	line = io.read("*line")
	score[2] = tonumber(string.sub(line, 10))
--	io.write(line, '\n')
--	io.write(tonumber(string.sub(line, 10)))
	if ( score[1] > score[2]) then return 1, score 
	else if (score[1] < score[2]) then return 2 ,score
	else return 3, score
	end
	end
end

function leave()
	love.timer.sleep(6)
	love.event.quit()
	os.exit()
end

--**************************************************************--

function	love.load()
	love.window.setFullscreen(true)
	font = love.graphics.newFont("font2.ttf", 40)
	love.graphics.setFont(font)
	fin = 0
	score = {}
	players = {}
	size_map = {}
	middle = {}
	size_cube = {}
	taille_x_fntr = love.graphics.getWidth()
	lag_y =  (love.graphics.getHeight() - 650) / 3
	file = io.read("*line")
	players = get_player(file)
	size_map = get_size_map(file)
	size_cube = size_cubes(size_map)
	--io.write(size_map[1], size_map[2])
	--io.write('\n')
	middle = get_middle(size_map)
end

function	love.update()
	love.timer.sleep(0.02)
	if (fin == 1) then 
		leave()
	end
	file = io.read("*line")
	while (string.find(file, "Plateau") == nil) do
		if (string.find(file, "== ") ~= nil) then
			fin = 1
			break
		end
		file = io.read("*line")
		if (file == nil) then
			love.timer.sleep(4) 
			os.exit()
		end
	end
--	io.write(file)
--	io.write('\n')
	if (fin ~= 1) then
		file = io.read("*line")
		file = io.read("*line")
	end
end


function	love.draw()
	local index_c = 1
	local red, green, blue
	if (fin == 1) then
		--io.write(file, '\n') 
		--file = io.read("*line")
		--io.write(file, '\n')
		--love.graphics.setColor(255,255,255)
		--love.graphics.rectangle('fill', 0,0,200,300)
		love.graphics.setColor(255,0,0)
		local winner
		winner, score = get_winner(file)
		love.graphics.print(players[winner] .. " WON", middle[1] - 150, middle[2])
		love.graphics.setColor(255, 255, 255)
		love.graphics.print("Score : ", middle[1], middle[2] + 100)
		love.graphics.setColor(255, 0, 255)
		love.graphics.print("\t\t" .. score[1], middle[1], middle[2] + 100)
		love.graphics.setColor(255, 255, 255)
		love.graphics.print("\t\t\t VS ", middle[1], middle[2] + 100)
		love.graphics.setColor(255, 0, 255)
		love.graphics.print("\t\t\t\t\t" .. score[2], middle[1], middle[2] + 100)
	end
	if (fin ~= 1) then
		love.graphics.setColor(0,0,255)
		love.graphics.print(players[1], 10, middle[2])
		love.graphics.setColor(255, 0, 0)
		love.graphics.print(players[2], taille_x_fntr - (string.len(players[2]) * 20), middle[2])
	end
	for index=0,size_map[1] - 1 do
		if (fin == 1) then break end
		file = string.sub(file, 5)
		for index_str=0, size_map[2] - 1 do
			--io.write(index, ' ', index_str)
			--io.write('\n')
			red, green, blue = get_color(string.sub(file, index_str, index_str))
			love.graphics.setColor(red, green, blue)
			--love.graphics.rectangle('fill', 0,0,653, 653)
			love.graphics.rectangle('fill', 325 + index_str * (size_cube[2] + 1), lag_y + index * (size_cube[1] + 1), size_cube[2], size_cube[1])
			index_c = index_c + 1 
		end
--		io.write(file)
--		io.write('\n')
		file = io.read("*line")
	end
--	io.write('\n')
	--love.timer.sleep(0.2)
end
