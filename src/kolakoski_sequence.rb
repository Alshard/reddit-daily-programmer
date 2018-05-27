require 'benchmark'

# Calculates the kolakoski sequence of length n with a brute force algorithm
def kolakoski(n)
  queue = [2]
  seq = "122"       # start with 122 
  lastLenOne = false
  
  while seq.length < n.to_i
    blockLen = queue.shift
    last = seq[-1]
    
    opp = last == "1" ? "2" : "1"
    
    if blockLen == 1
      seq << opp
      queue.push(opp.to_i)
      lastLenOne = true
      elsif blockLen == 2 && seq[-2] != last && !lastLenOne
      seq << last
      queue.push(last.to_i)
      lastLenOne = false
      else
      seq << opp << opp
      queue.push(opp.to_i)
      queue.push(opp.to_i)
      lastLenOne = false
      end
  end
  
  if seq.length > n.to_i
    seq = seq[0...n.to_i]   # remove excess symbols
  end
  
  return seq
end

# Calculate the kolakoski sequence of input length and print ratio of 1's to 2's
begin
  puts "Enter number of symbols:"
  input = $stdin.gets.chomp
  seq = ""
  ones = 0
  twos = 0
  
  Benchmark.bm(1) do |x|
    x.report("First:") {seq = kolakoski(input)}
    x.report("Second:") {
      (0..seq.length).each do |i|
        if seq[i] == '1'
          ones += 1
          else 
          twos += 1
          end
      end   
    }
    
    puts "Ratio is of 1's to 2's is: " << ones.to_s << ":" << twos.to_s   
    end
end