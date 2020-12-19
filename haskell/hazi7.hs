import Data.Char

concat' :: [[a]] -> [a]
concat' = foldr (++) []

upperOrBust x 
    | isUpper x = [toLower x]
    | otherwise = []

upperToLower  :: String -> String
upperToLower x = concat' (map upperOrBust x)

any' :: ( a-> Bool) -> [a] -> Bool
any' f l = foldr (||) False (map f l)

hasLongLines l = any (\x -> length x >2) $ map words (lines l)

splitAt' :: Int -> [a] -> ([a],[a])
splitAt' x l = (take x l, drop x l)