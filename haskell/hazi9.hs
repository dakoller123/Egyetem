dotProduct :: Num a => [a] -> [a] -> a
dotProduct (x:xs) (y:ys) = x * y + dotProduct xs ys
dotProduct [] [] = 0

dropWord :: [Char] -> [Char]   
dropWord = dropWhile (\ x -> x /= ' ')

evenSquareNums :: Integer 
evenSquareNums = sum $ map (^2) $ takeWhile (\x -> x^2 < 1000) [0,2..]
-- alternatíva
-- evenSquareNums = sum [x*x | x <- [0,2..(floor $ sqrt 1000)]]