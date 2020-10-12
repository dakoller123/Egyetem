divisors  :: Integer -> [Integer]
divisors 0 = [0..]
divisors x = [n | n <- [1..x], mod x n == 0] 

distantPairs :: [(Integer,Integer)] -> Int
distantPairs [] = 0
distantPairs [(x, y)]
   |   abs(x-y) > 1 = 1
   |   otherwise = 0
distantPairs (x:xs) = (distantPairs [x]) + (distantPairs xs)

everyFifth :: [a] -> [a]
everyFifth a = [ y | (x,y)<-zip [1..] a, mod x 5 == 1]