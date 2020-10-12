mountain :: Integer -> [Integer]
mountain 1 = [1]
mountain x 
    | x < 0      = []
    | otherwise  = [1.. x-1] ++ [x, x-1 .. 1]

isLetter :: Char -> Bool
isLetter x = elem x (['a'..'z'] ++ ['A'..'Z'])

isSingleton :: [a] -> Bool
isSingleton [x] = True
isSingleton _ = False