import Data.Char

count :: (a -> Bool) -> [a] -> Int
count f l = length $ filter f l

transformFirst :: String -> Maybe String
transformFirst "" = Nothing
transformFirst (x : xs )
    | isLower x = Just ((toUpper x) : xs)
    | isUpper x = Just ((toLower x) : xs)
    | otherwise = Just xs
    
negativeFilter :: (a -> Bool) -> [a] -> [a]
negativeFilter f l = foldr (\x r -> if (not $ f x) then x:r else r) [] l


firstFunction f x Nothing 
    | (f x) = Just x
    | otherwise =  Nothing
firstFunction f x (Just y) = Just y

first :: (a -> Bool) -> [a] -> Maybe a
first f l =  foldl (\r x -> firstFunction f x r) Nothing l

data Tool = Hammer Int | Wrench Int | Screwdriver deriving (Eq)

createTool :: String -> Int -> Maybe Tool
createTool "Hammer" n 
    | n < 1 = Nothing
    | otherwise = Just (Hammer n)
createTool "Screwdriver" n  = Just Screwdriver
createTool "Wrench" n
    | n < 1 = Nothing
    | otherwise = Just (Wrench n)
createTool s n = Nothing