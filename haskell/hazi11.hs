data Time = T Int Int deriving (Eq, Show, Ord)

isBetween:: (Eq a, Ord a) => a -> a -> a -> Bool
isBetween x y z = (x <= y && y <= z) || (z <= y && y <= x) 

timeWithValidHours :: Int -> Int -> Time
timeWithValidHours h m 
    | 0 <= m &&  m < 60 = T h m
    | otherwise = error "invalid minute: " h

time :: Int -> Int -> Time
time h m 
    | 0 <= h && h < 24 = timeWithValidHours h m
    | otherwise = error "invalid hour: " h
    
    
eqTime :: Time -> Time -> Bool
eqTime (T h1 m1) (T h2 m2) = (h1 == h2) && (m1 == m2)

data USTime = AM Int Int | PM Int Int deriving (Show, Eq)

showUSTime :: USTime -> String
showUSTime (AM hour minute) = concat [show hour, ".", show minute, " ", "am"]
showUSTime (PM hour minute) = concat [show hour, ".", show minute, " ", "pm"]

usTimeToTime :: USTime -> Time
usTimeToTime (AM 12 minute) = T 0 minute
usTimeToTime (AM hour minute) = T hour minute
usTimeToTime (PM 12 minute) = T 12 minute
usTimeToTime (PM hour minute) = T (hour +12) minute

timeToUSTime :: Time -> USTime
timeToUSTime (T hour minute)
    | hour < 1 = AM (hour+12) minute
    | hour < 12 = AM hour minute
    | hour == 12 = PM hour minute
    | otherwise = PM (hour-12) minute