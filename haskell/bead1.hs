data Sign = Rock | Paper | Scissors deriving (Eq, Show)
data Result = Player1 | Player2 | Draw deriving (Eq, Show)

type Player = (String, [Sign])
type Strat = (Int -> Sign)

annaStrat :: Strat
annaStrat x = 
    case (mod x 3) of
        0 -> Rock
        1 -> Paper
        2 -> Scissors

anna :: Player
anna = ("Anna", map annaStrat [0..])

john :: Player
john = ("John", map (\_ -> Paper) [1..])

georgeStrat :: Strat
georgeStrat x
    | mod x 7 == 5 = Rock
    | mod x 3 == 0 = Paper
    | otherwise = Scissors

georgeStrategy :: [Int] -> [Sign]
georgeStrategy = map georgeStrat    

george :: Player
george = ("George", georgeStrategy [1..])

invertGame :: Result -> Result
invertGame Player1 = Player2
invertGame Player2 = Player1
invertGame x = x

compareSign :: Sign -> Sign -> Result
compareSign Rock Scissors = Player1
compareSign Rock Paper = Player2
compareSign Scissors Paper = Player1
compareSign x y 
    | x == y = Draw
    | otherwise = invertGame (compareSign y x)

compareSigns :: [Sign] -> [Sign] -> [Result]
compareSigns x y = map (\z -> compareSign (fst z) (snd z)) (zip x y)

fightPlayers :: Player -> Player -> [Result]
fightPlayers x y = compareSigns (snd x) (snd y)

evaluateResult :: Result -> Int
evaluateResult Player1 = 1
evaluateResult Player2 = -1
evaluateResult _ = 0

calculatePoints :: [Result] -> Int
calculatePoints = foldr (\x v -> v + (evaluateResult x)) 0

fightPlayersUntil :: Player -> Player -> Int -> [Result]
fightPlayersUntil x y c = take c (fightPlayers x y)

evaluateTournament :: Int -> Result
evaluateTournament x
    | x > 0 = Player1
    | x < 0 = Player2
    | otherwise = Draw

tournament :: Player -> Player -> Int -> (String, Int)
tournament x y c = 
    case (evaluateTournament (score)) of
        Player1 -> (fst x, absScore)
        Player2 -> (fst y, absScore)
        Draw -> (concat [fst x, "/", fst y], absScore)
        where   score = calculatePoints (fightPlayersUntil x y c) 
                absScore = abs score
