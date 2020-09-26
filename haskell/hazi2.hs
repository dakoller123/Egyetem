circlePerimeter :: Float -> Float
circlePerimeter r = 2*r*pi

circleArea :: Float -> Float
circleArea r = r*r*pi

squarePerimeter x = 4*x
id' x = x 


elsohazi :: Bool
elsohazi = (4 + ((5 * (3 ^ (6 ^ 3))) `mod` (2 - 1))) == (4 + 5 * 3 ^ 6 ^ 3 `mod` 2 - 1)

isSorted :: Ord a => (a, a, a) -> Bool
isSorted (a, b, c) = ((a == b || a < b) && (b == c || b < c) && (a <= c || a == c))

