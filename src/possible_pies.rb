$pumpkin = [1,0,3,4,3]
$apple = [0,1,4,3,2]

begin
  pumpkins = 0
  apples = 0

  puts "Enter ingredients \n"
  ingredients = $stdin.gets.chomp
  ingredients = ingredients.split(",").map {|c| c.to_i}

  count = 0
  positive = true

  while positive
    ingredients.map!.with_index {|x, i| x - $pumpkin[i]} # use pumpkin ingredients

    # check that there are still ingredients remaining
    if ingredients.any? {|e| e < 0}
      positive = false
      break 
    end

    count += 1
    temp = ingredients.clone
    newApples = 0
    tempPositive = true

    # find number of apple pies possible with ingredients
    while tempPositive 
      temp.map!.with_index {|y, j| y - $apple[j]}
      if temp.any? {|k| k < 0}
        tempPositive = false
      else
        newApples += 1
      end
    end
    # update the max pumpkins and apples if they are larger than recorded values
    if (count + newApples) > (pumpkins + apples)
      pumpkins = count
      apples = newApples
    end
  end

  puts pumpkins.to_s << " pumpkin pies and " << apples.to_s << " apple pies"
end
