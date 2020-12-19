pow :: (Fractional a) => a -> Int -> a
pow x 0 = 1
pow x 1 = x
pow x y 
    | y < 0 = pow x (y+1) / x
    | otherwise = x * pow x (y-1)

length' :: [a] -> Int
length' [] = 0
length' [x] = 1
length' (x:xs) = 1 + length' xs

elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a [x] =  (a == x)
elem' a (x:xs) = (a == x) || elem' a xs

multiply 0 x = 0
multiply x 0 = 0
multiply x 1 = x
multiply x y = x + multiply x (y-1)