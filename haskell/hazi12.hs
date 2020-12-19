data MathError = ZeroDiv | NegSqrt | NegLog deriving (Eq, Show, Ord)

safeDiv :: Int -> Int -> Either MathError Int
safeDiv x y 
    | (y == 0)  = Left ZeroDiv
    | otherwise = Right $ div x  y
    
safeSqrt :: Float -> Either MathError Float
safeSqrt x 
    | x < 0 = Left NegSqrt
    | otherwise = Right $ sqrt x
    
safeLog :: Float -> Either MathError Float
safeLog x
    | x < 0 = Left NegLog
    | otherwise = Right $ log x