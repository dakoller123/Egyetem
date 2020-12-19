import Data.List

-- compress :: Eq a => [a] -> [(Int,a)]
-- compress l = map (\x -> ([head x], length x)) (group l)

numbersMadeOfThrees :: [Integer]

numbersMadeOfThrees = map (\x -> 3 * 10 ^ x) [1..] 