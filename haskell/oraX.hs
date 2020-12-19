import Data.Char

upAndDownList :: [Int]
upAndDownList = [1..100] ++ [99, 98..1]


upAndDownListToX :: Int -> [Int]
upAndDownListToX 1 = [1]
upAndDownListToX 2 = [1,2,1]
upAndDownListToX 3 = [1,2,3,2,1]
upAndDownListToX x = [1..x] ++ [x-1, x-2..1]

repeat123 :: [Int]
repeat123 = map (\x -> mod x 3 + 1) [0..78]

evenSeventeen :: [Int]
--eleg egy feltetel, mod x (17*2)
evenSeventeen = [x | x <-[67..978], mod x 17 == 0,  mod x 2 == 0]

absoluteNegatives :: [Int] -> [Int]
absoluteNegatives l  = map abs $ filter  (\x -> x < 0)  l

addSum :: [Int] -> [Int]
addSum l = sum l : l

data Answer = Yes | No | Unsure deriving Eq

convertAnswer :: Answer -> Maybe Bool
convertAnswer Yes = Just True
convertAnswer No = Just False
convertAnswer Unsure = Nothing

convertAnswerNumber :: (Int, Answer) -> (Int, Maybe Bool)
convertAnswerNumber x = (fst x, convertAnswer (snd x))

convertAnswers :: [(Int, Answer)] -> [(Int, Maybe Bool)]
convertAnswers l = map convertAnswerNumber l


convertAnswerBack :: Maybe Bool -> Answer
convertAnswerBack (Just True) = Yes
convertAnswerBack (Just False) = No
convertAnswerBack Nothing = Unsure

convertAnswerNumberBack :: (Int, Maybe Bool) -> (Int, Answer)
convertAnswerNumberBack x = (,) (fst x) (convertAnswerBack (snd x))

convertAnswersBack :: [(Int, Maybe Bool)] -> [(Int, Answer)]
convertAnswersBack l = map convertAnswerNumberBack l

lastMap :: (a -> a) -> [a] -> [a]
lastMap f [] = []
lastMap f [x] = [(f x)]
lastMap f l = reverse ((f (last l)) : (tail $ reverse l ))

data Shape = Circle Double | Square Double | Rectangle Double Double

area :: Shape -> Double
area (Circle x) = x * x * pi
area (Square x) = x * x
area (Rectangle x y) = x * y

zip3Lists :: [Int] -> [Int] -> [Int] -> [Int]
zip3Lists (x:xs) (y:ys) (z:zs) = (x*y*z) : zip3Lists xs ys zs
zip3Lists x y z = []

minusGameStep (a,b)
    | (a >= b) = ((a-b), b)
    | otherwise = (a, (b - a))

minusGameExit :: (Int, Int) -> Bool
minusGameExit x = (fst x == 0 || snd x == 0)

minusGameIterator :: [(Int, Int)] -> [(Int, Int)]
minusGameIterator l 
    | minusGameExit (head l) = l
    | otherwise = minusGameIterator ((minusGameStep (head l)) : l)

minusGame :: (Int, Int) -> [(Int, Int)]
minusGame x 
    | (minusGameExit x) = []
    | otherwise = reverse $ minusGameIterator [(minusGameStep x)]   

decodeMessage :: [Integer] -> String
decodeMessage  = map $ chr . floor . sqrt . fromInteger

data Tree a = Leaf a | Node (Tree a) (Tree a) deriving (Eq, Show)

convertTree :: Tree Int -> Tree Int
convertTree (Leaf x) = Leaf (x*x)
convertTree (Node x y) = Node (convertTree x) (convertTree y)

neptunCodeValidator :: String -> Bool
neptunCodeValidator x = (length x == 6) && (all (\y -> (isUpper y) || (isNumber y)) x)

lookupDict :: Eq a => a -> [(a, b)] -> Maybe b
lookupDict element [] = Nothing
lookupDict element (entry:rest)
    | (element == (fst entry)) = Just (snd entry)
    | otherwise = lookupDict element rest
    
lookupNeptunCode :: String -> [(String, String)] -> Maybe String
lookupNeptunCode code codes
    | neptunCodeValidator code = lookupDict code codes
    | otherwise = Nothing
