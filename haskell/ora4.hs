mul :: (Num a, Num b) => (a,b) -> (a,b) -> (a,b)

mul (a,b)  (c,d) = (a*c,b*d)


-- quad1 a b c = sqrt(b^2 -4*a*c)
-- quad2 x b

-- quadratic a b c = ( ((-b) + sqrt(b^2 -4*a*c)) / (2*a))

firstOfPair :: (a,b) -> a
firstOfPair = fst

convertInttoBool _ = True
convertInttoBool 0 = False