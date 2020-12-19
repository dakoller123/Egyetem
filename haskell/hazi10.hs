fromBin :: [Int] -> Integer
fromBin x =  toInteger (foldr (\e c -> c + 2 ^(fst e) * (snd e)) 0 $ zip [0..] x)


polinom :: Num a => [a] -> a -> a
polinom p x  = foldr (\e c -> c + x ^(fst e) * (snd e)) 0 $ zip [0..] p 


