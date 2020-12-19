import Data.List

compress :: Eq a => [a] -> [(Int,a)]
compress l = map (\x -> (length x, head x)) (group l)

decompress :: Eq a => [(Int,a)] -> [a]
decompress l = foldr (\x xs -> (take (fst x) (repeat (snd x))) ++ xs) [] l

threes:: Integer -> Integer
threes 0 = 0
threes 1 = 3
threes x = 3 * 10 ^ (x-1) + threes (x - 1)

numbersMadeOfThreesAndOne :: [Integer]
numbersMadeOfThreesAndOne = map ((\x -> x-2) . threes) [1..] 


emailProcess :: [Char] -> ([Char], [Char])
emailProcess l
    | length (filter (\ x -> x == '@') l) == 1 = (takeWhile (\x -> x /= '@') l, tail (dropWhile (\x -> x /= '@') l))
    | otherwise = error "this is an error message"