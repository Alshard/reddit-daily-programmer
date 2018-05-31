# copied from /u/FunWithCthulhu3 
require 'set'

def count_hours(lights)
  hours = Set.new
  lights.each_line do |pair|
    arr = pair.split(/\s+/).map(&:to_i)
    hours.merge(arr.first...arr.last)
  end
  hours.count
end

ex = '1 3
2 3
4 5'

c1 = '2 4
3 6
1 3
6 8'

c2 = '6 8
5 8
8 9
5 7
4 7'

bonus = '15 18
13 16
9 12
3 4
17 20
9 11
17 18
4 5
5 6
4 5
5 6
13 16
2 3
15 17
13 14'

puts count_hours(ex)
puts count_hours(c1)
puts count_hours(c2)
puts count_hours(bonus)
