import Data.List

pythagoreanTriple :: (Ord a, Num a) => a -> a -> a -> Bool
pythagoreanTriple a b c = ((sort [a,b,c]) !! 0) ^ 2 + ((sort [a,b,c]) !! 1) ^ 2 == ((sort [a,b,c]) !! 2) ^ 2

isLeapYear  :: Integral a => a -> Bool
isLeapYear a = mod a 400 == 0 || mod a 100 /=0 && mod a 4 == 0

calc :: (Int, Char, Int) -> Int
calc (a, '+', b) = a + b
calc (a, '*', b) = a * b
calc (a, '/', b) = div a b
calc (a, '-', b) = a - b